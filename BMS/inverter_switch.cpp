#include "inverter_switch.h"
#include "ui_inverter_switch.h"

Inverter_Switch::Inverter_Switch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inverter_Switch)
{
    ui->setupUi(this);
    COM_Flag=0;
}

Inverter_Switch::~Inverter_Switch()
{
    delete ui;
}


void Inverter_Switch::on_Inverter_Switch_OkBtn_clicked()
{

    if(COM_Flag==1)
    {
        QString str_Open;
        str_Open.append(QChar(0x01));
        str_Open.append(QChar(0x05));
        str_Open.append(QChar(0x00));
        str_Open.append(QChar(0x01));
        str_Open.append(QChar(0xFF));
        str_Open.append(QChar(0x00));
        str_Open.append(QChar(0xDD));
        str_Open.append(QChar(0xFA));
        Inverter_Port->write(str_Open.toLatin1());
        this->close();
    }
    else if(COM_Flag==2)
    {
        QString str_Close;
        str_Close.append(QChar(0x01));
        str_Close.append(QChar(0x05));
        str_Close.append(QChar(0x00));
        str_Close.append(QChar(0x01));
        str_Close.append(QChar(0x00));
        str_Close.append(QChar(0x00));
        str_Close.append(QChar(0x9C));
        str_Close.append(QChar(0x0A));

        Inverter_Port->write(str_Close.toLatin1());
        this->close();
    }
}



void Inverter_Switch::on_Inverter_Switch_QuitBtn_clicked()
{
    this->close();
}



void Inverter_Switch::on_Inverter_Open_Btn_clicked()
{
    COM_Flag=1;
}

void Inverter_Switch::on_Inverter_Close_Btn_clicked()
{
    COM_Flag=2;
}

