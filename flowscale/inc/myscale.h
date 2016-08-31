#ifndef MYSCALE_H
#define MYSCALE_H

#include <QThread>
#include <modbus/modbus.h>
#include <modbus/modbus-rtu.h>
#include <inttypes.h>
#include <iostream>
#include <math.h>
#include <cmath>
#include <QDebug>
#include <fstream>


#define SAMPLES_PER_BELTROUND 1000
#define NUMBER_OF_BELTROUNDS 10
#define FILTER_DELAY 10
#define NUMBER_OF_ELEMENTS_IN_LIST 5
#define PRODUCT_ENTRY 1 //start of conveyor
#define PRODUCT_WEIGHING_START_DISTANCE 430 // FIXME: was 330
#define PRODUCT_WEIGHING_STOP_DISTANCE 770 // FIXME: was 666
#define PRODUCT_RELEASE 1400 // FIXME


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
    void run();
    int *statusRegisterBinary(uint16_t number[]);
    std::ofstream filezero;

    struct productData {

        int tempId[NUMBER_OF_ELEMENTS_IN_LIST];
        int serialId[NUMBER_OF_ELEMENTS_IN_LIST];
        int batchId[NUMBER_OF_ELEMENTS_IN_LIST];
        int productId[NUMBER_OF_ELEMENTS_IN_LIST];
        int productType[NUMBER_OF_ELEMENTS_IN_LIST];
        int productSensorEntryPosition[NUMBER_OF_ELEMENTS_IN_LIST];
        int productSensorExitPosition[NUMBER_OF_ELEMENTS_IN_LIST];
        int productLength[NUMBER_OF_ELEMENTS_IN_LIST];
        int productWeight[NUMBER_OF_ELEMENTS_IN_LIST];
        int productStdDev[NUMBER_OF_ELEMENTS_IN_LIST];
        int productLengthCounter[NUMBER_OF_ELEMENTS_IN_LIST];
        int destinationGate[NUMBER_OF_ELEMENTS_IN_LIST];
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

    double dSorted[NUMBER_OF_BELTROUNDS];
    bool elementOnScaleArea[NUMBER_OF_ELEMENTS_IN_LIST];
    int zeroUnfilteredArray[NUMBER_OF_BELTROUNDS][SAMPLES_PER_BELTROUND];
    int productIDweights[NUMBER_OF_ELEMENTS_IN_LIST][SAMPLES_PER_BELTROUND];
    int zeroArray[SAMPLES_PER_BELTROUND];
    int updateZeroArray[SAMPLES_PER_BELTROUND];
    int zeroColumn[NUMBER_OF_BELTROUNDS];
    int runningFilter[FILTER_DELAY];
    int productTempId[NUMBER_OF_ELEMENTS_IN_LIST];
    int pulseCounterInEachRow[NUMBER_OF_BELTROUNDS];  //henda þessu þegar þetta hefur verið notað og sannprófað

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
    int meanWeightSamples;


signals:
    void receivedWeight(int);
    void sendFilteredWeight(int);
    void sendDebugData(int);

public slots:
    void conveyorBeltSignal();
    void enteringProductSensorSignal();
    void leavingProductSensorSignal();
    void modelZeroWeight(int);
    
};

#endif // MYSCALE_H
