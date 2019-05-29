#include "xmlwriter.h"

XmlNode XmlWriter::node;

QString XmlWriter::dataSource[119];

bool XmlWriter::ForceWrite = false;

bool XmlWriter::WindowClose = false;

bool XmlWriter::WriteBtnDisabled = false;

bool XmlWriter::IsWriting = true;

QString XmlWriter::logBox;

QDateTime *XMLcurrDateTime = new QDateTime(QDateTime::currentDateTime());

void XmlWriter::XmlData(QString *tempData)  // 给node赋值
{
    XmlNode::Battery node_bat;      //新建node_bat存储单体电池电压序号及电压值
    XmlNode::Temperature node_temp; //新建node_temp存储温度序号及温度值
    XmlNode::Voltage node_volt;     //新建node_volt存储总电压序号及电压值
    XmlNode::Current node_curr;     //新建node_curr存储总电流序号及电流值

    node = *(new XmlNode());

    //向node内储存数据
    *XMLcurrDateTime = QDateTime::currentDateTime();
    node.Date = XMLcurrDateTime->date().currentDate().toString("yyyy-MM-dd");
    node.Time = XMLcurrDateTime->time().currentTime().toString("hh:mm:ss");
    for(int u1 = 0; u1 < 2 ; u1++)      //向node_volt储存数据
    {
        node_volt.Num = QString::number(u1+1);
        node_volt.Volt = tempData[u1];
        node.Voltages.append(node_volt);
    }
    for(int c1 = 0 ; c1 < 1 ; c1++)     //向node_curr储存数据
    {
        node_curr.Num = QString::number(c1+1);
        node_curr.Curr = tempData[c1 + 2];
        node.Currents.append(node_curr);
    }
    for(int z1 = 1; z1 <= 4; z1++)       //向node_bat和node_temp储存数据
    {
        for (int v1 = 1; v1 <= 21; v1++)
        {
            if (v1 < 10)
                node_bat.Num = QString::number(z1) + "_0" + QString::number(v1);
            else
                node_bat.Num = QString::number(z1) + "_" + QString::number(v1);

            node_bat.Volt = tempData[(z1 - 1) * 21 + v1 + 2];
            node.Batteries.append(node_bat);
        }
        for (int t1 = 1; t1 <= 8; t1++)
        {
            node_temp.Num = QString::number(z1) + "_0" + QString::number(t1);
            node_temp.Temp = tempData[(z1 - 1) * 8 + t1 + 86];
            node.Temperatures.append(node_temp);
        }
    }
}

// 写xml文件的总函数
void XmlWriter::StartWrite()
{
    //QString searchPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/BatLogs";
    QString searchPath = "D:";
    QDir dir(searchPath);
    if(!dir.exists("Batlogs"))
    {
        dir.mkdir("Batlogs");
        dir.cd("Batlogs");
        searchPath += "/Batlogs";
    }
    else
    {
        dir.cd("Batlogs");
        searchPath += "Batlogs";
    }

    QStringList fileNameFilter;                                                             // 建立fileNameFilter存储筛选条件
    fileNameFilter<<"Log-*.xml";                                                            // 筛选条件为文件名类似于"Log-*.xml"的文件
    dir.setNameFilters(fileNameFilter);                                                     // 设置dir名字筛选器为"Log-*.xml"
    QList<QFileInfo> *fileInfo = new QList<QFileInfo>(dir.entryInfoList(fileNameFilter));   // 将筛选结果存入fileInfo
    int number = fileInfo->count();                                                         // number储存文件个数
    if(number == 0)                 // 若文件夹为空，直接新建XML文件开始写数据
    {
        WriteNewFile();
        return;
    }

    QString lastFileName = fileInfo->at(number - 1).fileName();            // lastFilName储存最后一个文件的文件名
    QString lastFilePath = searchPath + "/" + lastFileName;                // lastFilepath储存最后一个文件的路径

    // 开始编写10分钟写入一次XML文件的代码
    QString currentDateTime = node.Date + node.Time;                       // currentDateTime储存node中的日期和时间
    currentDateTime.remove(14, 4);                                         // 取日期、小时以及分钟数的第一位
    static QString lastDateTime = "2000-01-0100:0";                        // 给静态变量lastDateTime赋值

    QString newData = StoreNewData();                                      // 获得内存中新的一条node的值的字符串
    static QString dataBase = "";                                          // 定义dataBase用于存储内存中十分钟内的值的字符串
    dataBase += newData;

    if(operator > (currentDateTime, lastDateTime) || ForceWrite == true)   // 判断新的日期及时间的大小，以确定是否过了十分钟
    {
        ForceWrite = false;
        QString lastDate = lastFileName;                                   // 定义lastDate获得最后一个文件的日期
        lastDate.replace(QString("Log-"),QString(""));
        lastDate.replace(QString(".xml"),QString(""));

        if(operator > (node.Date, lastDate))                               // 判断新的node的日期是否大于最后一个文件的日期
        {
            int lastIndex = dataBase.lastIndexOf("\n    <record Date=");   // 删除dataBase中新的一天的数据
            int newDataLength = newData.length();
            dataBase.remove(lastIndex, newDataLength);
        }

        if (WindowClose == true)
        {
            InsertData(dataBase, lastFilePath);
        }
        else
        {
            // 新建线程将内存中的数据写入XML文件
            StartInsertData *newInsertData = new StartInsertData();
            newInsertData->dataBase = dataBase;
            newInsertData->lastFilePath = lastFilePath;
            newInsertData->start();
        }

        dataBase = "";                          // 清空内存中的数据
        lastDateTime = currentDateTime;         // 将内存中作为比较标准的时间变更为新的时间

        if(operator > (node.Date, lastDate))    // 判断新的node的日期是否大于最后一个文件的日期
        {
            WriteNewFile();                     // 新建一个xml写入新的一天的数据
        }
    }
}

