#ifndef SETTINGS_H
#define SETTINGS_H

#include <QThread>
#include <QDebug>
#include <QFile>
#include <QStandardItemModel>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "constants.h"

class Settings : public QThread
{
    Q_OBJECT

public:
    explicit Settings(QObject *parent = 0);
    ~Settings();

    std::string settingsArray[100][5];

    std::string lengthOfEachBeltChain;
    std::string calibrationWeight;
    std::string numberOfBeltChains;
    std::string productEntry;
    std::string productWeighingStartDistance;
    std::string productWeighingStopDistance;
    std::string productRelease;
    std::string XvalueMIN;
    std::string XvalueMAX;
    std::string YvalueMIN;
    std::string YvalueMAX;

    std::string gate_distanceTo[numberOfGates+1];
    std::string gate_distanceOpen[numberOfGates+1];
    std::string Grader_DistanceToEnd;
};

#endif // SETTINGS_H
