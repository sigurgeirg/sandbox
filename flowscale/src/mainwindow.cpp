#include "../inc/mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_keypad.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint); // This removes the Dialog TitleBar Title and min/max/quit buttons
    ui->setupUi(this);

    QPixmap conveyorObject("../images/conveyor.png");
//    ui->FlowScaleImage->setFixedSize(480,240);
//    ui->FlowScaleImage->setPixmap(conveyorObject);

    scale = new MyScale(this);
    mosq = new MyMessages(this);

    lineEdit = new QLineEdit();
    textEdit = new QTextEdit();

    weightValueFromScale = 0;
    sampleCount = 0;
    step = 0;
    currentWorkingID = 0;
    boundary = -1;
    limits = "";

    lastSettingsFile = "";
    lastRecipeFile = "";

    gate01_enabled = true;
    gate02_enabled = true;
    gate03_enabled = true;
    gate04_enabled = true;
    gate05_enabled = true;
    gate06_enabled = true;
    gate07_enabled = true;
    gate08_enabled = true;
    gate09_enabled = true;
    gate10_enabled = true;


        // Simulation, still undone, maybe no use for this:
        //connect(this, SIGNAL(reply(unsigned char, bool)),             dio, SLOT(updateInputSim(unsigned char, bool)));

        // Data from flowscale to Display:
        connect(scale, SIGNAL(conveyorRunState(QString)),       this,   SLOT(conveyorRunStateIndicator(QString)));
        connect(scale, SIGNAL(sendDescription(QString)),        this,   SLOT(displayDescription(QString)));
        connect(scale, SIGNAL(sendBatchId(QString)),            this,   SLOT(displayBatchId(QString)));
        connect(scale, SIGNAL(sendRecipeId(QString)),           this,   SLOT(displayRecipeId(QString)));
        connect(scale, SIGNAL(sendProductId(QString)),          this,   SLOT(displayProductId(QString)));
        connect(scale, SIGNAL(sendProductType(QString)),        this,   SLOT(displayProductType(QString)));
        connect(scale, SIGNAL(sendSerialNumber(int)),           this,   SLOT(displaySerialNumber(int)));
        connect(scale, SIGNAL(sendFilteredWeight(double)),      this,   SLOT(displayFilteredWeight(double)));
        connect(scale, SIGNAL(sendConfidence(QString)),         this,   SLOT(displayConfidence(QString)));
        connect(scale, SIGNAL(sendLength(QString)),             this,   SLOT(displayLength(QString)));
        connect(scale, SIGNAL(sendDestinationGate(QString)),    this,   SLOT(displayDestinationGate(QString)));
        connect(scale, SIGNAL(bufferCount(int,QString)),        this,   SLOT(displayBufferCount(int,QString)));
        connect(scale, SIGNAL(bufferWeight(int,QString)),       this,   SLOT(displayBufferWeight(int,QString)));

        // Arm control & Enable/Disable gates by checkboxes or by count/weight.
        connect(scale, SIGNAL(enableGate(int, bool)),           this,   SLOT(enableGate(int, bool)));
        connect(scale, SIGNAL(activateGateArm(int, bool)),      this,   SLOT(activateGateArm(int, bool)));

        connect(this, SIGNAL(gate01_Closed(bool)),              scale,  SLOT(gate01_Closed(bool)));
        connect(this, SIGNAL(gate02_Closed(bool)),              scale,  SLOT(gate02_Closed(bool)));
        connect(this, SIGNAL(gate03_Closed(bool)),              scale,  SLOT(gate03_Closed(bool)));
        connect(this, SIGNAL(gate04_Closed(bool)),              scale,  SLOT(gate04_Closed(bool)));
        connect(this, SIGNAL(gate05_Closed(bool)),              scale,  SLOT(gate05_Closed(bool)));
        connect(this, SIGNAL(gate06_Closed(bool)),              scale,  SLOT(gate06_Closed(bool)));


        // Product Data Over Mosquitto transmission:
        connect(scale, SIGNAL(sendMQTT(QString,const char*)),   mosq, SLOT(sendMessage(QString,const char*)));

        // Current product values sent to Display:
        connect(scale, SIGNAL(continuousModbusWeight(int)),     this,  SLOT(displayReceivedWeight(int)));
        connect(scale, SIGNAL(continuousModbusWeight(int)),     this,  SLOT(recordWeight(int)));
        connect(scale, SIGNAL(plotData(int)),                   this,  SLOT(plotProductGraph(int)));
        connect(scale, SIGNAL(productWeight(int)),              this,  SLOT(productWeightToDisplay(int)));

        // Graph, adjust limits on display to scale graph:
        connect(this, SIGNAL(xmin(QString)),                    scale,  SLOT(xmin(QString)));
        connect(this, SIGNAL(xmax(QString)),                    scale,  SLOT(xmax(QString)));
        connect(this, SIGNAL(ymin(QString)),                    scale,  SLOT(ymin(QString)));
        connect(this, SIGNAL(ymax(QString)),                    scale,  SLOT(ymax(QString)));


    ui->tabWidget->setStyleSheet("QTabBar::tab { height: 50px; }");
    ui->frameState->setStyleSheet("background-color: red");
    ui->btnConnect->setStyleSheet("background-color: #15d015; color: white");
    ui->btnDisconnect->setStyleSheet("background-color: red; color: white");
    ui->chkWriteToLoadcell->setStyleSheet("QCheckBox::indicator { width:25px; height: 25px; }");
    ui->chkDebugWriteToFile->setStyleSheet("QCheckBox::indicator { width:25px; height: 25px; }");
    ui->cbxGate1->setStyleSheet("QCheckBox::indicator { width:25px; height: 25px; }");
    ui->cbxGate2->setStyleSheet("QCheckBox::indicator { width:25px; height: 25px; }");
    ui->cbxGate3->setStyleSheet("QCheckBox::indicator { width:25px; height: 25px; }");
    ui->cbxGate4->setStyleSheet("QCheckBox::indicator { width:25px; height: 25px; }");
    ui->cbxGate5->setStyleSheet("QCheckBox::indicator { width:25px; height: 25px; }");
    ui->cbxGate6->setStyleSheet("QCheckBox::indicator { width:25px; height: 25px; }");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scale;
    delete mosq;
}

