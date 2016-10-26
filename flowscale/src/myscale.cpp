#include "../inc/myscale.h"


MyScale::MyScale(QObject *parent) :
    QThread(parent)
{
    settings = new Settings(this);
    recipe = new Recipe(this);

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


    processingProduct = false;
    requestBeltRoundPulse = false;
    beltRoundPulse = false;
    requestZeroUpdate = false;

    sampleCounter = 0;
    lastSampleCounter = 0;
    updateSampleCounter = 0;
    lastRound = 0;

    pulseCounterInAllRows = 0.0;
    pulsesPerBeltRound = 0.0;
    pulseResolution = 0.0;
    lengthOfEachBeltPeriod = 0.0;

    // System settings variables
    lengthOfEachBeltChain           = QString::fromStdString(settings->lengthOfEachBeltChain.c_str()).toFloat();
    numberOfBeltChains              = QString::fromStdString(settings->numberOfBeltChains.c_str()).toFloat();
    productEntry                    = QString::fromStdString(settings->productEntry.c_str()).toInt();
    productWeighingStartDistance    = QString::fromStdString(settings->productWeighingStartDistance.c_str()).toInt();
    productWeighingStopDistance     = QString::fromStdString(settings->productWeighingStopDistance.c_str()).toInt();
    productRelease                  = QString::fromStdString(settings->productRelease.c_str()).toInt();
    plotXvalueMIN                   = QString::fromStdString(settings->XvalueMIN.c_str()).toInt();
    plotXvalueMAX                   = QString::fromStdString(settings->XvalueMAX.c_str()).toInt();
    plotYvalueMIN                   = QString::fromStdString(settings->YvalueMIN.c_str()).toInt();
    plotYvalueMAX                   = QString::fromStdString(settings->YvalueMAX.c_str()).toInt();

    lengthOfEachBeltPeriod  = (lengthOfEachBeltChain * numberOfBeltChains);

    dMedian = 0.0;

    productCounter = 0;
    filterCounter = 0;
    numberOfBeltRoundsZero = -4;
    countFewBeltRounds = 0;
    pulseCounterInAllRows = 0;
    medianZeroSample = 0;

    filterValue = 0;
    filterSUM = 0;

    tempID = -1;

    nextZeroUpdatePosition = 0;

    zt_InitializeZeroVectors = 1;
    zt_UpdateZeroWeightSamples = 2;
    zt_CollectInitialZeroWeightSamples = 3;
    zt_CalculateMedianOfZeroPath = 4;
    zt_ReturnResultsToFile = 5;
    zt_ProductFilter = 6;

    zeroTracking = zt_InitializeZeroVectors;

    // Grader settings variables:
    numberOfGatesOnGrader = 6;

    distanceToGraderGate[0] = 200;  // [mm]
    distanceToGraderGate[1] = 200;
    distanceToGraderGate[2] = 1200;
    distanceToGraderGate[3] = 1200;
    distanceToGraderGate[4] = 2200;
    distanceToGraderGate[5] = 2200;

    distanceToEndOfGrader   = 3000; // [mm]

    distanceOpenGate[0] = 500;      // [mm]
    distanceOpenGate[1] = 500;
    distanceOpenGate[2] = 500;
    distanceOpenGate[3] = 500;
    distanceOpenGate[4] = 500;
    distanceOpenGate[5] = 500;

    evenDistribution = 1;
    fillUpInSequence = 2;
    sortingMethod    = evenDistribution;

    bufferByWeight = 1;
    bufferByCount  = 2;
    bufferByWeightOrByCount = bufferByWeight;

    gateBufferWeight[0] = 20; // [kg]
    gateBufferWeight[1] = 20;
    gateBufferWeight[2] = 20;
    gateBufferWeight[3] = 20;
    gateBufferWeight[4] = 20;
    gateBufferWeight[5] = 20;

    gateBufferAmount[0] = 40; // [pcs]
    gateBufferAmount[1] = 40;
    gateBufferAmount[2] = 40;
    gateBufferAmount[3] = 40;
    gateBufferAmount[4] = 40;
    gateBufferAmount[5] = 40;

    emit conveyorRunState("conveyorOff");
}


