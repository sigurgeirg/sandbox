#include "recipe.h"

Recipe::Recipe(QObject *parent) :
    QThread(parent)
{

    std::ifstream inputfile("../release/flowscale_recipe.csv");
    std::string line = "";
    std::string delimiter = ";";
    std::string token1;
    size_t pos = 0;

    //getline(inputfile, line);

    int i = 0;
    int j = 0;

    while (!getline(inputfile, line).eof())
    {
         if (line.size() > 0)
         {

             while ((pos = line.find(delimiter)) != std::string::npos)
             {
                 token1 = line.substr(0, pos);
                 line.erase(0, pos+1);

                 recipeArray[i][j] = token1.c_str();

                 j++;
             }

             j = 0;
             i = i + 1;
         }
    }

    std::string recipeID;
    std::string productID;
    std::string productType;
    std::string batchID;
    std::string serialStartsAt;
    std::string minProductLength;
    std::string maxProductLength;
    std::string maxProductPieceGap;
    std::string description;
    std::string weightRangeLower[30];
    std::string weightRangeUpper[30];
    std::string destinationGate[30];

    for (int k = 0; k < i; k++) {

        if (recipeArray[k][0] == "Recipe_ID"){
            recipeID = recipeArray[k][1];
        } else if (recipeArray[k][0] == "Product_ID"){
            productID = recipeArray[k][1];
        } else if (recipeArray[k][0] == "Product_Type"){
            productType = recipeArray[k][1];
        } else if (recipeArray[k][0] == "Batch_ID"){
            batchID = recipeArray[k][1];
        } else if (recipeArray[k][0] == "Serial_Starts_At"){
            serialStartsAt = recipeArray[k][1];
        } else if (recipeArray[k][0] == "Min_Prod_Length"){
            minProductLength = recipeArray[k][1];
        } else if (recipeArray[k][0] == "Max_Prod_Length"){
            maxProductLength = recipeArray[k][1];
        } else if (recipeArray[k][0] == "Max_Prod_Piece_Gap"){
            maxProductPieceGap = recipeArray[k][1];
        } else if (recipeArray[k][0] == "Recipe_Description"){
            description = recipeArray[k][1];
        } else if (recipeArray[k][0] == "Weight_Range_00"){
            for (int s = 1; s < 4; s++) weightRange[0][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_01"){
            for (int s = 1; s < 4; s++) weightRange[1][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_02"){
            for (int s = 1; s < 4; s++) weightRange[2][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_03"){
            for (int s = 1; s < 4; s++) weightRange[3][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_04"){
            for (int s = 1; s < 4; s++) weightRange[4][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_05"){
            for (int s = 1; s < 4; s++) weightRange[5][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_06"){
            for (int s = 1; s < 4; s++) weightRange[6][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_07"){
            for (int s = 1; s < 4; s++) weightRange[7][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_08"){
            for (int s = 1; s < 4; s++) weightRange[8][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_09"){
            for (int s = 1; s < 4; s++) weightRange[9][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_10"){
            for (int s = 1; s < 4; s++) weightRange[10][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_11"){
            for (int s = 1; s < 4; s++) weightRange[11][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_12"){
            for (int s = 1; s < 4; s++) weightRange[12][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_13"){
            for (int s = 1; s < 4; s++) weightRange[13][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_14"){
            for (int s = 1; s < 4; s++) weightRange[14][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_15"){
            for (int s = 1; s < 4; s++) weightRange[15][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_16"){
            for (int s = 1; s < 4; s++) weightRange[16][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_17"){
            for (int s = 1; s < 4; s++) weightRange[17][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_18"){
            for (int s = 1; s < 4; s++) weightRange[18][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_19"){
            for (int s = 1; s < 4; s++) weightRange[19][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_20"){
            for (int s = 1; s < 4; s++) weightRange[20][s] = recipeArray[k][s];
        }
    }

    for (int t = 0; t < i; t++){

        weightRangeLower[t] = weightRange[t][0];
        weightRangeUpper[t] = weightRange[t][1];
        destinationGate[t]  = weightRange[t][2];
    }

// ///////////////////////////////////////////////////////////////////////////////////
// How to use in other class:
// ///////////////////////////////////////////////////////////////////////////////////
// -> #include "recipe.h"  .. in other .h file
//    Recipe *recipe;
// -> recipe = new Recipe(); .. in .cpp file in class constructor

// -> In .cpp file where it will be used ..
//    qDebug() << "Lower_Range_02: "   << QString::fromStdString(recipe->weightRange[2][1])
//             << "Upper_Range_02: "   << QString::fromStdString(recipe->weightRange[2][2])
//             << "Destin_Gate_02: "   << QString::fromStdString(recipe->weightRange[2][3]);
//    qDebug() << "Recipe_Description: "   << QString::fromStdString(recipe->filterDelay);

// -> To convert from std::string to int ..
//    std::string rec->filterDelay = "45";
//    int value = atoi(recipe->filterDelay.c_str()); //value = 45
// ///////////////////////////////////////////////////////////////////////////////////

}


Recipe::~Recipe()
{

}
