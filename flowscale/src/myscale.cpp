#include "../inc/myscale.h"


MyScale::MyScale(QObject *parent) :
    QThread(parent)
{
    modbusConnected = false;
    mbCommand[0] = 0;
    commandRegister = 5;
    statusRegister = 6;
    sampleWeightForCalibrationL = 37;
    netDisplay = 7;
    semiAutomaticZero = 8;
    grossDisplay = 9;
    zeroSettingForCalibration = 100;
    sampleWeightStorage = 101;

    readFromRegister = statusRegister;
    weightGROSSorNET[0] = netDisplay; // Default NET weight

    statusRegisterBinaryTempValue = new int[16];
    statusRegisterBinaryReturnValue = new int[16];


    // from zerofilter
    enteringProduct = false;
    requestZeroUpdate = false;

    sampleCounter = 0;
    lastSampleCounter = 0;
    updateSampleCounter = 0;
    lastRound = 0;

    pulseCounter = 0.0;
    productCounter = 0.0;
    pulsesPerBeltRound = 0.0;
    pulseResolution = 0.0;
    lengthOfEachBeltPeriod = 0.0;
    lengthOfEachBeltChain =  (25.4 / 2);
    numberOfBeltChains = 280.0;
    lengthOfEachBeltPeriod = (lengthOfEachBeltChain * numberOfBeltChains);
    dMedian = 0.0;

    filterCounter = 0;
    numberOfBeltRoundsZero = -4;
    countFewBeltRounds = 0;

    zt_InitializeZeroVectors = 1;
    zt_UpdateZeroWeightSamples = 2;
    zt_CollectInitialZeroWeightSamples = 3;
    zt_CalculateMedianOfZeroPath = 4;
    zt_ReturnResultsToFile = 5;
    zt_RunningFilter = 6;
    zt_ProductFilter = 7;

    zeroTracking = zt_InitializeZeroVectors;

    filterValue = 0;
    filterSUM = 0;

    productID = -1;

    nextZeroUpdatePosition = 0;
}


MyScale::~MyScale()
{
    delete statusRegisterBinaryTempValue;
    delete statusRegisterBinaryReturnValue;
}


bool MyScale::between(int less, int value, int greater) {

    if ((value >= less) && (value < greater)) {
        return true;
    } else {
        return false;
    }
}


int* MyScale::statusRegisterBinary(uint16_t number[]) {

    uint16_t remainder=0, i=0, decimal=number[0];

    do {
        remainder = decimal%2;
        decimal = decimal/2;
        statusRegisterBinaryTempValue[i] = remainder;
        i = i+1;

    } while(decimal>0);

    return statusRegisterBinaryTempValue;
}


void MyScale::connectToSlaveDevice() {

    try {
            ctx = modbus_new_rtu("/dev/ttyUSB0", 38400, 'N', 8, 1);
            setslave = modbus_set_slave(ctx, 0x01);

            if (ctx == NULL) {
                qDebug() << "Unable to create the libmodbus context";
                modbus_free(ctx);
            }
            else qDebug() << "Creation successful";

            if (setslave == 0) {
                qDebug() << "Able to set slave successfully, value : " << setslave;
            }
            else {
                qDebug() << "Unable to set slave, value: " << setslave;
                modbus_free(ctx);
            }

            if (modbus_connect(ctx) == -1) {
                qDebug() << "Connection failed";
                modbus_free(ctx);
            }
            else {
                qDebug() << "Connection successful " << modbus_connect(ctx);
                modbusConnected = true;
                qDebug() << "ModBus is Connected";
                start();
            }
    } catch(...) {
            //
    }
}


void MyScale::disconnectFromSlaveDevice() {
    
    try {
            modbusConnected = false;

            if (modbus_connect(ctx) == -1) {
                modbus_free(ctx);
            }

            modbus_close(ctx);
            qDebug() << "ModBus is Disconnected";
            //modbus_free(ctx); //This function-call causes segfault if activated here.
    }
    catch(...) {
        //
    }
}


void MyScale::toggleWriteToLoadcell(bool checked) {
    
    if(checked == true)
        writeToLoadcell = true;
    else
        writeToLoadcell = false;
}


void MyScale::calibrateZERO() {
    
    writeToRegister = commandRegister;
    mbCommand[0] = zeroSettingForCalibration;
}


void MyScale::calibrateWEIGHT(int calibrationWeight) {

    writeToRegister = sampleWeightForCalibrationL;
    mbCommand[0] = calibrationWeight;
}


void MyScale::storeCalibrationWEIGHT() {
    
    writeToRegister = commandRegister;
    mbCommand[0] = sampleWeightStorage;
}