//void MainWindow::on_btnEditCalibrationWeight_clicked()
//{
//    keypad.clearDisplay();
//    keypad.show();
//    connect(&keypad, SIGNAL(value(QString)),            this,SLOT(keyValue(QString)));
//}

void MainWindow::keyValue(QString value)
{
    Q_UNUSED( value );
//    QString str;
//    str = ui->edtCalibrationWeight->text();

//    if (value == "91") {
//        ui->edtCalibrationWeight->backspace();

//    } else if (value == "92") {
//        disconnect(&keypad, SIGNAL(value(QString)),         this,SLOT(keyValue(QString)));
//        keypad.close();

//    } else {
//        str.append(value);
//        ui->edtCalibrationWeight->setText(str);
//    }
}

void MainWindow::on_xmin_clicked()
{
    keypad.clearDisplay();
    keypad.show();
    connect(&keypad, SIGNAL(value(QString)),     this,SLOT(graphBoundaries(QString)));
    boundary = 1;
}

void MainWindow::on_xmax_clicked()
{
    keypad.clearDisplay();
    keypad.show();
    connect(&keypad, SIGNAL(value(QString)),            this,SLOT(graphBoundaries(QString)));
    boundary = 2;
}

void MainWindow::on_ymin_clicked()
{
    keypad.clearDisplay();
    keypad.show();
    connect(&keypad, SIGNAL(value(QString)),            this,SLOT(graphBoundaries(QString)));
    boundary = 3;
}

