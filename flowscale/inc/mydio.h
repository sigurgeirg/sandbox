#ifndef MYDIO_H
#define MYDIO_H

#include <dio.h>
#include <iostream>
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

    void updateInputs();
    void updateOutputs();
    void newInput(unsigned char address);
    void run();

    Dio io;

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

private:

    bool trigger;
    bool tacho;
    bool conveyor;
    bool productEnteringSensor;
    bool productLeavingSensor;

    unsigned long tickBeltProfile;
    unsigned long beltRounds;
    unsigned char address;
    // /////////////////////////
    // Simulation
    // unsigned char _inputAddress;
    // bool _inputStatus;
    // /////////////////////////


signals:
    void inputValue(unsigned long);
    void conveyorSignal();
    void tachoSignal(unsigned long);
    void enteringProductSensorSignal();
    void leavingProductSensorSignal();


public slots:
    // /////////////////////////
    // Simulation
//    void updateInputSim(unsigned char, bool);
    // /////////////////////////

};


#endif // MYDIO_H
