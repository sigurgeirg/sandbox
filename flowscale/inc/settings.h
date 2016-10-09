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

class Settings : public QThread
{
    Q_OBJECT

public:
    explicit Settings(QObject *parent = 0);
    ~Settings();

    std::string settingsArray[100][5];

    std::string lengthOfEachBeltChain;
    std::string numberOfBeltChains;
    std::string productEntry;
    std::string productWeighingStartDistance;
    std::string productWeighingStopDistance;
    std::string productRelease;
    std::string XvalueMIN;
    std::string XvalueMAX;
    std::string YvalueMIN;
    std::string YvalueMAX;

};

#endif // SETTINGS_H
