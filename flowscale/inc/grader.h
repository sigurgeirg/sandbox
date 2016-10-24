#ifndef GRADER_H
#define GRADER_H

#include <QThread>
#include <QDebug>
#include "constants.h"




class Grader : public QThread
{
    Q_OBJECT

public:
    explicit Grader(QObject *parent = 0);
    ~Grader();

    void run();
    bool between(int less, int value, int greater);

    struct gradingData {
        QString batchId[numberOfElementsInList];
        QString recipeId[numberOfElementsInList];
        QString productId[numberOfElementsInList];
        QString productType[numberOfElementsInList];
        int serialId[numberOfElementsInList];
        int productWeight[numberOfElementsInList];
        QString productConfidence[numberOfElementsInList];
        QString productLength[numberOfElementsInList];
        QString destinationGate[numberOfElementsInList];
    } graderData;


private:
    bool firstRun;
    int tempID;
    int productCounter;
    int productEntry;
    int productEntryPulse;

    // Grader settings variables:
    int numberOfGatesOnGrader;
    int distanceToGraderGate[10];        // [mm]
    int distanceOpenGate[10];            // [mm]
    int distanceToEndOfGraderGate[10];   // [mm]
    int pulseDistanceToGate[10];         // [ticks]
    int pulseDistanceToEndOfGate[10];    // [ticks]

    int evenDistribution;
    int fillUpInSequence;
    int sortingMethod;

    int bufferByWeight;
    int bufferByCount;
    int bufferByWeightOrByCount;

    int gateBufferWeight[10]; // [kg]

    int gateBufferAmount[10]; // [pcs]


    QString gradBatchID;
    QString gradRecipeID;
    QString gradProductID;
    QString gradProductType;
    int     gradSerialNumber;
    int     gradFilteredWeight;
    QString gradLength;
    QString gradConfidence;
    QString gradDestinationGate;
    int     gradPulseResolution;


    int productTickPosition[numberOfElementsInList];


signals:
    void activateGate(QString);



public slots:
    void productEnteringGrader(bool);
    void gradingProducts(void);

    void graderBatchId(QString);
    void graderRecipeId(QString);
    void graderProductId(QString);
    void graderProductType(QString);
    void graderSerialNumber(int);
    void graderFilteredWeight(int);
    void graderConfidence(QString);
    void graderLength(QString);
    void graderDestinationGate(QString);
    void graderPulseResolution(QString);

};

#endif // GRADER_H