void MyScale::semiAutoZERO() {
    
    writeToRegister = commandRegister;
    mbCommand[0] = semiAutomaticZero;
}


void MyScale::grossWeight() {
    
    writeToRegister = commandRegister;
    mbCommand[0] = grossDisplay;
}


void MyScale::netWeight() {
    
    writeToRegister = commandRegister;
    mbCommand[0] = netDisplay;
}


void MyScale::conveyorBeltCounter()
{
    if (zeroTracking == zt_CollectInitialZeroWeightSamples) {
        lastSampleCounter = sampleCounter;
        if (numberOfBeltRoundsZero < 12) {
            pulseCounterInEachRow[numberOfBeltRoundsZero] = lastSampleCounter;
        }
        numberOfBeltRoundsZero++;
    }

    if (zeroTracking == zt_ProductFilter) {

        if (requestZeroUpdate == false) {
            if (countFewBeltRounds > 3) {

                requestZeroUpdate = true;
                // Here we can emit information to display that running ZERO tracking update has been requested
            }
            countFewBeltRounds++;
        }
    }

    sampleCounter = 0;
}


void MyScale::productSignalCounter()
{
    enteringProduct = true;
    productCounter++;
    productID++;
    if (productID >= NUMBER_OF_ELEMENTS_IN_LIST) {
        productID = 0;
    }

    productTrackerOverScale[productID] = 0;
}

