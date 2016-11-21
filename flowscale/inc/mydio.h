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

private:
    bool trigger;
    bool tacho;
    bool conveyor;
    bool productEnteringSensor;
    bool productLeavingSensor;
    bool gate01_buttonPressed;
    bool gate02_buttonPressed;
    bool gate03_buttonPressed;
    bool gate04_buttonPressed;
    bool gate05_buttonPressed;
    bool gate06_buttonPressed;

    int setGateArm;
    int setGateArmStatus;
    int setGateDiode;
    int setGateDiodeStatus;

    unsigned long tickBeltProfile;
    unsigned long beltRounds;
    unsigned char address;
    int holdBeltPulseForCount;
    int holdGate01RisingForCount;
    int holdFallingForCount;
    int holdGate01_risingForCount;
    int holdGate02_risingForCount;
    int holdGate03_risingForCount;
    int holdGate04_risingForCount;
    int holdGate05_risingForCount;
    int holdGate06_risingForCount;
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
    void buttonPressed(int);


public slots:
    void activateGateArm(int, bool);
    void activateGateDiode(int, bool);
    // /////////////////////////
    // Simulation
//    void updateInputSim(unsigned char, bool);
    // /////////////////////////

};


#endif // MYDIO_H
