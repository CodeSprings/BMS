#ifndef INVERTER_SWITCH_H
#define INVERTER_SWITCH_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>


namespace Ui {
class Inverter_Switch;
}

class Inverter_Switch : public QDialog
{
    Q_OBJECT

public:
    explicit Inverter_Switch(QWidget *parent = 0);
    ~Inverter_Switch();
    int COM_Flag;
    QSerialPort *Inverter_Port;

private slots:
    void on_Inverter_Switch_OkBtn_clicked();

    void on_Inverter_Switch_QuitBtn_clicked();

    void on_Inverter_Open_Btn_clicked();

    void on_Inverter_Close_Btn_clicked();

private:
    Ui::Inverter_Switch *ui;
};

#endif // INVERTER_SWITCH_H
