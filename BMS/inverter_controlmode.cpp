#include "inverter_controlmode.h"
#include "ui_inverter_controlmode.h"

Inverter_ControlMode::Inverter_ControlMode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inverter_ControlMode)
{
    ui->setupUi(this);
    Mode_Flag=0;
}

Inverter_ControlMode::~Inverter_ControlMode()
{
    delete ui;
}

void Inverter_ControlMode::on_Inverter_ControlMode_OkBtn_clicked()
{

    if(Mode_Flag!=0)
    {
    QString str_Open;

    str_Open.append(QChar(0x01));
    str_Open.append(QChar(0x06));
    str_Open.append(QChar(0x00));
    str_Open.append(QChar(0x04));
    switch(Mode_Flag)
    {

    case 1:{
            str_Open.append(QChar(0x00));
            str_Open.append(QChar(0x01));
            str_Open.append(QChar(0x09));
            str_Open.append(QChar(0xCB));
            Inverter_Port->write(str_Open.toLatin1());
            } break;
    case 2:{
            str_Open.append(QChar(0x00));
            str_Open.append(QChar(0x02));

            str_Open.append(QChar(0x49));
            str_Open.append(QChar(0xCA));
            Inverter_Port->write(str_Open.toLatin1());
            } break;
    case 3:{
            str_Open.append(QChar(0x00));
            str_Open.append(QChar(0x03));
            str_Open.append(QChar(0x88));
            str_Open.append(QChar(0x0A));
            Inverter_Port->write(str_Open.toLatin1());
            } break;
    case 4:{
            str_Open.append(QChar(0x00));
            str_Open.append(QChar(0x04));
            str_Open.append(QChar(0xC9));
            str_Open.append(QChar(0xC8));
            Inverter_Port->write(str_Open.toLatin1());
            } break;
    default: break;
    }
    this->close();
    }
}

void Inverter_ControlMode::on_Inverter_ControlMode_QuitBtn_clicked()
{
    this->close();
}

void Inverter_ControlMode::on_Constant_Current_Charging_Btn_clicked()
{
    Mode_Flag = 1;
}

void Inverter_ControlMode::on_Constant_Current_Discharge_Btn_clicked()
{
    Mode_Flag = 2;
}

void Inverter_ControlMode::on_Constant_Power_Charging_Btn_clicked()
{
    Mode_Flag = 3;
}

void Inverter_ControlMode::on_Constant_Power_Discharge_Btn_clicked()
{
    Mode_Flag = 4;
}
