#include "inverter_current_set.h"
#include "ui_inverter_current_set.h"
#include "jqchecksum.h"

Inverter_Current_Set::Inverter_Current_Set(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inverter_Current_Set)
{
    ui->setupUi(this);
}

Inverter_Current_Set::~Inverter_Current_Set()
{
    delete ui;
}

void Inverter_Current_Set::on_set_Inverter_Current_OkBtn_clicked()
{
  if(ui->input_Inverter_Current->text()!="")
    {
      QString str_Open;

   str_Open.append(QChar(0x01));
   str_Open.append(QChar(0x06));
   str_Open.append(QChar(0x00));
   str_Open.append(QChar(0x03));

   QString CurSet = ui->input_Inverter_Current->text();
   int CurSet_Hex = CurSet.toInt(0,10);
   int CurSetH_Bit = CurSet_Hex/256;
   int CurSetL_Bit = CurSet_Hex%256;
   str_Open.append(CurSetH_Bit);
   str_Open.append(CurSetL_Bit);

   auto str1 = JQChecksum::crc16ForModbus(str_Open.toLatin1());//校验

   int CurH_VolSetdata = str1/256;
   int CurL_VolSetdata = str1%256;
   str_Open.append(CurL_VolSetdata);
   str_Open.append(CurH_VolSetdata);
   Inverter_Port->write(str_Open.toLatin1());
   this->close();
   }
}

void Inverter_Current_Set::on_set_Inverter_Current_QuitBtn_clicked()
{
    this->close();
}
