#ifndef MYSCALE_H
#define MYSCALE_H

#include "constants.h"
#include "settings.h"
#include "recipe.h"
#include "mydio.h"
#include <QThread>
#include <QDebug>
#include <modbus/modbus.h>
#include <modbus/modbus-rtu.h>
#include <inttypes.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <math.h>
#include <cmath>
#include <ctime>
#include <stdlib.h>
#include "../../QCustomPlot/qcustomplot.h"


class MyScale : public QThread
{
    Q_OBJECT

public:
    explicit MyScale(QObject *parent = 0);
    ~MyScale();

    Settings *settings;
    Recipe *recipe;
    MyDio *dio;
    Dio io;

    void writeBufferDataToFile();
    void updateRecipe(QString);
    bool debug;
    bool between(int less, int value, int greater);
    int  returnToGate(int measuredWeight);
    void connectToSlaveDevice();
    void disconnectFromSlaveDevice();
    void toggleWriteToLoadcell(bool checked);
    void calibrateZERO();
    void calibrateWEIGHT();
    void semiAutoZERO();
    void grossWeight();
    void netWeight();
    void writeToModbus();
    void setupPlot(QCustomPlot* customPlot, int workingID);
    void weightProcessing(int);
    void run();
    int *statusRegisterBinary(uint16_t number[]);
    std::ofstream filezero;
    std::ofstream filebatch;
    std::string bufferTotalCount;
    std::string bufferTotalWeight;

    const char *gateBufferTotalCount;
    const char *gateBufferTotalWeight;

    std::string recipeArray[100][5];

    int zeroUnfilteredArray[numberOfBeltRounds][samplesPerBeltRound];
    int productIDweights[numberOfElementsInList][weightSamplesInWindowOfInterest];

    int numberOfBeltRoundsZero;


    struct productData {
        std::string description[numberOfElementsInList];
        std::string recipeId[numberOfElementsInList];
        std::string productId[numberOfElementsInList];
        std::string productType[numberOfElementsInList];
        std::string batchId[numberOfElementsInList];
        int serialId[numberOfElementsInList];
        int productLengthPulseCounter[numberOfElementsInList];
        int productLength[numberOfElementsInList];
        int productWeight[numberOfElementsInList];
        int productConfidence[numberOfElementsInList];
        int destinationGate[numberOfElementsInList];
        bool inProductSensor[numberOfElementsInList];
        bool productEnteringGateArea[numberOfElementsInList];
        bool openGate[numberOfElementsInList];
        bool closeGate[numberOfElementsInList];
    } proData;

private:
    int *statusRegisterBinaryTempValue;
    int *statusRegisterBinaryReturnValue;
    uint16_t data[64];      // Incoming data values are stored for a moment in a vector
    modbus_t *ctx;
    int setslave;
    bool modbusConnected;   // Flag that allows while loop to scan through incoming data
    bool writeToLoadcell;   // Flag that only allows one way communication via modbus, to prevent data collision
    uint16_t *mbCommand;  // Command on specific int format for LoadCell amplifier
    int commandRegister;    // Register 5 (40006)
    int statusRegister;     // Register 6 (40007)
    int sampleWeightForCalibrationH;    // Register 36 (40037)
    int sampleWeightForCalibrationL;    // Register 37 (40038)
    int netDisplay;                 // Command 7
    int semiAutomaticZero;          // Command 8
    int grossDisplay;               // Command 9
    int zeroSettingForCalibration;  // Command 100
    int sampleWeightStorage;        // Command 101
    int readFromRegister;   // Points to some register, fx. statusRegister ...
    int writeToRegister;    // Points to some register, fx. commandRegister ...
    int calibrationWeight;  // Variable that keeps calibration weight value in terms of [g]
    int weightGROSSorNET[1];// Indicates whether selected weight is sampleWeightForCalibrationLGROSS or NET weight.

    time_t rawtime;
    char recipeActivationTimeStamp[80];
    char batchCloseTimeStamp[80];
    std::string batchClosedWhen;
    std::string recipeActivatedWhen;

    int newDataReady;

    bool processingProduct;
    bool productOnScaleArea[numberOfElementsInList];
    bool productEnteringGradingArea[numberOfElementsInList];

    bool requestBeltRoundPulse;
    bool beltRoundPulse;
    bool requestZeroUpdate;

    bool updateZero_1;
    bool updateZero_2;
    bool updateZero_3;
    bool updateZero_4;

