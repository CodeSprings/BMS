#ifndef MAIN_INTERFACE_H
#define MAIN_INTERFACE_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QTimer>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include "inverter_activepower_set.h"
#include "inverter_current_set.h"
#include "inverter_voltage_set.h"
#include "inverter_controlmode.h"
#include "inverter_switch.h"
#include "stove1_temperature_set.h"
#include "stove2_temperature_set.h"
#include "stove3_temperature_set.h"
#include "stove4_temperature_set.h"
#include "parameter_range.h"
#include "xmlwriter.h"
#include "ECanVci.h"

#include <QLCDNumber>
#include <QVBoxLayout>
#include <QProcess>
#include <QThread>
#include <QMutexLocker>
#include <QMutex>
#include <QTime>
#include <QApplication>
#include <QMessageBox>
#include <QXmlStreamReader>
#include <QDialogButtonBox>

#define nDeviceType 4
#define nDeviceInd 0
#define nCANInd 0
#define nReserevd 0


namespace Ui {
class Main_Interface;
}

class Main_Interface : public QDialog
{
    Q_OBJECT

public:
    explicit Main_Interface(QWidget *parent = 0);
    ~Main_Interface();
    //串口声明
    QSerialPort *Inverter_Port;
    QSerialPort *Stove_Port;

    //子窗口声明
    Inverter_ActivePower_Set* Inverter_ActivePower_Set_Dialog;
    Inverter_Current_Set* Inverter_Current_Set_Dialog;
    Inverter_Voltage_Set* Inverter_Voltage_Set_Dialog;
    Inverter_ControlMode* Inverter_ControlMode_Dialog;
    Inverter_Switch* Inverter_Switch_Dialog;
    Stove1_Temperature_Set* Stove1_Temperature_Set_Dialog;
    Stove2_Temperature_Set* Stove2_Temperature_Set_Dialog;
    Stove3_Temperature_Set* Stove3_Temperature_Set_Dialog;
    Stove4_Temperature_Set* Stove4_Temperature_Set_Dialog;
    Parameter_Range_Set* Parameter_Range_Set_Dialog;

    void XMLTimer();
    void LcdDateTime();
    void LogWiget();
    void show_Inverter_Msg();
    int Mode_Flag;

    int Stove_Flag[4];
    double Stove_Temperature[4];

    void sleep(unsigned int msec);
    double capacity[2];
    int inverter_Flag;
    int port_Flag;
    int can_Flag;
    int delay_Flag;

    CAN_OBJ vco[200],vto;
    INIT_CONFIG vic;
    DWORD dwRel;
    bool close_can;





public slots:
    void XMLWriter();

    void onTimeOut();

    void LogBoxReFresh();

    void EnableWriteDataButton();

    void GenerateTemp_data();

    void GetParaRange();

    void ReadParaIni();

    int getDecimalPointBits(int L1,int H1);

    double displayCurrentTemperature(int LT1,int HT1,int stoveFlag);

    double displayBatteryVoltage(int,int);

    double displayBatteryTemperature(int,int);

private slots:
    void on_show_Inverter_Btn_clicked();

    //发送请求
    void send_Read_Inverter();
    void send_Read_Stove();
    void send_Inverter_Mode();


    //读取数据
    void read_Inverter();
    void read_Battery();
    void read_Stove();



    void on_set_Active_Power_Btn_clicked();

    void on_set_Current_Btn_clicked();

    void on_set_Voltage_Btn_clicked();

    void on_set_Control_Mode_Btn_clicked();

    void on_Wiring_Diagram_Btn_clicked();

    void on_Main_Loop_Information_Btn_clicked();

    void on_Battery_Voltage_Information_Btn_clicked();

    void on_Battery_Temperature_Information_Btn_clicked();

    void on_Inverter_Information_Btn_clicked();

    void on_Stove_Temperature_Control_Btn_clicked();

    void on_Historical_Data_View_Btn_clicked();

    void on_WriteData_clicked();

    void on_data_Query_Btn_clicked();

    void on_Exit_Login_Btn_clicked();

    void on_stove1_Temperature_SetBtn_clicked();

    void on_stove2_Temperature_SetBtn_clicked();

    void on_stove3_Temperature_SetBtn_clicked();

    void on_stove4_Temperature_SetBtn_clicked();

    void on_SetRarm_clicked();

    void on_Main_Interface_shown();

    void on_Open_Delay_Button_clicked();

    void on_open_Port_Btn_clicked();

    void on_open_Can_Btn_clicked();

    void open_delay_success();

    void close_delay_success();


private:
    Ui::Main_Interface *ui;
    QTimer *Inverter_timer;
    QTimer *Battery_timer;
    QTimer *Stove_timer;

    void InitPlot();
    QTimer *timerPlot;

signals:
    void login_Show();
    void inverter_Charge_Mode();
    void shown();

    void delay_open_success();

    void delay_close_success();


protected:
    void closeEvent(QCloseEvent *event);
};

// 启动日志读取的后台线程
class RunLogReader : public QThread
{
protected:
    void run();
};


#endif // MAIN_INTERFACE_H
