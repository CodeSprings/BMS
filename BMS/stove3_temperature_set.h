#ifndef STOVE3_TEMPERATURE_SET_H
#define STOVE3_TEMPERATURE_SET_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QTime>
#include <QApplication>

namespace Ui {
class Stove3_Temperature_Set;
}

class Stove3_Temperature_Set : public QDialog
{
    Q_OBJECT

public:
    explicit Stove3_Temperature_Set(QWidget *parent = 0);
    ~Stove3_Temperature_Set();
    QSerialPort *Stove_Port;
    void sleep(unsigned int msec);

    void stove3_Temperature_Set();
    static bool Stove3_temp_read_stop;

private slots:
    void on_stove3_Temperature_Set_OkBtn_clicked();

    void on_stove3_Temperature_Set_QuitBtn_clicked();

private:
    Ui::Stove3_Temperature_Set *ui;
};

#endif // STOVE3_TEMPERATURE_SET_H