void XmlWriter::WriteNewFile()      //新建xml并写入新一天的数据
{
    //QString searchPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/BatLogs";
    QString searchPath = "D:/BatLogs";
    QString newfilepath = searchPath + "/Log-" + node.Date  + ".xml";

    IsWriting = true;

    QFile newFile(newfilepath);
    if(!newFile.open(QFile::WriteOnly | QFile::Text))
    {
        return;
    }

    QXmlStreamWriter writer(&newFile);          // 开始写XML
    writer.setCodec("utf-8");                   // XML 编码
    writer.setAutoFormatting(true);             // 自动格式化
    writer.writeStartDocument("1.0");           // 开始.文档（XML 声明）
    writer.writeStartElement("records");        // 开始根节点 <records>

    writer.writeStartElement("record");         // 开始一级节点 <record>
    writer.writeAttribute("Date", node.Date);   // record的属性：Date
    writer.writeAttribute("Time", node.Time);   // record的属性：Time

    //battery部分写入xml
    writer.writeStartElement("battery");        // 开始二级节点<battery>
    for(int v2 = 0 ; v2 < 84 ; v2++)
    {
        XmlNode::Battery battery = node.Batteries[v2];
        writer.writeStartElement("volt");       // 开始子元素<volt>
        writer.writeAttribute("Num", battery.Num);
        writer.writeCharacters(battery.Volt);
        writer.writeEndElement();
    }
    writer.writeEndElement();                   // 结束二级节点<battery>

    //temperature部分写入xml
    writer.writeStartElement("temperature");    // 开始二级节点<temperature>
    for(int t2 = 0 ; t2 < 32 ; t2++)
    {
        XmlNode::Temperature tempereture = node.Temperatures[t2];
        writer.writeStartElement("temp");       // 开始子元素<temp>
        writer.writeAttribute("Num", tempereture.Num);
        writer.writeCharacters(tempereture.Temp);
        writer.writeEndElement();
    }
    writer.writeEndElement();                   // 结束二级节点<temperature>

    //voltage部分写入xml
    writer.writeStartElement("voltage");        // 开始二级节点<voltage>
    for(int u2 = 0 ; u2< 2 ; u2++)
    {
        XmlNode::Voltage voltage = node.Voltages[u2];
        writer.writeStartElement("volt");       // 开始子元素<volt>
        writer.writeAttribute("Num", voltage.Num);
        writer.writeCharacters(voltage.Volt);
        writer.writeEndElement();
    }
    writer.writeEndElement();                   // 结束二级节点<voltage>

    //current部分写入xml
    writer.writeStartElement("current");        // 开始二级节点<current>
    for(int c2 = 0 ; c2< 1 ; c2++)
    {
        XmlNode::Current current = node.Currents[c2];
        writer.writeStartElement("curr");       // 开始子元素<curr>
        writer.writeAttribute("Num", current.Num);
        writer.writeCharacters(current.Curr);
        writer.writeEndElement();
    }
    writer.writeEndElement();                   // 结束二级节点<current>

    writer.writeEndElement();                   // 结束一级节点<record>
    writer.writeEndElement();                   // 结束根元素 <records>
    writer.writeEndDocument();                  // 结束文档
    newFile.close();                            // 关闭文件

}

