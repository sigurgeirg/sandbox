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
    zero = new Zerofilter(this);
    dio = new MyDio(this);
    graph = new MyGraph(this);
    mosq = new MyMessages(this);
    numberOfBeltRounds = new int;

    weightValueFromScale = 0;
    sampleCount = 0;
    step = 0;


    // ZERO Filtering:
        connect(scale, SIGNAL(receivedWeight(int)),         zero, SLOT(recordZeroWeight(int)));
        connect(dio,   SIGNAL(conveyorSignal()),            zero, SLOT(conveyorBeltCounter()));

        //This is the output array from zerofilter, and it will be sent to destination when ready.
        //connect(zero, SIGNAL(filteredZeroArray(int)),         this, SLOT(givethisnewnameandcreatefunction(int)));

    // Show live weight on display (FIXME see below):
        connect(scale, SIGNAL(receivedWeight(int)),         this, SLOT(displayReceivedWeight(int)));

    // Collect live weight to a csv-file:
        connect(scale, SIGNAL(receivedWeight(int)),         this, SLOT(recordWeight(int)));

    // Return avg weight to next component:
        connect(this, SIGNAL(avgWeight(int)),               mosq, SLOT(processReceivedWeight(int)));

    // Read from physical inputs and write to physical outputs:
        connect(dio,   SIGNAL(inputValue(unsigned long)),   this, SLOT(displayInputValue(unsigned long)));

    // Read from physcial input from inductive metal sensor, increments for each beltround:
        connect(dio,   SIGNAL(conveyorSignal()),  this, SLOT(conveyorBeltCounter()));

    // Tick is calculated from number of ticks per beltround therefore no need for physical signal:
        //connect(dio,   SIGNAL(tachoSignal(unsigned long)),  this, SLOT(displayTachoCount(unsigned long)));

    // Simulation, still undone, maybe no use for this:
        //connect(this, SIGNAL(reply(unsigned char, bool)),             dio, SLOT(updateInputSim(unsigned char, bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scale;
    delete dio;
    delete graph;
    delete mosq;
    delete numberOfBeltRounds;
}

void MainWindow::conveyorBeltCounter()
{
    // FIXME: This has to be redifined wrt types *int = bool --- change or remote
    //*numberOfBeltRounds = beltRoundCounter;
}


// Record measured weight
void MainWindow::recordWeight(int weightValueFromScale)
{
    std::ofstream fout;
    QPixmap penguinObject("../images/penguin.png");

    weightValueFromScale = weightValueFromScale;

    // Commented out due to issues with streaming into two files at the same time
    /*

    // //////////////////////////////////
    // stream to file
    if (sampleCount < 1000000){
        fout.open("weight.csv", std::ofstream::out | std::ofstream::app); // trunc changed to app, trunc clears the file while app appends it
        if (fout.is_open())
        {
            fout << *numberOfBeltRounds  << "," <<  sampleCount << "," << weightValueFromScale << std::endl;
            sampleCount = sampleCount + 1;


        }
        fout.close();
    }
    */
    // ////////////////////////////////////





    /*
    if ( weightValueFromScale < 50 && step == 0)
    {

        qDebug() << "Step 0 ";
        step = 1;
        counter = 0;

    }
    else if ( step == 1)
    {
        if ( weightValueFromScale > 50 && counter < NUMBER_OF_WEIGHT_SAMPLES)
        {
            ui->PenguinImage->setGeometry(300,50,80,96);
            ui->PenguinImage->setPixmap(penguinObject);

            array[counter][0] = counter + 1;
            array[counter][1] = weightValueFromScale;

            counter = counter + 1;

        }
        else if ( weightValueFromScale <= 50 && counter > 1 )
        {
            step = 2;
            qDebug() << "Step 1 ";
        }

    }
    else if( weightValueFromScale < 50 && step == 2 )
    {
        qDebug() << "Step 2 ";

        fout.open("weight.csv", std::ofstream::out | std::ofstream::trunc);

        if (fout.is_open())
        {
            for (int i=0; i < counter; i++)
            {
                //qDebug() << "Counter: " << counter << "   -    WeightFromScale: " << weightValueFromScale;
                fout << array[i][0] << "," << array[i][1] << std::endl;

            }
            if (counter < 200)
            {
                for (int k = counter; k <= 200; k++)
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

        step = 3;

    }
    else if ( step == 3 ) {

        // with sensor to trigger weight reading - not active now
        if ( dio->value[5] == 0 ) {
            step = 0;
        }
        // without any sensor to trigger weight reading, using only threshold - active now
        step = 0;


    }
    */
}


void MainWindow::displayReceivedWeight(int weightValueFromScale)
{
    // /////////////////////////////////////////////////////////////////////////////////////////////
    // FIXME: This part might possibly put some load on the CPU, haven't checked although,
    // but it can either be opt'ed out for debugging or removed completely
    // /////////////////////////////////////////////////////////////////////////////////////////////

    weightValueFromScale = weightValueFromScale;
    ui->lblReceivedWeight->setText(QString::number(weightValueFromScale));

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
    zero->start();
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

