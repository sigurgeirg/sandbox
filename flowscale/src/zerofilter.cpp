#include "../inc/zerofilter.h"


Zerofilter::Zerofilter(QObject *parent) :
    QThread(parent)
{
    numberOfBeltRounds = new int;

    *numberOfBeltRounds = -1;
    sampleCount = 0;
    lastRound = 0;

}


Zerofilter::~Zerofilter()
{
    //
    delete numberOfBeltRounds;

}


void Zerofilter::conveyorBeltCounter()
{
    sampleCount = 0;

    //*numberOfBeltRounds++;
    this->numberOfBeltRounds++;

//    if (*numberOfBeltRounds > INIT_MATRIX_COLUMNS) {
//      *numberOfBeltRounds = 0;
//    }
}


void Zerofilter::recordZeroWeight(int weightValueFromScale) {

    weightValueFromScale = weightValueFromScale;
    std::ofstream filezero;

    // ////////////////////////////////
    // Prepare Zero-filter, collect weight from running empty conveyor for few rounds
    // By using "if" condition to set boundaries to collect data we lower the load on the CPU
    // ////////////////////////////////

    if (*numberOfBeltRounds <= NUMBER_OF_BELTROUNDS) {
        // Assign weight value from scale in initializing matrix
        if (sampleCount <= SAMPLES_PER_BELTROUND) {

            zeroUnfilteredArray[*numberOfBeltRounds][sampleCount] = weightValueFromScale;
            sampleCount++;
        }

    } else {

        filezero.open("zeroweight.csv", std::ofstream::out | std::ofstream::trunc); // trunc changed to app, trunc clears the file while app appends it
        if (filezero.is_open())
        {
            for (int _rounds = 0; _rounds < 10; _rounds++) {
                for (int _samples = 0; _samples < 1000; _samples++) {
                    filezero << "BeltRounds: " << _rounds << "Sample: " << _samples << "Value: " << zeroUnfilteredArray[_rounds][_samples] << std::endl;
                    // filezero << *numberOfBeltRounds  << "," <<  sampleCount << "," << weightValueFromScale << std::endl;
                }
                filezero << "\n";
            }
        }
        filezero.close();
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

    //if (zeroFilterHasBeenUpdated == 1) {

        // When Zerofilter has been processed and is ready for delivery
        // then send (emit) filtered zero array back, to where it will be used.
        //emit filteredZeroArray(value[i]);
    //}
}
