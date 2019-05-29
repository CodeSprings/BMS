#include "main_interface.h"
#include "ui_main_interface.h"
#include <QDebug>

XmlWriter xmlWriter;

//Parameter_Range_Set GetParaRange;
static bool closeWrite = false;

QString temp_data[119];

double ParaRange [16];

QDateTime *currDateTime = new QDateTime(QDateTime::currentDateTime());

Main_Interface::Main_Interface(QWidget *parent) :
    QDialog(parent),
    // 启动系统进行各项设置
    ui(new Ui::Main_Interface)
{
    ui->setupUi(this);

    //串口指针初始化
    Inverter_Port = new QSerialPort(this);
    Stove_Port = new QSerialPort(this);

    //初始化接收帧数组
    for(int i=0;i<200;i++)
    {
        vco[i].ID=0;
        vco[i].DataLen=8;
        vco[i].RemoteFlag=0;
        vco[i].SendType=0;
        vco[i].TimeFlag=0;
        vco[i].TimeStamp=0;
        vco[i].ExternFlag=0;
        for(int j=0;j<3;j++)
        {
            vco[i].Reserved[j]=0;
        }
        for(int j=0;j<8;j++)
        {
            vco[i].Data[j]=0;
        }
    }


    //逆变器、电池、炉子定时器
    Battery_timer = new QTimer(this);
    Inverter_timer = new QTimer(this);
    Stove_timer = new QTimer(this);

    connect(Inverter_timer, SIGNAL(timeout()), this, SLOT(send_Read_Inverter()));
    connect(Inverter_Port, SIGNAL(readyRead()), this, SLOT(read_Inverter()));

    connect(Battery_timer, SIGNAL(timeout()), this, SLOT(read_Battery()));

    connect(Stove_timer, SIGNAL(timeout()), this, SLOT(send_Read_Stove()));
    connect(Stove_Port, SIGNAL(readyRead()), this, SLOT(read_Stove()));

    connect(this,SIGNAL(inverter_Charge_Mode()),this,SLOT(send_Inverter_Mode()));
    connect(this,SIGNAL(delay_open_success()),this,SLOT(open_delay_success()));
    connect(this,SIGNAL(delay_close_success()),this,SLOT(close_delay_success()));

    this->InitPlot();         //绘图函数初始化

    //子窗口初始化
    Inverter_ActivePower_Set_Dialog = NULL;
    Inverter_ControlMode_Dialog = NULL;
    Inverter_Current_Set_Dialog = NULL;
    Inverter_Switch_Dialog = NULL;
    Inverter_Voltage_Set_Dialog = NULL;
    Stove1_Temperature_Set_Dialog = NULL;
    Stove2_Temperature_Set_Dialog = NULL;
    Stove3_Temperature_Set_Dialog = NULL;
    Stove4_Temperature_Set_Dialog = NULL;


    for(int i=0;i<4;i++)
    {
        Stove_Flag[i]=0;
        Stove_Temperature[i]=0;
    }

    for(int i=0;i<2;i++)
    {
        capacity[i]=0;
    }

    inverter_Flag=0;
    Mode_Flag = 0;
    port_Flag=0;
    can_Flag=0;
    delay_Flag=0;
}

Main_Interface::~Main_Interface()
{
    delete ui;
}


//打开串口并对串口初始化或关闭串口
void Main_Interface::on_open_Port_Btn_clicked()
{
    if(ui->open_Port_Btn->text()==tr("打开串口"))
    {
        port_Flag=0;
    }
    if(ui->open_Port_Btn->text()==tr("关闭串口"))
    {
        port_Flag=1;
    }
    switch (port_Flag) {
    case 0:
    {
        Inverter_Port->setPortName("COM1");
        Inverter_Port->open(QSerialPort::ReadWrite);
        Inverter_Port->setBaudRate(QSerialPort::Baud9600);
        Inverter_Port->setDataBits(QSerialPort::Data8);
        Inverter_Port->setFlowControl(QSerialPort::NoFlowControl);
        Inverter_Port->setParity(QSerialPort::NoParity);
        Inverter_Port->setStopBits(QSerialPort::OneStop);

        Stove_Port->setPortName("COM15");
        Stove_Port->open(QSerialPort::ReadWrite);
        Stove_Port->setBaudRate(QSerialPort::Baud9600);
        Stove_Port->setDataBits(QSerialPort::Data8);
        Stove_Port->setFlowControl(QSerialPort::NoFlowControl);
        Stove_Port->setParity(QSerialPort::NoParity);
        Stove_Port->setStopBits(QSerialPort::OneStop);

        ui->open_Port_Btn->setText("关闭串口");

        Inverter_timer->start(1000);
        Stove_timer->start(1000);
    } break;

    case 1:
    {

        Inverter_timer->stop();
        Stove_timer->stop();
        Inverter_Port->close();
        Stove_Port->close();
        ui->open_Port_Btn->setText("打开串口");

    } break;

    }

}


//打开CAN设备并初始化或关闭CAN设备
void Main_Interface::on_open_Can_Btn_clicked()
{
    if(ui->open_Can_Btn->text()==tr("关闭CAN"))
    {
        can_Flag=0;
    }

    if(ui->open_Can_Btn->text()==tr("打开CAN"))
    {
        can_Flag=1;
    }

    switch (can_Flag)
    {
    case 0:
    {
        Battery_timer->stop();
        close_can=CloseDevice(nDeviceType,nDeviceInd);
        ui->open_Can_Btn->setText("打开CAN");

    } break;

    case 1:
    {
        dwRel=OpenDevice(nDeviceType,nDeviceInd,nReserevd);
        if(dwRel!=STATUS_OK)
        {
            QMessageBox::critical(NULL,"Alarm","打开失败!",QMessageBox::Ok);
        }
        else
        {
            vic.AccCode=0;
            vic.AccMask=0xffffff;
            vic.Filter=0;
            vic.Timing0=0;
            vic.Timing1=0x1c;
            vic.Mode=0;
            dwRel=InitCAN(nDeviceType,nDeviceInd,nCANInd,&vic);
            if(dwRel==STATUS_ERR)
            {
                close_can=CloseDevice(nDeviceType,nDeviceInd);
                QMessageBox::critical(NULL,"Alarm","初始化失败！",QMessageBox::Ok);
            }
            else
            {
                dwRel=StartCAN(nDeviceType,nDeviceInd,nCANInd);
                if(dwRel==STATUS_ERR)
                {
                    close_can=CloseDevice(nDeviceType,nDeviceInd);
                    QMessageBox::critical(NULL,"Alarm","启动设备失败！",QMessageBox::Ok);
                }
                else
                {
                    ui->open_Can_Btn->setText("关闭CAN");
                    Battery_timer->start(100);
                }

            }
        }
    }




    }


}


// 主窗口显示完成之后运行下列程序
void Main_Interface::on_Main_Interface_shown()
{
    //setWindowFlags(windowFlags() & (~Qt::WindowCloseButtonHint));
    //show();
    xmlWriter.logBox = currDateTime->toString("yyyy-MM-dd hh:mm:ss") + "    系统启动成功";
    ui->LogBox->append(xmlWriter.logBox);
    LcdDateTime();
    LogWiget();
    XMLTimer();
    ReadParaIni();
}

// 产生随机数
void Main_Interface::GenerateTemp_data()
{
    /*qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    QString Dec[35];
    for(int i = 0; i < 35; i++)
    {
        int test = qrand() % 10000;
        Dec[i] = QString::number(test);
    }
    for(int i = 0; i < 2; i++)
    {
        int test = qrand() % 20 + 200;
        temp_data[i] = QString::number(test) + "." + Dec[i];
    }
    for(int i = 2; i < 3; i++)
    {
        int test = qrand() % 20 + 40;
        temp_data[i] = QString::number(test) + "." + Dec[i];
    }
    for(int i = 3; i < 87; i++)
    {
        int test = qrand() % 10000 + 15000;
        int v1 = test / 10000;
        int v2 = test % 10000;
        temp_data[i] = QString::number(v1) + "." + QString::number(v2);
    }
    for(int i = 87; i < 119; i++)
    {
        int test = qrand() % 50 + 300;
        temp_data[i] = QString::number(test) + "." + Dec[i - 84];
    }
*/
}

// 显示逆变器开关对应界面
void Main_Interface::on_show_Inverter_Btn_clicked()
{
    if (Inverter_Switch_Dialog == NULL)
    {
        Inverter_Switch_Dialog = new Inverter_Switch(this);
        Inverter_Switch_Dialog->Inverter_Port = Inverter_Port;
        Inverter_Switch_Dialog->show();
    }
    else
        Inverter_Switch_Dialog->show();
    return;
}

// 发送读取逆变器信息的命令
void Main_Interface::send_Read_Inverter()
{
    QString str;

    str.append(QChar(0x01));
    str.append(QChar(0x03));
    str.append(QChar(0x00));
    str.append(QChar(0x00));
    str.append(QChar(0x00));
    str.append(QChar(0x32));
    str.append(QChar(0xC4));
    str.append(QChar(0x1F));

    Inverter_Port->write(str.toLatin1());

}

// 判断串口字节数达标后，调用读取逆变器信息函数
void Main_Interface::read_Inverter()
{
    if (Inverter_Port->bytesAvailable() >= 105)
    {
        show_Inverter_Msg();
    }
}

