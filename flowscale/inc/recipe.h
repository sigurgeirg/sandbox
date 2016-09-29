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

    std::string recipeArray[100][5];
    std::string weightRange[30][5];

    std::string recipeID;
    std::string productID;
    std::string productType;
    std::string batchID;
    std::string serialStartsAt;
    std::string minProductLength;
    std::string maxProductLength;
    std::string maxProductPieceGap;
    std::string productDescription;
    std::string weightRangeLower[30];
    std::string weightRangeUpper[30];
    std::string destinationGate[30];

};

#endif // RECIPE_H
