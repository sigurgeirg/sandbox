#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "constants.h"
#include "mydio.h"
#include "myscale.h"
#include "mymessages.h"
#include <QMainWindow>
#include "keypad.h"
#include <QLineEdit>
#include <QTextEdit>
#include <QtCore>
#include <QDebug>
#include "../../QCustomPlot/qcustomplot.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <unistd.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    MyScale *scale;
    MyDio *dio;
    MyMessages *mosq;
    Dio io;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    int boundary;

    std::ofstream fout;


private:
    Ui::MainWindow *ui;
    KeyPad keypad;
    int *numberOfBeltRounds;
    int step;
    int currentWorkingID;
    int currentMeanWeight;
    long sampleCount;
    int weightValueFromScale;
    long counter;
    int array[samplesPerBeltRound][2];
//    int productIDweights[numberOfElementsInList][samplesPerBeltRound];

signals:
    void avgWeight(int);
    void value(QString);
    void xmin(QString);
    void xmax(QString);
    void ymin(QString);
    void ymax(QString);
    // /////////////////////////
    // Simulation
    // void reply(unsigned char, bool);
    // /////////////////////////

private slots:
    void on_btnConnect_clicked();
    void on_btnDisconnect_clicked();
    void on_chkWriteToLoadcell_toggled(bool checked);
    void on_btnCalibrateZERO_clicked();
    void on_btnCalibrateWEIGHT_clicked();
    void on_btnAPPLY_clicked();
    void on_btnSemiAutoZERO_clicked();
    void on_btnGrossWeight_clicked();
    void on_btnNetWeight_clicked();
    void on_btnEditCalibrationWeight_clicked();
    void on_xmin_clicked();
    void on_xmax_clicked();
    void on_ymin_clicked();
    void on_ymax_clicked();


    // /////////////////////////
    // Simulation
//    void on_chkDIN_01_clicked();
//    void on_chkDIN_02_clicked();
//    void on_chkDIN_03_clicked();
//    void on_chkDIN_04_clicked();
    // /////////////////////////

    void on_btnReverse_clicked();
    void on_btnForward_clicked();


    void on_btnNetWeightConnect_clicked();


public slots:
    void conveyorBeltSignal();
    void recordWeight(int);
    void displayReceivedWeight(int);
    void displayFilteredWeight(int);
    void displayDebugData(int);
    void displayInputValue(unsigned long);
    void plotProductWeight(int);
    void plotProductGraph(int);
    void keyValue(QString);
    void graphBoundaries(QString);


};

#endif // MAINWINDOW_H
