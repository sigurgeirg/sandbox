#include "../inc/grader.h"


Grader::Grader(QObject *parent) :
    QThread(parent)
{

    productEntry = 1; // Remember grader settings recipe file
    productCounter = 0;
    tempID = -1;

    firstRun = true;

    // Grader settings variables:
    numberOfGatesOnGrader = 6;

    distanceToGraderGate[0] = 200;  // [mm]
    distanceToGraderGate[1] = 200;
    distanceToGraderGate[2] = 1200;
    distanceToGraderGate[3] = 1200;
    distanceToGraderGate[4] = 2200;
    distanceToGraderGate[5] = 2200;

    distanceOpenGate[0] = 500;  // [mm]
    distanceOpenGate[1] = 500;
    distanceOpenGate[2] = 500;
    distanceOpenGate[3] = 500;
    distanceOpenGate[4] = 500;
    distanceOpenGate[5] = 500;

    evenDistribution = 1;
    fillUpInSequence = 2;
    sortingMethod    = evenDistribution;

    bufferByWeight = 1;
    bufferByCount  = 2;
    bufferByWeightOrByCount = bufferByWeight;

    gateBufferWeight[0] = 20; // [kg]
    gateBufferWeight[1] = 20;
    gateBufferWeight[2] = 20;
    gateBufferWeight[3] = 20;
    gateBufferWeight[4] = 20;
    gateBufferWeight[5] = 20;

    gateBufferAmount[0] = 40; // [pcs]
    gateBufferAmount[1] = 40;
    gateBufferAmount[2] = 40;
    gateBufferAmount[3] = 40;
    gateBufferAmount[4] = 40;
    gateBufferAmount[5] = 40;



    gradBatchID = "";
    gradRecipeID = "";
    gradProductID = "";
    gradProductType = "";
    gradSerialNumber = 0;
    gradFilteredWeight = 0;
    gradLength = "";
    gradConfidence = "";
    gradDestinationGate = "";

    // Grader settings variabales
//    lengthOfEachBeltChain           = QString::fromStdString(settings->lengthOfEachBeltChain.c_str()).toFloat();
//    numberOfBeltChains              = QString::fromStdString(settings->numberOfBeltChains.c_str()).toFloat();
//    productEntry                    = QString::fromStdString(settings->productEntry.c_str()).toInt();
//    productWeighingStartDistance    = QStrinS::fromStdString(settings->productWeighingStartDistance.c_str()).toInt();
//    productWeighingStopDistance     = QString::fromStdString(settings->productWeighingStopDistance.c_str()).toInt();

}


Grader::~Grader()
{

}


bool Grader::between(int less, int value, int greater) {

    if ((value >= less) && (value < greater)) {
        return true;
    } else {
        return false;
    }
}


void Grader::graderBatchId(QString batchId)
{
    gradBatchID = batchId;
}


void Grader::graderRecipeId(QString recipeId)
{
    gradRecipeID = recipeId;
}


void Grader::graderProductId(QString productId)
{
    gradProductID = productId;
}


void Grader::graderProductType(QString productType)
{
    gradProductType = productType;
}


void Grader::graderSerialNumber(int serialNumber)
{
    gradSerialNumber = serialNumber;
}


void Grader::graderFilteredWeight(int filteredWeight)
{
    gradFilteredWeight = filteredWeight;
}


void Grader::graderLength(QString length)
{
    gradLength = length;
}


void Grader::graderConfidence(QString confidence)
{
    gradConfidence = confidence;
}


void Grader::graderDestinationGate(QString destinationGate)
{
    gradDestinationGate = destinationGate;
}


void Grader::graderPulseResolution(QString pulseResolution)
{
    gradPulseResolution = pulseResolution.toInt();
}


void Grader::productEnteringGrader(bool)
{
    productCounter++;
    tempID++;
    if (tempID >= numberOfElementsInList) {
        tempID = 0;
    }

    productTickPosition[tempID] = 0;

    graderData.batchId[tempID] = gradBatchID;
    graderData.recipeId[tempID] = gradRecipeID;
    graderData.productId[tempID] = gradProductID;
    graderData.productType[tempID] = gradProductType;

    graderData.serialId[tempID] = gradSerialNumber;
    graderData.productWeight[tempID] = gradFilteredWeight;
    graderData.productLength[tempID] = gradLength;

    graderData.productConfidence[tempID] = gradConfidence;
    graderData.destinationGate[tempID] = gradDestinationGate;


    productEntryPulse = (int)((double)(productEntry)/gradPulseResolution + 0.5);

    for (int i = 0; i < 6; i++) {
        pulseDistanceToGate[i] = (int)((double)(distanceToGraderGate[i])/gradPulseResolution + 0.5);

        distanceToEndOfGraderGate[i] = distanceToGraderGate[i] + distanceOpenGate[i];
        pulseDistanceToEndOfGate[i] = (int)((double)(distanceToEndOfGraderGate[i])/gradPulseResolution + 0.5);
    }
}


void Grader::gradingProducts(void)
{

    // Track elements from Grader entry point (>=0) and to Grader product Exit Gate on program-scantime resolution +1

    for (int _elementId = 0; _elementId < numberOfElementsInList; _elementId++) {
        if (productTickPosition[_elementId] >= 0) {
            productTickPosition[_elementId]++;

            if (between(pulseDistanceToGate[_elementId], productTickPosition[_elementId], pulseDistanceToEndOfGate[_elementId]))
            {
                emit activateGate(graderData.destinationGate[_elementId]);
                qDebug() << "What About This ???";
            }

            if (productTickPosition[_elementId] >= pulseDistanceToEndOfGate[_elementId])
            {
                productTickPosition[_elementId] = -1;
            }
            // Ef current product -> Eitthvað annað -> Reason -> Destination End



        }
    }
}

void Grader::run()
{
    if (firstRun == true) {

        for (int _count = 0; _count < numberOfElementsInList; _count++) {
            productTickPosition[_count] = -1;
        }
        firstRun = false;
    }


    while(true) {

        gradingProducts();
    }
}
