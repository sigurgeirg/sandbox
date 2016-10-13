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


using namespace std;

class Recipe : public QThread
{
    Q_OBJECT

public:
    explicit Recipe(QObject *parent = 0);
    ~Recipe();
    void updateRecipe(QString);

    QString recipePathAndName;
    string recipeArray[100][5];
    string weightRange[50][5];

    string recipeID;
    string productID;
    string productType;
    string batchID;
    string serialStartsAt;
    string minProductLength;
    string maxProductLength;
    string maxProductPieceGap;
    string description;
    string weightRangeLower[50];
    string weightRangeUpper[50];
    string destinationGate[50];


public slots:


};

#endif // RECIPE_H