// 读取串口的逆变器信息并在界面上显示
void Main_Interface::show_Inverter_Msg()
{

    QByteArray  temp = Inverter_Port->readAll();
    QString str;
    int L_Bit = temp[0];
    int H_Bit = temp[1];
    if ((L_Bit == 0x01) && (H_Bit == 0x03))
    {
        //有功给定
        int Power_set_H, Power_set_L;
        Power_set_H = temp[3];
        Power_set_L = temp[4];
        if (Power_set_L<0)
            Power_set_L = Power_set_L + 256;
        if (Power_set_H<0)
            Power_set_H = Power_set_H + 256;
        double Power_set;
        Power_set = ((double)(Power_set_H * 256 + Power_set_L));
        ui->show_Power_Set->display(str.setNum(Power_set));

        //电压给定
        int V_set_H, V_set_L;
        V_set_H = temp[7];
        V_set_L = temp[8];
        if (V_set_L<0)
            V_set_L = V_set_L + 256;
        if (V_set_H<0)
            V_set_H = V_set_H + 256;
        double V_set;
        V_set = ((double)(V_set_H * 256 + V_set_L));
        ui->show_Voltage_Set->display(str.setNum(V_set));

        //电流给定
        int I_set_H, I_set_L;
        I_set_H = temp[9];
        I_set_L = temp[10];
        if (I_set_L<0)
            I_set_L = I_set_L + 256;
        if (I_set_H<0)
            I_set_H = I_set_H + 256;
        double I_set;
        I_set = ((double)(I_set_H * 256 + I_set_L));
        ui->show_Current_Set->display(str.setNum(I_set));

        //控制模式
        int Col_set = temp[12];
        switch (Col_set)
        {
        case 0: {ui->show_Control_Mode->setText("恒电压充电"); break; }
        case 1: {ui->show_Control_Mode->setText("恒电流放电"); break; }
        case 2: {ui->show_Control_Mode->setText("恒电流充电"); break; }
        case 3: {ui->show_Control_Mode->setText("恒功率放电"); break; }
        case 4: {ui->show_Control_Mode->setText("恒功率充电"); break; }
        default:break;
        }


        //逆变器频率
        long int Frequence_H, Frequence_L;
        Frequence_H = temp[61];
        Frequence_L = temp[62];
        if (Frequence_L<0)
            Frequence_L = Frequence_L + 256;
        if (Frequence_H<0)
            Frequence_H = Frequence_H + 256;
        double Frequence;
        Frequence = ((double)(Frequence_H * 256 + Frequence_L)) / 10.0;
        ui->show_Inverter_Frequency->display(str.setNum(Frequence));

        //有功功率
        long int Pac_H, Pac_L;
        Pac_H = temp[65];
        Pac_L = temp[66];
        if (Pac_L<0)
            Pac_L = Pac_L + 256;
        if (Pac_H<0)
            Pac_H = Pac_H + 256;
        double Pac;
        Pac = ((double)(Pac_H * 256 + Pac_L)) / 10.0;
        ui->show_Active_Power->display(str.setNum(Pac));

        //逆变器效率
        long int Effective_H, Effective_L;
        Effective_H = temp[69];
        Effective_L = temp[70];
        if (Effective_L<0)
            Effective_L = Effective_L + 256;
        if (Effective_H<0)
            Effective_H = Effective_H + 256;
        double Effective;
        Effective = ((double)(Effective_H * 256 + Effective_L)) / 10.0;
        ui->show_Inverter_Efficiency->display(str.setNum(Effective));

        //设备运行状态

        long int Work_State_L;
        Work_State_L = temp[74];
        switch (Work_State_L)
        {

        case 1:
        {
            ui->show_Inverter_Wait->setStyleSheet("background-color: rgb(24, 255, 82);");
        }break;
        case 2:
        {
            ui->show_Inverter_Start->setStyleSheet("background-color: rgb(24, 255, 82);");
        }break;
        case 3:
        {
            ui->show_Inverter_Soft_Charging->setStyleSheet("background-color: rgb(24, 255, 82);");
        }break;
        case 4:
        {
            ui->show_Inverter_Combination_Contactor->setStyleSheet("background-color: rgb(24, 255, 82);");
        }break;
        case 5:
        {
            ui->show_Inverter_Fault->setStyleSheet("background-color: rgb(24, 255, 82);");
        }break;
        case 6:
        {
            ui->show_Inverter_Stop->setStyleSheet("background-color: rgb(24, 255, 82);");
        }break;
        case 7:
        {
            ui->show_Inverter_Combination_DCswitch->setStyleSheet("background-color: rgb(24, 255, 82);");
        }break;

        case 8:
        {
            ui->show_Inverter_Stop->setStyleSheet("background-color: rgb(24, 255, 82);");
        }break;
        case 9:
        {
            ui->show_Inverter_Discharge->setStyleSheet("background-color: rgb(24, 255, 82);");
        }break;
        case 10:
        {
            ui->show_Inverter_Charging->setStyleSheet("background-color: rgb(24, 255, 82);");
        }break;
        default: break;

        }

        //无功功率
        long int Qac_H, Qac_L;
        Qac_H = temp[85];
        Qac_L = temp[86];
        if (Qac_L<0)
            Qac_L = Qac_L + 256;
        if (Qac_H<0)
            Qac_H = Qac_H + 256;
        double Qac;
        Qac = ((double)(Qac_H * 256 + Qac_L)) / 10.0;
        ui->show_Reactive_Power->display(str.setNum(Qac));


        //直流功率
        long int Power_H, Power_L;
        Power_H = temp[89];
        Power_L = temp[90];
        double Power;

        if (Power_L<0)
            Power_L = Power_L + 256;
        if (Power_H<0)
        {
            Power_H = Power_H + 256;
            Power = ((double)((Power_H * 256 + Power_L) - 65536)) / 10.0;
        }
        else Power = ((double)(Power_H * 256 + Power_L)) / 10.0;
        ui->show_DC_Power->display(str.setNum(Power));

        //设备故障信息
        long int Equipment_Error_H, Equipment_Error_L;
        Equipment_Error_H = temp[101];
        Equipment_Error_L = temp[102];
        if ((Equipment_Error_L & 0x01) == 0x01)
            ui->show_DC_Overvoltage->setStyleSheet("background-color: rgb(250, 0, 0  );");
        else ui->show_DC_Overvoltage->setStyleSheet("background-color: rgb(111, 111, 111  );");
        if ((Equipment_Error_L & 0x02) == 0x02)
            ui->show_DC_Overcurrent->setStyleSheet("background-color: rgb(250, 0, 0  );");
        else ui->show_DC_Overcurrent->setStyleSheet("background-color: rgb(111, 111, 111  );");
        if ((Equipment_Error_L & 0x04) == 0x04)
            ui->show_Islanding_Fault->setStyleSheet("background-color: rgb(250, 0, 0  );");
        else ui->show_Islanding_Fault->setStyleSheet("background-color: rgb(111, 111, 111  );");
        if ((Equipment_Error_L & 0x08) == 0x08)
            ui->show_Grid_Overvoltage->setStyleSheet("background-color: rgb(250,0,0);");
        else ui->show_Grid_Overvoltage->setStyleSheet("background-color: rgb(111,111,111);");
        if ((Equipment_Error_L & 0x10) == 0x10)
            ui->show_Grid_Undervoltage->setStyleSheet("background-color: rgb(250, 0, 0  );");
        else ui->show_Grid_Undervoltage->setStyleSheet("background-color: rgb(111,111,111  );");
        if ((Equipment_Error_L & 0x20) == 0x20)
            ui->show_Grid_Overfrequency->setStyleSheet("background-color: rgb(250, 0, 0  );");
        else ui->show_Grid_Overfrequency->setStyleSheet("background-color: rgb(111,111,111);");
        if ((Equipment_Error_L & 0x40) == 0x40)
            ui->show_Grid_Underfrequency->setStyleSheet("background-color: rgb(250, 0, 0  );");
        else ui->show_Grid_Underfrequency->setStyleSheet("background-color: rgb(111,111,111 );");
        if ((Equipment_Error_L & 0x80) == 0x80)
            ui->show_AC_Overcurrent->setStyleSheet("background-color: rgb(250, 0, 0  );");
        else  ui->show_AC_Overcurrent->setStyleSheet("background-color: rgb(111,111,111 );");

        if ((Equipment_Error_H & 0x01) == 0x01)
            ui->show_Communication_Anomaly->setStyleSheet("background-color: rgb(250, 0, 0  );");

        else ui->show_Communication_Anomaly->setStyleSheet("background-color: rgb(111,111,111  );");
        if ((Equipment_Error_H & 0x02) == 0x02)
            ui->show_Inverter_OverTemperature->setStyleSheet("background-color: rgb(250, 0, 0  );");
        else ui->show_Inverter_OverTemperature->setStyleSheet("background-color: rgb(111,111,111 );");
        if ((Equipment_Error_H & 0x04) == 0x04)
            ui->show_Fan_Fault->setStyleSheet("background-color: rgb(250, 0, 0  );");
        else ui->show_Fan_Fault->setStyleSheet("background-color: rgb(111,111,111);");
        if ((Equipment_Error_H & 0x08) == 0x08)
            ui->show_Contactor_Fault->setStyleSheet("background-color: rgb(250, 0, 0  );");
        else ui->show_Contactor_Fault->setStyleSheet("background-color: rgb(111,111,111  );");
        if ((Equipment_Error_H & 0x10) == 0x10)
            ui->show_Lightning_Arrester_Fault->setStyleSheet("background-color: rgb(250, 0, 0  );");
        else ui->show_Lightning_Arrester_Fault->setStyleSheet("background-color: rgb(111,111,111 );");
        if ((Equipment_Error_H & 0x20) == 0x20)
            ui->show_Phase_Sequence_Fault->setStyleSheet("background-color: rgb(250, 0, 0  );");
        else ui->show_Phase_Sequence_Fault->setStyleSheet("background-color: rgb(111,111,111  );");
        if ((Equipment_Error_H & 0x40) == 0x40)
            ui->show_Drive_Fault->setStyleSheet("background-color: rgb(250, 0, 0  );");
        else ui->show_Drive_Fault->setStyleSheet("background-color: rgb(111,111,111);");
        if ((Equipment_Error_H & 0x80) == 0x80)
            ui->show_Charging_Fault->setStyleSheet("background-color: rgb(250, 0, 0  );");
        else  ui->show_Charging_Fault->setStyleSheet("background-color: rgb(111,111,111);");
    }
    temp.clear();
}

