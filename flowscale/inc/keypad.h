#ifndef KEYPAD_H
#define KEYPAD_H

#include <QDialog>

namespace Ui {
class KeyPad;
}

class KeyPad : public QDialog
{
    Q_OBJECT

public:
    explicit KeyPad(QWidget *parent = 0);
    ~KeyPad();

private slots:
    void on_pushButton_00_clicked();
    void on_pushButton_02_clicked();
    void on_pushButton_01_clicked();
    void on_pushButton_03_clicked();
    void on_pushButton_04_clicked();
    void on_pushButton_05_clicked();
    void on_pushButton_06_clicked();
    void on_pushButton_07_clicked();
    void on_pushButton_08_clicked();
    void on_pushButton_09_clicked();
    void on_pushButton_Del_clicked();
    void on_pushButton_Enter_clicked();

private:
    Ui::KeyPad *ui;

signals:
    void value(QString);


};

#endif // KEYPAD_H