void MyScale::modelZeroWeight(int weightValueFromScale) {

    if (zeroTracking == zt_CollectInitialZeroWeightSamples) {

        if ((numberOfBeltRoundsZero > -1) && (numberOfBeltRoundsZero < NUMBER_OF_BELTROUNDS)) {
            // Assign weight value from scale in initializing matrix
            if (sampleCounter < SAMPLES_PER_BELTROUND) {

                zeroUnfilteredArray[numberOfBeltRoundsZero][sampleCounter] = weightValueFromScale;

                if ((numberOfBeltRoundsZero > 0) && (lastSampleCounter+sampleCounter < SAMPLES_PER_BELTROUND)) {
                    zeroUnfilteredArray[numberOfBeltRoundsZero-1][lastSampleCounter+sampleCounter] = weightValueFromScale;
                }
                pulseCounter++;
            }
        }

        if (numberOfBeltRoundsZero >= NUMBER_OF_BELTROUNDS) {

            lastSampleCounter = 0;
            nextZeroUpdatePosition = 0;
            numberOfBeltRoundsZero = -1;

            pulsesPerBeltRound = pulseCounter / NUMBER_OF_BELTROUNDS;
            pulseResolution = lengthOfEachBeltPeriod / pulsesPerBeltRound;

            zeroTracking = zt_CalculateMedianOfZeroPath;
        }
    }



    // /////////////////////////////////////////////////////////////////////
    // In this state we update oldest zeroWeight sample with a new sample.
    // /////////////////////////////////////////////////////////////////////
    if (zeroTracking == zt_UpdateZeroWeightSamples) {

        for (int i = 0; i <= pulsesPerBeltRound; i ++) {
            zeroUnfilteredArray[nextZeroUpdatePosition][i] = updateZeroArray[i];
        }

        if (nextZeroUpdatePosition >= NUMBER_OF_BELTROUNDS) {
            nextZeroUpdatePosition = 0;
        } else {
            nextZeroUpdatePosition++;
        }

        countFewBeltRounds = 0;
        updateSampleCounter = 0;
        requestZeroUpdate = false;
        zeroTracking = zt_CalculateMedianOfZeroPath;
    }



    if (zeroTracking == zt_CalculateMedianOfZeroPath) {

        for (int _sampleColumn = 0; _sampleColumn < SAMPLES_PER_BELTROUND; _sampleColumn++) {

            for (int _rounds = 0; _rounds < NUMBER_OF_BELTROUNDS; _rounds++) {

                // This line: make new 1D array[] from only single column from zeroUnfilteredArray
                dSorted[_rounds] = (double)zeroUnfilteredArray[_rounds][_sampleColumn];
            }

            // Sort numerical values in array by size for further processing
            for (int _round = (NUMBER_OF_BELTROUNDS - 1); _round > 0; --_round) {
                for (int _sample = 0; _sample < _round; ++_sample) {
                    if (dSorted[_sample] > dSorted[_sample+1]) {
                        double dTemp = dSorted[_sample];
                        dSorted[_sample] = dSorted[_sample+1];
                        dSorted[_sample+1] = dTemp;
                    }
                }
            }


            // Median values returned from a sorted array.
            if ((NUMBER_OF_BELTROUNDS % 2) == 0) {
                dMedian = (dSorted[NUMBER_OF_BELTROUNDS/2] + dSorted[(NUMBER_OF_BELTROUNDS/2) - 1])/2.0;
            } else {
                dMedian = dSorted[NUMBER_OF_BELTROUNDS/2];
            }

            dMedian = dMedian + 0.5;                    // rounding by adding half and then cutting out the comma value
            zeroArray[_sampleColumn] = (int)(dMedian);  // when casting the double to int value

        }

        productEntryPulse = (int)((double)(PRODUCT_ENTRY)/pulseResolution + 0.5);
        weightStartPulse = (int)((double)(PRODUCT_WEIGHING_START_DISTANCE)/pulseResolution + 0.5);
        weightEndPulse = (int)((double)(PRODUCT_WEIGHING_STOP_DISTANCE)/pulseResolution + 0.5);
        productReleasePulse = (int)((double)(PRODUCT_RELEASE)/pulseResolution + 0.5);

        zeroTracking = zt_ReturnResultsToFile;
    }


    if (zeroTracking == zt_ReturnResultsToFile) {

        //filezero.open("zeroweight.csv", std::ofstream::out | std::ofstream::trunc); // trunc changed to app, trunc clears the file while app appends it
        filezero.open("zeroweight.csv", std::ofstream::out | std::ofstream::app); // trunc changed to app, trunc clears the file while app appends it

        if (filezero.is_open()) {

            for (int _rounds = 0; _rounds < NUMBER_OF_BELTROUNDS; _rounds++) {

                for (int _samples = 0; _samples < SAMPLES_PER_BELTROUND; _samples++) {
                    filezero << zeroUnfilteredArray[_rounds][_samples] << ",";
                }
                filezero << std::endl;
            }

            filezero << std::endl;
            filezero << std::endl;

            for (int _samples = 0; _samples < SAMPLES_PER_BELTROUND; _samples++) {
                filezero << zeroArray[_samples] <<  ",";
            }

            filezero << std::endl;
            filezero << "Total pulses: " << pulseCounter << "" << std::endl;
            filezero << std::endl;
            filezero << "Pulses per beltround: " << pulsesPerBeltRound << "" << std::endl;
            filezero << std::endl;
            filezero << "Resolution of each pulse: " << pulseResolution << " mm " << std::endl;
            filezero << std::endl;
            for (int i = 0; i < NUMBER_OF_BELTROUNDS; i++) {
                filezero << "PulseCounterInZeroRow number " << i << ": " << pulseCounterInEachRow[i] << "" << std::endl;
            }

        }
        filezero.close();

        int temp = 0;
        emit sendFilteredWeight(temp);
        zeroTracking = zt_ProductFilter;
    }


/*
    if (zeroTracking == zt_RunningFilter){

        runningFilter[filterCounter] = weightValueFromScale-zeroArray[sampleCounter];

        filterCounter++;
        sampleCounter++;

        if (filterCounter > 9){
            filterCounter = 0;
        }

        for(int i = 0; i < FILTER_DELAY; i++){
           filterSUM += runningFilter[i];
        }
        filterValue = filterSUM / FILTER_DELAY;
        filterSUM = 0;

        emit sendFilteredWeight(filterValue);
    }
*/



    if (zeroTracking == zt_ProductFilter){

        if (requestZeroUpdate == true) {

            if (enteringProduct == false) {

                updateZeroArray[sampleCounter] = weightValueFromScale;
                updateSampleCounter++;
                // Here we can emit information to display that running ZERO tracking update is being attempted

            } else {

                updateSampleCounter = 0;
            }

            if (updateSampleCounter >= (pulsesPerBeltRound*1.05)) {

                zeroTracking = zt_UpdateZeroWeightSamples;
                qDebug() << "Update ZeroWeight Samples";
                // Here we can emit information to display that running ZERO tracking update has been performed
            }
        }


        // Track elements from product sensor (>=0) and over weighing area on program-scantime resolution +1

        for (int _elementId = 0; _elementId < NUMBER_OF_ELEMENTS_IN_LIST; _elementId++) {
            if (productTrackerOverScale[_elementId] >= 0) {
                productTrackerOverScale[_elementId]++;


                // Track active weight on scale AREA and give each position weight
                if (between(weightStartPulse, productTrackerOverScale[_elementId], weightEndPulse)) {

                    productIDweights[_elementId][productTrackerOverScale[_elementId]-weightStartPulse] = weightValueFromScale-zeroArray[sampleCounter];
                }


                // At weiging endpoint on scale platform calculate mean value and emit modeled weight
                if (productTrackerOverScale[_elementId] == weightEndPulse) {
                    meanSample = 0;

                    for (int _sample = 0; _sample < weightEndPulse-weightStartPulse; _sample++) {
                        meanSample += productIDweights[_elementId][_sample];
                    }

                    meanSample = meanSample / (weightEndPulse-weightStartPulse);

                    emit sendFilteredWeight(meanSample);
                    emit sendDebugData(productTrackerOverScale[_elementId]);
                }


                // Last product is leaving the main platform, at delivery point, when we can consider to update the ZERO weight again.
                if (productTrackerOverScale[_elementId] ==  productReleasePulse) {

                    enteringProduct = false;
                }



                // At delivery point release product information to next module
                // FIXME: assign product ID and save product information
                //            // Later:
                //            // put info onto each product, such as IDnr, BathcNr,
                //            // weight, stddev or variance, length, destination gate, ..

                if (productTrackerOverScale[_elementId] > productReleasePulse) {
                    productTrackerOverScale[_elementId] = -1;

                    filezero.open("zeroweight.csv", std::ofstream::out | std::ofstream::app); // trunc changed to app, trunc clears the file while app appends it

                    if (filezero.is_open()) {
                        filezero << meanSample << ",";

                        for (int _samples = 0; _samples < weightEndPulse-weightStartPulse; _samples++) {
                            filezero << productIDweights[_elementId][_samples] << ",";
                        }
                        filezero << std::endl;
                    }
                    filezero.close();
                    emit sendDebugData(_elementId);
                    productTrackerOverScale[_elementId] = -1;
                }


            }
        }
    }

    sampleCounter++;
}


