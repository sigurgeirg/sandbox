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
    ui->FlowScaleImage->setFixedSize(480,240);
    ui->FlowScaleImage->setPixmap(conveyorObject);

    scale = new MyScale(this);
    dio = new MyDio(this);
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


    // ZERO Filtering:

        // FIXME:This next line should be deleted when this part has been implemented inside of the scale class.
        //connect(scale, SIGNAL(receivedWeight(int)),           scale, SLOT(modelZeroWeight(int)));
        connect(dio,   SIGNAL(conveyorSignal()),                scale,  SLOT(conveyorBeltSignal()));
        connect(dio,   SIGNAL(enteringProductSensorSignal()),   scale,  SLOT(enteringProductSensorSignal()));
        connect(dio,   SIGNAL(leavingProductSensorSignal()),    scale,  SLOT(leavingProductSensorSignal()));

        connect(scale, SIGNAL(sendDescription(QString)),        this,   SLOT(displayDescription(QString)));
        connect(scale, SIGNAL(sendFilteredWeight(int)),         this,   SLOT(displayFilteredWeight(int)));
        connect(scale, SIGNAL(sendSerialNumber(int)),           this,   SLOT(displaySerialNumber(int)));
        connect(scale, SIGNAL(sendBatchId(QString)),            this,   SLOT(displayBatchId(QString)));
        connect(scale, SIGNAL(sendRecipeId(QString)),           this,   SLOT(displayRecipeId(QString)));
        connect(scale, SIGNAL(sendProductId(QString)),          this,   SLOT(displayProductId(QString)));
        connect(scale, SIGNAL(sendProductType(QString)),        this,   SLOT(displayProductType(QString)));
        connect(scale, SIGNAL(sendConfidence(QString)),         this,   SLOT(displayConfidence(QString)));
        connect(scale, SIGNAL(sendLength(QString)),             this,   SLOT(displayLength(QString)));
        connect(scale, SIGNAL(sendDestinationGate(QString)),    this,   SLOT(displayDestinationGate(QString)));
        connect(scale, SIGNAL(conveyorRunState(QString)),       this,   SLOT(conveyorRunStateIndicator(QString)));

        connect(this, SIGNAL(xmin(QString)),                    scale,  SLOT(xmin(QString)));
        connect(this, SIGNAL(xmax(QString)),                    scale,  SLOT(xmax(QString)));
        connect(this, SIGNAL(ymin(QString)),                    scale,  SLOT(ymin(QString)));
        connect(this, SIGNAL(ymax(QString)),                    scale,  SLOT(ymax(QString)));

        //connect(this, SIGNAL(setCurrentRecipe(QString)),        scale,  SLOT(updateRecipe(QString)));

        //This is the output array from zerofilter, and it will be sent to destination when ready.
        //connect(zero, SIGNAL(filteredZeroArray(int)),         this, SLOT(givethisnewnameandcreatefunction(int)));

    // Show live weight on display (FIXME see below):
        connect(scale, SIGNAL(receivedWeight(int)),            this, SLOT(displayReceivedWeight(int)));

    // Collect live weight to a csv-file:
        connect(scale, SIGNAL(receivedWeight(int)),             this, SLOT(recordWeight(int)));


        connect(scale, SIGNAL(plotData(int)),                   this,  SLOT(plotProductGraph(int)));
        connect(scale, SIGNAL(plotWeight(int)),                 this,  SLOT(plotProductWeight(int)));

    // Return avg weight to next component:
        connect(this, SIGNAL(avgWeight(int)),                   mosq, SLOT(processReceivedWeight(int)));

    // Read from physical inputs and write to physical outputs:
        connect(dio,   SIGNAL(inputValue(unsigned long)),   this, SLOT(displayInputValue(unsigned long)));

    // Read from physcial input from inductive metal sensor, increments for each beltround:
        //connect(dio,   SIGNAL(conveyorSignal()),  scale, SLOT(conveyorBeltCounter()));

    // Tick is calculated from number of ticks per beltround therefore no need for physical signal:
        //connect(dio,   SIGNAL(tachoSignal(unsigned long)),  this, SLOT(displayTachoCount(unsigned long)));

    // Simulation, still undone, maybe no use for this:
        //connect(this, SIGNAL(reply(unsigned char, bool)),             dio, SLOT(updateInputSim(unsigned char, bool)));

    ui->frameState->setStyleSheet("background-color: red");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scale;
    delete dio;
    delete mosq;
}

void MainWindow::on_btnEditCalibrationWeight_clicked()
{
    keypad.clearDisplay();
    keypad.show();
    connect(&keypad, SIGNAL(value(QString)),            this,SLOT(keyValue(QString)));
}

void MainWindow::keyValue(QString value)
{
    QString str;
    str = ui->edtCalibrationWeight->text();

    if (value == "91") {
        ui->edtCalibrationWeight->backspace();

    } else if (value == "92") {
        disconnect(&keypad, SIGNAL(value(QString)),         this,SLOT(keyValue(QString)));
        keypad.close();

    } else {
        str.append(value);
        ui->edtCalibrationWeight->setText(str);
    }
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
        ui->edtCalibrationWeight->backspace();

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
    // FIXME: This has to be redifined wrt types *int = bool --- change or remote
}


void MainWindow::conveyorRunStateIndicator(QString state)
{
    QString stateMessage;

    if        (state == "conveyorOff") {

        stateMessage = "Start conveyor to full speed, then press Connect";

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

void MainWindow::plotProductWeight(int meanWeight)
{
    currentMeanWeight = meanWeight;
    ui->lblFilteredWeight->setText(QString::number(currentMeanWeight));
}



void MainWindow::plotProductGraph(int workingID)
{
    currentWorkingID = workingID;

    ui->PenguinImage->clear();

    //ui->lblElementId->setText(QString::number(currentWorkingID));
    scale->setupPlot(ui->customPlot, currentWorkingID);
}


void MainWindow::displayReceivedWeight(int weightValueFromScale)
{
    ui->lblReceivedWeight->setText(QString::number(weightValueFromScale));
    ui->lblRawWeight->setText(QString::number(weightValueFromScale));
}

void MainWindow::displayFilteredWeight(int filteredWeight)
{
    ui->lblReceivedWeight_2->setText(QString::number(filteredWeight));
    ui->lblProductWeight->setText(QString::number(filteredWeight));
    ui->lblFilteredWeight->setText(QString::number(filteredWeight));
}

void MainWindow::displaySerialNumber(int serialNumber)
{
    ui->lblReceivedWeight_3->setText(QString::number(serialNumber));
    ui->lblSerialNumber->setText(QString::number(serialNumber));
    ui->lblElementId->setText(QString::number(serialNumber));
}

void MainWindow::displayDescription(QString description)
{
    ui->lblDescription->setText(description);
}

void MainWindow::displayBatchId(QString batchId)
{
    ui->lblBatchID->setText(batchId);
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

void MainWindow::on_btnNetWeightConnect_clicked()
{
    // Switch to netto weight and write to loadCell controller:
    scale->netWeight();
    scale->toggleWriteToLoadcell(true);

    // Connect over modbus and start processes:
    scale->connectToSlaveDevice();
    scale->start();
    dio->start();

    usleep(20*1000);

    // Disconnect from modbus and stop processes:
    scale->disconnectFromSlaveDevice();
    scale->exit();
    dio->exit();

    usleep(20*1000);

    // From now on, only read from loadCell controller:
    scale->toggleWriteToLoadcell(false);

    // Connect over modbus and start processes again:
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
