#ifndef INVERTER_VOLTAGE_SET_H
#define INVERTER_VOLTAGE_SET_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>

namespace Ui {
class Inverter_Voltage_Set;
}

class Inverter_Voltage_Set : public QDialog
{
    Q_OBJECT

public:
    explicit Inverter_Voltage_Set(QWidget *parent = 0);
    ~Inverter_Voltage_Set();
    QSerialPort *Inverter_Port;


private slots:
    void on_set_Inverter_Voltage_OkBtn_clicked();

    void on_set_Inverter_Voltage_QuitBtn_clicked();

private:
    Ui::Inverter_Voltage_Set *ui;
};

#endif // INVERTER_VOLTAGE_SET_H

