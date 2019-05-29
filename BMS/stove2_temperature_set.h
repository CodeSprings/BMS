#ifndef STOVE2_TEMPERATURE_SET_H
#define STOVE2_TEMPERATURE_SET_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QTime>
#include <QApplication>

namespace Ui {
class Stove2_Temperature_Set;
}

class Stove2_Temperature_Set : public QDialog
{
    Q_OBJECT

public:
    explicit Stove2_Temperature_Set(QWidget *parent = 0);
    ~Stove2_Temperature_Set();
    QSerialPort *Stove_Port;
    void sleep(unsigned int msec);

    void stove2_Temperature_Set();

    static bool Stove2_temp_read_stop;

private slots:
    void on_stove2_Temperature_Set_OkBtn_clicked();

    void on_stove2_Temperature_Set_QuitBtn_clicked();

private:
    Ui::Stove2_Temperature_Set *ui;
};

#endif // STOVE2_TEMPERATURE_SET_H