MyScale::~MyScale()
{
    delete statusRegisterBinaryTempValue;
    delete statusRegisterBinaryReturnValue;
    delete settings;
}


void MyScale::updateRecipe(QString selectedRecipe) {

    recipe->updateRecipe(selectedRecipe);

    // Recipe variables
    productDescription              = recipe->description;
    recipeID                        = recipe->recipeID;
    batchID                         = recipe->batchID;
    productID                       = recipe->productID;
    productType                     = recipe->productType;
    serialStartsAt                  = QString::fromStdString(recipe->serialStartsAt.c_str()).toInt();
    minProductLength                = QString::fromStdString(recipe->minProductLength.c_str()).toInt();
    maxProductLength                = QString::fromStdString(recipe->maxProductLength.c_str()).toInt();
    maxProductPieceGap              = QString::fromStdString(recipe->maxProductPieceGap.c_str()).toInt();

    for (int t = 0; t < 50; t++) {

        weightRangeLower[t] = QString::fromStdString(recipe->weightRangeLower[t].c_str()).toInt();
        weightRangeUpper[t] = QString::fromStdString(recipe->weightRangeUpper[t].c_str()).toInt();
        destinationGate[t]  = QString::fromStdString(recipe->destinationGate[t].c_str()).toInt();
    }

    emit sendBatchId(QString::fromStdString(batchID.c_str()));
    emit sendRecipeId(QString::fromStdString(recipeID.c_str()));
    emit sendProductId(QString::fromStdString(productID.c_str()));
    emit sendProductType(QString::fromStdString(productType.c_str()));
    emit sendDescription(QString::fromStdString(productDescription.c_str()));
}


bool MyScale::between(int less, int value, int greater) {

    if ((value >= less) && (value < greater)) {
        return true;
    } else {
        return false;
    }
}


