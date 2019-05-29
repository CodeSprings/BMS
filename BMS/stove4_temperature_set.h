#ifndef STOVE4_TEMPERATURE_SET_H
#define STOVE4_TEMPERATURE_SET_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QTime>
#include <QApplication>

namespace Ui {
class Stove4_Temperature_Set;
}

class Stove4_Temperature_Set : public QDialog
{
    Q_OBJECT

public:
    explicit Stove4_Temperature_Set(QWidget *parent = 0);
    ~Stove4_Temperature_Set();
    QSerialPort *Stove_Port;
    void sleep(unsigned int msec);

    void stove4_Temperature_Set();
    static bool Stove4_temp_read_stop;

private slots:
    void on_stove4_Temperature_Set_OkBtn_clicked();

    void on_stove4_Temperature_Set_QuitBtn_clicked();

private:
    Ui::Stove4_Temperature_Set *ui;
};

#endif // STOVE4_TEMPERATURE_SET_H
