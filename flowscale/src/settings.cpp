#include "../inc/settings.h"

Settings::Settings(QObject *parent) :
    QThread(parent)
{

    QString fileName;
    QString file;
    QString data;
    QStringList rowOfData;
    QStringList rowData;

    fileName = "flowscale_settings.csv";
    file = "settings/" + fileName;
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
            settingsArray[x][y] = rowData[y].toStdString();
        }
    }


    for (int k = 0; k < rowOfData.size(); k++) {

        if (settingsArray[k][0] == "Length_Of_Each_BeltChain"){
            lengthOfEachBeltChain = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Number_Of_BeltChains"){
            numberOfBeltChains = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Product_Entry"){
            productEntry = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Product_Weighing_Start_Distance"){
            productWeighingStartDistance = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Product_Weighing_Stop_Distance"){
            productWeighingStopDistance = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Product_Release"){
            productRelease = settingsArray[k][1];
        } else if (settingsArray[k][0] == "X_Value_Min"){
            XvalueMIN = settingsArray[k][1];
        } else if (settingsArray[k][0] == "X_Value_Max"){
            XvalueMAX = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Y_Value_Min"){
            YvalueMIN = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Y_Value_Max"){
            YvalueMAX = settingsArray[k][1];
        }
    }

    // ///////////////////////////////////////////////////////////////////////////////////
    // How to use in other class:
    // ///////////////////////////////////////////////////////////////////////////////////
    // -> #include "settings.h"  .. in other .h file
    //    Settings *sett;
    // -> sett = new Settings(); .. in .cpp file in class constructor

    // -> In .cpp file where it will be used ..
    //    qDebug() << "Lower_Range_02: "   << QString::fromStdString(con->recipeWeightRange[2][1])
    //             << "Upper_Range_02: "   << QString::fromStdString(con->recipeWeightRange[2][2])
    //             << "Destin_Gate_02: "   << QString::fromStdString(con->recipeWeightRange[2][3]);
    //    qDebug() << "Recipe_Description: "   << QString::fromStdString(con->filterDelay);

    // -> To convert from std::string to int ..
    //    std::string set->filterDelay = "45";
    //    int value = atoi(set->filterDelay.c_str()); //value = 45
    // ///////////////////////////////////////////////////////////////////////////////////
}

Settings::~Settings()
{

}
