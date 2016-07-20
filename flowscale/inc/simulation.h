#ifndef SIMULATION
#define SIMULATION

#include <QThread>
#include <inttypes.h>
#include <iostream>
#include <math.h>
#include <QDebug>

class Simulation : public QThread
{
    Q_OBJECT
public:
    explicit Simulation(QObject *parent = 0);
    ~Simulation();

    void run();
    int *statusRegisterBinary(uint16_t number[]);

    int *statusRegisterBinaryTempValue;
    int *statusRegisterBinaryReturnValue;
    uint16_t data[10];      // Incoming data values are stored for a moment in a vector of size 10

    bool modbusConnected;   // Flag that allows while loop to scan through incoming data


signals:
    void receivedWeight(int);

public slots:

};

#endif // SIMULATION

