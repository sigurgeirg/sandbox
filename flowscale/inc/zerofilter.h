#ifndef ZEROFILTER
#define ZEROFILTER

#include <QThread>
#include <inttypes.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <QDebug>

#define NUMBER_OF_WEIGHT_SAMPLES 1000

class Zerofilter : public QThread
{
    Q_OBJECT
public:
    explicit Zerofilter(QObject *parent = 0);
    ~Zerofilter();

    unsigned long *numberOfBeltRounds;


    void run();

    int zeroUnfilteredArray[NUMBER_OF_WEIGHT_SAMPLES];
    int runningSmoothArray[10];

    std::ofstream fout;

    int _weightValueFromScale;
    long _sampleCount;

signals:
    void filteredZeroArray(int);

public slots:
    void conveyorBeltCounter(unsigned long);
    void recordZeroWeight(int);

};

#endif // ZEROFILTER