void MainWindow::on_ymax_clicked()
{
    keypad.clearDisplay();
    keypad.show();
    connect(&keypad, SIGNAL(value(QString)),            this,SLOT(graphBoundaries(QString)));
    boundary = 4;
}

void MainWindow::graphBoundaries(QString value)
{

    if (value == "91") {
//        ui->edtCalibrationWeight->backspace();

    } else if (value == "92") {
        disconnect(&keypad, SIGNAL(value(QString)),         this,SLOT(graphBoundaries(QString)));
        keypad.close();

        if (boundary == 1) {
            emit xmin(limits);
        } else if (boundary == 2) {
            emit xmax(limits);
        } else if (boundary == 3) {
            emit ymin(limits);
        } else if (boundary == 4) {
            emit ymax(limits);
        }
        boundary = -1;
        limits = "";

    } else {
        limits.append(value);
    }
}

void MainWindow::conveyorBeltSignal()
{
    // FIXME: This has to be redifined wrt types *int = bool --- change or remove
}


void MainWindow::conveyorRunStateIndicator(QString state)
{
    QString stateMessage;

    if        (state == "conveyorOff") {

        stateMessage = "Start conveyor ... Press Connect";

    } else if (state == "conveyorIdle") {

        stateMessage = "System is starting";

    } else if (state == "conveyorWarmUp") {

        stateMessage = "System is warming up";

    } else if (state == "conveyorZeroCalibration") {

        stateMessage = "System is calibrating, wait ...";

    } else if (state == "conveyorRunning") {

        stateMessage = "System is Running";
    }
    ui->lblSystemState->setText(stateMessage);


    if (state == "conveyorRunning") {

        ui->lblCountDown->setText("");
        ui->frameState->setStyleSheet("background-color: #15d015");

    } else if (state == "conveyorZeroCalibration") {

        ui->lblCountDown->setText(QString::number(numberOfBeltRounds - scale->numberOfBeltRoundsZero));
        ui->frameState->setStyleSheet("background-color: orange");

    } else {

        ui->lblCountDown->setText("");
        ui->frameState->setStyleSheet("background-color: red");

    }
}

// Record measured weight
void MainWindow::recordWeight(int weightValueFromScale)
{
    std::ofstream fout;
    QPixmap penguinObject("../images/penguin.png");

    weightValueFromScale = weightValueFromScale;
}

void MainWindow::productWeightToDisplay(int meanWeight)
{
    currentMeanWeight = meanWeight;
    ui->lblFilteredWeight->setText(QString::number(currentMeanWeight));
}



void MainWindow::plotProductGraph(int workingID)
{
    currentWorkingID = workingID;

//    ui->PenguinImage->clear();

    //ui->lblElementId->setText(QString::number(currentWorkingID));
    scale->setupPlot(ui->customPlot, currentWorkingID);
}


void MainWindow::displayReceivedWeight(int weightValueFromScale)
{
    ui->lblRawWeight->setText(QString::number(weightValueFromScale));
}

void MainWindow::displayDescription(QString description)
{
    ui->lblDescription->setText(description);
}

void MainWindow::displayBatchId(QString batchId)
{
    ui->lblBatchID->setText(batchId);
    ui->lblBatchID_2->setText(batchId);
}

void MainWindow::displayRecipeId(QString recipeId)
{
    ui->lblRecipeID->setText(recipeId);
}

void MainWindow::displayProductId(QString productId)
{
    ui->lblProductID->setText(productId);
}

void MainWindow::displayProductType(QString productType)
{
    Q_UNUSED( productType );
}

void MainWindow::displaySerialNumber(int serialNumber)
{
    ui->lblSerialNumber->setText(QString::number(serialNumber));
    ui->lblSerialNumber_2->setText(QString::number(serialNumber));
    ui->lblElementId->setText(QString::number(serialNumber));
}