// 通过电池容量和电压来调整逆变器控制模式
void Main_Interface::send_Inverter_Mode()
{
    if(capacity[0]>=325&&inverter_Flag==0)
    {
        inverter_Flag=1;
        QString str;
        str.append(QChar(0x01));
        str.append(QChar(0x06));
        str.append(QChar(0x00));
        str.append(QChar(0x04));
        str.append(QChar(0x00));
        str.append(QChar(0x01));
        str.append(QChar(0x09));
        str.append(QChar(0xCB));

        Inverter_Port->write(str.toLatin1());
    }
    if(capacity[0]>=0&&capacity[0]<=325&&inverter_Flag==1)
    {
        inverter_Flag=0;
        QString str;
        str.append(QChar(0x01));
        str.append(QChar(0x06));
        str.append(QChar(0x00));
        str.append(QChar(0x04));
        str.append(QChar(0x00));
        str.append(QChar(0x02));
        str.append(QChar(0x49));
        str.append(QChar(0xCA));

        Inverter_Port->write(str.toLatin1());

    }
}

// 显示逆变器有功功率设定子窗口
void Main_Interface::on_set_Active_Power_Btn_clicked()
{

    if (Inverter_ActivePower_Set_Dialog == NULL)
    {
        Inverter_ActivePower_Set_Dialog = new Inverter_ActivePower_Set(this);
        Inverter_ActivePower_Set_Dialog->Inverter_Port = Inverter_Port;
        Inverter_ActivePower_Set_Dialog->show();
    }
    else
        Inverter_ActivePower_Set_Dialog->show();
    return;
}

// 显示逆变器电流设定子窗口
void Main_Interface::on_set_Current_Btn_clicked()
{
    if (Inverter_Current_Set_Dialog == NULL)
    {
        Inverter_Current_Set_Dialog = new Inverter_Current_Set(this);
        Inverter_Current_Set_Dialog->Inverter_Port = Inverter_Port;
        Inverter_Current_Set_Dialog->show();
    }
    else
        Inverter_Current_Set_Dialog->show();
    return;

}

// 显示逆变器电压设定子窗口
void Main_Interface::on_set_Voltage_Btn_clicked()
{
    if (Inverter_Voltage_Set_Dialog == NULL)
    {
        Inverter_Voltage_Set_Dialog = new Inverter_Voltage_Set(this);
        Inverter_Voltage_Set_Dialog->Inverter_Port = Inverter_Port;
        Inverter_Voltage_Set_Dialog->show();
    }
    else
        Inverter_Voltage_Set_Dialog->show();
    return;

}

// 显示逆变器控制模式设定子窗口
void Main_Interface::on_set_Control_Mode_Btn_clicked()
{
    if (Inverter_ControlMode_Dialog == NULL)
    {
        Inverter_ControlMode_Dialog = new Inverter_ControlMode(this);
        Inverter_ControlMode_Dialog->Inverter_Port = Inverter_Port;
        Inverter_ControlMode_Dialog->show();
    }
    else
        Inverter_ControlMode_Dialog->show();
    return;
}

