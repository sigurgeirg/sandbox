#include "recipe.h"

Recipe::Recipe()
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

    for (int k = 0; k < i; k++) {

        if (recipeArray[k][0] == "Recipe_ID"){
            recipeID = recipeArray[k][1];
        } else if (recipeArray[k][0] == "Product_ID"){
            recipeProductId = recipeArray[k][1];
        } else if (recipeArray[k][0] == "Product_Type"){
            recipeProductType = recipeArray[k][1];
        } else if (recipeArray[k][0] == "Batch_ID"){
            recipeBatchID = recipeArray[k][1];
        } else if (recipeArray[k][0] == "Serial_Starts_At"){
            recipeSerialStartsAt = recipeArray[k][1];
        } else if (recipeArray[k][0] == "Min_Prod_Length"){
            recipeMinProdLength = recipeArray[k][1];
        } else if (recipeArray[k][0] == "Max_Prod_Length"){
            recipeMaxProdLength = recipeArray[k][1];
        } else if (recipeArray[k][0] == "Max_Prod_Piece_Gap"){
            recipeMaxProdPieceGap = recipeArray[k][1];
        } else if (recipeArray[k][0] == "Recipe_Description"){
            recipeDescription = recipeArray[k][1];
        } else if (recipeArray[k][0] == "Weight_Range_00"){
            for (int s = 1; s < 4; s++) recipeWeightRange[0][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_01"){
            for (int s = 1; s < 4; s++) recipeWeightRange[1][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_02"){
            for (int s = 1; s < 4; s++) recipeWeightRange[2][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_03"){
            for (int s = 1; s < 4; s++) recipeWeightRange[3][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_04"){
            for (int s = 1; s < 4; s++) recipeWeightRange[4][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_05"){
            for (int s = 1; s < 4; s++) recipeWeightRange[5][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_06"){
            for (int s = 1; s < 4; s++) recipeWeightRange[6][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_07"){
            for (int s = 1; s < 4; s++) recipeWeightRange[7][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_08"){
            for (int s = 1; s < 4; s++) recipeWeightRange[8][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_09"){
            for (int s = 1; s < 4; s++) recipeWeightRange[9][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_10"){
            for (int s = 1; s < 4; s++) recipeWeightRange[10][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_11"){
            for (int s = 1; s < 4; s++) recipeWeightRange[11][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_12"){
            for (int s = 1; s < 4; s++) recipeWeightRange[12][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_13"){
            for (int s = 1; s < 4; s++) recipeWeightRange[13][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_14"){
            for (int s = 1; s < 4; s++) recipeWeightRange[14][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_15"){
            for (int s = 1; s < 4; s++) recipeWeightRange[15][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_16"){
            for (int s = 1; s < 4; s++) recipeWeightRange[16][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_17"){
            for (int s = 1; s < 4; s++) recipeWeightRange[17][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_18"){
            for (int s = 1; s < 4; s++) recipeWeightRange[18][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_19"){
            for (int s = 1; s < 4; s++) recipeWeightRange[19][s] = recipeArray[k][s];
        } else if (recipeArray[k][0] == "Weight_Range_20"){
            for (int s = 1; s < 4; s++) recipeWeightRange[20][s] = recipeArray[k][s];
        }
    }

// ///////////////////////////////////////////////////////////////////////////////////
// How to use in other class:
// ///////////////////////////////////////////////////////////////////////////////////
// -> #include "recipe.h"  .. in other .h file
//    Recipe *rec;
// -> rec = new Recipe(); .. in .cpp file in class constructor

// -> In .cpp file where it will be used ..
//    qDebug() << "Lower_Range_02: "   << QString::fromStdString(con->recipeWeightRange[2][1])
//             << "Upper_Range_02: "   << QString::fromStdString(con->recipeWeightRange[2][2])
//             << "Destin_Gate_02: "   << QString::fromStdString(con->recipeWeightRange[2][3]);
//    qDebug() << "Recipe_Description: "   << QString::fromStdString(con->filterDelay);

// -> To convert from std::string to int ..
//    std::string rec->filterDelay = "45";
//    int value = atoi(rec->filterDelay.c_str()); //value = 45
// ///////////////////////////////////////////////////////////////////////////////////

}

