#ifndef INVERTER_ACTIVEPOWER_SET_H
#define INVERTER_ACTIVEPOWER_SET_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>



namespace Ui {
class Inverter_ActivePower_Set;
}

class Inverter_ActivePower_Set : public QDialog
{
    Q_OBJECT

public:
    explicit Inverter_ActivePower_Set(QWidget *parent = 0);
    ~Inverter_ActivePower_Set();
    QSerialPort *Inverter_Port;


private slots:
    void on_set_Inverter_ActivePower_OkBtn_clicked();

    void on_set_Inverter_ActivePower_QuitBtn_clicked();

private:
    Ui::Inverter_ActivePower_Set *ui;

};

#endif // INVERTER_ACTIVEPOWER_SET_H