// 读取电池串口的总电流，总电压，并显示出来；通过判断来决定逆变器控制模式
void Main_Interface::read_Battery()
{
    QLCDNumber *LCDNumber[] ={
        ui->show_TotalBattery_Voltage1, ui->show_TotalBattery_Voltage2, ui->show_TotalBattery_Current,
        ui->show_Battery1_Voltage1,  ui->show_Battery1_Voltage2,  ui->show_Battery1_Voltage3,
        ui->show_Battery1_Voltage4,  ui->show_Battery1_Voltage5,  ui->show_Battery1_Voltage6,
        ui->show_Battery1_Voltage7,  ui->show_Battery1_Voltage8,  ui->show_Battery1_Voltage9,
        ui->show_Battery1_Voltage10, ui->show_Battery1_Voltage11, ui->show_Battery1_Voltage12,
        ui->show_Battery1_Voltage13, ui->show_Battery1_Voltage14, ui->show_Battery1_Voltage15,
        ui->show_Battery1_Voltage16, ui->show_Battery1_Voltage17, ui->show_Battery1_Voltage18,
        ui->show_Battery1_Voltage19, ui->show_Battery1_Voltage20, ui->show_Battery1_Voltage21,
        ui->show_Battery2_Voltage1,  ui->show_Battery2_Voltage2,  ui->show_Battery2_Voltage3,
        ui->show_Battery2_Voltage4,  ui->show_Battery2_Voltage5,  ui->show_Battery2_Voltage6,
        ui->show_Battery2_Voltage7,  ui->show_Battery2_Voltage8,  ui->show_Battery2_Voltage9,
        ui->show_Battery2_Voltage10, ui->show_Battery2_Voltage11, ui->show_Battery2_Voltage12,
        ui->show_Battery2_Voltage13, ui->show_Battery2_Voltage14, ui->show_Battery2_Voltage15,
        ui->show_Battery2_Voltage16, ui->show_Battery2_Voltage17, ui->show_Battery2_Voltage18,
        ui->show_Battery2_Voltage19, ui->show_Battery2_Voltage20, ui->show_Battery2_Voltage21,
        ui->show_Battery3_Voltage1,  ui->show_Battery3_Voltage2,  ui->show_Battery3_Voltage3,
        ui->show_Battery3_Voltage4,  ui->show_Battery3_Voltage5,  ui->show_Battery3_Voltage6,
        ui->show_Battery3_Voltage7,  ui->show_Battery3_Voltage8,  ui->show_Battery3_Voltage9,
        ui->show_Battery3_Voltage10, ui->show_Battery3_Voltage11, ui->show_Battery3_Voltage12,
        ui->show_Battery3_Voltage13, ui->show_Battery3_Voltage14, ui->show_Battery3_Voltage15,
        ui->show_Battery3_Voltage16, ui->show_Battery3_Voltage17, ui->show_Battery3_Voltage18,
        ui->show_Battery3_Voltage19, ui->show_Battery3_Voltage20, ui->show_Battery3_Voltage21,
        ui->show_Battery4_Voltage1,  ui->show_Battery4_Voltage2,  ui->show_Battery4_Voltage3,
        ui->show_Battery4_Voltage4,  ui->show_Battery4_Voltage5,  ui->show_Battery4_Voltage6,
        ui->show_Battery4_Voltage7,  ui->show_Battery4_Voltage8,  ui->show_Battery4_Voltage9,
        ui->show_Battery4_Voltage10, ui->show_Battery4_Voltage11, ui->show_Battery4_Voltage12,
        ui->show_Battery4_Voltage13, ui->show_Battery4_Voltage14, ui->show_Battery4_Voltage15,
        ui->show_Battery4_Voltage16, ui->show_Battery4_Voltage17, ui->show_Battery4_Voltage18,
        ui->show_Battery4_Voltage19, ui->show_Battery4_Voltage20, ui->show_Battery4_Voltage21,
        ui->show_Battery1_Temperature1, ui->show_Battery1_Temperature2,
        ui->show_Battery1_Temperature3, ui->show_Battery1_Temperature4,
        ui->show_Battery1_Temperature5, ui->show_Battery1_Temperature6,
        ui->show_Battery1_Temperature7, ui->show_Battery1_Temperature8,
        ui->show_Battery2_Temperature1, ui->show_Battery2_Temperature2,
        ui->show_Battery2_Temperature3, ui->show_Battery2_Temperature4,
        ui->show_Battery2_Temperature5, ui->show_Battery2_Temperature6,
        ui->show_Battery2_Temperature7, ui->show_Battery2_Temperature8,
        ui->show_Battery3_Temperature1, ui->show_Battery3_Temperature2,
        ui->show_Battery3_Temperature3, ui->show_Battery3_Temperature4,
        ui->show_Battery3_Temperature5, ui->show_Battery3_Temperature6,
        ui->show_Battery3_Temperature7, ui->show_Battery3_Temperature8,
        ui->show_Battery4_Temperature1, ui->show_Battery4_Temperature2,
        ui->show_Battery4_Temperature3, ui->show_Battery4_Temperature4,
        ui->show_Battery4_Temperature5, ui->show_Battery4_Temperature6,
        ui->show_Battery4_Temperature7, ui->show_Battery4_Temperature8,
        ui->show_Battery1_MinVoltage, ui->show_Battery1_MaxVoltage,
        ui->show_Battery2_MinVoltage, ui->show_Battery2_MaxVoltage,
        ui->show_Battery3_MinVoltage, ui->show_Battery3_MaxVoltage,
        ui->show_Battery4_MinVoltage, ui->show_Battery4_MaxVoltage,
        ui->show_Battery1_MinTemperature, ui->show_Battery1_MaxTemperature,
        ui->show_Battery2_MinTemperature, ui->show_Battery2_MaxTemperature,
        ui->show_Battery3_MinTemperature, ui->show_Battery3_MaxTemperature,
        ui->show_Battery4_MinTemperature, ui->show_Battery4_MaxTemperature};

    QString BMS_str;
    double data[119];
    for(int i=0;i<119;i++)
    {
        data[i]=0;
    }

    sleep(500);
    dwRel=Receive(nDeviceType,nDeviceInd,nCANInd,vco,200,10);
    for(int i=0;i<200;i++)
    {
        int id=vco[i].ID;

        switch(id)
        {
        //关闭继保功能
        case 1408:
        {
            emit delay_close_success();
            ui->show_delay_status->setStyleSheet("QLabel{background:red}");

        } break;

            //打开继保功能
        case 1664:
        {
            emit delay_open_success();
            ui->show_delay_status->setStyleSheet("QLabel{background:green}");

        } break;

            //继电器功能
        case 896:
        {
            ui->show_contactor_status->setStyleSheet("QLabel{background:red}");
        } break;

            //总电压和总电流
        case 640:
        {

            int lowbit,highbit;
            for(int j=1;j<2;j++)
            {
                lowbit=vco[i].Data[j*2+1];
                highbit=vco[i].Data[j*2];

                if (lowbit<0)
                    lowbit = lowbit + 256;
                if (highbit<0)
                    highbit = highbit + 256;


                data[j]=(double)(((highbit*256+lowbit)/100.0-1.61)/0.0066);
                temp_data[j]=BMS_str.setNum(data[j]);
                LCDNumber[j]->display(BMS_str.setNum(data[j]));
            }
            for(int j=2;j<3;j++)
            {
                lowbit=vco[i].Data[j*2+1];
                highbit=vco[i].Data[j*2];

                if (lowbit<0)
                    lowbit = lowbit + 256;
                if (highbit<0)
                    highbit = highbit + 256;

                data[j]=(double)(((highbit*256+lowbit)/100.0-1.646)/0.0165);
                temp_data[j]=BMS_str.setNum(data[j]);
                //LCDNumber[j]->display(BMS_str.setNum(data[j]));

            }

        } break;


            //1号子板21个电压信息
        case 512:
        {
            for(int j=0;j<4;j++)
            {
                data[j+3]=displayBatteryVoltage(i,j);
                temp_data[j+3]=BMS_str.setNum(data[j+3]);
                LCDNumber[j+3]->display(BMS_str.setNum(data[j+3]));
            }


        }break;

        case 513:
        {

            for(int j=0;j<4;j++)
            {
                data[j+7]=displayBatteryVoltage(i,j);
                temp_data[j+7]=BMS_str.setNum(data[j+7]);
                LCDNumber[j+7]->display(BMS_str.setNum(data[j+7]));
            }
        }break;

        case 514:
        {
            for(int j=0;j<4;j++)
            {

                data[j+11]=displayBatteryVoltage(i,j);
                temp_data[j+11]=BMS_str.setNum(data[j+11]);
                LCDNumber[j+11]->display(BMS_str.setNum(data[j+11]));
            }
        }break;

        case 528:
        {
            for(int j=0;j<4;j++)
            {
                data[j+15]=displayBatteryVoltage(i,j);
                temp_data[j+15]=BMS_str.setNum(data[j+15]);
                LCDNumber[j+15]->display(BMS_str.setNum(data[j+15]));
            }
        }break;

        case 529:
        {
            for(int j=0;j<4;j++)
            {
                data[j+19]=displayBatteryVoltage(i,j);
                temp_data[j+19]=BMS_str.setNum(data[j+19]);
                LCDNumber[j+19]->display(BMS_str.setNum(data[j+19]));
            }
        }break;

        case 530:
        {
            data[23]=displayBatteryVoltage(i,0);
            temp_data[23]=BMS_str.setNum(data[23]);
            LCDNumber[23]->display(BMS_str.setNum(data[23]));

        }break;


            //2号子板21个电压信息
        case 544:
        {
            for(int j=0;j<4;j++)
            {
                data[j+24]=displayBatteryVoltage(i,j);
                temp_data[j+24]=BMS_str.setNum(data[j+24]);
                LCDNumber[j+24]->display(BMS_str.setNum(data[j+24]));
            }
        }break;

        case 545:
        {
            for(int j=0;j<4;j++)
            {
                data[j+28]=displayBatteryVoltage(i,j);
                temp_data[j+28]=BMS_str.setNum(data[j+28]);
                LCDNumber[j+28]->display(BMS_str.setNum(data[j+28]));
            }
        }break;

        case 546:
        {
            for(int j=0;j<4;j++)
            {
                data[j+32]=displayBatteryVoltage(i,j);
                temp_data[j+32]=BMS_str.setNum(data[j+32]);
                LCDNumber[j+32]->display(BMS_str.setNum(data[j+32]));
            }
        }break;

        case 560:
        {
            for(int j=0;j<4;j++)
            {

                data[j+36]=displayBatteryVoltage(i,j);
                temp_data[j+36]=BMS_str.setNum(data[j+36]);
                LCDNumber[j+36]->display(BMS_str.setNum(data[j+36]));
            }
        }break;

        case 561:
        {
            for(int j=0;j<4;j++)
            {
                data[j+40]=displayBatteryVoltage(i,j);
                temp_data[j+40]=BMS_str.setNum(data[j+40]);
                LCDNumber[j+40]->display(BMS_str.setNum(data[j+40]));
            }
        }break;

        case 562:
        {
            data[44]=displayBatteryVoltage(i,0);
            temp_data[44]=BMS_str.setNum(data[44]);
            LCDNumber[44]->display(BMS_str.setNum(data[44]));

        }break;


            //3号子板21个电压信息
        case 576:
        {
            for(int j=0;j<4;j++)
            {
                data[j+45]=displayBatteryVoltage(i,j);
                temp_data[j+45]=BMS_str.setNum(data[j+45]);
                LCDNumber[j+45]->display(BMS_str.setNum(data[j+45]));
            }
        }break;

        case 577:
        {
            for(int j=0;j<4;j++)
            {
                data[j+49]=displayBatteryVoltage(i,j);
                temp_data[j+49]=BMS_str.setNum(data[j+49]);
                LCDNumber[j+49]->display(BMS_str.setNum(data[j+49]));
            }
        }break;

        case 578:
        {
            for(int j=0;j<4;j++)
            {
                data[j+53]=displayBatteryVoltage(i,j);
                temp_data[j+53]=BMS_str.setNum(data[j+53]);
                LCDNumber[j+53]->display(BMS_str.setNum(data[j+53]));
            }
        }break;

        case 592:
        {
            for(int j=0;j<4;j++)
            {
                data[j+57]=displayBatteryVoltage(i,j);
                temp_data[j+57]=BMS_str.setNum(data[j+57]);
                LCDNumber[j+57]->display(BMS_str.setNum(data[j+57]));
            }
        }break;

        case 593:
        {
            for(int j=0;j<4;j++)
            {
                data[j+61]=displayBatteryVoltage(i,j);
                temp_data[j+61]=BMS_str.setNum(data[j+61]);
                LCDNumber[j+61]->display(BMS_str.setNum(data[j+61]));
            }
        }break;

        case 594:
        {
            data[65]=displayBatteryVoltage(i,0);
            temp_data[65]=BMS_str.setNum(data[65]);
            LCDNumber[65]->display(BMS_str.setNum(data[65]));

        }break;


            //4号子板21个电压信息
        case 608:
        {
            for(int j=0;j<4;j++)
            {
                data[j+66]=displayBatteryVoltage(i,j);
                temp_data[j+66]=BMS_str.setNum(data[j+66]);
                LCDNumber[j+66]->display(BMS_str.setNum(data[j+66]));
            }
        }break;

        case 609:
        {
            for(int j=0;j<4;j++)
            {
                data[j+70]=displayBatteryVoltage(i,j);
                temp_data[j+70]=BMS_str.setNum(data[j+70]);
                LCDNumber[j+70]->display(BMS_str.setNum(data[j+70]));
            }
        }break;

        case 610:
        {
            for(int j=0;j<4;j++)
            {
                data[j+74]=displayBatteryVoltage(i,j);
                temp_data[j+74]=BMS_str.setNum(data[j+74]);
                LCDNumber[j+74]->display(BMS_str.setNum(data[j+74]));
            }
        }break;

        case 624:
        {
            for(int j=0;j<4;j++)
            {
                data[j+78]=displayBatteryVoltage(i,j);
                temp_data[j+78]=BMS_str.setNum(data[j+78]);
                LCDNumber[j+78]->display(BMS_str.setNum(data[j+78]));
            }
        }break;

        case 625:
        {
            for(int j=0;j<4;j++)
            {
                data[j+82]=displayBatteryVoltage(i,j);
                temp_data[j+82]=BMS_str.setNum(data[j+82]);
                LCDNumber[j+82]->display(BMS_str.setNum(data[j+82]));
            }
        }break;

        case 626:
        {
            data[86]=displayBatteryVoltage(i,0);
            temp_data[86]=BMS_str.setNum(data[86]);
            LCDNumber[86]->display(BMS_str.setNum(data[86]));

        }break;


            //1号子板8个温度信息
        case 1024:
        {
            for(int j=0;j<4;j++)
            {
                data[j+87]=displayBatteryTemperature(i,j);
                temp_data[j+87]=BMS_str.setNum(data[j+87]);
                LCDNumber[j+87]->display(BMS_str.setNum(data[j+87]));
            }
        }break;

        case 1025:
        {
            for(int j=0;j<4;j++)
            {
                data[j+91]=displayBatteryTemperature(i,j);
                temp_data[j+91]=BMS_str.setNum(data[j+91]);
                LCDNumber[j+91]->display(BMS_str.setNum(data[j+91]));
            }
        }break;


            //2号子板8个温度信息
        case 1056:
        {
            for(int j=0;j<4;j++)
            {
                data[j+95]=displayBatteryTemperature(i,j);
                temp_data[j+95]=BMS_str.setNum(data[j+95]);
                LCDNumber[j+95]->display(BMS_str.setNum(data[j+95]));
            }
        }break;

        case 1057:
        {
            for(int j=0;j<4;j++)
            {
                data[j+99]=displayBatteryTemperature(i,j);
                temp_data[j+99]=BMS_str.setNum(data[j+99]);
                LCDNumber[j+99]->display(BMS_str.setNum(data[j+99]));
            }
        }break;



            //3号子板8个温度信息
        case 1088:
        {
            for(int j=0;j<4;j++)
            {
                data[j+103]=displayBatteryTemperature(i,j);
                temp_data[j+103]=BMS_str.setNum(data[j+103]);
                LCDNumber[j+103]->display(BMS_str.setNum(data[j+103]));
            }
        }break;

        case 1089:
        {
            for(int j=0;j<4;j++)
            {
                data[j+107]=displayBatteryTemperature(i,j);
                temp_data[j+107]=BMS_str.setNum(data[j+107]);
                LCDNumber[j+107]->display(BMS_str.setNum(data[j+107]));
            }
        }break;


            //4号子板8个温度信息
        case 1120:
        {
            for(int j=0;j<4;j++)
            {
                data[j+111]=displayBatteryTemperature(i,j);
                temp_data[j+111]=BMS_str.setNum(data[j+111]);
                LCDNumber[j+111]->display(BMS_str.setNum(data[j+111]));
            }
        }break;

        case 1121:
        {
            for(int j=0;j<4;j++)
            {
                data[j+115]=displayBatteryTemperature(i,j);
                temp_data[j+115]=BMS_str.setNum(data[j+115]);
                LCDNumber[j+115]->display(BMS_str.setNum(data[j+115]));
            }
        }break;

        default:
            break;
        }
    }

    //判断并显示总电压是否异常
    for(int i=0;i<2;i++)
    {
        if (data[i] >= ParaRange[4] || data[i] <= ParaRange[5])
        {
            *currDateTime = QDateTime::currentDateTime();
            xmlWriter.logBox += currDateTime->toString("yyyy-MM-dd hh:mm:ss")
                    + "    总电压" + QString::number(i + 1) + "数据异常！\r\n";
        }
    }

    //判断并显示总电流是否异常
    if (data[2] >= ParaRange[6] || data[2] <= ParaRange[7])
    {
        *currDateTime = QDateTime::currentDateTime();
        xmlWriter.logBox += currDateTime->toString("yyyy-MM-dd hh:mm:ss")
                + "    总电流数据异常！\r\n";
    }

    //判断并显示84个单体电压是否异常
    for(int i=3;i<87;i++)
    {
        if (data[i]<1 || data[i]>5)
        {
            int stoveid = (i-3)/21;
            switch (stoveid)
            {
            case 0:
            {
                QString str;

                str.append(0x81);
                str.append(0x81);
                str.append(0x43);
                str.append(0x1B);
                str.append(0x01);
                str.append(0x00);
                str.append(0x46);
                str.append(0x07);

                Stove_Port->write(str.toLatin1());

            } break;
            case 1:
            {
                QString str;

                str.append(0x82);
                str.append(0x82);
                str.append(0x43);
                str.append(0x1B);
                str.append(0x01);
                str.append(0x00);
                str.append(0x47);
                str.append(0x07);

                Stove_Port->write(str.toLatin1());
            } break;
            case 2:
            {
                QString str;

                str.append(0x83);
                str.append(0x83);
                str.append(0x43);
                str.append(0x1B);
                str.append(0x01);
                str.append(0x00);
                str.append(0x4);
                str.append(0x07);

                Stove_Port->write(str.toLatin1());
            } break;
            case 3:
            {
                QString str;

                str.append(0x84);
                str.append(0x84);
                str.append(0x43);
                str.append(0x1B);
                str.append(0x01);
                str.append(0x00);
                str.append(0x49);
                str.append(0x07);

                Stove_Port->write(str.toLatin1());
            } break;
            }
        }

        if (data[i] >= ParaRange[0] || data[i] <= ParaRange[1])
        {
            *currDateTime = QDateTime::currentDateTime();
            xmlWriter.logBox += currDateTime->toString("yyyy-MM-dd hh:mm:ss")
                    + "    " + QString::number((i-3)/ 21 + 1) + "号子板"
                    + QString::number((i-3) % 21 + 1) + "号电池数据异常！\r\n";
        }
    }

    //判断并显示32个单体温度是否异常
    for(int i=87;i<119;i++)
    {
        if (data[i]<20 || data[i]>60)
        {
            int stoveid = (i-87)/8;
            switch (stoveid)
            {
            case 0:
            {
                QString str;

                str.append(0x81);
                str.append(0x81);
                str.append(0x43);
                str.append(0x1B);
                str.append(0x01);
                str.append(0x00);
                str.append(0x46);
                str.append(0x07);

                Stove_Port->write(str.toLatin1());

            } break;
            case 1:
            {
                QString str;

                str.append(0x82);
                str.append(0x82);
                str.append(0x43);
                str.append(0x1B);
                str.append(0x01);
                str.append(0x00);
                str.append(0x47);
                str.append(0x07);

                Stove_Port->write(str.toLatin1());
            } break;
            case 2:
            {
                QString str;

                str.append(0x83);
                str.append(0x83);
                str.append(0x43);
                str.append(0x1B);
                str.append(0x01);
                str.append(0x00);
                str.append(0x4);
                str.append(0x07);

                Stove_Port->write(str.toLatin1());
            } break;
            case 3:
            {
                QString str;

                str.append(0x84);
                str.append(0x84);
                str.append(0x43);
                str.append(0x1B);
                str.append(0x01);
                str.append(0x00);
                str.append(0x49);
                str.append(0x07);

                Stove_Port->write(str.toLatin1());
            } break;
            }
        }

        if (data[i] >= ParaRange[2] || data[i] <= ParaRange[3])
        {
            *currDateTime = QDateTime::currentDateTime();
            xmlWriter.logBox += currDateTime->toString("yyyy-MM-dd hh:mm:ss")
                    + "    " + QString::number((i-87)/ 8 + 1) + "号子板"
                    + QString::number((i-87) % 8 + 1) + "号电池数据异常！\r\n";
        }

    }

    //计算并显示电池充放电总容量同时依此改变逆变器工作模式
    QString str1, str2;
    if (capacity[0] >= 0 && capacity[0] <= 325)
    {
        capacity[1] = data[2];
        capacity[0] = (capacity[1] * 0.1)/3600 + capacity[0];
        ui->show_Capacity->display(str1.setNum(capacity[0]));
        emit inverter_Charge_Mode();
    }
    else if (capacity[0] >= 325 && capacity[0] <= 650)
    {
        capacity[1] = data[2];
        capacity[0] = (capacity[1] * 0.1 + capacity[0])/3600;
        ui->show_Capacity->display(str2.setNum(650 - capacity[0]));
        emit inverter_Charge_Mode();
    }
    else
    {
        capacity[0] = 0;
        emit inverter_Charge_Mode();

    }


    // 产生随机数，测试用
    /*GenerateTemp_data();
    for (int j = 0; j <119; j++)
    {
        (LCDNumber[j])->display(temp_data[j]);
    }*/


    //分别显示每组电池温度和电压最大最小值
    for(int i = 0; i < 4; i++)
    {
        double MaxVolt, MinVolt, MaxTemp, MinTemp;
        MinVolt = MaxVolt = data[i * 21 + 3];
        MinTemp = MaxTemp = data[i * 8 + 87];
        for(int j = 0; j < 20; j++)
        {
            if(MinVolt >= data[i * 21 + j + 4])
                MinVolt = data[i * 21 + j + 4];
            if(MaxVolt < data[i * 21 + j + 4])
                MaxVolt = data[i * 21 + j + 4];
        }
        LCDNumber[i * 2 + 119]->display(BMS_str.setNum(MinVolt));
        LCDNumber[i * 2 + 120]->display(BMS_str.setNum(MaxVolt));

        for(int j = 0; j < 7; j++)
        {
            if(MinTemp > data[i * 8 + j + 88])
                MinTemp = data[i * 8 + j + 88];
            if(MaxTemp < data[i * 8 + j + 88])
                MaxTemp = data[i * 8 + j + 88];
        }
        LCDNumber[i * 2 + 127]->display(BMS_str.setNum(MinTemp));
        LCDNumber[i * 2 + 128]->display(BMS_str.setNum(MaxTemp));
    }

    dwRel=ClearBuffer(nDeviceType,nDeviceInd,nCANInd);

}

