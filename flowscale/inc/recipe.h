#ifndef RECIPE_H
#define RECIPE_H

#include <QThread>
#include <QDebug>
#include <QFile>
#include <QStandardItemModel>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "constants.h"


class Recipe : public QThread
{
    Q_OBJECT

public:
    explicit Recipe(QObject *parent = 0);
    ~Recipe();
    void updateRecipe(QString);

    QString recipePathAndName;
    std::string recipeArray[100][5];
    std::string weightRange[100][5];
    std::string gateBufferWeight[100];
    std::string gateBufferCount[100];

    std::string recipeID;
    std::string productID;
    std::string productType;
    std::string batchID;
    std::string serialStartsAt;
    std::string minProductLength;
    std::string maxProductLength;
    std::string maxProductPieceGap;
    std::string description;
    std::string weightRangeLower[100];
    std::string weightRangeUpper[100];
    std::string destinationGate[100];



public slots:


};

#endif // RECIPE_H
