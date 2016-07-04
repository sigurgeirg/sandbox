#include "../inc/mydio.h"


unsigned long MyDio::lastValue[] 		= {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
unsigned long MyDio::newValue[]  		= {1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
unsigned long MyDio::value[] 	 		= {1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
unsigned char MyDio::delay[] 			= {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
unsigned char MyDio::delayLeftUp[] 		= {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
unsigned char MyDio::delayLeftDown[] 	= {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
unsigned char MyDio::falling[] 			= {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
unsigned char MyDio::rising[] 			= {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
unsigned char MyDio::inverted[] 		= {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
unsigned char MyDio::tickOrTime[] 		= {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};



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

    address	= 0;
    tickBeltProfile = 0;
}

MyDio::~MyDio()
{
    //
}

///////////////////////////
//FIXME: For Simulation
void MyDio::updateInputSim(unsigned char n, bool state)
{
    _inputAddress = n;
    _inputStatus = state;

    qDebug() << _inputAddress << " AND " << _inputStatus << endl;

    io.DISetSim(_inputAddress, _inputStatus);
    io.DIWrSim();

    io.DIRd();
    io.DIUpdate();
    //io.DIWrSim();
}
///////////////////////////

void MyDio::updateInputs()
{
    io.DIRd();
    io.DIUpdate();
}

void MyDio::updateOutputs()
{
    io.DOUpdate();
    io.DOWr();
}

void MyDio::newInput(unsigned char address)
{

    newValue[address] = (unsigned char)io.DIGet(address);

    if ( !delay[address]      )	{ delay[address] = 0; }
    if ( !tickOrTime[address] )	{ tickOrTime[address] = 0; }

    if ( inverted[address] and inverted[address] == 1 ){
        newValue[address] =((newValue[address] == 0) ? 1 : 0); }

    if ( newValue[address] != lastValue[address] ) {
        if ( newValue[address] == 1 ) {
            if ( tickOrTime[address] > 0 ) {
                delayLeftUp[address] = tickOrTime[address] + delay[address];
            } else {
                delayLeftUp[address] = std::clock() + delay[address];
            }
        } else {
            if ( tickOrTime[address] > 0 ) {
                delayLeftDown[address] = tickOrTime[address] + delay[address];
            } else {
                delayLeftDown[address] = std::clock() + delay[address];
            }
        }
    }

    if ( tickOrTime[address] > 0 ) {
        if ( delayLeftUp[address] > 0 &&  tickOrTime[address] > delayLeftUp[address] ){
            delayLeftUp[address] = 0;
            rising[address] = 1;
            value[address] = 1;
        } else {
            rising[address] = 0;
        }
    } else {
        if ( delayLeftUp[address] > 0 && std::clock() > delayLeftUp[address] ) {
            delayLeftUp[address] = 0;
            rising[address] = 1;
            value[address] = 1;
        } else {
            rising[address] = 0;
        }
    }

    if ( tickOrTime[address] > 0 ) {
        if ( delayLeftDown[address] > 0 &&  tickOrTime[address] > delayLeftDown[address] ){
            delayLeftDown[address] = 0;
            falling[address] = 1;
            value[address] = 0;
        } else {
            falling[address] = 0;
        }
    } else {
        if ( delayLeftDown[address] > 0 && std::clock() > delayLeftDown[address] ) {
            delayLeftDown[address] = 0;
            falling[address] = 1;
            value[address] = 0;
        } else {
            falling[address] = 0;
        }
    }
    lastValue[address] = newValue[address];

}

void MyDio::run()
{
    int _NUMBER_OF_USED_INPUTS = 16;

    // Only runs once
    for (int i = 0; i < _NUMBER_OF_USED_INPUTS; i++) {

        //io.DICfgMode(i,DI_MODE_DIRECT);
        io.DOCfgMode(i, DO_MODE_DIRECT, 0);

        // Initialization of all input values
        io.DIRd();
        io.DIUpdate();
        value[i] = (unsigned char)io.DIGet(i);
    }
    emit inputValue(value[0]);

    //*
//	struct timeval tim;
//	double lastTime;
//	double currTime;
    bool trigger = 0;
    bool tacho = 0;
    //*/

    while (1)
    {

        msleep(10);
        // Activate trigger on scantime, comment out and use the one below instead if you plan
        // to trigger when INPUT sensor (period/conveyor tacho) is used to monitor tacho
        trigger = true;

//		gettimeofday(&tim, NULL);
//		lastTime = tim.tv_usec;

        io.DOSet(1, 1);

        //FIXME: If simulation
        //io.DISetSim(1, 1);
        ///////////////////////////

        updateInputs();
        updateOutputs();

        for (int i = 0; i < _NUMBER_OF_USED_INPUTS; i++) {
            // rising and falling are reset after one scan-cycle for other processes to be able to monitor these.
            rising[i] = 0;
            falling[i] = 0;

            newInput(i);
        }

        // Here we assume that input[1] is one pulse per round periodic sensor of conveyor belt
        if (rising[1] == 1){
            qDebug() << "Input " << 1 << " is rising!";
            tickBeltProfile = 0;
        }

        // Here we assume that input[2] is tacho pulse listener input, many pulses per belt period.
        if (rising[2] == 1){
            qDebug() << "Input " << 2 << " is rising!";
            tickBeltProfile++;
            tacho = true;
        }

        if (tacho == true)
        {
            emit tachoSignal(tickBeltProfile);
            tacho = false;
        }

//		gettimeofday(&tim, NULL);
//		currTime = tim.tv_usec;
//		qDebug() << "Time taken: " << currTime - lastTime;

        // emit instance or value does not matter, only the fact that we trigger emit a signal (one for all)
        // once for every scan (every 20ms), that should cover all changes on initialized inputs.
        if (trigger == true)
        {
            emit inputValue(value[0]);
            trigger = false;
        }
    }
}