void MainWindow::displayFilteredWeight(double filteredWeight)
{
    ui->lblProductWeight->setText(QString::number(filteredWeight));
    ui->lblProductWeight_2->setText(QString::number(filteredWeight));
    ui->lblFilteredWeight->setText(QString::number(filteredWeight));
}

void MainWindow::displayConfidence(QString confidence)
{
    ui->lblWeightConfidence->setText(confidence);
}

void MainWindow::displayLength(QString length)
{
    ui->lblLength->setText(length);
}

void MainWindow::displayDestinationGate(QString destinationGate)
{
    ui->lblDestinationGate->setText(destinationGate);
    ui->lblDestinationGate_2->setText(destinationGate);
}

void MainWindow::displayBufferCount(int gate, QString bufferCount)
{
    if (gate == 1) { ui->lblBCnt1->setText(bufferCount);}
    if (gate == 2) { ui->lblBCnt2->setText(bufferCount);}
    if (gate == 3) { ui->lblBCnt3->setText(bufferCount);}
    if (gate == 4) { ui->lblBCnt4->setText(bufferCount);}
    if (gate == 5) { ui->lblBCnt5->setText(bufferCount);}
    if (gate == 6) { ui->lblBCnt6->setText(bufferCount);}
}

void MainWindow::displayBufferWeight(int gate, QString bufferWeight)
{
    if (gate == 1) { ui->lblBWgt1->setText(bufferWeight);}
    if (gate == 2) { ui->lblBWgt2->setText(bufferWeight);}
    if (gate == 3) { ui->lblBWgt3->setText(bufferWeight);}
    if (gate == 4) { ui->lblBWgt4->setText(bufferWeight);}
    if (gate == 5) { ui->lblBWgt5->setText(bufferWeight);}
    if (gate == 6) { ui->lblBWgt6->setText(bufferWeight);}
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
//    ui->lblDIN_01->setText(QString::number(dio->value[0]));
//    ui->lblDIN_02->setText(QString::number(dio->value[1]));
//    ui->lblDIN_03->setText(QString::number(dio->value[2]));
//    ui->lblDIN_04->setText(QString::number(dio->value[3]));

    // /////////////////////////
    // Simulation
//    ui->lblDIN_01->setText(QString::number(io.DIGet(0)));
//    ui->lblDIN_02->setText(QString::number(io.DIGet(1)));
//    ui->lblDIN_03->setText(QString::number(io.DIGet(2)));
//    ui->lblDIN_04->setText(QString::number(io.DIGet(3)));
    // /////////////////////////

//    ui->lblDOUT_01->setText(QString::number(io.DOGet(0)));
//    ui->lblDOUT_02->setText(QString::number(io.DOGet(1)));
//    ui->lblDOUT_03->setText(QString::number(io.DOGet(2)));
//    ui->lblDOUT_04->setText(QString::number(io.DOGet(3)));

}

//void MainWindow::on_btnConnect_clicked()
//{
//    scale->connectToSlaveDevice();
//    scale->start();
//}


void MainWindow::on_btnConnect_clicked()
{
    // Switch to netto weight and write to loadCell controller:
    scale->netWeight();
    scale->toggleWriteToLoadcell(true);

    // Connect over modbus and start processes:
    scale->connectToSlaveDevice();
    scale->start();

    usleep(20*1000);

    // Disconnect from modbus and stop processes:
    scale->disconnectFromSlaveDevice();
    scale->exit();

    usleep(20*1000);

    // From now on, only read from loadCell controller:
    scale->toggleWriteToLoadcell(false);

    // Connect over modbus and start processes again:
    scale->connectToSlaveDevice();
    scale->start();
}

void MainWindow::on_btnDisconnect_clicked()
{
    scale->disconnectFromSlaveDevice();
    scale->exit();
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
    scale->calibrateWEIGHT();
}

//void MainWindow::on_btnSemiAutoZERO_clicked()
//{
//    scale->semiAutoZERO();
//}

