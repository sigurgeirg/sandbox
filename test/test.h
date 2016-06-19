

#include <ctime>
#include <iostream>

using namespace std;

class Test
{
public:
    explicit Test();
    ~Test();

    void updateInputs();
    void updateOutputs();

    void newInput(unsigned char address, unsigned char *delay, unsigned char *inverted, unsigned char *tickOrTime);
    void run();

    unsigned char address;
    unsigned char *delay;
    unsigned char *delayLeftUp;
    unsigned char *delayLeftDown;
    unsigned long *lastValue;
    unsigned long *newValue;
    unsigned long *value;
    unsigned char *falling;
    unsigned char *rising;
    unsigned char *inverted;
    unsigned char *tickOrTime;

};