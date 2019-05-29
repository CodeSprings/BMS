#include "stove4_temperature_set.h"
#include "ui_stove4_temperature_set.h"

bool Stove4_Temperature_Set::Stove4_temp_read_stop = false;

Stove4_Temperature_Set::Stove4_Temperature_Set(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stove4_Temperature_Set)
{
    ui->setupUi(this);
}

Stove4_Temperature_Set::~Stove4_Temperature_Set()
{
    delete ui;
}

void Stove4_Temperature_Set::on_stove4_Temperature_Set_OkBtn_clicked()
{

    stove4_Temperature_Set();
}
void Stove4_Temperature_Set::stove4_Temperature_Set()
{
    this->close();
    Stove4_temp_read_stop = true;
    sleep(1000);
    if(ui->input_Start_Temperature->text()!="")
    {
        QString str;

        str.append(QChar(0x84));
        str.append(QChar(0x84));
        str.append(QChar(0x43));
        str.append(QChar(0x50));

        QString str_Stove = ui->input_Start_Temperature->text();
        int stove_Hex=str_Stove.toFloat(0)*10;
        int stove_H_Bit=stove_Hex/256;
        int stove_L_Bit=stove_Hex%256;
        str.append(stove_L_Bit);
        str.append(stove_H_Bit);

        int parity_Hex=80*256+71+str_Stove.toFloat(0)*10;
        int parity_L_Bit=parity_Hex%256;
        int parity_H_Bit=parity_Hex/256;
        str.append(parity_L_Bit);
        str.append(parity_H_Bit);

        Stove_Port->write(str.toLatin1());
    }

    sleep(200);
    if(ui->input_Time1->text()!="")
    {
        QString str;

        str.append(QChar(0x84));
        str.append(QChar(0x84));
        str.append(QChar(0x43));
        str.append(QChar(0x51));

        QString str_Stove = ui->input_Time1->text();
        int stove_Hex=str_Stove.toFloat(0)*10;
        int stove_H_Bit=stove_Hex/256;
        int stove_L_Bit=stove_Hex%256;
        str.append(stove_L_Bit);
        str.append(stove_H_Bit);

        int parity_Hex=81*256+71+str_Stove.toFloat(0)*10;
        int parity_L_Bit=parity_Hex%256;
        int parity_H_Bit=parity_Hex/256;
        str.append(parity_L_Bit);
        str.append(parity_H_Bit);

        Stove_Port->write(str.toLatin1());

    }
    sleep(200);
    if(ui->input_Terminal_Temperature1->text()!="")
    {
        QString str;

        str.append(QChar(0x84));
        str.append(QChar(0x84));
        str.append(QChar(0x43));
        str.append(QChar(0x52));

        QString str_Stove = ui->input_Terminal_Temperature1->text();
        int stove_Hex=str_Stove.toFloat(0)*10;
        int stove_H_Bit=stove_Hex/256;
        int stove_L_Bit=stove_Hex%256;
        str.append(stove_L_Bit);
        str.append(stove_H_Bit);

        int parity_Hex=82*256+71+str_Stove.toFloat(0)*10;
        int parity_L_Bit=parity_Hex%256;
        int parity_H_Bit=parity_Hex/256;
        str.append(parity_L_Bit);
        str.append(parity_H_Bit);

        Stove_Port->write(str.toLatin1());

    }
    sleep(200);
    if(ui->input_Time2->text()!="")
    {
        QString str;

        str.append(QChar(0x84));
        str.append(QChar(0x84));
        str.append(QChar(0x43));
        str.append(QChar(0x53));

        QString str_Stove = ui->input_Time2->text();
        int stove_Hex=str_Stove.toFloat(0)*10;
        int stove_H_Bit=stove_Hex/256;
        int stove_L_Bit=stove_Hex%256;
        str.append(stove_L_Bit);
        str.append(stove_H_Bit);

        int parity_Hex=83*256+71+str_Stove.toFloat(0)*10;
        int parity_L_Bit=parity_Hex%256;
        int parity_H_Bit=parity_Hex/256;
        str.append(parity_L_Bit);
        str.append(parity_H_Bit);

        Stove_Port->write(str.toLatin1());

    }
    sleep(200);
    if(ui->input_Terminal_Temperature2->text()!="")
    {
        QString str;

        str.append(QChar(0x84));
        str.append(QChar(0x84));
        str.append(QChar(0x43));
        str.append(QChar(0x54));

        QString str_Stove = ui->input_Terminal_Temperature2->text();
        int stove_Hex=str_Stove.toFloat(0)*10;
        int stove_H_Bit=stove_Hex/256;
        int stove_L_Bit=stove_Hex%256;
        str.append(stove_L_Bit);
        str.append(stove_H_Bit);

        int parity_Hex=84*256+71+str_Stove.toFloat(0)*10;
        int parity_L_Bit=parity_Hex%256;
        int parity_H_Bit=parity_Hex/256;
        str.append(parity_L_Bit);
        str.append(parity_H_Bit);

        Stove_Port->write(str.toLatin1());

    }
    sleep(200);
    if(ui->input_Time3->text()!="")
    {
        QString str;

        str.append(QChar(0x84));
        str.append(QChar(0x84));
        str.append(QChar(0x43));
        str.append(QChar(0x55));

        QString str_Stove = ui->input_Time3->text();
        int stove_Hex=str_Stove.toFloat(0)*10;
        int stove_H_Bit=stove_Hex/256;
        int stove_L_Bit=stove_Hex%256;
        str.append(stove_L_Bit);
        str.append(stove_H_Bit);

        int parity_Hex=85*256+71+str_Stove.toFloat(0)*10;
        int parity_L_Bit=parity_Hex%256;
        int parity_H_Bit=parity_Hex/256;
        str.append(parity_L_Bit);
        str.append(parity_H_Bit);

        Stove_Port->write(str.toLatin1());

    }
    sleep(200);
    if(ui->input_Terminal_Temperature3->text()!="")
    {
        QString str;

        str.append(QChar(0x84));
        str.append(QChar(0x84));
        str.append(QChar(0x43));
        str.append(QChar(0x56));

        QString str_Stove = ui->input_Terminal_Temperature3->text();
        int stove_Hex=str_Stove.toFloat(0)*10;
        int stove_H_Bit=stove_Hex/256;
        int stove_L_Bit=stove_Hex%256;
        str.append(stove_L_Bit);
        str.append(stove_H_Bit);

        int parity_Hex=86*256+71+str_Stove.toFloat(0)*10;
        int parity_L_Bit=parity_Hex%256;
        int parity_H_Bit=parity_Hex/256;
        str.append(parity_L_Bit);
        str.append(parity_H_Bit);

        Stove_Port->write(str.toLatin1());
    }
    sleep(200);
    if(ui->input_Time4->text()!="")
    {
        QString str;

        str.append(QChar(0x84));
        str.append(QChar(0x84));
        str.append(QChar(0x43));
        str.append(QChar(0x57));

        QString str_Stove = ui->input_Time4->text();
        int stove_Hex=str_Stove.toFloat(0)*10;
        int stove_H_Bit=stove_Hex/256;
        int stove_L_Bit=stove_Hex%256;
        str.append(stove_L_Bit);
        str.append(stove_H_Bit);

        int parity_Hex=87*256+71+str_Stove.toFloat(0)*10;
        int parity_L_Bit=parity_Hex%256;
        int parity_H_Bit=parity_Hex/256;
        str.append(parity_L_Bit);
        str.append(parity_H_Bit);

        Stove_Port->write(str.toLatin1());
    }
    sleep(200);
    if(ui->input_Terminal_Temperature4->text()!="")
    {
        QString str;

        str.append(QChar(0x84));
        str.append(QChar(0x84));
        str.append(QChar(0x43));
        str.append(QChar(0x58));

        QString str_Stove = ui->input_Terminal_Temperature4->text();
        int stove_Hex=str_Stove.toFloat(0)*10;
        int stove_H_Bit=stove_Hex/256;
        int stove_L_Bit=stove_Hex%256;
        str.append(stove_L_Bit);
        str.append(stove_H_Bit);

        int parity_Hex=88*256+71+str_Stove.toFloat(0)*10;
        int parity_L_Bit=parity_Hex%256;
        int parity_H_Bit=parity_Hex/256;
        str.append(parity_L_Bit);
        str.append(parity_H_Bit);

        Stove_Port->write(str.toLatin1());
    }
    sleep(200);
    if(ui->input_Time5->text()!="")
    {
        QString str;

        str.append(QChar(0x84));
        str.append(QChar(0x84));
        str.append(QChar(0x43));
        str.append(QChar(0x59));

        QString str_Stove = ui->input_Time5->text();
        int stove_Hex=str_Stove.toFloat(0)*10;
        int stove_H_Bit=stove_Hex/256;
        int stove_L_Bit=stove_Hex%256;
        str.append(stove_L_Bit);
        str.append(stove_H_Bit);

        int parity_Hex=89*256+71+str_Stove.toFloat(0)*10;
        int parity_L_Bit=parity_Hex%256;
        int parity_H_Bit=parity_Hex/256;
        str.append(parity_L_Bit);
        str.append(parity_H_Bit);

        Stove_Port->write(str.toLatin1());
    }
    Stove4_temp_read_stop = false;
}



void Stove4_Temperature_Set::on_stove4_Temperature_Set_QuitBtn_clicked()
{
    this->close();
}


void Stove4_Temperature_Set::sleep(unsigned int msec)
{
    QTime reachTime=QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<reachTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}


