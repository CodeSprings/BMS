#ifndef STOVE1_TEMPERATURE_SET_H
#define STOVE1_TEMPERATURE_SET_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QTime>
#include <QApplication>

namespace Ui {
class Stove1_Temperature_Set;
}

class Stove1_Temperature_Set : public QDialog
{
    Q_OBJECT

public:
    explicit Stove1_Temperature_Set(QWidget *parent = 0);
    ~Stove1_Temperature_Set();
    QSerialPort *Stove_Port;
    void sleep(unsigned int msec);

    void stove1_Temperature_Set();
    static bool Stove1_temp_read_stop;

private slots:
    void on_stove1_Temperature_Set_OkBtn_clicked();
    
    void on_stove1_Temperature_Set_QuitBtn_clicked();
    
private:
    Ui::Stove1_Temperature_Set *ui;


};

#endif // STOVE1_TEMPERATURE_SET_H
