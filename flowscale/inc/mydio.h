#ifndef MYDIO_H
#define MYDIO_H

#include "constants.h"
#include <dio.h>
#include <iostream>
#include <QThread>
#include <QDebug>
#include <ctime>
#include <sys/time.h>


class MyDio : public QThread
{
    Q_OBJECT
public:
    explicit MyDio(QObject *parent = 0);
    ~MyDio();

    Dio io;

    void updateInputs();
    void updateOutputs();
    void newInput(unsigned char address);
    void run();

    static unsigned long lastValue[numberOfUsedDigitalInputs];
    static unsigned long newValue[numberOfUsedDigitalInputs];
    static unsigned long value[numberOfUsedDigitalInputs];
    static unsigned char delay[numberOfUsedDigitalInputs];
    static unsigned char delayLeftUp[numberOfUsedDigitalInputs];
    static unsigned char delayLeftDown[numberOfUsedDigitalInputs];
    static unsigned char falling[numberOfUsedDigitalInputs];
    static unsigned char rising[numberOfUsedDigitalInputs];
    static unsigned char inverted[numberOfUsedDigitalInputs];
    static unsigned char tickOrTime[numberOfUsedDigitalInputs];

private:

    bool trigger;
    bool tacho;
    bool conveyor;
    bool productEnteringSensor;
    bool productLeavingSensor;

    int activeOutput;
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
    void setOutput(int);
    // /////////////////////////
    // Simulation
//    void updateInputSim(unsigned char, bool);
    // /////////////////////////

};


#endif // MYDIO_H
