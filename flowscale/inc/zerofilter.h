#ifndef ZEROFILTER
#define ZEROFILTER

#include <QThread>
#include <inttypes.h>
#include <iostream>
#include <math.h>
#include <QDebug>

#define NUMBER_OF_WEIGHT_SAMPLES 1000

class Zerofilter : public QThread
{
    Q_OBJECT
public:
    explicit Zerofilter(QObject *parent = 0);
    ~Zerofilter();

    void run();

    int zeroUnfilteredArray[NUMBER_OF_WEIGHT_SAMPLES];
    int runningSmoothArray[10];


signals:
    void filteredZeroArray(int);

public slots:
   void recordZeroWeight(int);

};

#endif // ZEROFILTER

