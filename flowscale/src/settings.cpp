#include "../inc/settings.h"

Settings::Settings(QObject *parent) :
    QThread(parent)
{

    std::ifstream inputfile("settings/flowscale_settings.csv");
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

                 settingsArray[i][j] = token1.c_str();

                 j++;
             }

             j = 0;
             i = i + 1;
         }
    }

    for (int k = 0; k < i; k++) {

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
