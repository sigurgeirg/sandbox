#ifndef MYGRAPH_H
#define MYGRAPH_H

#include <QThread>
#include <QDebug>
#include "../../QCustomPlot/qcustomplot.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

#define NUMBER_OF_WEIGHT_SAMPLES 1000

class MyGraph : public QThread
{
    Q_OBJECT
public:
    explicit MyGraph(QObject *parent = 0);
    ~MyGraph();

    //void newInput(unsigned char address);
    void run();
    double array[NUMBER_OF_WEIGHT_SAMPLES][2];
    void setupPlot(QCustomPlot* customPlot);
    QVector<double> x, y; // initialize (this many) vector entries

signals:


public slots:


};

#endif // MYGRAPH_H
