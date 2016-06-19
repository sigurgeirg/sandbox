#include "test.h"


Test::Test()
{
    address			= 0;
    delay 			= new unsigned char[32];
    delayLeftUp 	= new unsigned char[32];
    delayLeftDown 	= new unsigned char[32];
    lastValue 		= new unsigned long[32];
    newValue 		= new unsigned long[32];
    value           = new unsigned long[32];
    falling			= new unsigned char[32];
    rising			= new unsigned char[32];
    inverted		= new unsigned char[32];
    tickOrTime		= new unsigned char[32];
}

Test::~Test()
{
    //
    delete delay;
    delete delayLeftUp;
    delete delayLeftDown;
    delete lastValue;
    delete newValue;
    delete value;
    delete falling;
    delete rising;
    delete inverted;
    delete tickOrTime;
}

void Test::updateInputs()
{
	
	newInput(0, delay, inverted, tickOrTime);
    newInput(1, delay, inverted, tickOrTime);
    newInput(2, delay, inverted, tickOrTime);
}

void Test::updateOutputs()
{
}

void Test::newInput(unsigned char address, unsigned char *delay, unsigned char *inverted, unsigned char *tickOrTime)
{

    newValue[address] = 1;

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


void Test::run()
{
    while (1)
    {
        msleep(20);

        io.DOSet(1, 1);

        updateInputs();
        updateOutputs();

		for (int i=0;i<2;i++) {
			if (rising[i] == 1){
				cout << "Input " << i << " is rising!";
				rising[i] = 0;
			}
			if (falling[i] == 1){
				cout << "Input " << i << " is falling!";
				falling[i] = 0;
			}

			cout << "InputValue: " << value[i];
		}
    }
}

