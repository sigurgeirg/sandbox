#include "../inc/mygraph.h"




MyGraph::MyGraph(QObject *parent) :
    QThread(parent)
{
    //
}

MyGraph::~MyGraph()
{
    //
}

void MyGraph::setupPlot(QCustomPlot *customPlot)
{
    std::ifstream inputfile("weight.csv");
    std::string line = "";
    std::string delimiter = ",";
    std::string token1;
    std::string token2;
    size_t pos = 0;


    int i = 0;

    while (!getline(inputfile, line).eof())
    {
         if (line.size()>0)
         {
             while ((pos = line.find(delimiter)) != std::string::npos)
             {
                 token1 = line.substr(0, pos);
                 line.erase(0, pos+1);
                 token2 = line.substr(0);

                 array[i][0] = atof(token1.c_str());
                 array[i][1] = atof(token2.c_str());
                 //std::cout << token1 << " -> " << token2 << std::endl;
                 //std::cout << array[i][0] << "  ->  " << array[i][1] << std::endl;
             }
             i = i + 1;
         }
    }


    // Prepare graph array data:
    QVector<double> x(200), y(200); // initialize (this many) vector entries
    for (int i=0; i<100; ++i)   //up to max: NUMBER_OF_WEIGHT_SAMPLES
    {
      x[i] = array[i][0];
      y[i] = array[i][1];
    }

    // create graph and assign data to it:
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    customPlot->xAxis->setLabel("Ticks [cnt]");
    customPlot->yAxis->setLabel("Weight [gr]");
    // set axes ranges, so we see all data:
    customPlot->xAxis->setRange(0,100);
    customPlot->yAxis->setRange(0, 200);

    customPlot->graph(0)->setData(x, y);
    customPlot->replot();
}




void MyGraph::run()
{

}
