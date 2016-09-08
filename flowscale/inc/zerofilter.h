#ifndef ZEROFILTER
#define ZEROFILTER

#include <QThread>
#include <inttypes.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <QDebug>


class Zerofilter : public QThread
{
    Q_OBJECT
public:
    explicit Zerofilter(QObject *parent = 0);
    ~Zerofilter();

    void run();

    //std::ofstream filezero;

    static const int SAMPLES_PER_BELTROUND = 1000;
    static const int NUMBER_OF_BELTROUNDS = 10;
    static const int FILTER_DELAY = 10;


private:
    int numberOfBeltRoundsZero;
    bool runOnce;
    int phase;
    long sampleCounter;
    long lastRound;
    double pulseCounter;
    double pulsesPerBeltRound;
    double pulseResolution;
    double lengthOfEachBeltChain;
    double numberOfBeltChains;
    double lengthOfEachBeltPeriod;
    int zeroUnfilteredArray[NUMBER_OF_BELTROUNDS][SAMPLES_PER_BELTROUND];
    int zeroArray[SAMPLES_PER_BELTROUND];
    int zeroColumn[NUMBER_OF_BELTROUNDS];
    int runningFilter[FILTER_DELAY];
    int filterCounter;
    int runningSmoothArray[10];
    double dSorted[NUMBER_OF_BELTROUNDS];
    double dMedian;

signals:
    void filteredZeroArray(int);
    void debVal(int);

public slots:
    //void conveyorBeltCounter();
    //void recordZeroWeight(int);


};

#endif // ZEROFILTER

