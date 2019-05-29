#ifndef INVERTER_CONTROLMODE_H
#define INVERTER_CONTROLMODE_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>


namespace Ui {
class Inverter_ControlMode;
}

class Inverter_ControlMode : public QDialog
{
    Q_OBJECT

public:
    explicit Inverter_ControlMode(QWidget *parent = 0);
    ~Inverter_ControlMode();
    int Mode_Flag;
    QSerialPort *Inverter_Port;

private slots:
    void on_Inverter_ControlMode_OkBtn_clicked();

    void on_Inverter_ControlMode_QuitBtn_clicked();

    void on_Constant_Current_Charging_Btn_clicked();

    void on_Constant_Current_Discharge_Btn_clicked();

    void on_Constant_Power_Charging_Btn_clicked();

    void on_Constant_Power_Discharge_Btn_clicked();

private:
    Ui::Inverter_ControlMode *ui;
};

#endif // INVERTER_CONTROLMODE_H

