#include "../inc/zerofilter.h"


Zerofilter::Zerofilter(QObject *parent) :
    QThread(parent)
{
    numberOfBeltRounds = new unsigned long;
}


Zerofilter::~Zerofilter()
{
    //
    delete numberOfBeltRounds;

}


void Zerofilter::conveyorBeltCounter(unsigned long beltRoundCounter)
{
    *numberOfBeltRounds = beltRoundCounter;
}


void Zerofilter::recordZeroWeight(int weightValueFromScale) {

    // /////////////////////////
    // Instead of this part, write data into array as mentioned in point nr. 1
    // each numberOfBeltRounds value occupies one "row" array in matrix.
    // /////////////////////////
    _weightValueFromScale = weightValueFromScale;

    if (_sampleCount < 1000000){
        fout.open("weight.csv", std::ofstream::out | std::ofstream::app); // trunc changed to app, trunc clears the file while app appends it
        if (fout.is_open())
        {
            fout << *numberOfBeltRounds  << "," <<  _sampleCount << "," << _weightValueFromScale << std::endl;
            _sampleCount = _sampleCount + 1;
        }
        fout.close();
    }
    // /////////////////////////


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
