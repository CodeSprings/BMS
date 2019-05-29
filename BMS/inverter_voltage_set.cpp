#include "inverter_voltage_set.h"
#include "ui_inverter_voltage_set.h"
#include "jqchecksum.h"

Inverter_Voltage_Set::Inverter_Voltage_Set(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inverter_Voltage_Set)
{
    ui->setupUi(this);
}

Inverter_Voltage_Set::~Inverter_Voltage_Set()
{
    delete ui;
}

void Inverter_Voltage_Set::on_set_Inverter_Voltage_OkBtn_clicked()
{

    if(ui->input_Inverter_Voltage->text()!="")
    {
    QString str_Open;

   str_Open.append(QChar(0x01));
   str_Open.append(QChar(0x06));
   str_Open.append(QChar(0x00));
   str_Open.append(QChar(0x02));

   QString VolSet = ui->input_Inverter_Voltage->text();
   int VolSet_Hex = VolSet.toInt(0,10);
   int VolSetH_Bit = VolSet_Hex/256;
   int VolSetL_Bit = VolSet_Hex%256;
   str_Open.append(VolSetH_Bit);
   str_Open.append(VolSetL_Bit);
    //crc校验部分，先将输入的电压电流数值进行CRC校验
   auto str1 = JQChecksum::crc16ForModbus(str_Open.toLatin1());

   int H_VolSetdata = str1/256;
   int L_VolSetdata = str1%256;
   str_Open.append(L_VolSetdata);
   str_Open.append(H_VolSetdata);
   Inverter_Port->write(str_Open.toLatin1());
   this->close();
    }
}

void Inverter_Voltage_Set::on_set_Inverter_Voltage_QuitBtn_clicked()
{
    this->close();
}