//void MainWindow::on_btnGrossWeight_clicked()
//{
//    scale->grossWeight();
//}

//void MainWindow::on_btnNetWeight_clicked()
//{
//    scale->netWeight();
//}

void MainWindow::activateGateArm(int gate, bool value)
{
    if (this->gate01_enabled == true) {
        if (gate == 1) {
            if (value == true)  { ui->cbxGate1->setStyleSheet("color: #15d015"); }
            else                { ui->cbxGate1->setStyleSheet("color: black");   }
        }
    }

    if (this->gate02_enabled == true) {
        if (gate == 2) {
            if (value == true)  { ui->cbxGate2->setStyleSheet("color: #15d015"); }
            else                { ui->cbxGate2->setStyleSheet("color: black");   }
        }
    }

    if (this->gate03_enabled == true) {
        if (gate == 3) {
            if (value == true)  { ui->cbxGate3->setStyleSheet("color: #15d015"); }
            else                { ui->cbxGate3->setStyleSheet("color: black");   }
        }
    }

    if (this->gate04_enabled == true) {
        if (gate == 4) {
            if (value == true)  { ui->cbxGate4->setStyleSheet("color: #15d015"); }
            else                { ui->cbxGate4->setStyleSheet("color: black");   }
        }
    }

    if (this->gate05_enabled == true) {
        if (gate == 5) {
            if (value == true)  { ui->cbxGate5->setStyleSheet("color: #15d015"); }
            else                { ui->cbxGate5->setStyleSheet("color: black");   }
        }
    }

    if (this->gate06_enabled == true) {
        if (gate == 6)  {
            if (value == true)  { ui->cbxGate6->setStyleSheet("color: #15d015"); }
            else                { ui->cbxGate6->setStyleSheet("color: black");   }
        }
    }
}

// FIXME: Nota serialnumber frekar en currentWorkingID
void MainWindow::on_btnReverse_clicked()
{
    if (currentWorkingID > 0) {
        currentWorkingID--;
    } else {
        currentWorkingID = numberOfElementsInList-1;
    }

    ui->lblElementId->setText(QString::number(currentWorkingID));
    scale->setupPlot(ui->customPlot, currentWorkingID);
}

// FIXME: Nota serialnumber frekar en currentWorkingID
void MainWindow::on_btnForward_clicked()
{
    if (currentWorkingID >= numberOfElementsInList-1) {
        currentWorkingID = 0;
    } else {
        currentWorkingID++;
    }

    ui->lblElementId->setText(QString::number(currentWorkingID));
    scale->setupPlot(ui->customPlot, currentWorkingID);
}



void MainWindow::on_btnRefreshRecipeList_clicked()
{
    QStringList filters;
    QFileInfoList files;
    QDir dir("recipes");

    filters << "*.csv";
    dir.setFilter(QDir::Files | QDir::NoSymLinks);
    dir.setNameFilters(filters);

    files = dir.entryInfoList();

    ui->cbRecipeMenu->clear();

    foreach (QFileInfo file, files) {

        ui->cbRecipeMenu->addItem(file.fileName());
    }
}
//on_cbRecipeMenu_currentIndexChanged(const QString &arg1)
void MainWindow::on_cbRecipeMenu_activated(const QString &arg1)
{
    Q_UNUSED( arg1 );

    recipeFile = ui->cbRecipeMenu->currentText();
    recipeFileFullPath = "recipes/" + recipeFile;
    QFile importRecipeCSV(recipeFileFullPath);


    if (recipeFile != lastRecipeFile) {

        recipeData.clear();
        rowOfRecipeData.clear();
        rowRecipeData.clear();

        if (importRecipeCSV.open(QFile::ReadOnly)) {

            recipeData = importRecipeCSV.readAll();
            rowOfRecipeData = recipeData.split("\n");
            importRecipeCSV.close();
        }


        for (int x = 0; x < rowOfRecipeData.size(); x++)
        {
            rowRecipeData = rowOfRecipeData.at(x).split(";");

            for (int y = 0; y < rowRecipeData.size(); y++)
            {
                ui->recipeTable->setItem(x,y,new QTableWidgetItem(rowRecipeData[y]));
            }
        }
    }
    lastRecipeFile = recipeFile;

    ui->recipeTable->setColumnCount(4);
    ui->recipeTable->setRowCount(rowOfRecipeData.size());

    ui->recipeTable->setColumnWidth(0,200);
    ui->recipeTable->setColumnWidth(1,100);
    ui->recipeTable->setColumnWidth(2,100);
    ui->recipeTable->setColumnWidth(3,100);

    scale->updateRecipe(recipeFileFullPath);
}