// 点击跳出主回路接线图界面
void Main_Interface::on_Wiring_Diagram_Btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

// 点击跳出主回路监测信息界面
void Main_Interface::on_Main_Loop_Information_Btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

// 点击跳出单体电池电压监测信息界面
void Main_Interface::on_Battery_Voltage_Information_Btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

// 点击跳出单体电池温度监测信息界面
void Main_Interface::on_Battery_Temperature_Information_Btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

// 点击跳出逆变器监控界面
void Main_Interface::on_Inverter_Information_Btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

// 点击跳出炉温监控界面
void Main_Interface::on_Stove_Temperature_Control_Btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

// 点击跳出历史数据查看界面
void Main_Interface::on_Historical_Data_View_Btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

// 炉温设置指令定时发送
void Main_Interface::sleep(unsigned int msec)
{
    QTime reachTime = QTime::currentTime().addMSecs(msec);
    while (QTime::currentTime()<reachTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

// 发送读取炉子温度指令
void Main_Interface::send_Read_Stove()
{
    if(Stove1_Temperature_Set::Stove1_temp_read_stop == false)
    {
        QString Stove_str,Stove_str2;

        Stove_str.append(QChar(0x81));
        Stove_str.append(QChar(0x81));
        Stove_str.append(QChar(0x52));
        Stove_str.append(QChar(0x0C));
        Stove_str.append(QChar(0x00));
        Stove_str.append(QChar(0x00));
        Stove_str.append(QChar(0x53));
        Stove_str.append(QChar(0x0C));

        Stove_Port->write(Stove_str.toLatin1());
        sleep(200);

        Stove_str2.append(QChar(0x81));
        Stove_str2.append(QChar(0x81));
        Stove_str2.append(QChar(0x52));
        Stove_str2.append(QChar(0x00));
        Stove_str2.append(QChar(0x00));
        Stove_str2.append(QChar(0x00));
        Stove_str2.append(QChar(0x53));
        Stove_str2.append(QChar(0x00));

        Stove_Port->write(Stove_str2.toLatin1());

        sleep(200);
        QString Stove_str3,Stove_str4;

        Stove_str3.append(QChar(0x82));
        Stove_str3.append(QChar(0x82));
        Stove_str3.append(QChar(0x52));
        Stove_str3.append(QChar(0x0C));
        Stove_str3.append(QChar(0x00));
        Stove_str3.append(QChar(0x00));
        Stove_str3.append(QChar(0x54));
        Stove_str3.append(QChar(0x0C));

        Stove_Port->write(Stove_str3.toLatin1());
        sleep(200);

        Stove_str4.append(QChar(0x82));
        Stove_str4.append(QChar(0x82));
        Stove_str4.append(QChar(0x52));
        Stove_str4.append(QChar(0x00));
        Stove_str4.append(QChar(0x00));
        Stove_str4.append(QChar(0x00));
        Stove_str4.append(QChar(0x54));
        Stove_str4.append(QChar(0x00));

        Stove_Port->write(Stove_str4.toLatin1());

        sleep(200);
        QString Stove_str5,Stove_str6;

        Stove_str5.append(QChar(0x83));
        Stove_str5.append(QChar(0x83));
        Stove_str5.append(QChar(0x52));
        Stove_str5.append(QChar(0x0C));
        Stove_str5.append(QChar(0x00));
        Stove_str5.append(QChar(0x00));
        Stove_str5.append(QChar(0x55));
        Stove_str5.append(QChar(0x0C));

        Stove_Port->write(Stove_str5.toLatin1());
        sleep(200);

        Stove_str6.append(QChar(0x83));
        Stove_str6.append(QChar(0x83));
        Stove_str6.append(QChar(0x52));
        Stove_str6.append(QChar(0x00));
        Stove_str6.append(QChar(0x00));
        Stove_str6.append(QChar(0x00));
        Stove_str6.append(QChar(0x55));
        Stove_str6.append(QChar(0x00));

        Stove_Port->write(Stove_str6.toLatin1());
        sleep(200);

        QString Stove_str7,Stove_str8;

        Stove_str7.append(QChar(0x84));
        Stove_str7.append(QChar(0x84));
        Stove_str7.append(QChar(0x52));
        Stove_str7.append(QChar(0x0C));
        Stove_str7.append(QChar(0x00));
        Stove_str7.append(QChar(0x00));
        Stove_str7.append(QChar(0x56));
        Stove_str7.append(QChar(0x0C));

        Stove_Port->write(Stove_str7.toLatin1());
        sleep(200);

        Stove_str8.append(QChar(0x84));
        Stove_str8.append(QChar(0x84));
        Stove_str8.append(QChar(0x52));
        Stove_str8.append(QChar(0x00));
        Stove_str8.append(QChar(0x00));
        Stove_str8.append(QChar(0x00));
        Stove_str8.append(QChar(0x56));
        Stove_str8.append(QChar(0x00));

        Stove_Port->write(Stove_str8.toLatin1());


    }

}

// 读取炉子小数点位及温度
void Main_Interface::read_Stove()
{
    QLCDNumber *stove_Temperature_Lcd[4]={ui->show_Stove_Temperature1,ui->show_Stove_Temperature2,ui->show_Stove_Temperature3,ui->show_Stove_Temperature4};
    QCustomPlot *stove_Temperature_Plot[4]={ui->myplot1,ui->myplot2,ui->myplot3,ui->myplot4};

    if (Stove_Port->bytesAvailable() >= 80)
    {
        //获取当前串口缓冲区所有数据
        QByteArray temp = Stove_Port->readAll();

        //获取小数点位数
        for(int i=0;i<4;i++)
        {
            int Lbit=temp[i*20+6];
            int Hbit=temp[i*20+7];
            Stove_Flag[i] = getDecimalPointBits(Lbit,Hbit);
        }

        //获取温度值并显示在数码显示器上
        for(int i=0;i<4;i++)
        {
            QString str;
            int LTbit=temp[i*20+10];
            int HTbit=temp[i*20+11];
            if (LTbit<0)
                LTbit = LTbit + 256;
            if (HTbit<0)
                HTbit = HTbit + 256;
            Stove_Temperature[i] = displayCurrentTemperature(LTbit,HTbit,Stove_Flag[i]);
            stove_Temperature_Lcd[i]->display(str.setNum(Stove_Temperature[i]));
        }

        //将温度值显示在图上
        QVector<double> keys[4];
        QVector<double> values[4];
        double key[4];

        for(int i=0;i<4;i++)
        {
            key[i]=QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
            keys[i].append(key[i]);
            values[i].append(Stove_Temperature[i]);

            stove_Temperature_Plot[i]->graph(0)->addData(keys[i],values[i]);
            stove_Temperature_Plot[i]->xAxis->setRange(key[i],5,Qt::AlignRight);
            stove_Temperature_Plot[i]->replot();
        }

        //清空缓冲区
        temp.clear();
    }

}

// 整个程序关闭自动写入内存中的数据
void Main_Interface::closeEvent(QCloseEvent *event)
{
    if(xmlWriter.IsWriting == false)
    {
        QMessageBox *closeMessageBox = new QMessageBox();
        closeMessageBox->setWindowTitle("正在写入数据，请稍等……");
        closeMessageBox->show();
        closeMessageBox->setMaximumSize(200, 1);
        closeMessageBox->setMinimumSize(200, 1);

        xmlWriter.ForceWrite = true;
        xmlWriter.WindowClose = true;
        xmlWriter.StartWrite();
        closeMessageBox->hide();
    }
    else
    {
        QMessageBox::question(this, "退出程序", "警告：写入内存数据的任务正在进行，强行关闭程序将会出现错误", "确定");
        event->ignore();
    }
}

// 5s定时器，用来每5s调用一次写XML文件的函数
void Main_Interface::XMLTimer()
{
    QTimer *XMLTimer = new QTimer(this);
    // 设置定时间隔
    XMLTimer->setInterval(5000);
    connect(XMLTimer, SIGNAL(timeout()), this, SLOT(XMLWriter()));

    // 启动定时器
    XMLTimer->start();
}

// 调用写XML文件的函数
void Main_Interface::XMLWriter()
{
    for (int i = 0; i < 119; i++)
    {
        if(temp_data[i] == "")
        {
            temp_data[i] = "0";
        }
    }

    xmlWriter.XmlData(temp_data);
    xmlWriter.StartWrite();
}

// 自制时钟界面
void Main_Interface::LcdDateTime()
{
    // LcdYear
    ui->LcdYear->setMode(QLCDNumber::Dec);
    ui->LcdYear->setSegmentStyle(QLCDNumber::Flat);
    ui->LcdYear->setStyleSheet("border: 1px solid black; color: black; background: white;");

    // LcdMonth
    ui->LcdMonth->setMode(QLCDNumber::Dec);
    ui->LcdMonth->setSegmentStyle(QLCDNumber::Flat);
    ui->LcdMonth->setStyleSheet("border: 1px solid black; color: black; background: white;");

    // LcdDay
    ui->LcdDay->setMode(QLCDNumber::Dec);
    ui->LcdDay->setSegmentStyle(QLCDNumber::Flat);
    ui->LcdDay->setStyleSheet("border: 1px solid black; color: black; background: white;");

    // LcdTime
    ui->LcdTime->setDigitCount(8);
    ui->LcdTime->setMode(QLCDNumber::Dec);
    ui->LcdTime->setSegmentStyle(QLCDNumber::Flat);
    ui->LcdTime->setStyleSheet("border: 1px solid black; color: black; background: white;");

    QTimer *pTimer = new QTimer(this);
    // 设置定时间隔
    pTimer->setInterval(1000);
    connect(pTimer, SIGNAL(timeout()), this, SLOT(onTimeOut()));

    // 启动定时器
    pTimer->start();
}

// 1s刷新一次时钟界面
void Main_Interface::onTimeOut()
{
    QDateTime *LcdDateTime = new QDateTime(QDateTime::currentDateTime());
    //currDateTime->date().currentDate().toString("yyyy-MM-dd");  // 获取当前日期的代码，结合前面的currDateTime
    //currDateTime->time().currentTime().toString("hh:mm:ss");    // 获取当前时间的代码，结合前面的currDateTime
    QString Year, Month, Day, Time, WeekDate;
    Year = LcdDateTime->date().currentDate().toString("yyyy");
    Month = LcdDateTime->date().currentDate().toString("MM");
    Day = LcdDateTime->date().currentDate().toString("dd");
    Time = LcdDateTime->time().currentTime().toString("hh:mm:ss");
    WeekDate = LcdDateTime->date().currentDate().toString("dddd");

    ui->LcdYear->display(Year);
    ui->LcdMonth->display(Month);
    ui->LcdDay->display(Day);
    ui->WeekDate->setText(WeekDate);
    ui->LcdTime->display(Time);
}

// 新建线程用来运行XmlReader
void Main_Interface::on_data_Query_Btn_clicked()
{
    RunLogReader *newLogReader = new RunLogReader();
    newLogReader->start();
}

// 在新的线程运行XmlReader
void RunLogReader::run()
{
    QProcess process;
    process.execute("XmlLogReader.exe");
}

// 0.1s刷新一次系统运行日志界面
void Main_Interface::LogWiget()
{
    QTimer *pTimer = new QTimer(this);
    // 设置定时间隔
    pTimer->setInterval(100);
    connect(pTimer, SIGNAL(timeout()), this, SLOT(LogBoxReFresh()));

    // 启动定时器
    pTimer->start();
}

// 将新的运行日志加入系统运行日志界面
void Main_Interface::LogBoxReFresh()
{
    static QString lastLogBox = xmlWriter.logBox;
    QString textToBeCut = xmlWriter.logBox;

    if (xmlWriter.WriteBtnDisabled == true)
    {
        ui->WriteData->setDisabled(true);
    }
    if (lastLogBox != textToBeCut)
    {
        QString textToCut = lastLogBox;
        lastLogBox = xmlWriter.logBox;
        textToBeCut.replace(QString(textToCut), QString(""));
        ui->LogBox->append(textToBeCut);

        QTimer *pTimer = new QTimer(this);
        pTimer->setSingleShot(true);                // 设定只运行一次
        pTimer->setInterval(1000);                  // 设置定时间隔
        connect(pTimer, SIGNAL(timeout()), this, SLOT(EnableWriteDataButton()));

        // 启动定时器
        pTimer->start();
    }
}

// 单击数据写入XML按键，将内存数据写入XML文件
void Main_Interface::on_WriteData_clicked()
{
    xmlWriter.ForceWrite = true;
    ui->WriteData->setDisabled(true);
}

// 将写入内存数据的按键激活
void Main_Interface::EnableWriteDataButton()
{
    closeWrite = true;
    xmlWriter.WriteBtnDisabled = false;
    ui->WriteData->setDisabled(false);
    xmlWriter.IsWriting = false;
}

// 单击退出登录按键，退出系统
void Main_Interface::on_Exit_Login_Btn_clicked()
{
    Inverter_Port->close();
    Stove_Port->close();
    Inverter_timer->stop();
    Battery_timer->stop();
    Stove_timer->stop();
    this->close();
    emit login_Show();
}

// 点击跳出炉子1温度设置界面
void Main_Interface::on_stove1_Temperature_SetBtn_clicked()
{
    if (Stove1_Temperature_Set_Dialog == NULL)
    {
        Stove1_Temperature_Set_Dialog = new Stove1_Temperature_Set(this);
        Stove1_Temperature_Set_Dialog->Stove_Port = Stove_Port;
        Stove1_Temperature_Set_Dialog->show();
    }
    else
        Stove1_Temperature_Set_Dialog->show();
    return;
}

// 点击跳出炉子2温度设置界面
void Main_Interface::on_stove2_Temperature_SetBtn_clicked()
{
    if (Stove2_Temperature_Set_Dialog == NULL)
    {
        Stove2_Temperature_Set_Dialog = new Stove2_Temperature_Set(this);
        Stove2_Temperature_Set_Dialog->Stove_Port = Stove_Port;
        Stove2_Temperature_Set_Dialog->show();
    }
    else
        Stove2_Temperature_Set_Dialog->show();
    return;
}

// 点击跳出炉子3温度设置界面
void Main_Interface::on_stove3_Temperature_SetBtn_clicked()
{
    if (Stove3_Temperature_Set_Dialog == NULL)
    {
        Stove3_Temperature_Set_Dialog = new Stove3_Temperature_Set(this);
        Stove3_Temperature_Set_Dialog->Stove_Port = Stove_Port;
        Stove3_Temperature_Set_Dialog->show();
    }
    else
        Stove3_Temperature_Set_Dialog->show();
    return;
}

// 点击跳出炉子4温度设置界面
void Main_Interface::on_stove4_Temperature_SetBtn_clicked()
{
    if (Stove4_Temperature_Set_Dialog == NULL)
    {
        Stove4_Temperature_Set_Dialog = new Stove4_Temperature_Set(this);
        Stove4_Temperature_Set_Dialog->Stove_Port = Stove_Port;
        Stove4_Temperature_Set_Dialog->show();
    }
    else
        Stove4_Temperature_Set_Dialog->show();
    return;
}

// 绘图初始化函数
void Main_Interface::InitPlot()
{
    ui->myplot1->addGraph();
    ui->myplot2->addGraph();
    ui->myplot3->addGraph();
    ui->myplot4->addGraph();


    ui->myplot1->graph(0)->setPen(QPen(Qt::red));//设置画笔，也就是曲线的颜色；

    //注释掉的这两行表示的是坐标图是否为包含模式
    // ui->plot->graph(0)->setBrush(QBrush(QColor(240, 255, 200)));//设置画刷，也就是曲线所包括部分的颜色；
    // ui->plot->graph(0)->setAntialiasedFill(true);//设置曲线覆盖包含的模式；
    ui->myplot1->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::red, 1), QBrush(Qt::white), 9));

    ui->myplot1->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->myplot1->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->myplot1->xAxis->setAutoTickStep(false);
    ui->myplot1->xAxis->setTickStep(1);
    ui->myplot1->xAxis->setRange(0, 5, Qt::AlignRight);
    ui->myplot1->yAxis->setRange(0, 655);


    ui->myplot1->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->myplot1->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->myplot1->xAxis->setTickPen(QPen(Qt::white, 1));
    ui->myplot1->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->myplot1->xAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->myplot1->yAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->myplot1->xAxis->setTickLabelColor(Qt::white);
    ui->myplot1->yAxis->setTickLabelColor(Qt::white);

    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    plotGradient.setColorAt(1, QColor(50, 50, 50));
    ui->myplot1->setBackground(plotGradient);

    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    ui->myplot1->axisRect()->setBackground(axisRectGradient);

    ///ui->plot->axisRect()->setupFullAxesBox();
    ui->myplot1->replot();



    timerPlot = new QTimer(this);
    //connect(timerPlot, SIGNAL(timeout()), this, SLOT(addPlot()));



    ui->myplot2->graph(0)->setPen(QPen(Qt::red));//设置画笔，也就是曲线的颜色；

    //注释掉的这两行表示的是坐标图是否为包含模式
    // ui->plot->graph(0)->setBrush(QBrush(QColor(240, 255, 200)));//设置画刷，也就是曲线所包括部分的颜色；
    // ui->plot->graph(0)->setAntialiasedFill(true);//设置曲线覆盖包含的模式；
    ui->myplot2->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::red, 1), QBrush(Qt::white), 9));

    ui->myplot2->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->myplot2->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->myplot2->xAxis->setAutoTickStep(false);
    ui->myplot2->xAxis->setTickStep(1);
    ui->myplot2->xAxis->setRange(0, 5, Qt::AlignRight);
    ui->myplot2->yAxis->setRange(0, 655);


    ui->myplot2->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->myplot2->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->myplot2->xAxis->setTickPen(QPen(Qt::white, 1));
    ui->myplot2->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->myplot2->xAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->myplot2->yAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->myplot2->xAxis->setTickLabelColor(Qt::white);
    ui->myplot2->yAxis->setTickLabelColor(Qt::white);

    QLinearGradient plotGradient2;
    plotGradient2.setStart(0, 0);
    plotGradient2.setFinalStop(0, 350);
    plotGradient2.setColorAt(0, QColor(80, 80, 80));
    plotGradient2.setColorAt(1, QColor(50, 50, 50));
    ui->myplot2->setBackground(plotGradient2);

    QLinearGradient axisRectGradient2;
    axisRectGradient2.setStart(0, 0);
    axisRectGradient2.setFinalStop(0, 350);
    axisRectGradient2.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient2.setColorAt(1, QColor(30, 30, 30));
    ui->myplot2->axisRect()->setBackground(axisRectGradient2);

    ///ui->plot->axisRect()->setupFullAxesBox();
    ui->myplot2->replot();



    ui->myplot3->graph(0)->setPen(QPen(Qt::red));//设置画笔，也就是曲线的颜色；

    //注释掉的这两行表示的是坐标图是否为包含模式
    // ui->plot->graph(0)->setBrush(QBrush(QColor(240, 255, 200)));//设置画刷，也就是曲线所包括部分的颜色；
    // ui->plot->graph(0)->setAntialiasedFill(true);//设置曲线覆盖包含的模式；
    ui->myplot3->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::red, 1), QBrush(Qt::white), 9));

    ui->myplot3->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->myplot3->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->myplot3->xAxis->setAutoTickStep(false);
    ui->myplot3->xAxis->setTickStep(1);
    ui->myplot3->xAxis->setRange(0, 5, Qt::AlignRight);
    ui->myplot3->yAxis->setRange(0, 655);


    ui->myplot3->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->myplot3->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->myplot3->xAxis->setTickPen(QPen(Qt::white, 1));
    ui->myplot3->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->myplot3->xAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->myplot3->yAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->myplot3->xAxis->setTickLabelColor(Qt::white);
    ui->myplot3->yAxis->setTickLabelColor(Qt::white);

    QLinearGradient plotGradient3;
    plotGradient3.setStart(0, 0);
    plotGradient3.setFinalStop(0, 350);
    plotGradient3.setColorAt(0, QColor(80, 80, 80));
    plotGradient3.setColorAt(1, QColor(50, 50, 50));
    ui->myplot3->setBackground(plotGradient3);

    QLinearGradient axisRectGradient3;
    axisRectGradient3.setStart(0, 0);
    axisRectGradient3.setFinalStop(0, 350);
    axisRectGradient3.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient3.setColorAt(1, QColor(30, 30, 30));
    ui->myplot3->axisRect()->setBackground(axisRectGradient3);

    ///ui->plot->axisRect()->setupFullAxesBox();
    ui->myplot3->replot();

    ui->myplot4->graph(0)->setPen(QPen(Qt::red));//设置画笔，也就是曲线的颜色；

    //注释掉的这两行表示的是坐标图是否为包含模式
    // ui->plot->graph(0)->setBrush(QBrush(QColor(240, 255, 200)));//设置画刷，也就是曲线所包括部分的颜色；
    // ui->plot->graph(0)->setAntialiasedFill(true);//设置曲线覆盖包含的模式；
    ui->myplot4->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::red, 1), QBrush(Qt::white), 9));

    ui->myplot4->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->myplot4->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->myplot4->xAxis->setAutoTickStep(false);
    ui->myplot4->xAxis->setTickStep(1);
    ui->myplot4->xAxis->setRange(0, 5, Qt::AlignRight);
    ui->myplot4->yAxis->setRange(0, 655);


    ui->myplot4->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->myplot4->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->myplot4->xAxis->setTickPen(QPen(Qt::white, 1));
    ui->myplot4->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->myplot4->xAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->myplot4->yAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->myplot4->xAxis->setTickLabelColor(Qt::white);
    ui->myplot4->yAxis->setTickLabelColor(Qt::white);

    QLinearGradient plotGradient4;
    plotGradient4.setStart(0, 0);
    plotGradient4.setFinalStop(0, 350);
    plotGradient4.setColorAt(0, QColor(80, 80, 80));
    plotGradient4.setColorAt(1, QColor(50, 50, 50));
    ui->myplot4->setBackground(plotGradient4);

    QLinearGradient axisRectGradient4;
    axisRectGradient4.setStart(0, 0);
    axisRectGradient4.setFinalStop(0, 350);
    axisRectGradient4.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient4.setColorAt(1, QColor(30, 30, 30));
    ui->myplot4->axisRect()->setBackground(axisRectGradient4);

    ///ui->plot->axisRect()->setupFullAxesBox();
    ui->myplot4->replot();
}

