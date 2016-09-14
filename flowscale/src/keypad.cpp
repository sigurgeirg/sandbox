#include "keypad.h"
#include "ui_keypad.h"

KeyPad::KeyPad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KeyPad)
{
    ui->setupUi(this);
}

KeyPad::~KeyPad()
{
    delete ui;
}


void KeyPad::on_pushButton_00_clicked()
{
    emit value("0");
}

void KeyPad::on_pushButton_01_clicked()
{
    emit value("1");
}

void KeyPad::on_pushButton_02_clicked()
{
    emit value("2");
}

void KeyPad::on_pushButton_03_clicked()
{
    emit value("3");
}

void KeyPad::on_pushButton_04_clicked()
{
    emit value("4");
}

void KeyPad::on_pushButton_05_clicked()
{
    emit value("5");
}

void KeyPad::on_pushButton_06_clicked()
{
    emit value("6");
}

void KeyPad::on_pushButton_07_clicked()
{
    emit value("7");
}

void KeyPad::on_pushButton_08_clicked()
{
    emit value("8");
}

void KeyPad::on_pushButton_09_clicked()
{
    emit value("9");
}

void KeyPad::on_pushButton_Del_clicked()
{
    emit value("91");
}

void KeyPad::on_pushButton_Enter_clicked()
{
    emit value("92");
}