    long sampleCounter;
    long lastSampleCounter;
    long updateSampleCounter;
    long lastRound;

    double pulseCounterInAllRows;
    double pulsesPerBeltRound;
    double pulseResolution;

    double lengthOfEachBeltChain;
    double numberOfBeltChains;
    double lengthOfEachBeltPeriod;
    double dMedian;

    double gate01_distanceTo;

    double dSorted[numberOfBeltRounds];
    int zeroArray[samplesPerBeltRound];
    int updateZeroArray[samplesPerBeltRound];
    int zeroColumn[numberOfBeltRounds];
    int productTickPosition[numberOfElementsInList];
    int pulseCounterInEachRow[numberOfBeltRounds];  //henda þessu þegar þetta hefur verið notað og sannprófað

    int conveyorOff;
    int conveyorWarmUp;
    int conveyorZeroCalibration;
    int conveyorRunning;

    int productCounter;
    int filterCounter;
    int updateZeroEveryNumberOfRounds;
    int countFewBeltRounds;
    int productEntry;
    int productWeighingStartDistance;
    int productWeighingStopDistance;
    int productRelease;
    int plotXvalueMIN;
    int plotXvalueMAX;
    int plotYvalueMIN;
    int plotYvalueMAX;


    // Recipe variables
    QString currentRecipe;
    std::string productDescription;
    std::string recipeID;
    std::string productID;
    std::string productType;

    int serialStartsAt;
    int minProductLength;
    int maxProductLength;
    int maxProductPieceGap;
    int weightRangeLower[50];
    int weightRangeUpper[50];
    int destinationGate[50];

    // ZeroTracking
    int zt_InitializeZeroVectors;
    int zt_UpdateZeroWeightSamples;
    int zt_CollectInitialZeroWeightSamples;
    int zt_CalculateMedianOfZeroPath;
    int zt_ReturnResultsToFile;
    int zt_ProductFilter;

    int filterValue;
    int filterSUM;

    int tempID;

    int nextZeroUpdatePosition;
    int zeroTracking;
    int productEntryPulse;
    int weightStartPulse;
    int weightEndPulse;
    int productReleasePulse;
    int maxProductLengthPulse;
    int medianZeroSample;
    int meanWeightSample;

    // Grader settings variables:
    int gate_available[50];

    double distanceToGraderGate[50];               // [mm]
    double distanceOpenGate[50];                   // [mm]
    double distanceToEndOfGrader;                  // [mm]

    int pulseDistanceToGate[50];                   // [ticks]
    int pulseDistanceToEndOfGate[50];              // [ticks]
    int pulseDistanceToEndOfConveyorBelt;          // [ticks]

    int gateBufferCount[50];                      // [pcs]
    double gateBufferWeight[50];                  // [kg]

    int gateBufferProcessedCount[50];             // [pcs]
    double gateBufferProcessedWeight[50];         // [kg]

    int gateBufferProcessedCountTotalizer[50];     // [pcs]
    double gateBufferProcessedWeightTotalizer[50]; // [kg]

    int evenDistribution;
    int fillUpInSequence;
    int sortingMethod;

    int bufferByWeight;
    int bufferByCount;
    int bufferByWeightOrByCount;


signals:
    void continuousModbusWeight(int);
    void sendFilteredWeight(double);
    void sendSerialNumber(int);
    void sendDescription(QString);
    void sendBatchId(QString);
    void sendRecipeId(QString);
    void sendProductId(QString);
    void sendProductType(QString);
    void sendConfidence(QString);
    void sendLength(QString);
    void sendDestinationGate(QString);
    void plotData(int);
    void productWeight(int);
    void requestNewRecipe(QString);
    void conveyorRunState(QString);
    void sendMQTT(QString, const char*);
    void activateGateArm(int, bool);
    void activateGateDiode(int, bool);
    void enableGate(int, bool);
    void bufferCount(int, QString);
    void bufferWeight(int, QString);

public slots:
    void conveyorBeltSignal();
    void enteringProductSensorSignal();
    void leavingProductSensorSignal();
    void xmin(QString);
    void xmax(QString);
    void ymin(QString);
    void ymax(QString);
    void gate01_Closed(bool);
    void gate02_Closed(bool);
    void gate03_Closed(bool);
    void gate04_Closed(bool);
    void gate05_Closed(bool);
    void gate06_Closed(bool);
    void changeGateStateWithButtonPress(int);

};

#endif // MYSCALE_H