// 读取参数范围的配置文件
void Main_Interface::ReadParaIni()
{
    QString ParaName[] =
    {
        "Alarm_Volt_H", "Alarm_Volt_L", "Alarm_Temp_H", "Alarm_Temp_L",
        "Alarm_SumVolt_H", "Alarm_SumVolt_L", "Alarm_SumCurr_H", "Alarm_SumCurr_L",
        "UrgentAlarm_Volt_H", "UrgentAlarm_Volt_L",
        "UrgentAlarm_Temp_H", "UrgentAlarm_Temp_L",
        "UrgentAlarm_SumVolt_H", "UrgentAlarm_SumVolt_L",
        "UrgentAlarm_SumCurr_H", "UrgentAlarm_SumCurr_L"
    };

    QString AppdataRoamingPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    AppdataRoamingPath.replace(AppdataRoamingPath.lastIndexOf("/"), 65535, "");
    QDir dir(AppdataRoamingPath);
    if(!dir.exists("UESTC"))
    {
        dir.mkdir("UESTC");
        dir.cd("UESTC");
        dir.mkdir("Battery_Monitoring_System");
    }
    else
    {
        dir.cd("UESTC");
        if(!dir.exists("Battery_Monitoring_System"))
        {
            dir.mkdir("Battery_Monitoring_System");
        }
    }

    QString ParaIniFilePath = AppdataRoamingPath
            + "/UESTC/Battery_Monitoring_System/BatPara.ini";

    if(!QFile::exists(ParaIniFilePath))
    {
        Parameter_Range_Set_Dialog = new Parameter_Range_Set(this);
        Parameter_Range_Set_Dialog->show();
        while(Parameter_Range_Set_Dialog->isVisible())
            sleep(100);
    }

    QFile ParaIniFile(ParaIniFilePath);
    if(!ParaIniFile.open(QFile::ReadOnly | QFile::Text))
    {
        return;
    }

    QXmlStreamReader IniReader(&ParaIniFile);

    if(IniReader.readNextStartElement())
    {
        while(IniReader.name() != "data")
        {
            IniReader.readNextStartElement();
        }

        for(int i = 0; i < 16; i++)
        {
            IniReader.readNextStartElement();
            if(IniReader.name().toString() == ParaName[i])
            {
                if(IniReader.isStartElement() && IniReader.name().toString() == ParaName[i])
                    ParaRange[i] = IniReader.readElementText().toDouble();
            }

        }
    }
    ParaIniFile.close();
    IniReader.clear();
    //QMessageBox::information(this,NULL,"参数设置成功","确定");
}

