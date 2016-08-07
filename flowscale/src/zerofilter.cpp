#include "../inc/zerofilter.h"


Zerofilter::Zerofilter(QObject *parent) :
    QThread(parent)
{
    numberOfBeltRoundsZero = -2;
    sampleCount = 0;
    lastRound = 0;
    phase = 0;
    runOnce = true;
    dpSorted = new double[NUMBER_OF_BELTROUNDS];
    dMedian = 0.0;

}


Zerofilter::~Zerofilter()
{
    //
    //delete numberOfBeltRoundsZero;
    delete dpSorted;

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


    // /////////////////////////////////////////////////////////////////////////////////////////////////
    // Calculate median of rows in zeroUnfilteredArray
    // /////////////////////////////////////////////////////////////////////////////////////////////////

    // Þessi hluti compilar, en hann er óprófaður, virkar logiskt, en sjáum hvað gerist ...


    if (phase == 2) {

        for (int _sampleColumn = 0; _sampleColumn < SAMPLES_PER_BELTROUND; _sampleColumn++) {

            for (int _rounds = 0; _rounds < NUMBER_OF_BELTROUNDS; _rounds++) {

                // This line: make new 1D array[] from only single column from zeroUnfilteredArray
                dpSorted[_rounds] = (double)zeroUnfilteredArray[_rounds][_sampleColumn];
            }

            // Sort numerical values in array by size for further processing
            for (int _round = (NUMBER_OF_BELTROUNDS - 1); _round > 0; --_round) {
                for (int _sample = 0; _sample < _round; ++_sample) {
                    if (dpSorted[_sample] > dpSorted[_sample+1]) {
                        double dTemp = dpSorted[_sample];
                        dpSorted[_sample] = dpSorted[_sample+1];
                        dpSorted[_sample+1] = dTemp;
                    }
                }
            }


            // Middle or average of middle values in the sorted array.

            if ((NUMBER_OF_BELTROUNDS % 2) == 0) {
                dMedian = (dpSorted[NUMBER_OF_BELTROUNDS/2] + dpSorted[(NUMBER_OF_BELTROUNDS/2) - 1])/2.0;
            } else {
                dMedian = dpSorted[NUMBER_OF_BELTROUNDS/2];
            }
            //Ætti námundunin kannski bara að eiga við í öðru tilvikinu en ekki hinu ??

            dMedian = dMedian + 0.5;                    // rounding by adding half and then cutting out the comma value
            zeroArray[_sampleColumn] = (int)(dMedian);  // when casting the double to int value

        }
        phase = 3;
    }


    if (phase == 3) {

        filezero.open("zeroweight.csv", std::ofstream::out | std::ofstream::trunc); // trunc changed to app, trunc clears the file while app appends it
        if (filezero.is_open())
        {

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
        }
        filezero.close();

//        numberOfBeltRoundsZero = 0;

        phase = 4;
    }


    // Next step ...
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
