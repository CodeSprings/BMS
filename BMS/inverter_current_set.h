#ifndef INVERTER_CURRENT_SET_H
#define INVERTER_CURRENT_SET_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>

namespace Ui {
class Inverter_Current_Set;
}

class Inverter_Current_Set : public QDialog
{
    Q_OBJECT

public:
    explicit Inverter_Current_Set(QWidget *parent = 0);
    ~Inverter_Current_Set();
    QSerialPort *Inverter_Port;

private slots:
    void on_set_Inverter_Current_OkBtn_clicked();

    void on_set_Inverter_Current_QuitBtn_clicked();

private:
    Ui::Inverter_Current_Set *ui;
};

#endif // INVERTER_CURRENT_SET_H