// 获得参数范围
void Main_Interface::GetParaRange()
{
    ReadParaIni();

    //QMessageBox::information(this,NULL,"参数修改成功","确定");
}

// 按键实现参数范围的更改
void Main_Interface::on_SetRarm_clicked()
{
    Parameter_Range_Set_Dialog = new Parameter_Range_Set(this);
    connect(Parameter_Range_Set_Dialog,SIGNAL(SuccessWriting()),this,SLOT(GetParaRange()));
    Parameter_Range_Set_Dialog->Set_Parameter_Range_Dialog();

}

//打开或关闭继保功能
void Main_Interface::on_Open_Delay_Button_clicked()
{
    if(ui->Open_Delay_Button->text()==tr("打开继保"))
    {
        delay_Flag=0;
    }
    if(ui->Open_Delay_Button->text()==tr("关闭继保"))
    {
        delay_Flag=1;
    }

    switch (delay_Flag) {
    case 0:
    {
        vto.ID=1378;
        vto.SendType=0;
        vto.RemoteFlag=0;
        vto.ExternFlag=0;
        vto.DataLen=8;
        for(int i=0;i<8;i++)
        {
            vto.Data[i]=17;
        }

        dwRel=Transmit(nDeviceType,nDeviceInd,nCANInd,&vto,8);

    }

        break;
    case 1:
    {
        vto.ID=1378;
        vto.SendType=0;
        vto.RemoteFlag=0;
        vto.ExternFlag=0;
        vto.DataLen=8;
        for(int i=0;i<8;i++)
        {
            vto.Data[i]=34;
        }

        dwRel=Transmit(nDeviceType,nDeviceInd,nCANInd,&vto,8);


    }
    default:
        break;
    }

}