int MyScale::returnToGate(int measuredWeight) {

    if        (between(weightRangeLower[0], measuredWeight, weightRangeUpper[0])){

        return destinationGate[0];

    } else if (between(weightRangeLower[1], measuredWeight, weightRangeUpper[1])){

        return destinationGate[1];

    } else if (between(weightRangeLower[2], measuredWeight, weightRangeUpper[2])){

        return destinationGate[2];

    } else if (between(weightRangeLower[3], measuredWeight, weightRangeUpper[3])){

        return destinationGate[3];

    } else if (between(weightRangeLower[4], measuredWeight, weightRangeUpper[4])){

        return destinationGate[4];

    } else if (between(weightRangeLower[5], measuredWeight, weightRangeUpper[5])){

        return destinationGate[5];

    } else if (between(weightRangeLower[6], measuredWeight, weightRangeUpper[6])){

        return destinationGate[6];

    } else if (between(weightRangeLower[7], measuredWeight, weightRangeUpper[7])){

        return destinationGate[7];

    } else if (between(weightRangeLower[8], measuredWeight, weightRangeUpper[8])){

        return destinationGate[8];

    } else if (between(weightRangeLower[9], measuredWeight, weightRangeUpper[9])){

        return destinationGate[9];

    } else {

        return 0;

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

            zeroTracking = zt_InitializeZeroVectors;
            emit conveyorRunState("conveyorOff");
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


void MyScale::conveyorBeltSignal()
{
    if (zeroTracking == zt_CollectInitialZeroWeightSamples) {
        lastSampleCounter = sampleCounter;

        if (requestBeltRoundPulse == true) {
            beltRoundPulse = true;
        }

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


void MyScale::enteringProductSensorSignal()
{
    processingProduct = true;
    productCounter++;
    tempID++;
    if (tempID >= numberOfElementsInList) {
        tempID = 0;
    }

    productTickPosition[tempID] = 0;




    // Recipe variables

    //    serialStartsAt;
    //    minProductLength;
    //    maxProductLength;
    //    maxProductPieceGap;

    //    for (int t = 0; t < 50; t++) {
    //        weightRangeLower[t];
    //        weightRangeUpper[t];
    //        destinationGate[t];
    //    }

    // //////////////////////////////////////////////////////////
    // FIXME: Data that follows product from scale to grader - find better location later
    // //////////////////////////////////////////////////////////
    proData.description[tempID] = productDescription;
    proData.recipeId[tempID] = recipeID;
    proData.batchId[tempID] = batchID;
    proData.productId[tempID] = productID;
    proData.productType[tempID] = productType;

    proData.serialId[tempID] = productCounter;
    proData.productLengthPulseCounter[tempID] = 0;
    proData.productLength[tempID] = 0;
    proData.productWeight[tempID] = 0;
    proData.productConfidence[tempID] = 0;
    proData.destinationGate[tempID] = 0;
    // //////////////////////////////////////////////////////////
}


void MyScale::leavingProductSensorSignal() {

    proData.productLength[tempID] = proData.productLengthPulseCounter[tempID] * pulseResolution;
}


void MyScale::weightProcessing(int weightValueFromScale) {

    if (zeroTracking == zt_CollectInitialZeroWeightSamples) {

        // FIXME: This guard (condition) ensures that the first round starts same time as the first beltRoundPulse
        requestBeltRoundPulse = true;

        if (beltRoundPulse == true) {

            if (numberOfBeltRoundsZero < -1) {

                emit conveyorRunState("conveyorWarmUp");

            } else if ((numberOfBeltRoundsZero > -1) && (numberOfBeltRoundsZero < numberOfBeltRounds)) {

                emit conveyorRunState("conveyorZeroCalibration");

                // Assign weight value from scale in initializing matrix
                if (sampleCounter < samplesPerBeltRound) {

                    zeroUnfilteredArray[numberOfBeltRoundsZero][sampleCounter] = weightValueFromScale;

                    if ((numberOfBeltRoundsZero > 0) && (lastSampleCounter+sampleCounter < samplesPerBeltRound)) {
                        zeroUnfilteredArray[numberOfBeltRoundsZero-1][lastSampleCounter+sampleCounter] = weightValueFromScale;
                    }
                }

            } else if (numberOfBeltRoundsZero >= numberOfBeltRounds) {

                emit conveyorRunState("conveyorRunning");

                // /////////////////////////////////////////////////////////////////////
                // Median of number of samples per BeltRound
                // /////////////////////////////////////////////////////////////////////

                for (int _rounds = 0; _rounds < numberOfBeltRounds; _rounds++) {
                    dSorted[_rounds] = (double)pulseCounterInEachRow[_rounds];
                }

                // Sort numerical values in array by size for further processing
                for (int _round = (numberOfBeltRounds - 1); _round > 0; --_round) {
                    for (int _sample = 0; _sample < _round; ++_sample) {
                        if (dSorted[_sample] > dSorted[_sample+1]) {
                            double dTemp = dSorted[_sample];
                            dSorted[_sample] = dSorted[_sample+1];
                            dSorted[_sample+1] = dTemp;
                        }
                    }
                }

                // Median values returned from a sorted array.
                if ((numberOfBeltRounds % 2) == 0) {
                    dMedian = (dSorted[numberOfBeltRounds/2] + dSorted[(numberOfBeltRounds/2) - 1])/2.0;
                } else {
                    dMedian = dSorted[numberOfBeltRounds/2];
                }

                dMedian = dMedian + 0.5;                    // rounding by adding half and then cutting out the comma value
                medianZeroSample = (int)(dMedian);  // when casting the double to int value

                // /////////////////////////////////////////////////////////////////////
                // If beltRounds are more than 5% from median value, use the median value instead.
                // /////////////////////////////////////////////////////////////////////

                for (int _round = 0; _round < numberOfBeltRounds; _round++) {

                     if (( fabs((double)pulseCounterInEachRow[_round] - (double)medianZeroSample) / (double)medianZeroSample ) >= 0.05) {

                        pulseCounterInEachRow[_round] = medianZeroSample;
                    }

                    pulseCounterInAllRows += pulseCounterInEachRow[_round];
                }


                lastSampleCounter = 0;
                nextZeroUpdatePosition = 0;
                numberOfBeltRoundsZero = -1;
                requestBeltRoundPulse = false;
                beltRoundPulse = false;

                pulsesPerBeltRound = pulseCounterInAllRows / numberOfBeltRounds;
                pulseResolution = lengthOfEachBeltPeriod / pulsesPerBeltRound;

                zeroTracking = zt_CalculateMedianOfZeroPath;
            }
        }
    }



    // /////////////////////////////////////////////////////////////////////
    // In this state we update oldest zeroWeight sample with a new sample.
    // /////////////////////////////////////////////////////////////////////
    if (zeroTracking == zt_UpdateZeroWeightSamples) {

        for (int i = 0; i <= pulsesPerBeltRound; i ++) {
            zeroUnfilteredArray[nextZeroUpdatePosition][i] = updateZeroArray[i];
        }

        if (nextZeroUpdatePosition >= numberOfBeltRounds) {
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

        // /////////////////////////////////////////////////////////////////////
        // Median of ZERO weight values over entire beltlength
        // /////////////////////////////////////////////////////////////////////

        for (int _sampleColumn = 0; _sampleColumn < samplesPerBeltRound; _sampleColumn++) {

            for (int _rounds = 0; _rounds < numberOfBeltRounds; _rounds++) {
                dSorted[_rounds] = (double)zeroUnfilteredArray[_rounds][_sampleColumn];
            }

            // Sort numerical values in array by size for further processing
            for (int _round = (numberOfBeltRounds - 1); _round > 0; --_round) {
                for (int _sample = 0; _sample < _round; ++_sample) {
                    if (dSorted[_sample] > dSorted[_sample+1]) {
                        double dTemp = dSorted[_sample];
                        dSorted[_sample] = dSorted[_sample+1];
                        dSorted[_sample+1] = dTemp;
                    }
                }
            }

            // Median values returned from a sorted array.
            if ((numberOfBeltRounds % 2) == 0) {
                dMedian = (dSorted[numberOfBeltRounds/2] + dSorted[(numberOfBeltRounds/2) - 1])/2.0;
            } else {
                dMedian = dSorted[numberOfBeltRounds/2];
            }

            dMedian = dMedian + 0.5;                    // rounding by adding half and then cutting out the comma value
            zeroArray[_sampleColumn] = (int)(dMedian);  // when casting the double to int value
        }

        // /////////////////////////////////////////////////////////////////////

        productEntryPulse = (int)((double)(productEntry)/pulseResolution + 0.5);
        weightStartPulse = (int)((double)(productWeighingStartDistance)/pulseResolution + 0.5);
        weightEndPulse = (int)((double)(productWeighingStopDistance)/pulseResolution + 0.5);
        productReleasePulse = (int)((double)(productRelease)/pulseResolution + 0.5);

        for (int i = 0; i < 6; i++) {
            pulseDistanceToGate[i] = (int)((double)(distanceToGraderGate[i])/pulseResolution + 0.5);

            distanceToEndOfGraderGate[i] = distanceToGraderGate[i] + distanceOpenGate[i];
            pulseDistanceToEndOfGate[i] = (int)((double)(distanceToEndOfGraderGate[i])/pulseResolution + 0.5);
        }

        zeroTracking = zt_ReturnResultsToFile;
    }


    if (zeroTracking == zt_ReturnResultsToFile) {

        //filezero.open("zeroweight.csv", std::ofstream::out | std::ofstream::trunc); // trunc changed to app, trunc clears the file while app appends it
        filezero.open("zeroweight.csv", std::ofstream::out | std::ofstream::app); // trunc changed to app, trunc clears the file while app appends it

        if (filezero.is_open()) {

            for (int _rounds = 0; _rounds < numberOfBeltRounds; _rounds++) {

                filezero << "Zero sample " << _rounds << ": " << ",";

                for (int _samples = 0; _samples < samplesPerBeltRound; _samples++) {
                    filezero << zeroUnfilteredArray[_rounds][_samples] << ",";
                }
                filezero << std::endl;
            }

            filezero << std::endl;
            filezero << std::endl;

            filezero << "Mean Zero sample: " << ",";
            for (int _samples = 0; _samples < samplesPerBeltRound; _samples++) {
                filezero << zeroArray[_samples] <<  ",";
            }

            filezero << std::endl;
            filezero << "Total pulses: " << pulseCounterInAllRows << "" << std::endl;
            filezero << std::endl;
            filezero << "Pulses per beltround: " << pulsesPerBeltRound << "" << std::endl;
            filezero << std::endl;
            filezero << "Resolution of each pulse: " << pulseResolution << " mm " << std::endl;
            filezero << std::endl;
            for (int i = 0; i < numberOfBeltRounds; i++) {
                filezero << "PulseCounterInZeroRow number " << i << ": " << pulseCounterInEachRow[i] << "" << std::endl;
            }

        }
        filezero.close();

        int temp = 0;
        emit sendFilteredWeight(temp);
        zeroTracking = zt_ProductFilter;
    }



    if (zeroTracking == zt_ProductFilter) {

        if (processingProduct == false) {

            if (requestZeroUpdate == true) {

                updateZeroArray[sampleCounter] = weightValueFromScale;
                updateSampleCounter++;
                // Here we can emit information to display that running ZERO tracking update is being attempted

                if (updateSampleCounter >= (pulsesPerBeltRound*1.05)) {

                    zeroTracking = zt_UpdateZeroWeightSamples;
                    qDebug() << "Update ZeroWeight Samples";
                    // Here we can emit information to display that running ZERO tracking update has been performed
                }
            }
        } else {
            updateSampleCounter = 0;
        }
        // ////////////////////////////////////


        // Track elements from product sensor (>=0) and over weighing area on program-scantime resolution +1

        for (int _elementId = 0; _elementId < numberOfElementsInList; _elementId++) {
            if (productTickPosition[_elementId] >= 0) {
                productTickPosition[_elementId]++;

                if (productTickPosition[_elementId] == productEntryPulse) {

                    proData.productLengthPulseCounter[_elementId] = productEntry;
                }

                if (between(productEntryPulse, productTickPosition[_elementId], weightEndPulse)) {

                    proData.productLengthPulseCounter[_elementId]++;
                }



//                // Track active weight on scale AREA and give each position weight
//                if (between(weightStartPulse, productTempId[_elementId], weightEndPulse)) {

//                    productIDweights[_elementId][productTempId[_elementId]] = weightValueFromScale-zeroArray[sampleCounter];
//                }

                // Track weight from productEntry sensor to the productDelivery point.
                if (between(productEntryPulse, productTickPosition[_elementId], productReleasePulse)) {

                    productIDweights[_elementId][productTickPosition[_elementId]] = weightValueFromScale-zeroArray[sampleCounter];
                }



                // At weiging endpoint on scale platform calculate mean value and emit modeled weight
                if (productTickPosition[_elementId] == weightEndPulse) {
                    meanWeightSample = 0;

                    for (int _sample = weightStartPulse; _sample < weightEndPulse; _sample++) {
                        meanWeightSample += productIDweights[_elementId][_sample];
                    }

                    meanWeightSample = meanWeightSample / (weightEndPulse-weightStartPulse);

                    // Here calculate some kind of confidence .. how many datapoints of approx. 40 are within 5[gr] relative to meanWeight
                    for (int _sample = weightStartPulse; _sample < weightEndPulse; _sample++) {

                        if (abs(meanWeightSample - productIDweights[_elementId][_sample]) < 5) {

                            proData.productConfidence[_elementId]++;
                        }
                    }


                    proData.productWeight[_elementId] = meanWeightSample;

                    proData.destinationGate[_elementId] = returnToGate(proData.productWeight[_elementId]);

                    qDebug() //<< "_elementId: " << _elementId
                            << " - Serial: " << QString::number(proData.serialId[_elementId])
                            << " - Batch: " << QString::fromStdString(proData.batchId[_elementId]).toInt()
                            << " - RecipeId: " << QString::fromStdString(proData.recipeId[_elementId].c_str())
                            << " - ProductId: " << QString::fromStdString(proData.productId[_elementId].c_str())
                            << " - ProductType: " << QString::fromStdString(proData.productType[_elementId].c_str())
                            << " - Weight: " << proData.productWeight[_elementId]
                            << " - Confidence: " << proData.productConfidence[_elementId]
                            << " - Length: " << proData.productLength[_elementId]
                            << " - Destination: " << proData.destinationGate[_elementId];


                    emit sendMQTT(QString::fromStdString(proData.batchId[_elementId].c_str()), "scale/batchID");
                    emit sendMQTT(QString::fromStdString(proData.recipeId[_elementId].c_str()), "scale/recipeID");
                    emit sendMQTT(QString::fromStdString(proData.productId[_elementId].c_str()), "scale/productID");
                    emit sendMQTT(QString::fromStdString(proData.productType[_elementId].c_str()), "scale/productType");
                    emit sendMQTT(QString::number(proData.serialId[_elementId]), "scale/serialID");
                    emit sendMQTT(QString::number(proData.productWeight[_elementId]), "scale/productWeight");
                    emit sendMQTT(QString::number(proData.productConfidence[_elementId]), "scale/productConfidence");
                    emit sendMQTT(QString::number(proData.productLength[_elementId]), "scale/productLength");
                    emit sendMQTT(QString::number(proData.destinationGate[_elementId]), "scale/destinationGate");

                    emit sendDescription(QString::fromStdString(proData.description[_elementId].c_str()));
                    emit sendBatchId(QString::fromStdString(proData.batchId[_elementId].c_str()));
                    emit sendRecipeId(QString::fromStdString(proData.recipeId[_elementId].c_str()));
                    emit sendProductId(QString::fromStdString(proData.productId[_elementId].c_str()));
                    emit sendProductType(QString::fromStdString(proData.productType[_elementId].c_str()));
                    emit sendSerialNumber(proData.serialId[_elementId]);
                    emit sendFilteredWeight(proData.productWeight[_elementId]);
                    emit sendConfidence(QString::number(proData.productConfidence[_elementId]));
                    emit sendLength(QString::number(proData.productLength[_elementId]));
                    emit sendDestinationGate(QString::number(proData.destinationGate[_elementId]));

                    proData.productLengthPulseCounter[_elementId] = 0;
                }


                // Product is leaving the main platform, at delivery point, then we can consider to update the ZERO weight again.
                if (productTickPosition[_elementId] ==  productReleasePulse) {

                    filezero.open("zeroweight.csv", std::ofstream::out | std::ofstream::app); // trunc changed to app, trunc clears the file while app appends it

                    if (filezero.is_open()) {

                        filezero << "Mean weight sample is :" << meanWeightSample <<",";

                        for (int _sample = weightStartPulse; _sample < weightEndPulse; _sample++) {
                            filezero << productIDweights[_elementId][_sample] << ",";
                        }
                        filezero << std::endl;
                    }
                    filezero.close();

                    processingProduct = false;

                    emit plotData(_elementId);
                }

                if (productTickPosition[_elementId] == (productReleasePulse + pulseDistanceToGate[_elementId]))
                {
                    emit activateGate(proData.destinationGate[_elementId], 1);
                }

                if (productTickPosition[_elementId] == (productReleasePulse + pulseDistanceToEndOfGate[_elementId]))
                {
                    productTickPosition[_elementId] = -1;
                    proData.productConfidence[_elementId] = -1;

                    emit activateGate(proData.destinationGate[_elementId], 0);
                }
            }
        }
    }

    sampleCounter++;
}

void MyScale::xmin(QString str) {
    plotXvalueMIN = str.toInt();
    qDebug() << "plotXvalueMIN: " << plotXvalueMIN;
}

void MyScale::xmax(QString str) {
    plotXvalueMAX = str.toInt();
    qDebug() << "plotXvalueMAX: " << plotXvalueMAX;
}

void MyScale::ymin(QString str) {
    plotYvalueMIN = str.toInt();
    qDebug() << "plotYvalueMIN: " << plotYvalueMIN;
}

void MyScale::ymax(QString str) {
    plotYvalueMAX = str.toInt();
    qDebug() << "plotYvalueMAX: " << plotYvalueMAX;
}

void MyScale::setupPlot(QCustomPlot *customPlot, int workingID) {

    QCPItemLine *startWeighingMark = new QCPItemLine(customPlot);
    QCPItemLine *endWeighingMark = new QCPItemLine(customPlot);

    customPlot->addItem(startWeighingMark);
    customPlot->addItem(endWeighingMark);

    QPen pen1;
    pen1.setStyle(Qt::DashLine);
    pen1.setWidth(1);
    pen1.setColor(Qt::red);

    QPen pen2;
    pen2.setStyle(Qt::DashLine);
    pen2.setWidth(1);
    pen2.setColor(Qt::red);

    QVector<double> x(200), y0(200), y1(200); // initialize (this many) vector entries
    for (int i=0; i<150; ++i)   //up to max: NUMBER_OF_WEIGHT_SAMPLES
    {
      x[i] = i;
      y0[i] = productIDweights[workingID][i];
      y1[i] = proData.productWeight[workingID];
    }   

    // create graph
    customPlot->addGraph();
    // set axis ranges and assign sampled weight data to it:
    customPlot->xAxis->setRange(plotXvalueMIN, plotXvalueMAX);
    customPlot->yAxis->setRange(plotYvalueMIN, plotYvalueMAX);
    customPlot->graph(0)->setData(x, y0);

    // create graph
    customPlot->addGraph();
    // set axis ranges and assign median weight data to it:
    customPlot->graph(1)->setPen(pen1);
    customPlot->graph(1)->setData(x, y1);

    startWeighingMark->setPen(pen2);
    startWeighingMark->start->setCoords(weightStartPulse, plotYvalueMIN);
    startWeighingMark->end->setCoords(weightStartPulse, plotYvalueMAX);
    endWeighingMark->setPen(pen2);
    endWeighingMark->start->setCoords(weightEndPulse, plotYvalueMIN);
    endWeighingMark->end->setCoords(weightEndPulse, plotYvalueMAX);

    emit productWeight( proData.productWeight[workingID] );

    customPlot->replot();
}


void MyScale::run() {


    int sign = 0;

    if (zeroTracking == zt_InitializeZeroVectors) {

        for (int _rounds = 0; _rounds < numberOfBeltRounds; _rounds++) {
            for (int _samples = 0; _samples < samplesPerBeltRound; _samples++) {
                zeroUnfilteredArray[_rounds][_samples] = 0;
            }
        }
        for (int _rounds = 0; _rounds < numberOfElementsInList; _rounds++) {
            for (int _samples = 0; _samples < weightSamplesInWindowOfInterest; _samples++) {
                productIDweights[_rounds][_samples] = 0;
            }
        }
        for (int _samples = 0; _samples < samplesPerBeltRound; _samples++) {
            zeroArray[_samples] = 0;
            updateZeroArray[_samples] = 0;
        }
        for (int _rounds = 0; _rounds < numberOfBeltRounds; _rounds++) {
            zeroColumn[_rounds] = 0;
            dSorted[_rounds] = 0;
        }
        for (int _count = 0; _count < numberOfElementsInList; _count++) {
            productTickPosition[_count] = -1;
        }
        pulseCounterInAllRows = 0.0;

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
                weightProcessing(sign*data[2]);
                emit continuousModbusWeight(sign*data[2]);
                //qDebug() << " WeightGross: " <<  sign*data[2];
            }
            else if(weightGROSSorNET[0] == netDisplay)
            {
                sign = pow((-1),(statusRegisterBinaryReturnValue[8]));
                weightProcessing(sign*data[4]);
                emit continuousModbusWeight(sign*data[4]);
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
