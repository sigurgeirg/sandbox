#include "../inc/mydio.h"


unsigned long MyDio::lastValue[] 		= {1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
unsigned long MyDio::newValue[]  		= {1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
unsigned long MyDio::value[] 	 		= {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
unsigned char MyDio::delay[]            = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
unsigned char MyDio::delayLeftUp[] 		= {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
unsigned char MyDio::delayLeftDown[] 	= {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
unsigned char MyDio::falling[] 			= {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
unsigned char MyDio::rising[] 			= {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
unsigned char MyDio::inverted[] 		= {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};



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
    io.DICfgMode(16,DI_MODE_DIRECT);
    io.DICfgMode(17,DI_MODE_DIRECT);
    io.DICfgMode(18,DI_MODE_DIRECT);
    io.DICfgMode(19,DI_MODE_DIRECT);

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
    holdGate01RisingForCount = 0;
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


void MyDio::activateGateArm(int gateArm, bool gateArmStatus) {

    setGateArm = gateArm;
    setGateArmStatus  = gateArmStatus;

//    qDebug() << "Output: " << setGate << " == " << activeValue;
}

void MyDio::activateGateDiode(int gateDiode, bool gateDiodeStatus) {

    setGateDiode = 10 + gateDiode;
    setGateDiodeStatus = gateDiodeStatus;
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

            holdGate01RisingForCount++;

            if (holdGate01RisingForCount >= 2){
                rising[2] = 0;
                holdGate01RisingForCount = 0;
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

        if (rising[11] == 1) {
            qDebug() << "Gate01 button pressed";
            gate01_buttonPressed = true;

            holdGate01_risingForCount++;

            if (holdGate01_risingForCount >= 2){
                rising[11] = 0;
                holdGate01_risingForCount = 0;
            }
        }

        if (rising[12] == 1) {
            qDebug() << "Gate02 button pressed";
            gate02_buttonPressed = true;

            holdGate02_risingForCount++;

            if (holdGate02_risingForCount >= 2){
                rising[12] = 0;
                holdGate02_risingForCount = 0;
            }
        }

        if (rising[13] == 1) {
            qDebug() << "Gate03 button pressed";
            gate03_buttonPressed = true;

            holdGate03_risingForCount++;

            if (holdGate03_risingForCount >= 2){
                rising[13] = 0;
                holdGate03_risingForCount = 0;
            }
        }

        if (rising[14] == 1) {
            qDebug() << "Gate04 button pressed";
            gate04_buttonPressed = true;

            holdGate04_risingForCount++;

            if (holdGate04_risingForCount >= 2){
                rising[14] = 0;
                holdGate04_risingForCount = 0;
            }
        }

        if (rising[15] == 1) {
            qDebug() << "Gate05 button pressed";
            gate05_buttonPressed = true;

            holdGate05_risingForCount++;

            if (holdGate05_risingForCount >= 2){
                rising[15] = 0;
                holdGate05_risingForCount = 0;
            }
        }

        if (rising[16] == 1) {
            qDebug() << "Gate06 button pressed";
            gate06_buttonPressed = true;

            holdGate06_risingForCount++;

            if (holdGate06_risingForCount >= 2){
                rising[16] = 0;
                holdGate06_risingForCount = 0;
            }
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

        if (gate01_buttonPressed == true) {
            emit buttonPressed(1);
            gate01_buttonPressed = false;
        }

        if (gate02_buttonPressed == true) {
            emit buttonPressed(2);
            gate02_buttonPressed = false;
        }

        if (gate03_buttonPressed == true) {
            emit buttonPressed(3);
            gate03_buttonPressed = false;
        }

        if (gate04_buttonPressed == true) {
            emit buttonPressed(4);
            gate04_buttonPressed = false;
        }

        if (gate05_buttonPressed == true) {
            emit buttonPressed(5);
            gate05_buttonPressed = false;
        }

        if (gate06_buttonPressed == true) {
            emit buttonPressed(6);
            gate06_buttonPressed = false;
        }




        for (int i = 0; i < numberOfUsedDigitalInputs; i++) {
            io.DOSet(i, 0);
        }

        io.DOSet((unsigned char)setGateArm, (bool)setGateArmStatus);
        io.DOSet((unsigned char)setGateDiode, (bool)setGateDiodeStatus);

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

