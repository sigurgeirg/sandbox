#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "myscale.h"
#include "mydio.h"
//#include "mygraph.h"
#include "mymessages.h"
#include <QMainWindow>
#include <QtCore>
//#include "../../QCustomPlot/qcustomplot.h"
#include <QDebug>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

#define NUMBER_OF_WEIGHT_SAMPLES 1000


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
    //MyGraph *graph;
    MyMessages *mosq;
    Dio io;

    std::ofstream fout;

    unsigned long *_beltRoundCounter;
    int _weightValueFromScale;
    long _counter;
    int _step;
    int array[NUMBER_OF_WEIGHT_SAMPLES][2];
    long counter;


signals:
    void avgWeight(int);

    // /////////////////////////
    // Simulation
//    void reply(unsigned char, bool);
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

    // /////////////////////////
    // Simulation
//    void on_chkDIN_01_clicked();
//    void on_chkDIN_02_clicked();
//    void on_chkDIN_03_clicked();
//    void on_chkDIN_04_clicked();
    // /////////////////////////

public slots:
    void conveyorBeltCounter(unsigned long);
    void recordWeight(int);
    void displayReceivedWeight(int);
    void displayInputValue(unsigned long);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
