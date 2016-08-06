#include "../inc/zerofilter.h"


Zerofilter::Zerofilter(QObject *parent) :
    QThread(parent)
{
    numberOfBeltRoundsZero = -2;
    sampleCount = 0;
    lastRound = 0;
    phase = 0;
    runOnce = true;

}


Zerofilter::~Zerofilter()
{
    //
    //delete numberOfBeltRoundsZero;

}


void Zerofilter::conveyorBeltCounter()
{
    sampleCount = 0;

    numberOfBeltRoundsZero++;
    //this->numberOfBeltRounds++;

//    if (*numberOfBeltRounds > INIT_MATRIX_COLUMNS) {
//      *numberOfBeltRounds = 0;
//    }
}


void Zerofilter::recordZeroWeight(int weightValueFromScale) {


    // ////////////////////////////////
    // Prepare Zero-filter, collect weight from running empty conveyor for few rounds
    // By using "if" condition to set boundaries to collect data we lower the load on the CPU
    // ////////////////////////////////

    if (phase == 1) {

        if ((numberOfBeltRoundsZero > -1) && (numberOfBeltRoundsZero < NUMBER_OF_BELTROUNDS)) {
            // Assign weight value from scale in initializing matrix
            if (sampleCount < SAMPLES_PER_BELTROUND) {

                zeroUnfilteredArray[numberOfBeltRoundsZero][sampleCount] = weightValueFromScale;
                sampleCount++;
            }
        }

        if (numberOfBeltRoundsZero >= NUMBER_OF_BELTROUNDS) {
            phase = 2;
        }
    }


    if (phase == 2) {


        for (int _sampleColumn = 0; _sampleColumn < SAMPLES_PER_BELTROUND; _sampleColumn++) {

            for (int _rounds = 0; _rounds < NUMBER_OF_BELTROUNDS; _rounds++) {

                zeroColumn[_rounds] = zeroUnfilteredArray[_rounds][_sampleColumn];






            }
        }

        // Spurning um að umskrifa þetta svo þetta geti komið í stað 2földu for lykkjunnar hér að ofan.

        double* dpSorted = new double[NUMBER_OF_BELTROUNDS];

        for (int i = 0; i < NUMBER_OF_BELTROUNDS; ++i) {
            dpSorted[i] = (double)zeroColumn[i];
        }
        for (int i = NUMBER_OF_BELTROUNDS - 1; i > 0; --i) {
            for (int j = 0; j < i; ++j) {
                if (dpSorted[j] > dpSorted[j+1]) {
                    double dTemp = dpSorted[j];
                    dpSorted[j] = dpSorted[j+1];
                    dpSorted[j+1] = dTemp;
                }
            }
        }

        // Middle or average of middle values in the sorted array.
        double dMedian = 0.0;
        if ((NUMBER_OF_BELTROUNDS % 2) == 0) {
            dMedian = (dpSorted[NUMBER_OF_BELTROUNDS/2] + dpSorted[(NUMBER_OF_BELTROUNDS/2) - 1])/2.0;
        } else {
            dMedian = dpSorted[NUMBER_OF_BELTROUNDS/2];
        }
        delete [] dpSorted;
        zeroArray[_sampleColumn] = (int)dMedian;







            // /////////////////////////////////////////////////////////////////////////////////////////////////
            // Calculate median of rows in zeroUnfilteredArray
            // /////////////////////////////////////////////////////////////////////////////////////////////////

//                double* dpSorted = new double[NUMBER_OF_BELTROUNDS];
//                int iSize = NUMBER_OF_BELTROUNDS;

//                for (int i = 0; i < iSize; ++i) {
//                    dpSorted[i] = (double)zeroColumn[i];
//                }
//                for (int i = iSize - 1; i > 0; --i) {
//                    for (int j = 0; j < i; ++j) {
//                        if (dpSorted[j] > dpSorted[j+1]) {
//                            double dTemp = dpSorted[j];
//                            dpSorted[j] = dpSorted[j+1];
//                            dpSorted[j+1] = dTemp;
//                        }
//                    }
//                }

//                // Middle or average of middle values in the sorted array.
//                double dMedian = 0.0;
//                if ((iSize % 2) == 0) {
//                    dMedian = (dpSorted[iSize/2] + dpSorted[(iSize/2) - 1])/2.0;
//                } else {
//                    dMedian = dpSorted[iSize/2];
//                }
//                delete [] dpSorted;
//                zeroArray[_sampleColumn] = (int)dMedian;
//            }

            // /////////////////////////////////////////////////////////////////////////////////////////////////


//        filezero.open("zeroweight.csv", std::ofstream::out | std::ofstream::trunc); // trunc changed to app, trunc clears the file while app appends it
//        if (filezero.is_open())
//        {
//            for (int _rounds = 0; _rounds < 10; _rounds++) {
//                filezero << zeroArray[_rounds] <<  std::endl;
//            }
//        }
//        filezero.close();
//        numberOfBeltRoundsZero = 0;




        /*
        if (numberOfBeltRoundsZero ==  NUMBER_OF_BELTROUNDS) {
            filezero.open("zeroweight.csv", std::ofstream::out | std::ofstream::trunc); // trunc changed to app, trunc clears the file while app appends it
            if (filezero.is_open())
            {
                for (int _rounds = 0; _rounds < 10; _rounds++) {
                    for (int _samples = 0; _samples < 10; _samples++) {
                        filezero << "BeltRounds: " << _rounds << "Sample: " << _samples << "Value: " << zeroUnfilteredArray[_rounds][_samples] << std::endl;
                        // filezero << *numberOfBeltRounds  << "," <<  sampleCount << "," << weightValueFromScale << std::endl;
                    }
                    filezero << "\n";
                }
            }
            filezero.close();
            numberOfBeltRoundsZero = 0;
        }*/
    }

    // SAVE ZERO PATH
    if (phase == 3){
        // CALCULATE ZERO


        phase = 4;
    }

    // PRODUCTION PHASE
    if (phase == 4){

    }











    // 1. Write 10 rows of ~ 402 zeroWeightSamples
    //    Info: Weight, tickPosition(==posInArray), roundNumber(==rownumber)
    // 2. Create some avg/median array from the sample matrix
    // 3. Produce std array with respect to the processed matrix (array)
    // 4. Return info:
    //          avg weight array, std array, number of samples, number of rounds
    //          number of samples might deviate +/-1, then we just accept lowest common denomintor ...
    // 5. Verify if zerofFilter has been updated
    // 6. emit all necessary signals back to where weighing will be processed with respect to floating zero.
    // 7. should all be emitted or some written to a globally accessible pointer ???

}


void Zerofilter::run() {

    if (runOnce == true) {
        // initialize zeroUnfilteredArray with zeros
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
        }
        runOnce = false;
        phase = 1;
    }

    //if (zeroFilterHasBeenUpdated == 1) {

        // When Zerofilter has been processed and is ready for delivery
        // then send (emit) filtered zero array back, to where it will be used.
        //emit filteredZeroArray(value[i]);
    //}
}
