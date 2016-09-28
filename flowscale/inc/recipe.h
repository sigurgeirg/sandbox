#ifndef RECIPE_H
#define RECIPE_H

#include <QDebug>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

class Recipe
{
public:
    Recipe();

    std::string recipeArray[100][5];

    std::string recipeID;
    std::string recipeProductId;
    std::string recipeProductType;
    std::string recipeBatchID;
    std::string recipeSerialStartsAt;
    std::string recipeMinProdLength;
    std::string recipeMaxProdLength;
    std::string recipeMaxProdPieceGap;
    std::string recipeDescription;
    std::string recipeWeightRange[30][5];

};

#endif // RECIPE_H
