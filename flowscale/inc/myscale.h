#ifndef MYSCALE_H
#define MYSCALE_H

#include <QThread>
#include <modbus/modbus.h>
#include <modbus/modbus-rtu.h>
#include <inttypes.h>
#include <iostream>
#include <math.h>
#include <QDebug>
#include <fstream>


#define SAMPLES_PER_BELTROUND 1000
#define NUMBER_OF_BELTROUNDS 10
#define FILTER_DELAY 10

class MyScale : public QThread
{
    Q_OBJECT
public:
    explicit MyScale(QObject *parent = 0);
    ~MyScale();

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
    int numberOfBeltRoundsZero;
    long sampleCounter;
    long lastRound;
    double pulseCounter;
    double pulsesPerBeltRound;
    double pulseResolution;
    double lengthOfEachBeltChain;
    double numberOfBeltChains;
    double lengthOfEachBeltPeriod;
    double dMedian;
    double dSorted[NUMBER_OF_BELTROUNDS];
    int zeroUnfilteredArray[NUMBER_OF_BELTROUNDS][SAMPLES_PER_BELTROUND];
    int zeroArray[SAMPLES_PER_BELTROUND];
    int zeroColumn[NUMBER_OF_BELTROUNDS];
    int runningFilter[FILTER_DELAY];
    int filterCounter;
    int zeroTracking;
    int zt_InitializeZeroVectors;
    int zt_CollectDiscreteWeightSamples;
    int zt_CalculateMedianOfZeroPath;
    int zt_ReturnResultsToFile;
    int zt_RunningFilter;

signals:
    void receivedWeight(int);

public slots:
    void conveyorBeltCounter();
    void modelZeroWeight(int);
    
};

#endif // MYSCALE_H
