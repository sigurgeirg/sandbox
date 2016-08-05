#ifndef ZEROFILTER
#define ZEROFILTER

#include <QThread>
#include <inttypes.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <QDebug>

#define SAMPLES_PER_BELTROUND 1000
#define NUMBER_OF_BELTROUNDS 10

class Zerofilter : public QThread
{
    Q_OBJECT
public:
    explicit Zerofilter(QObject *parent = 0);
    ~Zerofilter();

    void run();

    std::ofstream filezero;


private:
    int *numberOfBeltRounds;
    int weightValueFromScale;
    long sampleCount;
    long lastRound;
    int zeroUnfilteredArray[NUMBER_OF_BELTROUNDS][SAMPLES_PER_BELTROUND];
    int runningSmoothArray[10];

signals:
    void filteredZeroArray(int);

public slots:
    void conveyorBeltCounter();
    void recordZeroWeight(int);


};

#endif // ZEROFILTER

