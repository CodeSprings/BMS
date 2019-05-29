#include "inverter_activepower_set.h"
#include "ui_inverter_activepower_set.h"
#include "jqchecksum.h"

Inverter_ActivePower_Set::Inverter_ActivePower_Set(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inverter_ActivePower_Set)
{
    ui->setupUi(this);
}

Inverter_ActivePower_Set::~Inverter_ActivePower_Set()
{
    delete ui;
}

void Inverter_ActivePower_Set::on_set_Inverter_ActivePower_OkBtn_clicked()
{

    if(ui->input_Inverter_ActivePower->text()!="")
    {
    QString str_Open;

    str_Open.append(QChar(0x01));
    str_Open.append(QChar(0x06));
    str_Open.append(QChar(0x00));
    str_Open.append(QChar(0x00));

    QString Power = ui->input_Inverter_ActivePower->text();
    int Power_Hex = Power.toInt(0,10);
    int H_Bit = Power_Hex/256;
    int L_Bit = Power_Hex%256;
    str_Open.append(H_Bit);
    str_Open.append(L_Bit);

    auto str1 = JQChecksum::crc16ForModbus(str_Open.toLatin1());

    int H_powerdata = str1/256;
    int L_powerdata = str1%256;
    str_Open.append(L_powerdata);
    str_Open.append(H_powerdata);
    Inverter_Port->write(str_Open.toLatin1());
    this->close();
    }
}

void Inverter_ActivePower_Set::on_set_Inverter_ActivePower_QuitBtn_clicked()
{
    this->close();
}

