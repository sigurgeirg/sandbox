/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Apr 23 15:20:37 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "../QCustomPlot/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tabHome;
    QLabel *lblTest;
    QWidget *tabCalibrate;
    QFrame *transmitFrame;
    QLineEdit *edtCalibrationWeight;
    QPushButton *btnCalibrateZERO;
    QPushButton *btnCalibrateWEIGHT;
    QPushButton *btnAPPLY;
    QPushButton *btnSaveToEEPROM;
    QLabel *label;
    QPushButton *btnDisconnect;
    QPushButton *btnConnect;
    QCheckBox *chkWriteToLoadcell;
    QFrame *receiveFrame;
    QLabel *lblReceivedWeight;
    QLabel *lblWeight;
    QFrame *frame;
    QPushButton *btnGrossWeight;
    QPushButton *btnNetWeight;
    QPushButton *btnSemiAutoZERO;
    QLabel *lblCommands;
    QWidget *tabGraph;
    QVBoxLayout *verticalLayout;
    QCustomPlot *widget;
    QWidget *tabParams;
    QWidget *tabDio;
    QPushButton *btnDIN_00;
    QPushButton *btnDIN_01;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *lblDOUT_00;
    QLabel *lblDOUT_01;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(606, 404);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 571, 341));
        tabHome = new QWidget();
        tabHome->setObjectName(QString::fromUtf8("tabHome"));
        lblTest = new QLabel(tabHome);
        lblTest->setObjectName(QString::fromUtf8("lblTest"));
        lblTest->setGeometry(QRect(10, 10, 211, 61));
        tabWidget->addTab(tabHome, QString());
        tabCalibrate = new QWidget();
        tabCalibrate->setObjectName(QString::fromUtf8("tabCalibrate"));
        transmitFrame = new QFrame(tabCalibrate);
        transmitFrame->setObjectName(QString::fromUtf8("transmitFrame"));
        transmitFrame->setGeometry(QRect(10, 140, 301, 151));
        transmitFrame->setFrameShape(QFrame::StyledPanel);
        transmitFrame->setFrameShadow(QFrame::Raised);
        edtCalibrationWeight = new QLineEdit(transmitFrame);
        edtCalibrationWeight->setObjectName(QString::fromUtf8("edtCalibrationWeight"));
        edtCalibrationWeight->setGeometry(QRect(10, 70, 131, 33));
        btnCalibrateZERO = new QPushButton(transmitFrame);
        btnCalibrateZERO->setObjectName(QString::fromUtf8("btnCalibrateZERO"));
        btnCalibrateZERO->setGeometry(QRect(10, 30, 131, 31));
        btnCalibrateWEIGHT = new QPushButton(transmitFrame);
        btnCalibrateWEIGHT->setObjectName(QString::fromUtf8("btnCalibrateWEIGHT"));
        btnCalibrateWEIGHT->setGeometry(QRect(10, 110, 131, 31));
        btnAPPLY = new QPushButton(transmitFrame);
        btnAPPLY->setObjectName(QString::fromUtf8("btnAPPLY"));
        btnAPPLY->setGeometry(QRect(150, 70, 131, 31));
        btnSaveToEEPROM = new QPushButton(transmitFrame);
        btnSaveToEEPROM->setObjectName(QString::fromUtf8("btnSaveToEEPROM"));
        btnSaveToEEPROM->setGeometry(QRect(150, 30, 131, 31));
        QFont font;
        font.setStrikeOut(true);
        btnSaveToEEPROM->setFont(font);
        label = new QLabel(transmitFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 131, 21));
        btnDisconnect = new QPushButton(tabCalibrate);
        btnDisconnect->setObjectName(QString::fromUtf8("btnDisconnect"));
        btnDisconnect->setGeometry(QRect(110, 10, 97, 31));
        btnConnect = new QPushButton(tabCalibrate);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));
        btnConnect->setGeometry(QRect(10, 10, 97, 31));
        chkWriteToLoadcell = new QCheckBox(tabCalibrate);
        chkWriteToLoadcell->setObjectName(QString::fromUtf8("chkWriteToLoadcell"));
        chkWriteToLoadcell->setGeometry(QRect(220, 10, 151, 26));
        receiveFrame = new QFrame(tabCalibrate);
        receiveFrame->setObjectName(QString::fromUtf8("receiveFrame"));
        receiveFrame->setGeometry(QRect(10, 50, 301, 81));
        receiveFrame->setFrameShape(QFrame::StyledPanel);
        receiveFrame->setFrameShadow(QFrame::Raised);
        lblReceivedWeight = new QLabel(receiveFrame);
        lblReceivedWeight->setObjectName(QString::fromUtf8("lblReceivedWeight"));
        lblReceivedWeight->setGeometry(QRect(80, 30, 111, 31));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        lblReceivedWeight->setFont(font1);
        lblWeight = new QLabel(receiveFrame);
        lblWeight->setObjectName(QString::fromUtf8("lblWeight"));
        lblWeight->setGeometry(QRect(10, 0, 67, 21));
        frame = new QFrame(tabCalibrate);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(320, 130, 191, 161));
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
        tabWidget->addTab(tabCalibrate, QString());
        tabGraph = new QWidget();
        tabGraph->setObjectName(QString::fromUtf8("tabGraph"));
        verticalLayout = new QVBoxLayout(tabGraph);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QCustomPlot(tabGraph);
        widget->setObjectName(QString::fromUtf8("widget"));

        verticalLayout->addWidget(widget);

        tabWidget->addTab(tabGraph, QString());
        tabParams = new QWidget();
        tabParams->setObjectName(QString::fromUtf8("tabParams"));
        tabWidget->addTab(tabParams, QString());
        tabDio = new QWidget();
        tabDio->setObjectName(QString::fromUtf8("tabDio"));
        btnDIN_00 = new QPushButton(tabDio);
        btnDIN_00->setObjectName(QString::fromUtf8("btnDIN_00"));
        btnDIN_00->setGeometry(QRect(40, 50, 51, 27));
        btnDIN_01 = new QPushButton(tabDio);
        btnDIN_01->setObjectName(QString::fromUtf8("btnDIN_01"));
        btnDIN_01->setGeometry(QRect(40, 110, 51, 27));
        label_2 = new QLabel(tabDio);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 30, 91, 17));
        label_3 = new QLabel(tabDio);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 90, 91, 17));
        lblDOUT_00 = new QLabel(tabDio);
        lblDOUT_00->setObjectName(QString::fromUtf8("lblDOUT_00"));
        lblDOUT_00->setGeometry(QRect(150, 50, 66, 31));
        lblDOUT_01 = new QLabel(tabDio);
        lblDOUT_01->setObjectName(QString::fromUtf8("lblDOUT_01"));
        lblDOUT_01->setGeometry(QRect(150, 110, 66, 17));
        tabWidget->addTab(tabDio, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 606, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(tabWidget, btnCalibrateZERO);
        QWidget::setTabOrder(btnCalibrateZERO, btnCalibrateWEIGHT);
        QWidget::setTabOrder(btnCalibrateWEIGHT, btnAPPLY);
        QWidget::setTabOrder(btnAPPLY, btnSemiAutoZERO);
        QWidget::setTabOrder(btnSemiAutoZERO, edtCalibrationWeight);
        QWidget::setTabOrder(edtCalibrationWeight, btnSaveToEEPROM);
        QWidget::setTabOrder(btnSaveToEEPROM, btnGrossWeight);
        QWidget::setTabOrder(btnGrossWeight, btnNetWeight);
        QWidget::setTabOrder(btnNetWeight, btnConnect);
        QWidget::setTabOrder(btnConnect, btnDisconnect);
        QWidget::setTabOrder(btnDisconnect, chkWriteToLoadcell);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        lblTest->setText(QApplication::translate("MainWindow", "Test", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabHome), QApplication::translate("MainWindow", "Home", 0, QApplication::UnicodeUTF8));
        btnCalibrateZERO->setText(QApplication::translate("MainWindow", "Calibrate ZERO", 0, QApplication::UnicodeUTF8));
        btnCalibrateWEIGHT->setText(QApplication::translate("MainWindow", "Calibrate WEIGHT", 0, QApplication::UnicodeUTF8));
        btnAPPLY->setText(QApplication::translate("MainWindow", "Apply", 0, QApplication::UnicodeUTF8));
        btnSaveToEEPROM->setText(QApplication::translate("MainWindow", "Save to EEPROM", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Calibration weight:", 0, QApplication::UnicodeUTF8));
        btnDisconnect->setText(QApplication::translate("MainWindow", "Disconnect", 0, QApplication::UnicodeUTF8));
        btnConnect->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        chkWriteToLoadcell->setText(QApplication::translate("MainWindow", "Write Commands", 0, QApplication::UnicodeUTF8));
        lblReceivedWeight->setText(QApplication::translate("MainWindow", "Number", 0, QApplication::UnicodeUTF8));
        lblWeight->setText(QApplication::translate("MainWindow", "Weight:", 0, QApplication::UnicodeUTF8));
        btnGrossWeight->setText(QApplication::translate("MainWindow", "GROSS weight", 0, QApplication::UnicodeUTF8));
        btnNetWeight->setText(QApplication::translate("MainWindow", "NET weight", 0, QApplication::UnicodeUTF8));
        btnSemiAutoZERO->setText(QApplication::translate("MainWindow", "Semi-Auto ZERO", 0, QApplication::UnicodeUTF8));
        lblCommands->setText(QApplication::translate("MainWindow", "Commands:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabCalibrate), QApplication::translate("MainWindow", "Calibrate", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabGraph), QApplication::translate("MainWindow", "Graph", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabParams), QApplication::translate("MainWindow", "Params", 0, QApplication::UnicodeUTF8));
        btnDIN_00->setText(QApplication::translate("MainWindow", "IN_00", 0, QApplication::UnicodeUTF8));
        btnDIN_01->setText(QApplication::translate("MainWindow", "IN_01", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Set Input 00", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Set Input 00", 0, QApplication::UnicodeUTF8));
        lblDOUT_00->setText(QApplication::translate("MainWindow", "OUT_00", 0, QApplication::UnicodeUTF8));
        lblDOUT_01->setText(QApplication::translate("MainWindow", "OUT_01", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabDio), QApplication::translate("MainWindow", "Dio", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
