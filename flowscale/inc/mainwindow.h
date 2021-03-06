#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "constants.h"
#include "myscale.h"
#include "mymessages.h"
#include <QMainWindow>
#include "keypad.h"
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QtCore>
#include <QDebug>
#include <QStandardItemModel>
#include "../../QCustomPlot/qcustomplot.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <unistd.h>

#include "settings.h"
#include "recipe.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setCurrentRecipe(QString);

    MyScale *scale;
    MyMessages *mosq;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    int boundary;
    QString limits;
    std::ofstream fout;

    Settings *settings;

    bool gate01_enabled;
    bool gate02_enabled;
    bool gate03_enabled;
    bool gate04_enabled;
    bool gate05_enabled;
    bool gate06_enabled;
    bool gate07_enabled;
    bool gate08_enabled;
    bool gate09_enabled;
    bool gate10_enabled;


private:
    Ui::MainWindow *ui;
    KeyPad keypad;
    int step;
    int currentWorkingID;
    int currentMeanWeight;
    long sampleCount;
    int weightValueFromScale;
    long counter;
    int array[samplesPerBeltRound][2];

    QString recipeFile;
    QString recipeFileFullPath;
    QString recipeData;
    QStringList rowOfRecipeData;
    QStringList rowRecipeData;
    QString SettingsFileName;
    QString SettingsFile;
    QString settingsData;
    QString lastRecipeFile;
    QString lastSettingsFile;
    QStringList rowOfSettingsData;
    QStringList rowSettingsData;


signals:
    void avgWeight(int);
    void value(QString);
    void xmin(QString);
    void xmax(QString);
    void ymin(QString);
    void ymax(QString);

    void gate01_Closed(bool);
    void gate02_Closed(bool);
    void gate03_Closed(bool);
    void gate04_Closed(bool);
    void gate05_Closed(bool);
    void gate06_Closed(bool);
    // /////////////////////////
    // Simulation
    // void reply(unsigned char, bool);
    // /////////////////////////

private slots:
    //void on_btnConnect_clicked();
    void on_btnDisconnect_clicked();
    void on_chkWriteToLoadcell_toggled(bool checked);
    void on_btnCalibrateZERO_clicked();
    void on_btnCalibrateWEIGHT_clicked();
    //void on_btnSemiAutoZERO_clicked();
    //void on_btnGrossWeight_clicked();
    //void on_btnNetWeight_clicked();
    //void on_btnEditCalibrationWeight_clicked();
    void on_xmin_clicked();
    void on_xmax_clicked();
    void on_ymin_clicked();
    void on_ymax_clicked();
    void activateGateArm(int, bool);

    // /////////////////////////
    // Simulation
//    void on_chkDIN_01_clicked();
//    void on_chkDIN_02_clicked();
//    void on_chkDIN_03_clicked();
//    void on_chkDIN_04_clicked();
    // /////////////////////////

    void on_btnReverse_clicked();
    void on_btnForward_clicked();

    void on_btnConnect_clicked();
    void on_btnRefreshRecipeList_clicked();
    void on_btnRefreshSettingsList_clicked();
    void on_cbRecipeMenu_activated(const QString &arg1);
    void on_cbSettingsMenu_activated(const QString &arg1);

    void on_cbxGate1_clicked(bool checked);
    void on_cbxGate2_clicked(bool checked);
    void on_cbxGate3_clicked(bool checked);
    void on_cbxGate4_clicked(bool checked);
    void on_cbxGate5_clicked(bool checked);
    void on_cbxGate6_clicked(bool checked);

    void on_btnCloseBatch_clicked();

    void on_chkDebugWriteToFile_clicked(bool checked);


public slots:
    void conveyorBeltSignal();
    void conveyorRunStateIndicator(QString);
    void recordWeight(int);
    void displayReceivedWeight(int);

    void displayDescription(QString);
    void displayBatchId(QString);
    void displayRecipeId(QString);
    void displayProductId(QString);
    void displayProductType(QString);
    void displaySerialNumber(int);
    void displayFilteredWeight(double);
    void displayConfidence(QString);
    void displayLength(QString);
    void displayDestinationGate(QString);

    void displayInputValue(unsigned long);
    void productWeightToDisplay(int);
    void plotProductGraph(int);
    void keyValue(QString);
    void graphBoundaries(QString);
    void enableGate(int, bool);

    void displayBufferCount(int, QString);
    void displayBufferWeight(int, QString);


};

#endif // MAINWINDOW_H
