#include "inc/recipe.h"

Recipe::Recipe(QObject *parent) :
    QThread(parent)
{

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

void Recipe::updateRecipe(QString selectedRecipe) {

    QString fileName;
    QString file;
    QString data;
    QStringList rowOfData;
    QStringList rowData;

    fileName = selectedRecipe.toStdString().c_str();
    file = "recipes/" + fileName;
    QFile importedCSV(file);

    data.clear();
    rowOfData.clear();
    rowData.clear();

    if (importedCSV.open(QFile::ReadOnly)) {

        data = importedCSV.readAll();
        rowOfData = data.split("\n");
        importedCSV.close();
    }

    for (int x = 0; x < rowOfData.size(); x++)
    {
        rowData = rowOfData.at(x).split(";");

        for (int y = 0; y < rowData.size(); y++)
        {
            recipeArray[x][y] = rowData[y].toStdString();
        }
    }


    for (int k = 0; k < rowOfData.size(); k++) {

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

    for (int t = 0; t < rowOfData.size(); t++) {

        weightRangeLower[t] = weightRange[t][1];
        weightRangeUpper[t] = weightRange[t][2];
        destinationGate[t]  = weightRange[t][3];
    }
}


