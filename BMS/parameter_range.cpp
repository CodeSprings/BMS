#include "parameter_range.h"
#include "ui_parameter_range.h"

QString RangeOfPara[16];

Parameter_Range_Set::Parameter_Range_Set(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Parameter_Range_Set)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint );
    setWindowTitle("监控系统参数设置");
}

Parameter_Range_Set::~Parameter_Range_Set()
{
    delete ui;
}

void Parameter_Range_Set::Set_Parameter_Range_Dialog()
{
    QLineEdit *Input_ParaRange[] =
    {
        ui->Alarm_Volt_H, ui->Alarm_Volt_L, ui->Alarm_Temp_H, ui->Alarm_Temp_L,
        ui->Alarm_SumVolt_H, ui->Alarm_SumVolt_L, ui->Alarm_SumCurr_H, ui->Alarm_SumCurr_L,
        ui->UrgentAlarm_Volt_H, ui->UrgentAlarm_Volt_L,
        ui->UrgentAlarm_Temp_H, ui->UrgentAlarm_Temp_L,
        ui->UrgentAlarm_SumVolt_H, ui->UrgentAlarm_SumVolt_L,
        ui->UrgentAlarm_SumCurr_H, ui->UrgentAlarm_SumCurr_L
    };

    ReadPara();
    for(int i = 0; i < 16; i++)
    {
        Input_ParaRange[i]->setText(RangeOfPara[i]);
    }

    this->show();
}

void Parameter_Range_Set::on_InsertParameter_clicked()
{
    this->close();
    Set_Parameter_Range();
    emit SuccessWriting();
}

void Parameter_Range_Set::Set_Parameter_Range()
{
    QLineEdit *Input_ParaRange[] =
    {
        ui->Alarm_Volt_H, ui->Alarm_Volt_L, ui->Alarm_Temp_H, ui->Alarm_Temp_L,
        ui->Alarm_SumVolt_H, ui->Alarm_SumVolt_L, ui->Alarm_SumCurr_H, ui->Alarm_SumCurr_L,
        ui->UrgentAlarm_Volt_H, ui->UrgentAlarm_Volt_L,
        ui->UrgentAlarm_Temp_H, ui->UrgentAlarm_Temp_L,
        ui->UrgentAlarm_SumVolt_H, ui->UrgentAlarm_SumVolt_L,
        ui->UrgentAlarm_SumCurr_H, ui->UrgentAlarm_SumCurr_L
    };

    QString ParaName[] =
    {
        "Alarm_Volt_H", "Alarm_Volt_L", "Alarm_Temp_H", "Alarm_Temp_L",
        "Alarm_SumVolt_H", "Alarm_SumVolt_L", "Alarm_SumCurr_H", "Alarm_SumCurr_L",
        "UrgentAlarm_Volt_H", "UrgentAlarm_Volt_L",
        "UrgentAlarm_Temp_H", "UrgentAlarm_Temp_L",
        "UrgentAlarm_SumVolt_H", "UrgentAlarm_SumVolt_L",
        "UrgentAlarm_SumCurr_H", "UrgentAlarm_SumCurr_L"
    };

    QDateTime *currDateTime = new QDateTime(QDateTime::currentDateTime());

    try
    {
        for(int i = 0; i < 16; i++)
        {
            if(Input_ParaRange[i]->text() == "")
            {
                QMessageBox error;
                error.setWindowTitle("error");
                error.setText("有数据未输入");
                QPushButton *yesBtn = error.addButton("确定",QMessageBox::ActionRole);
                error.exec();
                if(error.clickedButton() == yesBtn)
                {
                    error.close();
                    this->show();
                }
                return;
            }
            ParaData[i] = Input_ParaRange[i]->text();
        }
    }
    catch(...)
    {
        QMessageBox::warning(this,"error","数据输入错误","确定");
        this->show();
    }

    try
    {
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
        QFile newFile(ParaIniFilePath);

        if(!newFile.open(QFile::WriteOnly | QFile::Text))
        {
            return;
        }

        QXmlStreamWriter writer(&newFile);                                              // 开始写XML
        writer.setCodec("utf-8");                                                       // XML 编码
        writer.setAutoFormatting(true);                                                 // 自动格式化
        writer.writeStartDocument("1.0");                                               // 开始.文档（XML 声明）
        writer.writeStartElement("batparas");                                           // 开始根节点 <batparas>

        writer.writeStartElement("data");                                               // 开始一级节点 <data>
        writer.writeAttribute("Date", currDateTime->date().toString("yyyy-MM-dd"));     // record的属性：Date
        writer.writeAttribute("Time", currDateTime->time().toString("hh:mm:ss"));       // record的属性：Time

        for(int i = 0 ; i < 16 ; i++)
        {
            writer.writeStartElement(ParaName[i]);                                      // 开始子元素
            writer.writeCharacters(ParaData[i]);
            writer.writeEndElement();                                                   // 结束子元素节点
        }
        writer.writeEndElement();                                                       // 结束一级节点<Data>
        writer.writeEndElement();

        writer.writeEndDocument();
        newFile.close();
    }
    catch(...)
    {
        QMessageBox::warning(this,"error","配置文件写入错误","确定");
        this->show();
    }
}

// 读取参数范围的配置文件
void Parameter_Range_Set::ReadPara()
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

//    if(!QFile::exists(ParaIniFilePath))
//    {
//        this->show();
//        while(this->isVisible())
//            sleep(100);
//    }

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
                RangeOfPara[i] = IniReader.readElementText();
            }

        }
    }
    ParaIniFile.close();
    IniReader.clear();
    //QMessageBox::information(this,NULL,"参数设置成功","确定");
}