void MainWindow::on_btnRefreshSettingsList_clicked()
{
    QStringList filters;
    QFileInfoList files;
    QDir dir("settings");

    filters << "*.csv";
    dir.setFilter(QDir::Files | QDir::NoSymLinks);
    dir.setNameFilters(filters);

    files = dir.entryInfoList();

    ui->cbSettingsMenu->clear();

    foreach (QFileInfo file, files) {

        ui->cbSettingsMenu->addItem(file.fileName());
    }
}

void MainWindow::on_cbSettingsMenu_activated(const QString &arg1)
{
    Q_UNUSED( arg1 );

    ui->settingsTable->setColumnCount(2);
    ui->settingsTable->setRowCount(rowOfSettingsData.size());

    ui->settingsTable->setColumnWidth(0,300);
    ui->settingsTable->setColumnWidth(1,100);


    SettingsFileName = ui->cbSettingsMenu->currentText();
    SettingsFile = "settings/" + SettingsFileName;
    QFile importSettingsCSV(SettingsFile);

//    if (SettingsFile != lastSettingsFile) {

        settingsData.clear();
        rowOfSettingsData.clear();
        rowSettingsData.clear();

        if (importSettingsCSV.open(QFile::ReadOnly)) {

            settingsData = importSettingsCSV.readAll();
            rowOfSettingsData = settingsData.split("\n");
            importSettingsCSV.close();
        }

        for (int x = 0; x < rowOfSettingsData.size(); x++)
        {
            rowSettingsData = rowOfSettingsData.at(x).split(";");

            for (int y = 0; y < rowSettingsData.size(); y++)
            {
                ui->settingsTable->setItem(x,y,new QTableWidgetItem(rowSettingsData[y]));
            }
        }
//    }

//    lastSettingsFile = SettingsFile;

}