void MyScale::run() {
    
    int sign = 0;

    if (zeroTracking == zt_InitializeZeroVectors) {

        for (int _rounds = 0; _rounds < NUMBER_OF_BELTROUNDS; _rounds++) {
            for (int _samples = 0; _samples < SAMPLES_PER_BELTROUND; _samples++) {
                zeroUnfilteredArray[_rounds][_samples] = 0;
            }
        }
        for (int _rounds = 0; _rounds < NUMBER_OF_ELEMENTS_IN_LIST; _rounds++) {
            for (int _samples = 0; _samples < SAMPLES_PER_BELTROUND; _samples++) {
                productIDweights[_rounds][_samples] = 0;
            }
        }
        for (int _samples = 0; _samples < SAMPLES_PER_BELTROUND; _samples++) {
            zeroArray[_samples] = 0;
            updateZeroArray[_samples] = 0;
        }
        for (int _rounds = 0; _rounds < NUMBER_OF_BELTROUNDS; _rounds++) {
            zeroColumn[_rounds] = 0;
            dSorted[_rounds] = 0;
        }
        for (int _samples = 0; _samples < FILTER_DELAY; _samples++) {
            runningFilter[_samples] = 0;
        }
        for (int _samples = 0; _samples < NUMBER_OF_ELEMENTS_IN_LIST; _samples++) {
            productTrackerOverScale[_samples] = -1;
        }
        pulseCounter = 0.0;

        zeroTracking = zt_CollectInitialZeroWeightSamples;
    }


    while(modbusConnected == true)
    {
        if(writeToLoadcell != true)
        {
            modbus_read_registers(ctx, readFromRegister, 5, data);
            statusRegisterBinaryReturnValue = statusRegisterBinary(data);

            if(weightGROSSorNET[0] == grossDisplay)
            {
                sign = pow((-1),(statusRegisterBinaryReturnValue[7]));
                modelZeroWeight(sign*data[2]);
                emit receivedWeight(sign*data[2]);
                //qDebug() << " WeightGross: " <<  sign*data[2];
            }
            else if(weightGROSSorNET[0] == netDisplay)
            {
                sign = pow((-1),(statusRegisterBinaryReturnValue[8]));
                modelZeroWeight(sign*data[4]);
                emit receivedWeight(sign*data[4]);
                //qDebug() << " WeightNetto: " << sign*data[4];
            }
        }
        else
        {
            if(mbCommand[0] != 0)
            {
                modbus_write_registers(ctx, writeToRegister, 1, mbCommand);
                //qDebug() << "mbCommand: " << mbCommand[0];

                if(mbCommand[0] == grossDisplay)
                {
                    weightGROSSorNET[0] = grossDisplay;
                }
		
                else if(mbCommand[0] == netDisplay)
                {
                    weightGROSSorNET[0] = netDisplay;
                }

                mbCommand[0] = 0;
            }
        }
    }
}
