#include "../inc/mydio.h"


unsigned long MyDio::lastValue[] 		= {1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
unsigned long MyDio::newValue[]  		= {1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
unsigned long MyDio::value[] 	 		= {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
unsigned char MyDio::delay[]            = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
unsigned char MyDio::delayLeftUp[] 		= {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
unsigned char MyDio::delayLeftDown[] 	= {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
unsigned char MyDio::falling[] 			= {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
unsigned char MyDio::rising[] 			= {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
unsigned char MyDio::inverted[] 		= {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};



MyDio::MyDio(QObject *parent) :
    QThread(parent)
{

    io.DICfgMode(0,DI_MODE_DIRECT);
    io.DICfgMode(1,DI_MODE_DIRECT);
    io.DICfgMode(2,DI_MODE_DIRECT);
    io.DICfgMode(3,DI_MODE_DIRECT);
    io.DICfgMode(4,DI_MODE_DIRECT);
    io.DICfgMode(5,DI_MODE_DIRECT);
    io.DICfgMode(6,DI_MODE_DIRECT);
    io.DICfgMode(7,DI_MODE_DIRECT);
    io.DICfgMode(8,DI_MODE_DIRECT);
    io.DICfgMode(9,DI_MODE_DIRECT);
    io.DICfgMode(10,DI_MODE_DIRECT);
    io.DICfgMode(11,DI_MODE_DIRECT);
    io.DICfgMode(12,DI_MODE_DIRECT);
    io.DICfgMode(13,DI_MODE_DIRECT);
    io.DICfgMode(14,DI_MODE_DIRECT);
    io.DICfgMode(15,DI_MODE_DIRECT);

    //io.DICfgMode(2,DI_MODE_EDGE_BOTH);
    //io.DICfgMode(2,DI_MODE_EDGE_LOW_GOING);
    //io.DICfgMode(3,DI_MODE_EDGE_HIGH_GOING);

    //*
//	struct timeval tim;
//	double lastTime;
//	double currTime;
    trigger = false;
    tacho = false;
    conveyor = false;
    productEnteringSensor = false;
    productLeavingSensor = false;
    //*/

    address	= 0;
    tickBeltProfile = 0;
    holdBeltPulseForCount = 0;
    holdRisingForCount = 0;
    holdFallingForCount = 0;

}

MyDio::~MyDio()
{
    //
}

// /////////////////////////
// Simulation
//void MyDio::updateInputSim(unsigned char n, bool state) {

//    _inputAddress = n;
//    _inputStatus = state;

//    qDebug() << "Input:" << _inputAddress+1 << " is " << _inputStatus << endl;

//    io.DISetSim(_inputAddress, _inputStatus);
//    io.DIWrSim();

//    io.DIRd();
//    io.DIUpdate();
//    //io.DIWrSim();
//}
// /////////////////////////

void MyDio::updateInputs() {

    io.DIRd();
    io.DIUpdate();
}

void MyDio::updateOutputs() {

    io.DOUpdate();
    io.DOWr();
}


void MyDio::setOutput(int output, int value) {

    activeOutput = output;
    activeValue  = value;

//    qDebug() << "Output: " << activeOutput << " == " << activeValue;
}


void MyDio::newInput(unsigned char address) {

    rising[address] = 0;
    falling[address] = 0;


    newValue[address] = (unsigned char)io.DIGet(address);

    if ( !delay[address] ) {

        delay[address] = 0;
    }

    if ( inverted[address] and inverted[address] == 1 ) {

        newValue[address] =((newValue[address] == 0) ? 1 : 0);
    }

    if ( newValue[address] != lastValue[address] ) {

        if ( newValue[address] == 1 ) {
            delayLeftDown[address] = std::clock() + delay[address];
        } else {
            delayLeftUp[address] = std::clock() + delay[address];
        }
    }

    if ( delayLeftUp[address] > 0 && std::clock() > delayLeftUp[address] ) {

        delayLeftUp[address] = 0;
        rising[address] = 1;
        value[address] = 1;

    } else {

        //rising[address] = 0;
    }

    if ( delayLeftDown[address] > 0 && std::clock() > delayLeftDown[address] ) {

        delayLeftDown[address] = 0;
        falling[address] = 1;
        value[address] = 0;

    } else {

        //falling[address] = 0;
    }

    lastValue[address] = newValue[address];
}

void MyDio::run() {

    // Only runs once
    for (int i = 0; i < numberOfUsedDigitalInputs; i++) {

        //io.DICfgMode(i,DI_MODE_DIRECT);
        io.DOCfgMode(i, DO_MODE_DIRECT, 0);

        // Initialization of all input values
        io.DIRd();
        io.DIUpdate();
        value[i] = (unsigned char)io.DIGet(i);

        emit inputValue(value[i]);
    }


    while (1) {

        msleep(10);
        // Activate trigger on scantime, comment out and use the one below instead if you plan
        // to trigger when INPUT sensor (period/conveyor tacho) is used to monitor tacho
        trigger = true;
        conveyor = false;

//		gettimeofday(&tim, NULL);
//		lastTime = tim.tv_usec;

        // ////////////////////////
        // FIXME: If simulation
        // io.DISetSim(1, 1);
        // /////////////////////////

        updateInputs();

        for (int i = 0; i < numberOfUsedDigitalInputs; i++) {

            newInput(i);
            value[i] = (unsigned char)io.DIGet(i);
        }

        // Here we assume that input[0] is one pulse per round periodic sensor of conveyor belt
        if (rising[0] == 1) {
            qDebug() << "BeltPeriod Pulse";
            tickBeltProfile = 0;
            conveyor = true;
            holdBeltPulseForCount++;

            if (holdBeltPulseForCount >= 2){
                rising[0] = 0;
                holdBeltPulseForCount = 0;
            }
        }

        // FIXME: This input is not used currently, we use tick on program scantime, insted of tacho or encoder signal...
        // Here we assume that input[1] is tacho pulse listener input, many pulses per belt period.
        if (rising[1] == 1) {
            // qDebug() << "Input 2:" << 2 << " is rising!";
            tickBeltProfile++;
            tacho = true;
            rising[1] = 0;
        }

        // Here we assume that input[2] is the product sensor and this is the rising event
        if (rising[2] == 1) {
            qDebug() << "Entering Product Sensor";
            productEnteringSensor = true;
            holdRisingForCount++;

            if (holdRisingForCount >= 2){
                rising[2] = 0;
                holdRisingForCount = 0;
            }
        }

        // Here we assume that input[2] is the product sensor and this is the rising event
        if (falling[2] == 1) {
            qDebug() << "Leaving Product Sensor";
            productLeavingSensor = true;
            holdFallingForCount++;

            if (holdFallingForCount >= 2){
                falling[2] = 0;
                holdFallingForCount = 0;
            }
        }

        // Here we assume that input[3] is available input signal
        if (rising[3] == 1) {
            // qDebug() << "Input 4:" << 4 << " is rising!";
            rising[3] = 0;
        }

        if (conveyor == true) {
            emit conveyorSignal();
            conveyor = false;
        }

        if (tacho == true) {
            emit tachoSignal(tickBeltProfile);
            tacho = false;
        }

        if (productEnteringSensor == true) {
            emit enteringProductSensorSignal();
            productEnteringSensor = false;
        }

        if (productLeavingSensor == true) {
            emit leavingProductSensorSignal();
            productLeavingSensor = false;
        }


        for (int i = 0; i < 16; i++) {
            io.DOSet(i, 0);
        }

        io.DOSet((unsigned char)activeOutput, (bool)activeValue);

        updateOutputs();


//		gettimeofday(&tim, NULL);
//		currTime = tim.tv_usec;
//		qDebug() << "Time taken: " << currTime - lastTime;

        // emit instance or value does not matter, only the fact that we trigger emit a signal (one for all)
        // once for every scan (every 20ms), that should cover all changes on initialized inputs.
        if (trigger == true) {

            for (int i = 0; i < numberOfUsedDigitalInputs; i++) {
                emit inputValue(value[i]);
            }
            trigger = false;
        }
    }
}

