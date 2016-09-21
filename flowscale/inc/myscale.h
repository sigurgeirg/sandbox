#ifndef MYSCALE_H
#define MYSCALE_H

#include "constants.h"
#include <QThread>
#include <modbus/modbus.h>
#include <modbus/modbus-rtu.h>
#include <inttypes.h>
#include <iostream>
#include <math.h>
#include <cmath>
#include <QDebug>
#include <fstream>
#include "../../QCustomPlot/qcustomplot.h"


class MyScale : public QThread
{
    Q_OBJECT

public:
    explicit MyScale(QObject *parent = 0);
    ~MyScale();

    bool between(int less, int value, int greater);
    void connectToSlaveDevice();
    void disconnectFromSlaveDevice();
    void toggleWriteToLoadcell(bool checked);
    void calibrateZERO();
    void calibrateWEIGHT(int calibrationWeight);
    void storeCalibrationWEIGHT();
    void semiAutoZERO();
    void grossWeight();
    void netWeight();
    void setupPlot(QCustomPlot* customPlot, int workingID);
    void run();
    int *statusRegisterBinary(uint16_t number[]);
    std::ofstream filezero;

    int zeroUnfilteredArray[numbersOfBeltRounds][samplesPerBeltRound];
    int productIDweights[numberOfElementsInList][weightSamplesInWindowOfInterest];

    struct productData {

        int tempId[numberOfElementsInList];
        int serialId[numberOfElementsInList];
        int batchId[numberOfElementsInList];
        int productId[numberOfElementsInList];
        int productType[numberOfElementsInList];
        int productSensorEntryPosition[numberOfElementsInList];
        int productSensorExitPosition[numberOfElementsInList];
        int productLength[numberOfElementsInList];
        int productWeight[numberOfElementsInList];
        int productStdDev[numberOfElementsInList];
        int productLengthCounter[numberOfElementsInList];
        int destinationGate[numberOfElementsInList];
    } proData;

private:
    int *statusRegisterBinaryTempValue;
    int *statusRegisterBinaryReturnValue;
    uint16_t data[64];      // Incoming data values are stored for a moment in a vector
    modbus_t *ctx;
    int setslave;
    bool modbusConnected;   // Flag that allows while loop to scan through incoming data
    bool writeToLoadcell;   // Flag that only allows one way communication via modbus, to prevent data collision
    uint16_t mbCommand[1];  // Command on specific int format for LoadCell amplifier
    int commandRegister;    // Register 5 (40006)
    int statusRegister;     // Register 6 (40007)
    int sampleWeightForCalibrationL;    // Register 37 (40038)
    int netDisplay;                 // Command 7
    int semiAutomaticZero;          // Command 8
    int grossDisplay;               // Command 9
    int zeroSettingForCalibration;  // Command 100
    int sampleWeightStorage;        // Command 101
    int readFromRegister;   // Points to some register, fx. statusRegister ...
    int writeToRegister;    // Points to some register, fx. commandRegister ...
    int calibrationWeight;  // Variable that keeps calibration weight value in terms of [g]
    int weightGROSSorNET[1];// Indicates whether selected weight is GROSS or NET weight.


    // from zerofilter
    bool enteringProduct;
    bool requestBeltRoundPulse;
    bool beltRoundPulse;
    bool requestZeroUpdate;

    long sampleCounter;
    long lastSampleCounter;
    long updateSampleCounter;
    long lastRound;

    double pulseCounterInAllRows;
    double productCounter;
    double pulsesPerBeltRound;
    double pulseResolution;
    double lengthOfEachBeltChain;
    double numberOfBeltChains;
    double lengthOfEachBeltPeriod;
    double dMedian;

    double dSorted[numbersOfBeltRounds];
    bool elementOnScaleArea[numberOfElementsInList];
    // zeroUnfilteredArray[numbersOfBeltRounds][samplesPerBeltRound];
    // int productIDweights[numberOfElementsInList][weightSamplesInWindowOfInterest];
    int zeroArray[samplesPerBeltRound];
    int updateZeroArray[samplesPerBeltRound];
    int zeroColumn[numbersOfBeltRounds];
    int runningFilter[filterDelay];
    int productTempId[numberOfElementsInList];
    int pulseCounterInEachRow[numbersOfBeltRounds];  //henda þessu þegar þetta hefur verið notað og sannprófað

    int filterCounter;
    int numberOfBeltRoundsZero;
    int countFewBeltRounds;

    int zt_InitializeZeroVectors;
    int zt_UpdateZeroWeightSamples;
    int zt_CollectInitialZeroWeightSamples;
    int zt_CalculateMedianOfZeroPath;
    int zt_ReturnResultsToFile;
    int zt_RunningFilter;
    int zt_ProductFilter;

    int filterValue;
    int filterSUM;

    int productID;

    int nextZeroUpdatePosition;
    int zeroTracking;
    int productEntryPulse;
    int weightStartPulse;
    int weightEndPulse;
    int productReleasePulse;
    int medianZeroSample;
    int meanWeightSample;

    int plotXvalueMIN;
    int plotXvalueMAX;
    int plotYvalueMIN;
    int plotYvalueMAX;


signals:
    void receivedWeight(int);
    void sendFilteredWeight(int);
    void sendDebugData(int);
    void plotData(int);
    void plotWeight(int);

public slots:
    void conveyorBeltSignal();
    void enteringProductSensorSignal();
    void leavingProductSensorSignal();
    void modelZeroWeight(int);
    void xmin(QString);
    void xmax(QString);
    void ymin(QString);
    void ymax(QString);
    
};

#endif // MYSCALE_H