void MainWindow::enableGate(int gate, bool enabled)
{
    if (gate == 1) {
        if (enabled == true)    { ui->cbxGate1->setChecked(false); ui->cbxGate1->setStyleSheet("color: black"); this->gate01_enabled = true;
                                  ui->lblBCnt1->setText("0");      ui->lblBWgt1->setText("0");}
        else                    { ui->cbxGate1->setChecked(true);  ui->cbxGate1->setStyleSheet("color: red");   this->gate01_enabled = false; }
    }

    if (gate == 2) {
        if (enabled == true)    { ui->cbxGate2->setChecked(false); ui->cbxGate2->setStyleSheet("color: black"); this->gate02_enabled = true;
                                  ui->lblBCnt2->setText("0");      ui->lblBWgt2->setText("0");}
        else                    { ui->cbxGate2->setChecked(true);  ui->cbxGate2->setStyleSheet("color: red");   this->gate02_enabled = false; }
    }

    if (gate == 3) {
        if (enabled == true)    { ui->cbxGate3->setChecked(false); ui->cbxGate3->setStyleSheet("color: black"); this->gate03_enabled = true;
                                  ui->lblBCnt3->setText("0");      ui->lblBWgt3->setText("0");}
        else                    { ui->cbxGate3->setChecked(true);  ui->cbxGate3->setStyleSheet("color: red");   this->gate03_enabled = false; }
    }

    if (gate == 4) {
        if (enabled == true)    { ui->cbxGate4->setChecked(false); ui->cbxGate4->setStyleSheet("color: black"); this->gate04_enabled = true;
                                  ui->lblBCnt4->setText("0");      ui->lblBWgt4->setText("0");}
        else                    { ui->cbxGate4->setChecked(true);  ui->cbxGate4->setStyleSheet("color: red");   this->gate04_enabled = false; }
    }
    if (gate == 5) {
        if (enabled == true)    { ui->cbxGate5->setChecked(false); ui->cbxGate5->setStyleSheet("color: black"); this->gate05_enabled = true;
                                  ui->lblBCnt5->setText("0");      ui->lblBWgt5->setText("0");}
        else                    { ui->cbxGate5->setChecked(true);  ui->cbxGate5->setStyleSheet("color: red");   this->gate05_enabled = false; }
    }

    if (gate == 6) {
        if (enabled == true)    { ui->cbxGate6->setChecked(false); ui->cbxGate6->setStyleSheet("color: black"); this->gate06_enabled = true;
                                  ui->lblBCnt6->setText("0");      ui->lblBWgt6->setText("0");}
        else                    { ui->cbxGate6->setChecked(true);  ui->cbxGate6->setStyleSheet("color: red");   this->gate06_enabled = false; }
    }
}



void MainWindow::on_cbxGate1_clicked(bool state)
{
    emit gate01_Closed(state);
}

void MainWindow::on_cbxGate2_clicked(bool state)
{
    emit gate02_Closed(state);
}

void MainWindow::on_cbxGate3_clicked(bool state)
{
    emit gate03_Closed(state);
}

void MainWindow::on_cbxGate4_clicked(bool state)
{
    emit gate04_Closed(state);
}

void MainWindow::on_cbxGate5_clicked(bool state)
{
    emit gate05_Closed(state);
}

void MainWindow::on_cbxGate6_clicked(bool state)
{
    emit gate06_Closed(state);
}

void MainWindow::on_btnCloseBatch_clicked()
{
    scale->writeBufferDataToFile();

    ui->lblBCnt1->setText("0");
    ui->lblBCnt2->setText("0");
    ui->lblBCnt3->setText("0");
    ui->lblBCnt4->setText("0");
    ui->lblBCnt5->setText("0");
    ui->lblBCnt6->setText("0");

    ui->lblBWgt1->setText("0");
    ui->lblBWgt2->setText("0");
    ui->lblBWgt3->setText("0");
    ui->lblBWgt4->setText("0");
    ui->lblBWgt5->setText("0");
    ui->lblBWgt6->setText("0");

    ui->cbxGate1->setChecked(false);
    ui->cbxGate2->setChecked(false);
    ui->cbxGate3->setChecked(false);
    ui->cbxGate4->setChecked(false);
    ui->cbxGate5->setChecked(false);
    ui->cbxGate6->setChecked(false);

    ui->cbxGate1->setStyleSheet("color: black");
    ui->cbxGate2->setStyleSheet("color: black");
    ui->cbxGate3->setStyleSheet("color: black");
    ui->cbxGate4->setStyleSheet("color: black");
    ui->cbxGate5->setStyleSheet("color: black");
    ui->cbxGate6->setStyleSheet("color: black");

    this->gate01_enabled = true;
    this->gate02_enabled = true;
    this->gate03_enabled = true;
    this->gate04_enabled = true;
    this->gate05_enabled = true;
    this->gate06_enabled = true;

    emit gate01_Closed(false);
    emit gate02_Closed(false);
    emit gate03_Closed(false);
    emit gate04_Closed(false);
    emit gate05_Closed(false);
    emit gate06_Closed(false);
}

void MainWindow::on_chkDebugWriteToFile_clicked(bool checked)
{
    scale->debug = checked;
}
