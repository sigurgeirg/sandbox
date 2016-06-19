/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Nov 26 22:55:00 2014
**      by: Qt User Interface Compiler version 4.8.1
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
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
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
    QLabel *FlowScaleImage;
    QLabel *PenguinImage;
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
    QCustomPlot *customPlot;
    QLabel *lblFilteredWeight;
    QWidget *tabParams;
    QWidget *tabDio;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *lblDIN_00;
    QLabel *lblDIN_01;
    QLabel *label_4;
    QLabel *lblDOUT_01;
    QLabel *lblDOUT_00;
    QLabel *label_5;
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
        FlowScaleImage = new QLabel(tabHome);
        FlowScaleImage->setObjectName(QString::fromUtf8("FlowScaleImage"));
        FlowScaleImage->setGeometry(QRect(60, 60, 211, 61));
        PenguinImage = new QLabel(tabHome);
        PenguinImage->setObjectName(QString::fromUtf8("PenguinImage"));
        PenguinImage->setGeometry(QRect(60, 60, 61, 21));
        PenguinImage->setMidLineWidth(0);
        PenguinImage->setMargin(0);
        PenguinImage->setIndent(-1);
        tabWidget->addTab(tabHome, QString());
        tabCalibrate = new QWidget();
        tabCalibrate->setObjectName(QString::fromUtf8("tabCalibrate"));
        transmitFrame = new QFrame(tabCalibrate);
        transmitFrame->setObjectName(QString::fromUtf8("transmitFrame"));
        transmitFrame->setGeometry(QRect(10, 140, 301, 151));
        transmitFrame->setStyleSheet(QString::fromUtf8(""));
        transmitFrame->setFrameShape(QFrame::StyledPanel);
        transmitFrame->setFrameShadow(QFrame::Raised);
        edtCalibrationWeight = new QLineEdit(transmitFrame);
        edtCalibrationWeight->setObjectName(QString::fromUtf8("edtCalibrationWeight"));
        edtCalibrationWeight->setGeometry(QRect(10, 70, 131, 33));
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
        QFont font1;
        font1.setStrikeOut(true);
        btnSaveToEEPROM->setFont(font1);
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
        receiveFrame->setStyleSheet(QString::fromUtf8(""));
        receiveFrame->setFrameShape(QFrame::StyledPanel);
        receiveFrame->setFrameShadow(QFrame::Raised);
        lblReceivedWeight = new QLabel(receiveFrame);
        lblReceivedWeight->setObjectName(QString::fromUtf8("lblReceivedWeight"));
        lblReceivedWeight->setGeometry(QRect(80, 30, 141, 31));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        lblReceivedWeight->setFont(font2);
        lblReceivedWeight->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lblWeight = new QLabel(receiveFrame);
        lblWeight->setObjectName(QString::fromUtf8("lblWeight"));
        lblWeight->setGeometry(QRect(10, 0, 67, 21));
        frame = new QFrame(tabCalibrate);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(320, 140, 191, 151));
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
        tabWidget->addTab(tabCalibrate, QString());
        tabGraph = new QWidget();
        tabGraph->setObjectName(QString::fromUtf8("tabGraph"));
        verticalLayout = new QVBoxLayout(tabGraph);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        customPlot = new QCustomPlot(tabGraph);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setAutoFillBackground(false);
        lblFilteredWeight = new QLabel(customPlot);
        lblFilteredWeight->setObjectName(QString::fromUtf8("lblFilteredWeight"));
        lblFilteredWeight->setGeometry(QRect(250, 100, 141, 31));
        lblFilteredWeight->setFont(font2);
        lblFilteredWeight->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(customPlot);

        tabWidget->addTab(tabGraph, QString());
        tabParams = new QWidget();
        tabParams->setObjectName(QString::fromUtf8("tabParams"));
        tabWidget->addTab(tabParams, QString());
        tabDio = new QWidget();
        tabDio->setObjectName(QString::fromUtf8("tabDio"));
        label_2 = new QLabel(tabDio);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 30, 91, 17));
        label_3 = new QLabel(tabDio);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 90, 91, 17));
        lblDIN_00 = new QLabel(tabDio);
        lblDIN_00->setObjectName(QString::fromUtf8("lblDIN_00"));
        lblDIN_00->setGeometry(QRect(40, 50, 66, 21));
        lblDIN_01 = new QLabel(tabDio);
        lblDIN_01->setObjectName(QString::fromUtf8("lblDIN_01"));
        lblDIN_01->setGeometry(QRect(40, 110, 66, 21));
        label_4 = new QLabel(tabDio);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(140, 30, 91, 17));
        lblDOUT_01 = new QLabel(tabDio);
        lblDOUT_01->setObjectName(QString::fromUtf8("lblDOUT_01"));
        lblDOUT_01->setGeometry(QRect(150, 110, 66, 21));
        lblDOUT_00 = new QLabel(tabDio);
        lblDOUT_00->setObjectName(QString::fromUtf8("lblDOUT_00"));
        lblDOUT_00->setGeometry(QRect(150, 50, 66, 21));
        label_5 = new QLabel(tabDio);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(140, 90, 91, 17));
        tabWidget->addTab(tabDio, QString());
        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(20, 460, 621, 51));
        frame_3->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 208, 21);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        MainWindow->setCentralWidget(centralWidget);
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

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        FlowScaleImage->setText(QApplication::translate("MainWindow", "FlowScale", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_ACCESSIBILITY
        PenguinImage->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        PenguinImage->setText(QApplication::translate("MainWindow", "Penguin", 0, QApplication::UnicodeUTF8));
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
        lblFilteredWeight->setText(QApplication::translate("MainWindow", "Number", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabGraph), QApplication::translate("MainWindow", "Graph", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabParams), QApplication::translate("MainWindow", "Params", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Input 00", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Input 00", 0, QApplication::UnicodeUTF8));
        lblDIN_00->setText(QApplication::translate("MainWindow", "IN_00", 0, QApplication::UnicodeUTF8));
        lblDIN_01->setText(QApplication::translate("MainWindow", "IN_01", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Output 00", 0, QApplication::UnicodeUTF8));
        lblDOUT_01->setText(QApplication::translate("MainWindow", "OUT_01", 0, QApplication::UnicodeUTF8));
        lblDOUT_00->setText(QApplication::translate("MainWindow", "OUT_00", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Output 00", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabDio), QApplication::translate("MainWindow", "Dio", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
