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
        } else if (settingsArray[k][0] == "Graph_X_Min"){
            XvalueMIN = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Graph_X_Max"){
            XvalueMAX = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Graph_Y_Min"){
            YvalueMIN = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Graph_Y_Max"){
            YvalueMAX = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Gate_01_Distance_To"){
            gate_distanceTo[ 1] = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Gate_02_Distance_To"){
            gate_distanceTo[ 2] = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Gate_03_Distance_To"){
            gate_distanceTo[ 3] = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Gate_04_Distance_To"){
            gate_distanceTo[ 4] = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Gate_05_Distance_To"){
            gate_distanceTo[ 5] = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Gate_06_Distance_To"){
            gate_distanceTo[ 6] = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Gate_07_Distance_To"){
            gate_distanceTo[ 7] = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Gate_08_Distance_To"){
            gate_distanceTo[ 8] = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Gate_09_Distance_To"){
            gate_distanceTo[ 9] = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Gate_10_Distance_To"){
            gate_distanceTo[10] = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Grader_Distance_To_End"){
            Grader_DistanceToEnd = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Gate_01_Distance_Open"){
            gate_distanceOpen[ 1] = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Gate_02_Distance_Open"){
            gate_distanceOpen[ 2] = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Gate_03_Distance_Open"){
            gate_distanceOpen[ 3] = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Gate_04_Distance_Open"){
            gate_distanceOpen[ 4] = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Gate_05_Distance_Open"){
            gate_distanceOpen[ 5] = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Gate_06_Distance_Open"){
            gate_distanceOpen[ 6] = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Gate_07_Distance_Open"){
            gate_distanceOpen[ 7] = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Gate_08_Distance_Open"){
            gate_distanceOpen[ 8] = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Gate_09_Distance_Open"){
            gate_distanceOpen[ 9] = settingsArray[k][1];
        } else if (settingsArray[k][0] == "Gate_10_Distance_Open"){
            gate_distanceOpen[10] = settingsArray[k][1];
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
