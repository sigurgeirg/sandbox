#include "../inc/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint); // This removes the Dialog TitleBar Title and min/max/quit buttons
    ui->setupUi(this);

    QPixmap conveyorObject("../images/conveyor.png");
    ui->FlowScaleImage->setFixedSize(480,240);
    ui->FlowScaleImage->setPixmap(conveyorObject);


    scale = new MyScale(this);
    dio = new MyDio(this);
    graph = new MyGraph(this);
    mosq = new MyMessages(this);

    _weightValueFromScale = 0;
    _counter = 0;
    _step = 0;


    connect(scale, SIGNAL(receivedWeight(int)),         this, SLOT(displayReceivedWeight(int)));
    connect(this, SIGNAL(avgWeight(int)),               mosq, SLOT(processReceivedWeight(int)));
    connect(scale, SIGNAL(receivedWeight(int)),         this, SLOT(recordWeight(int)));
    connect(dio,   SIGNAL(inputValue(unsigned long)),   this, SLOT(displayInputValue(unsigned long)));
    //connect(dio,   SIGNAL(tachoSignal(unsigned long)),  this, SLOT(displayTachoCount(unsigned long)));

    // /////////////////////////
    // Simulation
//    connect(this, SIGNAL(reply(unsigned char, bool)),             dio, SLOT(updateInputSim(unsigned char, bool)));
    // /////////////////////////
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scale;
    delete dio;
    delete graph;
    delete mosq;
}

//Record measured weight
void MainWindow::recordWeight(int weightValueFromScale)
{
    std::ofstream fout;

    QPixmap penguinObject("../images/penguin.png");

    _weightValueFromScale = weightValueFromScale;

    if ( _weightValueFromScale < 50 && _step == 0)
    {

        qDebug() << "Step 0 ";
        _step = 1;
        _counter = 0;

    }
    else if ( _step == 1)
    {
        if ( _weightValueFromScale > 50 && _counter < NUMBER_OF_WEIGHT_SAMPLES)
        {
            ui->PenguinImage->setGeometry(300,50,80,96);
            ui->PenguinImage->setPixmap(penguinObject);

            array[_counter][0] = _counter + 1;
            array[_counter][1] = _weightValueFromScale;

            _counter = _counter + 1;

        }
        else if ( _weightValueFromScale <= 50 && _counter > 1 )
        {
            _step = 2;
            qDebug() << "Step 1 ";
        }

    }
    else if( _weightValueFromScale < 50 && _step == 2 )
    {
        qDebug() << "Step 2 ";

        fout.open("weight.csv", std::ofstream::out | std::ofstream::trunc);

        if (fout.is_open())
        {
            for (int i=0; i < _counter; i++)
            {
                //qDebug() << "Counter: " << _counter << "   -    WeightFromScale: " << _weightValueFromScale;
                fout << array[i][0] << "," << array[i][1] << std::endl;

            }
            if (_counter < 200)
            {
                for (int k = _counter; k <= 200; k++)
                {
                    array[k][1] = 0;
                    fout << array[k][0] << "," << array[k][1] << std::endl;
                }
            }

        }
        fout.close();

        ui->PenguinImage->clear();

        graph->setupPlot(ui->customPlot);

        int sumWeight, averageWeight, entryPosition, exitPosition;
        sumWeight = 0;
        averageWeight = 0;
        entryPosition = 30;
        exitPosition = 50;

        for (int i =  entryPosition; i < exitPosition; i++)
        {
            sumWeight = sumWeight + array[i][1];
        }
        averageWeight = sumWeight / (exitPosition - entryPosition);
        emit avgWeight(averageWeight);
        ui->lblFilteredWeight->setText(QString::number(averageWeight));

        _step = 3;

    }
    else if ( _step == 3 ) {

        // with sensor to trigger weight reading - not active now
        if ( dio->value[5] == 0 ) {
            _step = 0;
        }
        // without any sensor to trigger weight reading, using only threshold - active now
        _step = 0;


    }
}


void MainWindow::displayReceivedWeight(int weightValueFromScale)
{
    _weightValueFromScale = weightValueFromScale;
    ui->lblReceivedWeight->setText(QString::number(_weightValueFromScale));

}

// /////////////////////////
// Simulation
//void MainWindow::on_chkDIN_01_clicked() {
//    emit reply(0, ui->chkDIN_01->isChecked());
//}

//void MainWindow::on_chkDIN_02_clicked() {
//    emit reply(1, ui->chkDIN_02->isChecked());
//}

//void MainWindow::on_chkDIN_03_clicked() {
//    emit reply(2, ui->chkDIN_03->isChecked());
//}

//void MainWindow::on_chkDIN_04_clicked() {
//    emit reply(3, ui->chkDIN_04->isChecked());
//}
// /////////////////////////

void MainWindow::displayInputValue(unsigned long)
{
    //Fixme: Real IO module
    ui->lblDIN_01->setText(QString::number(dio->value[0]));
    ui->lblDIN_02->setText(QString::number(dio->value[1]));
    ui->lblDIN_03->setText(QString::number(dio->value[2]));
    ui->lblDIN_04->setText(QString::number(dio->value[3]));

    // /////////////////////////
    // Simulation
//    ui->lblDIN_01->setText(QString::number(io.DIGet(0)));
//    ui->lblDIN_02->setText(QString::number(io.DIGet(1)));
//    ui->lblDIN_03->setText(QString::number(io.DIGet(2)));
//    ui->lblDIN_04->setText(QString::number(io.DIGet(3)));
    // /////////////////////////

    ui->lblDOUT_01->setText(QString::number(io.DOGet(0)));
    ui->lblDOUT_02->setText(QString::number(io.DOGet(1)));
    ui->lblDOUT_03->setText(QString::number(io.DOGet(2)));
    ui->lblDOUT_04->setText(QString::number(io.DOGet(3)));

}

void MainWindow::on_btnConnect_clicked()
{
    scale->connectToSlaveDevice();
    scale->start();
    dio->start();
}

void MainWindow::on_btnDisconnect_clicked()
{
    scale->disconnectFromSlaveDevice();
    scale->exit();
    dio->exit();
}

void MainWindow::on_chkWriteToLoadcell_toggled(bool checked)
{
    scale->toggleWriteToLoadcell(checked);
}

void MainWindow::on_btnCalibrateZERO_clicked()
{
    scale->calibrateZERO();
}

void MainWindow::on_btnCalibrateWEIGHT_clicked()
{
    scale->calibrateWEIGHT( ui->edtCalibrationWeight->text().toInt() );
}

void MainWindow::on_btnAPPLY_clicked()
{
    scale->storeCalibrationWEIGHT();
}

void MainWindow::on_btnSemiAutoZERO_clicked()
{
    scale->semiAutoZERO();
}

void MainWindow::on_btnGrossWeight_clicked()
{
    scale->grossWeight();
}

void MainWindow::on_btnNetWeight_clicked()
{
    scale->netWeight();
}

