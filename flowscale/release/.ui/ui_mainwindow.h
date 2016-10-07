/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <../QCustomPlot/qcustomplot.h>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame_2;
    QTabWidget *tabWidget;
    QWidget *tabHome;
    QFrame *receiveFrame;
    QLabel *lblReceivedWeight;
    QLabel *lblWeight;
    QFrame *receiveFrame_3;
    QLabel *lblReceivedWeight_3;
    QLabel *lblWeight_3;
    QFrame *receiveFrame_2;
    QLabel *lblReceivedWeight_2;
    QLabel *lblWeight_2;
    QPushButton *btnNetWeightConnect;
    QPushButton *btnDisconnect;
    QWidget *tabCalibrate;
    QFrame *transmitFrame;
    QLineEdit *edtCalibrationWeight;
    QPushButton *btnCalibrateZERO;
    QPushButton *btnCalibrateWEIGHT;
    QPushButton *btnAPPLY;
    QPushButton *btnSaveToEEPROM;
    QLabel *label;
    QPushButton *btnEditCalibrationWeight;
    QCheckBox *chkWriteToLoadcell;
    QFrame *frame;
    QPushButton *btnGrossWeight;
    QPushButton *btnNetWeight;
    QPushButton *btnSemiAutoZERO;
    QLabel *lblCommands;
    QPushButton *btnDisconnect_2;
    QPushButton *btnConnect;
    QWidget *tabGraph;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QFrame *frame_4;
    QCustomPlot *customPlot;
    QLabel *lblFilteredWeight;
    QPushButton *btnForward;
    QPushButton *btnReverse;
    QLabel *lblElementId;
    QPushButton *ymax;
    QPushButton *ymin;
    QPushButton *xmin;
    QPushButton *xmax;
    QWidget *tabSettings;
    QComboBox *cbSettingsMenu;
    QPushButton *btnRefreshSettingsList;
    QTableWidget *settingsTable;
    QWidget *tabRecipe;
    QPushButton *btnRefreshRecipeList;
    QComboBox *cbRecipeMenu;
    QTableWidget *recipeTable;
    QWidget *tabDio;
    QWidget *layoutWidget_1;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *chkDIN_03;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_6;
    QLabel *lblDIN_03;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_7;
    QLabel *lblDOUT_03;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *chkDIN_04;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_8;
    QLabel *lblDIN_04;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_9;
    QLabel *lblDOUT_04;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout;
    QCheckBox *chkDIN_01;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLabel *lblDIN_01;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QLabel *lblDOUT_01;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *chkDIN_02;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QLabel *lblDIN_02;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_5;
    QLabel *lblDOUT_02;
    QWidget *tabStuff;
    QLabel *PenguinImage;
    QLabel *FlowScaleImage;
    QFrame *frame_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QPalette palette;
        QBrush brush(QColor(115, 115, 115, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        MainWindow->setPalette(palette);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(115, 115, 115);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(110, 30, 661, 531));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 135, 223);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        tabWidget = new QTabWidget(frame_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(20, 50, 621, 391));
        QPalette palette1;
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        QBrush brush2(QColor(100, 135, 223, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        QBrush brush3(QColor(253, 254, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush3);
        QBrush brush4(QColor(195, 216, 248, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush4);
        QBrush brush5(QColor(68, 89, 121, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush5);
        QBrush brush6(QColor(91, 119, 161, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        QBrush brush7(QColor(255, 255, 255, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush7);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        QBrush brush8(QColor(196, 217, 248, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush8);
        QBrush brush9(QColor(255, 255, 220, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        QBrush brush10(QColor(137, 179, 242, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        tabWidget->setPalette(palette1);
        QFont font;
        font.setPointSize(14);
        font.setBold(false);
        font.setWeight(50);
        tabWidget->setFont(font);
        tabWidget->setFocusPolicy(Qt::ClickFocus);
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 135, 223);"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(16, 16));
        tabWidget->setElideMode(Qt::ElideNone);
        tabHome = new QWidget();
        tabHome->setObjectName(QString::fromUtf8("tabHome"));
        receiveFrame = new QFrame(tabHome);
        receiveFrame->setObjectName(QString::fromUtf8("receiveFrame"));
        receiveFrame->setGeometry(QRect(10, 60, 301, 81));
        receiveFrame->setStyleSheet(QString::fromUtf8(""));
        receiveFrame->setFrameShape(QFrame::StyledPanel);
        receiveFrame->setFrameShadow(QFrame::Raised);
        lblReceivedWeight = new QLabel(receiveFrame);
        lblReceivedWeight->setObjectName(QString::fromUtf8("lblReceivedWeight"));
        lblReceivedWeight->setGeometry(QRect(80, 30, 141, 31));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        lblReceivedWeight->setFont(font1);
        lblReceivedWeight->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lblWeight = new QLabel(receiveFrame);
        lblWeight->setObjectName(QString::fromUtf8("lblWeight"));
        lblWeight->setGeometry(QRect(10, 0, 67, 21));
        receiveFrame_3 = new QFrame(tabHome);
        receiveFrame_3->setObjectName(QString::fromUtf8("receiveFrame_3"));
        receiveFrame_3->setGeometry(QRect(10, 140, 591, 51));
        receiveFrame_3->setStyleSheet(QString::fromUtf8(""));
        receiveFrame_3->setFrameShape(QFrame::StyledPanel);
        receiveFrame_3->setFrameShadow(QFrame::Raised);
        lblReceivedWeight_3 = new QLabel(receiveFrame_3);
        lblReceivedWeight_3->setObjectName(QString::fromUtf8("lblReceivedWeight_3"));
        lblReceivedWeight_3->setGeometry(QRect(120, 10, 141, 31));
        lblReceivedWeight_3->setFont(font1);
        lblReceivedWeight_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lblWeight_3 = new QLabel(receiveFrame_3);
        lblWeight_3->setObjectName(QString::fromUtf8("lblWeight_3"));
        lblWeight_3->setGeometry(QRect(10, 20, 67, 21));
        receiveFrame_2 = new QFrame(tabHome);
        receiveFrame_2->setObjectName(QString::fromUtf8("receiveFrame_2"));
        receiveFrame_2->setGeometry(QRect(310, 60, 291, 81));
        receiveFrame_2->setStyleSheet(QString::fromUtf8(""));
        receiveFrame_2->setFrameShape(QFrame::StyledPanel);
        receiveFrame_2->setFrameShadow(QFrame::Raised);
        lblReceivedWeight_2 = new QLabel(receiveFrame_2);
        lblReceivedWeight_2->setObjectName(QString::fromUtf8("lblReceivedWeight_2"));
        lblReceivedWeight_2->setGeometry(QRect(80, 30, 141, 31));
        lblReceivedWeight_2->setFont(font1);
        lblReceivedWeight_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lblWeight_2 = new QLabel(receiveFrame_2);
        lblWeight_2->setObjectName(QString::fromUtf8("lblWeight_2"));
        lblWeight_2->setGeometry(QRect(6, 0, 151, 21));
        btnNetWeightConnect = new QPushButton(tabHome);
        btnNetWeightConnect->setObjectName(QString::fromUtf8("btnNetWeightConnect"));
        btnNetWeightConnect->setGeometry(QRect(10, 10, 97, 41));
        btnDisconnect = new QPushButton(tabHome);
        btnDisconnect->setObjectName(QString::fromUtf8("btnDisconnect"));
        btnDisconnect->setGeometry(QRect(110, 10, 97, 41));
        tabWidget->addTab(tabHome, QString());
        tabCalibrate = new QWidget();
        tabCalibrate->setObjectName(QString::fromUtf8("tabCalibrate"));
        transmitFrame = new QFrame(tabCalibrate);
        transmitFrame->setObjectName(QString::fromUtf8("transmitFrame"));
        transmitFrame->setGeometry(QRect(0, 190, 301, 151));
        transmitFrame->setStyleSheet(QString::fromUtf8(""));
        transmitFrame->setFrameShape(QFrame::StyledPanel);
        transmitFrame->setFrameShadow(QFrame::Raised);
        edtCalibrationWeight = new QLineEdit(transmitFrame);
        edtCalibrationWeight->setObjectName(QString::fromUtf8("edtCalibrationWeight"));
        edtCalibrationWeight->setGeometry(QRect(10, 70, 101, 31));
        btnCalibrateZERO = new QPushButton(transmitFrame);
        btnCalibrateZERO->setObjectName(QString::fromUtf8("btnCalibrateZERO"));
        btnCalibrateZERO->setGeometry(QRect(10, 30, 131, 31));
        btnCalibrateZERO->setAutoFillBackground(false);
        btnCalibrateZERO->setStyleSheet(QString::fromUtf8(""));
        btnCalibrateWEIGHT = new QPushButton(transmitFrame);
        btnCalibrateWEIGHT->setObjectName(QString::fromUtf8("btnCalibrateWEIGHT"));
        btnCalibrateWEIGHT->setGeometry(QRect(10, 110, 131, 31));
        btnAPPLY = new QPushButton(transmitFrame);
        btnAPPLY->setObjectName(QString::fromUtf8("btnAPPLY"));
        btnAPPLY->setGeometry(QRect(150, 70, 131, 31));
        btnSaveToEEPROM = new QPushButton(transmitFrame);
        btnSaveToEEPROM->setObjectName(QString::fromUtf8("btnSaveToEEPROM"));
        btnSaveToEEPROM->setGeometry(QRect(150, 30, 131, 31));
        QFont font2;
        font2.setStrikeOut(true);
        btnSaveToEEPROM->setFont(font2);
        label = new QLabel(transmitFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 131, 21));
        btnEditCalibrationWeight = new QPushButton(transmitFrame);
        btnEditCalibrationWeight->setObjectName(QString::fromUtf8("btnEditCalibrationWeight"));
        btnEditCalibrationWeight->setGeometry(QRect(110, 70, 31, 31));
        btnEditCalibrationWeight->setFont(font1);
        chkWriteToLoadcell = new QCheckBox(tabCalibrate);
        chkWriteToLoadcell->setObjectName(QString::fromUtf8("chkWriteToLoadcell"));
        chkWriteToLoadcell->setGeometry(QRect(230, 150, 151, 26));
        frame = new QFrame(tabCalibrate);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(320, 190, 191, 151));
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        btnGrossWeight = new QPushButton(frame);
        btnGrossWeight->setObjectName(QString::fromUtf8("btnGrossWeight"));
        btnGrossWeight->setGeometry(QRect(10, 70, 131, 31));
        btnNetWeight = new QPushButton(frame);
        btnNetWeight->setObjectName(QString::fromUtf8("btnNetWeight"));
        btnNetWeight->setGeometry(QRect(10, 110, 131, 31));
        btnSemiAutoZERO = new QPushButton(frame);
        btnSemiAutoZERO->setObjectName(QString::fromUtf8("btnSemiAutoZERO"));
        btnSemiAutoZERO->setGeometry(QRect(10, 30, 131, 31));
        lblCommands = new QLabel(frame);
        lblCommands->setObjectName(QString::fromUtf8("lblCommands"));
        lblCommands->setGeometry(QRect(10, 0, 91, 21));
        btnDisconnect_2 = new QPushButton(tabCalibrate);
        btnDisconnect_2->setObjectName(QString::fromUtf8("btnDisconnect_2"));
        btnDisconnect_2->setGeometry(QRect(120, 150, 97, 31));
        btnConnect = new QPushButton(tabCalibrate);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));
        btnConnect->setGeometry(QRect(20, 150, 97, 31));
        tabWidget->addTab(tabCalibrate, QString());
        tabGraph = new QWidget();
        tabGraph->setObjectName(QString::fromUtf8("tabGraph"));
        verticalLayout = new QVBoxLayout(tabGraph);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(tabGraph);
        widget->setObjectName(QString::fromUtf8("widget"));
        frame_4 = new QFrame(widget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(40, 10, 551, 181));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        customPlot = new QCustomPlot(frame_4);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setEnabled(true);
        customPlot->setGeometry(QRect(10, 10, 531, 161));
        customPlot->setAutoFillBackground(false);
        lblFilteredWeight = new QLabel(widget);
        lblFilteredWeight->setObjectName(QString::fromUtf8("lblFilteredWeight"));
        lblFilteredWeight->setGeometry(QRect(300, 220, 141, 31));
        lblFilteredWeight->setFont(font1);
        lblFilteredWeight->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        btnForward = new QPushButton(widget);
        btnForward->setObjectName(QString::fromUtf8("btnForward"));
        btnForward->setGeometry(QRect(290, 260, 97, 31));
        btnReverse = new QPushButton(widget);
        btnReverse->setObjectName(QString::fromUtf8("btnReverse"));
        btnReverse->setGeometry(QRect(190, 260, 97, 31));
        lblElementId = new QLabel(widget);
        lblElementId->setObjectName(QString::fromUtf8("lblElementId"));
        lblElementId->setGeometry(QRect(110, 220, 161, 31));
        lblElementId->setFont(font1);
        lblElementId->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        ymax = new QPushButton(widget);
        ymax->setObjectName(QString::fromUtf8("ymax"));
        ymax->setGeometry(QRect(0, 10, 41, 31));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        ymax->setFont(font3);
        ymin = new QPushButton(widget);
        ymin->setObjectName(QString::fromUtf8("ymin"));
        ymin->setGeometry(QRect(0, 160, 41, 31));
        ymin->setFont(font3);
        xmin = new QPushButton(widget);
        xmin->setObjectName(QString::fromUtf8("xmin"));
        xmin->setGeometry(QRect(40, 190, 41, 31));
        xmin->setFont(font3);
        xmax = new QPushButton(widget);
        xmax->setObjectName(QString::fromUtf8("xmax"));
        xmax->setGeometry(QRect(550, 190, 41, 31));
        xmax->setFont(font3);

        verticalLayout->addWidget(widget);

        tabWidget->addTab(tabGraph, QString());
        tabSettings = new QWidget();
        tabSettings->setObjectName(QString::fromUtf8("tabSettings"));
        cbSettingsMenu = new QComboBox(tabSettings);
        cbSettingsMenu->setObjectName(QString::fromUtf8("cbSettingsMenu"));
        cbSettingsMenu->setGeometry(QRect(10, 10, 451, 41));
        btnRefreshSettingsList = new QPushButton(tabSettings);
        btnRefreshSettingsList->setObjectName(QString::fromUtf8("btnRefreshSettingsList"));
        btnRefreshSettingsList->setGeometry(QRect(480, 10, 131, 41));
        settingsTable = new QTableWidget(tabSettings);
        if (settingsTable->columnCount() < 2)
            settingsTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        settingsTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        settingsTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (settingsTable->rowCount() < 40)
            settingsTable->setRowCount(40);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(4, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(5, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(6, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(7, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(8, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(9, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(10, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(11, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(12, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(13, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(14, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(15, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(16, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(17, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(18, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(19, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(20, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(21, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(22, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(23, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(24, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(25, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(26, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(27, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(28, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(29, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(30, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(31, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(32, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(33, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(34, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(35, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(36, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(37, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(38, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        settingsTable->setVerticalHeaderItem(39, __qtablewidgetitem41);
        settingsTable->setObjectName(QString::fromUtf8("settingsTable"));
        settingsTable->setGeometry(QRect(10, 60, 451, 281));
        settingsTable->setMinimumSize(QSize(451, 0));
        settingsTable->setAutoScrollMargin(16);
        tabWidget->addTab(tabSettings, QString());
        tabRecipe = new QWidget();
        tabRecipe->setObjectName(QString::fromUtf8("tabRecipe"));
        btnRefreshRecipeList = new QPushButton(tabRecipe);
        btnRefreshRecipeList->setObjectName(QString::fromUtf8("btnRefreshRecipeList"));
        btnRefreshRecipeList->setGeometry(QRect(480, 10, 131, 41));
        cbRecipeMenu = new QComboBox(tabRecipe);
        cbRecipeMenu->setObjectName(QString::fromUtf8("cbRecipeMenu"));
        cbRecipeMenu->setGeometry(QRect(10, 10, 451, 41));
        recipeTable = new QTableWidget(tabRecipe);
        if (recipeTable->columnCount() < 4)
            recipeTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        recipeTable->setHorizontalHeaderItem(0, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        recipeTable->setHorizontalHeaderItem(1, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        recipeTable->setHorizontalHeaderItem(2, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        recipeTable->setHorizontalHeaderItem(3, __qtablewidgetitem45);
        if (recipeTable->rowCount() < 40)
            recipeTable->setRowCount(40);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(0, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(1, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(2, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(3, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(4, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(5, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(6, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(7, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(8, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(9, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(10, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(11, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(12, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(13, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(14, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(15, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(16, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(17, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(18, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(19, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(20, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(21, __qtablewidgetitem67);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(22, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(23, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(24, __qtablewidgetitem70);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(25, __qtablewidgetitem71);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(26, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(27, __qtablewidgetitem73);
        QTableWidgetItem *__qtablewidgetitem74 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(28, __qtablewidgetitem74);
        QTableWidgetItem *__qtablewidgetitem75 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(29, __qtablewidgetitem75);
        QTableWidgetItem *__qtablewidgetitem76 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(30, __qtablewidgetitem76);
        QTableWidgetItem *__qtablewidgetitem77 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(31, __qtablewidgetitem77);
        QTableWidgetItem *__qtablewidgetitem78 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(32, __qtablewidgetitem78);
        QTableWidgetItem *__qtablewidgetitem79 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(33, __qtablewidgetitem79);
        QTableWidgetItem *__qtablewidgetitem80 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(34, __qtablewidgetitem80);
        QTableWidgetItem *__qtablewidgetitem81 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(35, __qtablewidgetitem81);
        QTableWidgetItem *__qtablewidgetitem82 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(36, __qtablewidgetitem82);
        QTableWidgetItem *__qtablewidgetitem83 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(37, __qtablewidgetitem83);
        QTableWidgetItem *__qtablewidgetitem84 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(38, __qtablewidgetitem84);
        QTableWidgetItem *__qtablewidgetitem85 = new QTableWidgetItem();
        recipeTable->setVerticalHeaderItem(39, __qtablewidgetitem85);
        recipeTable->setObjectName(QString::fromUtf8("recipeTable"));
        recipeTable->setGeometry(QRect(10, 60, 601, 281));
        recipeTable->setMinimumSize(QSize(451, 0));
        tabWidget->addTab(tabRecipe, QString());
        tabDio = new QWidget();
        tabDio->setObjectName(QString::fromUtf8("tabDio"));
        layoutWidget_1 = new QWidget(tabDio);
        layoutWidget_1->setObjectName(QString::fromUtf8("layoutWidget_1"));
        layoutWidget_1->setGeometry(QRect(20, 80, 321, 33));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        chkDIN_03 = new QCheckBox(layoutWidget_1);
        chkDIN_03->setObjectName(QString::fromUtf8("chkDIN_03"));

        horizontalLayout_3->addWidget(chkDIN_03);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        label_6 = new QLabel(layoutWidget_1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_3->addWidget(label_6);

        lblDIN_03 = new QLabel(layoutWidget_1);
        lblDIN_03->setObjectName(QString::fromUtf8("lblDIN_03"));

        horizontalLayout_3->addWidget(lblDIN_03);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        label_7 = new QLabel(layoutWidget_1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_3->addWidget(label_7);

        lblDOUT_03 = new QLabel(layoutWidget_1);
        lblDOUT_03->setObjectName(QString::fromUtf8("lblDOUT_03"));

        horizontalLayout_3->addWidget(lblDOUT_03);

        layoutWidget_2 = new QWidget(tabDio);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 110, 321, 33));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        chkDIN_04 = new QCheckBox(layoutWidget_2);
        chkDIN_04->setObjectName(QString::fromUtf8("chkDIN_04"));

        horizontalLayout_4->addWidget(chkDIN_04);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        label_8 = new QLabel(layoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_4->addWidget(label_8);

        lblDIN_04 = new QLabel(layoutWidget_2);
        lblDIN_04->setObjectName(QString::fromUtf8("lblDIN_04"));

        horizontalLayout_4->addWidget(lblDIN_04);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        label_9 = new QLabel(layoutWidget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_4->addWidget(label_9);

        lblDOUT_04 = new QLabel(layoutWidget_2);
        lblDOUT_04->setObjectName(QString::fromUtf8("lblDOUT_04"));

        horizontalLayout_4->addWidget(lblDOUT_04);

        layoutWidget_3 = new QWidget(tabDio);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(20, 20, 321, 33));
        horizontalLayout = new QHBoxLayout(layoutWidget_3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        chkDIN_01 = new QCheckBox(layoutWidget_3);
        chkDIN_01->setObjectName(QString::fromUtf8("chkDIN_01"));
        chkDIN_01->setChecked(false);

        horizontalLayout->addWidget(chkDIN_01);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(layoutWidget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lblDIN_01 = new QLabel(layoutWidget_3);
        lblDIN_01->setObjectName(QString::fromUtf8("lblDIN_01"));
        lblDIN_01->setEnabled(true);
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        lblDIN_01->setPalette(palette2);
        lblDIN_01->setAutoFillBackground(false);

        horizontalLayout->addWidget(lblDIN_01);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_4 = new QLabel(layoutWidget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        lblDOUT_01 = new QLabel(layoutWidget_3);
        lblDOUT_01->setObjectName(QString::fromUtf8("lblDOUT_01"));

        horizontalLayout->addWidget(lblDOUT_01);

        layoutWidget_4 = new QWidget(tabDio);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(20, 50, 321, 33));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        chkDIN_02 = new QCheckBox(layoutWidget_4);
        chkDIN_02->setObjectName(QString::fromUtf8("chkDIN_02"));

        horizontalLayout_2->addWidget(chkDIN_02);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_3 = new QLabel(layoutWidget_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lblDIN_02 = new QLabel(layoutWidget_4);
        lblDIN_02->setObjectName(QString::fromUtf8("lblDIN_02"));

        horizontalLayout_2->addWidget(lblDIN_02);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        label_5 = new QLabel(layoutWidget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        lblDOUT_02 = new QLabel(layoutWidget_4);
        lblDOUT_02->setObjectName(QString::fromUtf8("lblDOUT_02"));

        horizontalLayout_2->addWidget(lblDOUT_02);

        tabWidget->addTab(tabDio, QString());
        tabStuff = new QWidget();
        tabStuff->setObjectName(QString::fromUtf8("tabStuff"));
        tabStuff->setEnabled(true);
        PenguinImage = new QLabel(tabStuff);
        PenguinImage->setObjectName(QString::fromUtf8("PenguinImage"));
        PenguinImage->setGeometry(QRect(50, 40, 61, 21));
        PenguinImage->setMidLineWidth(0);
        PenguinImage->setMargin(0);
        PenguinImage->setIndent(-1);
        FlowScaleImage = new QLabel(tabStuff);
        FlowScaleImage->setObjectName(QString::fromUtf8("FlowScaleImage"));
        FlowScaleImage->setGeometry(QRect(50, 40, 211, 61));
        tabWidget->addTab(tabStuff, QString());
        FlowScaleImage->raise();
        PenguinImage->raise();
        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(20, 460, 621, 51));
        frame_3->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 208, 21);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        MainWindow->setCentralWidget(centralWidget);
        QWidget::setTabOrder(btnAPPLY, btnSemiAutoZERO);
        QWidget::setTabOrder(btnSemiAutoZERO, edtCalibrationWeight);
        QWidget::setTabOrder(edtCalibrationWeight, btnSaveToEEPROM);
        QWidget::setTabOrder(btnSaveToEEPROM, btnGrossWeight);
        QWidget::setTabOrder(btnGrossWeight, btnNetWeight);
        QWidget::setTabOrder(btnNetWeight, btnCalibrateZERO);
        QWidget::setTabOrder(btnCalibrateZERO, chkWriteToLoadcell);
        QWidget::setTabOrder(chkWriteToLoadcell, chkDIN_03);
        QWidget::setTabOrder(chkDIN_03, chkDIN_04);
        QWidget::setTabOrder(chkDIN_04, chkDIN_01);
        QWidget::setTabOrder(chkDIN_01, chkDIN_02);
        QWidget::setTabOrder(chkDIN_02, btnNetWeightConnect);
        QWidget::setTabOrder(btnNetWeightConnect, btnDisconnect);
        QWidget::setTabOrder(btnDisconnect, btnCalibrateWEIGHT);
        QWidget::setTabOrder(btnCalibrateWEIGHT, btnForward);
        QWidget::setTabOrder(btnForward, btnReverse);
        QWidget::setTabOrder(btnReverse, btnEditCalibrationWeight);
        QWidget::setTabOrder(btnEditCalibrationWeight, btnDisconnect_2);
        QWidget::setTabOrder(btnDisconnect_2, btnConnect);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        lblReceivedWeight->setText(QApplication::translate("MainWindow", "Number", 0, QApplication::UnicodeUTF8));
        lblWeight->setText(QApplication::translate("MainWindow", "Weight:", 0, QApplication::UnicodeUTF8));
        lblReceivedWeight_3->setText(QApplication::translate("MainWindow", "Number", 0, QApplication::UnicodeUTF8));
        lblWeight_3->setText(QApplication::translate("MainWindow", "Info:", 0, QApplication::UnicodeUTF8));
        lblReceivedWeight_2->setText(QApplication::translate("MainWindow", "Number", 0, QApplication::UnicodeUTF8));
        lblWeight_2->setText(QApplication::translate("MainWindow", "Filtered Weight:", 0, QApplication::UnicodeUTF8));
        btnNetWeightConnect->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        btnDisconnect->setText(QApplication::translate("MainWindow", "Disconnect", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabHome), QApplication::translate("MainWindow", "Home", 0, QApplication::UnicodeUTF8));
        btnCalibrateZERO->setText(QApplication::translate("MainWindow", "Calibrate ZERO", 0, QApplication::UnicodeUTF8));
        btnCalibrateWEIGHT->setText(QApplication::translate("MainWindow", "Calibrate WEIGHT", 0, QApplication::UnicodeUTF8));
        btnAPPLY->setText(QApplication::translate("MainWindow", "Apply", 0, QApplication::UnicodeUTF8));
        btnSaveToEEPROM->setText(QApplication::translate("MainWindow", "Save to EEPROM", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Calibration weight:", 0, QApplication::UnicodeUTF8));
        btnEditCalibrationWeight->setText(QApplication::translate("MainWindow", "\342\234\215", 0, QApplication::UnicodeUTF8));
        chkWriteToLoadcell->setText(QApplication::translate("MainWindow", "Write Commands", 0, QApplication::UnicodeUTF8));
        btnGrossWeight->setText(QApplication::translate("MainWindow", "GROSS weight", 0, QApplication::UnicodeUTF8));
        btnNetWeight->setText(QApplication::translate("MainWindow", "NET weight", 0, QApplication::UnicodeUTF8));
        btnSemiAutoZERO->setText(QApplication::translate("MainWindow", "Semi-Auto ZERO", 0, QApplication::UnicodeUTF8));
        lblCommands->setText(QApplication::translate("MainWindow", "Commands:", 0, QApplication::UnicodeUTF8));
        btnDisconnect_2->setText(QApplication::translate("MainWindow", "Disconnect", 0, QApplication::UnicodeUTF8));
        btnConnect->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabCalibrate), QApplication::translate("MainWindow", "Calibrate", 0, QApplication::UnicodeUTF8));
        lblFilteredWeight->setText(QApplication::translate("MainWindow", "Number", 0, QApplication::UnicodeUTF8));
        btnForward->setText(QApplication::translate("MainWindow", "Forward", 0, QApplication::UnicodeUTF8));
        btnReverse->setText(QApplication::translate("MainWindow", "Reverse", 0, QApplication::UnicodeUTF8));
        lblElementId->setText(QApplication::translate("MainWindow", "ElementId", 0, QApplication::UnicodeUTF8));
        ymax->setText(QApplication::translate("MainWindow", "Ymax", 0, QApplication::UnicodeUTF8));
        ymin->setText(QApplication::translate("MainWindow", "Ymin", 0, QApplication::UnicodeUTF8));
        xmin->setText(QApplication::translate("MainWindow", "Xmin", 0, QApplication::UnicodeUTF8));
        xmax->setText(QApplication::translate("MainWindow", "Xmax", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabGraph), QApplication::translate("MainWindow", "Graph", 0, QApplication::UnicodeUTF8));
        btnRefreshSettingsList->setText(QApplication::translate("MainWindow", "Refresh Settings", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = settingsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "01", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = settingsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "02", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = settingsTable->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "01", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = settingsTable->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "02", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = settingsTable->verticalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "03", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = settingsTable->verticalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "04", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = settingsTable->verticalHeaderItem(4);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "05", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = settingsTable->verticalHeaderItem(5);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "06", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = settingsTable->verticalHeaderItem(6);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "07", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = settingsTable->verticalHeaderItem(7);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "08", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = settingsTable->verticalHeaderItem(8);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "09", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = settingsTable->verticalHeaderItem(9);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "10", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = settingsTable->verticalHeaderItem(10);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "11", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = settingsTable->verticalHeaderItem(11);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "12", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = settingsTable->verticalHeaderItem(12);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "13", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = settingsTable->verticalHeaderItem(13);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "14", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem16 = settingsTable->verticalHeaderItem(14);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "15", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem17 = settingsTable->verticalHeaderItem(15);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "16", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem18 = settingsTable->verticalHeaderItem(16);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "17", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem19 = settingsTable->verticalHeaderItem(17);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "18", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem20 = settingsTable->verticalHeaderItem(18);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "19", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem21 = settingsTable->verticalHeaderItem(19);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "20", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem22 = settingsTable->verticalHeaderItem(20);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "21", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem23 = settingsTable->verticalHeaderItem(21);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "22", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem24 = settingsTable->verticalHeaderItem(22);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "23", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem25 = settingsTable->verticalHeaderItem(23);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "24", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem26 = settingsTable->verticalHeaderItem(24);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "25", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem27 = settingsTable->verticalHeaderItem(25);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "26", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem28 = settingsTable->verticalHeaderItem(26);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWindow", "27", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem29 = settingsTable->verticalHeaderItem(27);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWindow", "28", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem30 = settingsTable->verticalHeaderItem(28);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWindow", "29", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem31 = settingsTable->verticalHeaderItem(29);
        ___qtablewidgetitem31->setText(QApplication::translate("MainWindow", "30", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem32 = settingsTable->verticalHeaderItem(30);
        ___qtablewidgetitem32->setText(QApplication::translate("MainWindow", "31", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem33 = settingsTable->verticalHeaderItem(31);
        ___qtablewidgetitem33->setText(QApplication::translate("MainWindow", "32", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem34 = settingsTable->verticalHeaderItem(32);
        ___qtablewidgetitem34->setText(QApplication::translate("MainWindow", "33", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem35 = settingsTable->verticalHeaderItem(33);
        ___qtablewidgetitem35->setText(QApplication::translate("MainWindow", "34", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem36 = settingsTable->verticalHeaderItem(34);
        ___qtablewidgetitem36->setText(QApplication::translate("MainWindow", "35", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem37 = settingsTable->verticalHeaderItem(35);
        ___qtablewidgetitem37->setText(QApplication::translate("MainWindow", "36", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem38 = settingsTable->verticalHeaderItem(36);
        ___qtablewidgetitem38->setText(QApplication::translate("MainWindow", "37", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem39 = settingsTable->verticalHeaderItem(37);
        ___qtablewidgetitem39->setText(QApplication::translate("MainWindow", "38", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem40 = settingsTable->verticalHeaderItem(38);
        ___qtablewidgetitem40->setText(QApplication::translate("MainWindow", "39", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem41 = settingsTable->verticalHeaderItem(39);
        ___qtablewidgetitem41->setText(QApplication::translate("MainWindow", "40", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabSettings), QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        btnRefreshRecipeList->setText(QApplication::translate("MainWindow", "Refresh Recipes", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem42 = recipeTable->horizontalHeaderItem(0);
        ___qtablewidgetitem42->setText(QApplication::translate("MainWindow", "01", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem43 = recipeTable->horizontalHeaderItem(1);
        ___qtablewidgetitem43->setText(QApplication::translate("MainWindow", "02", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem44 = recipeTable->horizontalHeaderItem(2);
        ___qtablewidgetitem44->setText(QApplication::translate("MainWindow", "03", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem45 = recipeTable->horizontalHeaderItem(3);
        ___qtablewidgetitem45->setText(QApplication::translate("MainWindow", "04", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem46 = recipeTable->verticalHeaderItem(0);
        ___qtablewidgetitem46->setText(QApplication::translate("MainWindow", "01", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem47 = recipeTable->verticalHeaderItem(1);
        ___qtablewidgetitem47->setText(QApplication::translate("MainWindow", "02", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem48 = recipeTable->verticalHeaderItem(2);
        ___qtablewidgetitem48->setText(QApplication::translate("MainWindow", "03", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem49 = recipeTable->verticalHeaderItem(3);
        ___qtablewidgetitem49->setText(QApplication::translate("MainWindow", "04", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem50 = recipeTable->verticalHeaderItem(4);
        ___qtablewidgetitem50->setText(QApplication::translate("MainWindow", "05", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem51 = recipeTable->verticalHeaderItem(5);
        ___qtablewidgetitem51->setText(QApplication::translate("MainWindow", "06", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem52 = recipeTable->verticalHeaderItem(6);
        ___qtablewidgetitem52->setText(QApplication::translate("MainWindow", "07", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem53 = recipeTable->verticalHeaderItem(7);
        ___qtablewidgetitem53->setText(QApplication::translate("MainWindow", "08", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem54 = recipeTable->verticalHeaderItem(8);
        ___qtablewidgetitem54->setText(QApplication::translate("MainWindow", "09", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem55 = recipeTable->verticalHeaderItem(9);
        ___qtablewidgetitem55->setText(QApplication::translate("MainWindow", "10", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem56 = recipeTable->verticalHeaderItem(10);
        ___qtablewidgetitem56->setText(QApplication::translate("MainWindow", "11", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem57 = recipeTable->verticalHeaderItem(11);
        ___qtablewidgetitem57->setText(QApplication::translate("MainWindow", "12", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem58 = recipeTable->verticalHeaderItem(12);
        ___qtablewidgetitem58->setText(QApplication::translate("MainWindow", "13", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem59 = recipeTable->verticalHeaderItem(13);
        ___qtablewidgetitem59->setText(QApplication::translate("MainWindow", "14", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem60 = recipeTable->verticalHeaderItem(14);
        ___qtablewidgetitem60->setText(QApplication::translate("MainWindow", "15", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem61 = recipeTable->verticalHeaderItem(15);
        ___qtablewidgetitem61->setText(QApplication::translate("MainWindow", "16", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem62 = recipeTable->verticalHeaderItem(16);
        ___qtablewidgetitem62->setText(QApplication::translate("MainWindow", "17", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem63 = recipeTable->verticalHeaderItem(17);
        ___qtablewidgetitem63->setText(QApplication::translate("MainWindow", "18", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem64 = recipeTable->verticalHeaderItem(18);
        ___qtablewidgetitem64->setText(QApplication::translate("MainWindow", "19", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem65 = recipeTable->verticalHeaderItem(19);
        ___qtablewidgetitem65->setText(QApplication::translate("MainWindow", "20", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem66 = recipeTable->verticalHeaderItem(20);
        ___qtablewidgetitem66->setText(QApplication::translate("MainWindow", "21", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem67 = recipeTable->verticalHeaderItem(21);
        ___qtablewidgetitem67->setText(QApplication::translate("MainWindow", "22", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem68 = recipeTable->verticalHeaderItem(22);
        ___qtablewidgetitem68->setText(QApplication::translate("MainWindow", "23", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem69 = recipeTable->verticalHeaderItem(23);
        ___qtablewidgetitem69->setText(QApplication::translate("MainWindow", "24", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem70 = recipeTable->verticalHeaderItem(24);
        ___qtablewidgetitem70->setText(QApplication::translate("MainWindow", "25", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem71 = recipeTable->verticalHeaderItem(25);
        ___qtablewidgetitem71->setText(QApplication::translate("MainWindow", "26", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem72 = recipeTable->verticalHeaderItem(26);
        ___qtablewidgetitem72->setText(QApplication::translate("MainWindow", "27", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem73 = recipeTable->verticalHeaderItem(27);
        ___qtablewidgetitem73->setText(QApplication::translate("MainWindow", "28", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem74 = recipeTable->verticalHeaderItem(28);
        ___qtablewidgetitem74->setText(QApplication::translate("MainWindow", "29", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem75 = recipeTable->verticalHeaderItem(29);
        ___qtablewidgetitem75->setText(QApplication::translate("MainWindow", "30", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem76 = recipeTable->verticalHeaderItem(30);
        ___qtablewidgetitem76->setText(QApplication::translate("MainWindow", "31", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem77 = recipeTable->verticalHeaderItem(31);
        ___qtablewidgetitem77->setText(QApplication::translate("MainWindow", "32", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem78 = recipeTable->verticalHeaderItem(32);
        ___qtablewidgetitem78->setText(QApplication::translate("MainWindow", "33", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem79 = recipeTable->verticalHeaderItem(33);
        ___qtablewidgetitem79->setText(QApplication::translate("MainWindow", "34", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem80 = recipeTable->verticalHeaderItem(34);
        ___qtablewidgetitem80->setText(QApplication::translate("MainWindow", "35", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem81 = recipeTable->verticalHeaderItem(35);
        ___qtablewidgetitem81->setText(QApplication::translate("MainWindow", "36", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem82 = recipeTable->verticalHeaderItem(36);
        ___qtablewidgetitem82->setText(QApplication::translate("MainWindow", "37", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem83 = recipeTable->verticalHeaderItem(37);
        ___qtablewidgetitem83->setText(QApplication::translate("MainWindow", "38", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem84 = recipeTable->verticalHeaderItem(38);
        ___qtablewidgetitem84->setText(QApplication::translate("MainWindow", "39", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem85 = recipeTable->verticalHeaderItem(39);
        ___qtablewidgetitem85->setText(QApplication::translate("MainWindow", "40", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabRecipe), QApplication::translate("MainWindow", "Recipe", 0, QApplication::UnicodeUTF8));
        chkDIN_03->setText(QApplication::translate("MainWindow", "SI_03", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "I 03", 0, QApplication::UnicodeUTF8));
        lblDIN_03->setText(QApplication::translate("MainWindow", "I_03", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Q 03", 0, QApplication::UnicodeUTF8));
        lblDOUT_03->setText(QApplication::translate("MainWindow", "Q_03", 0, QApplication::UnicodeUTF8));
        chkDIN_04->setText(QApplication::translate("MainWindow", "SI_04", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "I 04", 0, QApplication::UnicodeUTF8));
        lblDIN_04->setText(QApplication::translate("MainWindow", "I_04", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Q 04", 0, QApplication::UnicodeUTF8));
        lblDOUT_04->setText(QApplication::translate("MainWindow", "Q_04", 0, QApplication::UnicodeUTF8));
        chkDIN_01->setText(QApplication::translate("MainWindow", "SI_01", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "I 01", 0, QApplication::UnicodeUTF8));
        lblDIN_01->setText(QApplication::translate("MainWindow", "I_01", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Q 01", 0, QApplication::UnicodeUTF8));
        lblDOUT_01->setText(QApplication::translate("MainWindow", "Q_01", 0, QApplication::UnicodeUTF8));
        chkDIN_02->setText(QApplication::translate("MainWindow", "SI_02", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "I 02", 0, QApplication::UnicodeUTF8));
        lblDIN_02->setText(QApplication::translate("MainWindow", "I_02", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Q 02", 0, QApplication::UnicodeUTF8));
        lblDOUT_02->setText(QApplication::translate("MainWindow", "Q_02", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabDio), QApplication::translate("MainWindow", "Dio", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_ACCESSIBILITY
        PenguinImage->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        PenguinImage->setText(QApplication::translate("MainWindow", "Penguin", 0, QApplication::UnicodeUTF8));
        FlowScaleImage->setText(QApplication::translate("MainWindow", "FlowScale", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabStuff), QApplication::translate("MainWindow", "Page", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
