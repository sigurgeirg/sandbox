#ifndef RECIPE_H
#define RECIPE_H

#include <QThread>
#include <QDebug>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>


class Recipe : public QThread
{
    Q_OBJECT

public:
    explicit Recipe(QObject *parent = 0);
    ~Recipe();
    void updateRecipe(QString);

    QString recipePathAndName;
    std::string recipeArray[100][5];
    std::string weightRange[50][5];

    std::string recipeID;
    std::string productID;
    std::string productType;
    std::string batchID;
    std::string serialStartsAt;
    std::string minProductLength;
    std::string maxProductLength;
    std::string maxProductPieceGap;
    std::string description;
    std::string weightRangeLower[50];
    std::string weightRangeUpper[50];
    std::string destinationGate[50];

public slots:


};

#endif // RECIPE_H
