#include "../inc/zerofilter.h"


Zerofilter::Zerofilter(QObject *parent) :
    QThread(parent)
{

}


Zerofilter::~Zerofilter()
{
    //

}


void Zerofilter::processReceivedWeight(int weightValueFromScale) {




}


void Zerofilter::run() {



    // When Zerofilter has been processed and is ready for delivery
    // then send (emit) filtered zero array back, to where it will be used.
    //emit filteredZeroArray(value[i]);
}
