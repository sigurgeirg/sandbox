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

void KeyPad::clearDisplay()
{
    ui->display->clear();
}

void KeyPad::on_pushButton_00_clicked()
{
    ui->display->setText(ui->display->text().append("0"));
    emit value("0");
}

void KeyPad::on_pushButton_01_clicked()
{
    ui->display->setText(ui->display->text().append("1"));
    emit value("1");
}

void KeyPad::on_pushButton_02_clicked()
{
    ui->display->setText(ui->display->text().append("2"));
    emit value("2");
}

void KeyPad::on_pushButton_03_clicked()
{
    ui->display->setText(ui->display->text().append("3"));
    emit value("3");
}

void KeyPad::on_pushButton_04_clicked()
{
    ui->display->setText(ui->display->text().append("4"));
    emit value("4");
}

void KeyPad::on_pushButton_05_clicked()
{
    ui->display->setText(ui->display->text().append("5"));
    emit value("5");
}

void KeyPad::on_pushButton_06_clicked()
{
    ui->display->setText(ui->display->text().append("6"));
    emit value("6");
}

void KeyPad::on_pushButton_07_clicked()
{
    ui->display->setText(ui->display->text().append("7"));
    emit value("7");
}

void KeyPad::on_pushButton_08_clicked()
{
    ui->display->setText(ui->display->text().append("8"));
    emit value("8");
}

void KeyPad::on_pushButton_09_clicked()
{
    ui->display->setText(ui->display->text().append("9"));
    emit value("9");
}

void KeyPad::on_pushButton_Del_clicked()
{
    ui->display->backspace();
    emit value("91");
}

void KeyPad::on_pushButton_Enter_clicked()
{
    emit value("92");
}