//将继保按钮文本改为关闭继保
void Main_Interface::open_delay_success()
{
    ui->Open_Delay_Button->setText("关闭继保");
}

//将继保按钮文本改为打开继保
void Main_Interface::close_delay_success()
{
    ui->Open_Delay_Button->setText("打开继保");
}

//获取小数点位数函数实现
int Main_Interface::getDecimalPointBits(int L1, int H1)
{
    int flag;
    if ((L1 == 0x00) && (H1 == 0x00))
    {
        flag = 1;
    }
    if ((L1 == 0x01) && (H1 == 0x00))
    {
        flag = 2;
    }
    if ((L1 == 0x02) && (H1 == 0x00))
    {
        flag = 3;
    }
    if ((L1 == 0x03) && (H1 == 0x00))
    {
        flag = 4;
    }
    if ((L1 == 0x80) && (H1 == 0x00))
    {
        flag = 5;
    }
    if ((L1 == 0x81) && (H1 == 0x00))
    {
        flag = 6;
    }
    if ((L1 == 0x82) && (H1 == 0x00))
    {
        flag = 7;
    }
    if ((L1 == 0x83) && (H1 == 0x00))
    {
        flag = 8;
    }

    return flag;
}

//获取当前炉温函数实现
double Main_Interface::displayCurrentTemperature(int LT1,int HT1,int stoveFlag)
{
    int temper;
    double t1;
    switch (stoveFlag)
    {
    case 1: {
        t1 = ((double)(HT1 * 256 + LT1));

    }
        break;
    case 2: {
        t1 = ((double)(HT1 * 256 + LT1)) / 10.0;

    }
        break;
    case 3: {
        t1 = ((double)(HT1 * 256 + LT1)) / 100.0;

    }
        break;
    case 4: {
        t1 = ((double)(HT1 * 256 + LT1)) / 1000.0;

    }
        break;
    case 5: {
        temper = (HT1 * 256 + LT1) / 10;
        t1 = ((double)(temper));

    }
        break;
    case 6: {
        temper = (HT1 * 256 + LT1) / 10;
        t1 = ((double)(temper)) / 10.0;

    }
        break;
    case 7: {
        temper = (HT1 * 256 + LT1) / 10;
        t1 = ((double)(temper)) / 100.0;

    }
        break;
    case 8: {
        temper = (HT1 * 256 + LT1) / 10;
        t1 = ((double)(temper)) / 1000.0;

    }
        break;
    default:
        break;
    }

    return t1;
}

//显示当前电池电压函数实现
double Main_Interface::displayBatteryVoltage(int i,int j)
{
    int lowbit,highbit;

    lowbit=vco[i].Data[j*2];
    highbit=vco[i].Data[j*2+1];

    if (lowbit<0)
        lowbit = lowbit + 256;
    if (highbit<0)
        highbit = highbit + 256;

    return (double)((highbit*256+lowbit)/10000.0);

}

//显示当前电池温度函数实现
double Main_Interface::displayBatteryTemperature(int i, int j)
{
    int lowbit,highbit;

    lowbit=vco[i].Data[j*2];
    highbit=vco[i].Data[j*2+1];

    if (lowbit<0)
        lowbit = lowbit + 256;
    if (highbit<0)
        highbit = highbit + 256;

    return (double)((highbit*256+lowbit-450)/10.0);
}