QString XmlWriter::StoreNewData()   //将新的node的内容转成字符串写入内存
{
    QString newData;                //新建newData储存新的node的值的字符串
    newData += "\n    <record Date=\"" + node.Date + "\" Time=\"" + node.Time + "\">";

    //battery部分写入newData
    newData += "\n        <battery>";
    for(int v2 = 0; v2<84; v2++)
    {
        XmlNode::Battery battery = node.Batteries[v2];
        newData +="\n            <volt Num=\"" + battery.Num + "\">" + battery.Volt + "</volt>";
    }
    newData += "\n        </battery>";

    //temperature部分写入newData
    newData += "\n        <temperature>";
    for(int t2 = 0 ; t2 < 32 ; t2++)
    {
        XmlNode::Temperature tempereture = node.Temperatures[t2];
        newData += "\n            <temp Num=\"" + tempereture.Num + "\">" + tempereture.Temp + "</temp>";
    }
    newData += "\n        </temperature>";

    //voltage部分写入newData
    newData += "\n          <voltage>";
    for(int u2 = 0 ; u2< 2 ; u2++)
    {
        XmlNode::Voltage voltage = node.Voltages[u2];
        newData += "\n            <volt Num=\"" + voltage.Num + "\">" + voltage.Volt + "</volt>";
    }
    newData += "\n        </voltage>";

    //current部分写入newData
    newData += "\n        <current>";
    for(int c2 = 0 ; c2< 1 ; c2++)
    {
        XmlNode::Current current = node.Currents[c2];
        newData += "\n            <curr Num=\"" + current.Num + "\">" + current.Curr + "</curr>";
    }
    newData += "\n        </current>";
    newData += "\n    </record>";

    return newData;                 //返回newData
}

void StartInsertData::run()         // 新的线程用来写入内存中的数据
{
    XmlWriter::WriteBtnDisabled = true;
    //QString searchPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/BatLogs";
    QString searchPath = "D:/BatLogs";
    QString dataBase = StartInsertData::dataBase;                   // 将传进来的十分钟的数据的字符串赋给dataBase
    QString lastFilePath = StartInsertData::lastFilePath;           // 将传进来的最后一个文件的路径的字符串赋给lastFilepath

    XmlWriter::IsWriting = true;

    QFile lastFile(lastFilePath);
    if(!(lastFile.open(QFile::ReadOnly | QFile::Text)))             // 以只读模式打开最后一个文件
    {
        return;
    }


    QString previousData = lastFile.readAll();                      // 读取文件所有内容
    QString BakFilePath = searchPath + "/Log-" +
            XMLcurrDateTime->toString("yyyy-MM-dd") + ".xml.bak";       // 获取备份文件的路径
    lastFile.copy(BakFilePath);                                     // 备份最后一个文件

    previousData.replace(QString("\n</records>\n"), QString(""));   // 去掉xml文件中的结束根节点records
    QString finalData = previousData + dataBase +"\n</records>\n";  // 将新的十分钟的数据的字符串加到原有数据的字符串中并在最后加上结束根节点records
    QFile newFile(lastFilePath);                                    // 在原来的最后一个文件的路径新建一个文件

    if(!newFile.open(QFile::WriteOnly | QFile::Text))               // 以只写模式打开文件
    {
        return;
    }
    QTextStream out(&newFile);                                      // 将目前为止所有的数据写入新的xml中
    out<<finalData;
    out.flush();

    newFile.close();                                                // 关闭文件
    QFile BakFile(BakFilePath);                                     // 删除备份文件
    BakFile.remove();

    *XMLcurrDateTime = QDateTime::currentDateTime();
    XmlWriter::logBox += XMLcurrDateTime->toString("yyyy-MM-dd hh:mm:ss")
            + "    数据已写入“Log-" + XMLcurrDateTime->toString("yyyy-MM-dd") + ".xml”文件";

}

void XmlWriter::InsertData(QString data, QString lastPath)
{
    //QString searchPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/BatLogs";
    QString searchPath = "D:/BatLogs";
    QString dataBase = data;                   //将传进来的十分钟的数据的字符串赋给dataBase
    QString lastFilePath = lastPath;           //将传进来的最后一个文件的路径的字符串赋给lastFilepath
    QFile lastFile(lastFilePath);
    if(!(lastFile.open(QFile::ReadOnly | QFile::Text)))             // 以只读模式打开最后一个文件
    {
        return;
    }

    QString previousData = lastFile.readAll();                      // 读取文件所有内容
    QString BakFilePath = searchPath + "/Log-" +
            XMLcurrDateTime->toString("yyyy-MM-dd") + ".xml.bak";       // 获取备份文件的路径
    lastFile.copy(BakFilePath);                                     // 备份最后一个文件

    previousData.replace(QString("\n</records>\n"), QString(""));   // 去掉xml文件中的结束根节点records
    QString finalData = previousData + dataBase +"\n</records>\n";  // 将新的十分钟的数据的字符串加到原有数据的字符串中并在最后加上结束根节点records
    QFile newFile(lastFilePath);                                    // 在原来的最后一个文件的路径新建一个文件

    if(!newFile.open(QFile::WriteOnly | QFile::Text))               // 以只写模式打开文件
    {
        return;
    }
    QTextStream out(&newFile);                                      // 将目前为止所有的数据写入新的xml中
    out<<finalData;
    out.flush();

    newFile.close();                                                // 关闭文件
    QFile BakFile(BakFilePath);                                     // 删除备份文件
    BakFile.remove();

}











