#ifndef MYGRAPH_H
#define MYGRAPH_H

#include "constants.h"
#include <QThread>
#include "myscale.h"
#include <QDebug>
#include "../../QCustomPlot/qcustomplot.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>



class MyGraph : public QThread
{
    Q_OBJECT
public:
    explicit MyGraph(QObject *parent = 0);
    ~MyGraph();

    //void newInput(unsigned char address);
    void run();
    void setupPlot(QCustomPlot* customPlot, int workingID);



private:
    // FIXME: Throw away array[][] when it has been cleared out of mygraph.cpp
    double array[samplesPerBeltRound][2];
    QVector<double> x, y; // initialize (this many) vector entries

signals:


public slots:

};

#endif // MYGRAPH_H
