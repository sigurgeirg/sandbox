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
    numberOfBeltRoundsZero = -4;
    sampleCounter = 0;
    productCounter = 0;
    filterCounter = 0;
    lastRound = 0;
    pulseCounter = 0.0;
    pulsesPerBeltRound = 0.0;
    pulseResolution = 0.0;
    lengthOfEachBeltPeriod = 0.0;
    lengthOfEachBeltChain =  (25.4 / 2);
    numberOfBeltChains = 280;
    lengthOfEachBeltPeriod = (lengthOfEachBeltChain * numberOfBeltChains);
    dMedian = 0.0;

    zt_InitializeZeroVectors = 1;
    zt_CollectDiscreteWeightSamples = 2;
    zt_CalculateMedianOfZeroPath = 3;
    zt_ReturnResultsToFile = 4;
    zt_RunningFilter = 5;
    zt_ProductFilter = 6;

    zeroTracking = zt_InitializeZeroVectors;

    filterValue = 0;
    filterSUM = 0;

}


MyScale::~MyScale()
{
    delete statusRegisterBinaryTempValue;
    delete statusRegisterBinaryReturnValue;
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
    sampleCounter = 0;
    numberOfBeltRoundsZero++;
}

void MyScale::productSignalCounter()
{
    productCounter = 0;
}

void MyScale::modelZeroWeight(int weightValueFromScale) {


    if (zeroTracking == zt_CollectDiscreteWeightSamples) {

        if ((numberOfBeltRoundsZero > -1) && (numberOfBeltRoundsZero < NUMBER_OF_BELTROUNDS)) {
            // Assign weight value from scale in initializing matrix
            if (sampleCounter < SAMPLES_PER_BELTROUND) {

                zeroUnfilteredArray[numberOfBeltRoundsZero][sampleCounter] = weightValueFromScale;
                sampleCounter++;
                pulseCounter++;
            }
        }

        if (numberOfBeltRoundsZero >= NUMBER_OF_BELTROUNDS) {

            pulsesPerBeltRound = pulseCounter / NUMBER_OF_BELTROUNDS;
            pulseResolution = lengthOfEachBeltPeriod / pulsesPerBeltRound;

            zeroTracking = zt_CalculateMedianOfZeroPath;
        }
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
        zeroTracking = zt_ReturnResultsToFile;
    }


    if (zeroTracking == zt_ReturnResultsToFile) {

        filezero.open("zeroweight.csv", std::ofstream::out | std::ofstream::trunc); // trunc changed to app, trunc clears the file while app appends it

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
        }
        filezero.close();

        zeroTracking = zt_ProductFilter;
    }


    // Next step :
    // 1. Should we write std array with respect to the processed matrix (array) where we do the zeroArray ??
    // 2. Return info:
    //          avg weight array, std array, number of samples, number of rounds
    //          number of samples might deviate +/-1, then we just accept lowest common denomintor ...
    // 3. Verify if zerofFilter has been updated
    // 4. emit all necessary signals back to where weighing will be processed with respect to floating zero.
    // 5. should all be emitted or some written to a globally accessible pointer ???

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

    if (zeroTracking == zt_ProductFilter){

        productCounter++;

        if ((productCounter > pulseResolution




        emit sendFilteredWeight(filterValue);
    }




}




void MyScale::run() {
    
    int sign = 0;

    if (zeroTracking == zt_InitializeZeroVectors) {

        for (int _rounds = 0; _rounds < NUMBER_OF_BELTROUNDS; _rounds++) {
            for (int _samples = 0; _samples < SAMPLES_PER_BELTROUND; _samples++) {
                zeroUnfilteredArray[_rounds][_samples] = 0;
            }
        }
        for (int _samples = 0; _samples < SAMPLES_PER_BELTROUND; _samples++) {
            zeroArray[_samples] = 0;
        }
        for (int _rounds = 0; _rounds < NUMBER_OF_BELTROUNDS; _rounds++) {
            zeroColumn[_rounds] = 0;
            dSorted[_rounds] = 0;
        }
        for (int _samples = 0; _samples < FILTER_DELAY; _samples++) {
            runningFilter[_samples] = 0;
        }
        pulseCounter = 0.0;

        zeroTracking = zt_CollectDiscreteWeightSamples;
    }


    while(modbusConnected == true)
    {
        if(writeToLoadcell != true)
        {
            // /////////////////////////////////////////////////////////////////////////////////////////////
            // FIXME: Here we can set condition to only read from loadcell and emit the data forward
            // Only at zero-modelling as initialization process or when requested and when product sensor
            // indicates that the scale is about to be loaded.
            // /////////////////////////////////////////////////////////////////////////////////////////////
            modbus_read_registers(ctx, readFromRegister, 5, data);
            statusRegisterBinaryReturnValue = statusRegisterBinary(data);

            if(weightGROSSorNET[0] == grossDisplay)
            {
                sign = pow((-1),(statusRegisterBinaryReturnValue[7]));
                emit receivedWeight(sign*data[2]);
                //qDebug() << " WeightGross: " <<  sign*data[2];
            }
            else if(weightGROSSorNET[0] == netDisplay)
            {
                sign = pow((-1),(statusRegisterBinaryReturnValue[8]));
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
