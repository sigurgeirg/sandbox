#ifndef MYDIO_H
#define MYDIO_H

#include <dio.h>
#include <QThread>
#include <QDebug>
#include <ctime>
#include <sys/time.h>

#define NUMBER_OF_USED_INPUTS 16	// Number of Used    Digital Inputs in: MODE_DIRECT

class MyDio : public QThread
{
    Q_OBJECT
public:
    explicit MyDio(QObject *parent = 0);
    ~MyDio();

    int tickBeltProfile;
    // /////////////////////////
    // Simulation
//    unsigned char _inputAddress;
//    bool _inputStatus;
    // /////////////////////////

    void updateInputs();
    void updateOutputs();

    void newInput(unsigned char address);
    void run();

    Dio io;

    unsigned char address;
    static unsigned long lastValue[NUMBER_OF_USED_INPUTS];
    static unsigned long newValue[NUMBER_OF_USED_INPUTS];
    static unsigned long value[NUMBER_OF_USED_INPUTS];
    static unsigned char delay[NUMBER_OF_USED_INPUTS];
    static unsigned char delayLeftUp[NUMBER_OF_USED_INPUTS];
    static unsigned char delayLeftDown[NUMBER_OF_USED_INPUTS];
    static unsigned char falling[NUMBER_OF_USED_INPUTS];
    static unsigned char rising[NUMBER_OF_USED_INPUTS];
    static unsigned char inverted[NUMBER_OF_USED_INPUTS];
    static unsigned char tickOrTime[NUMBER_OF_USED_INPUTS];

signals:
    void inputValue(unsigned long);
    void tachoSignal(unsigned long);


public slots:
    // /////////////////////////
    // Simulation
//    void updateInputSim(unsigned char, bool);
    // /////////////////////////

};


#endif // MYDIO_H
