#ifndef XMLWRITER_H
#define XMLWRITER_H

#include <QWidget>
#include <QFile>
#include <QXmlStreamWriter>
#include <QList>
#include <QStringList>
#include <QDesktopServices>
#include <QDateTime>
#include <QIODevice>
#include <QtXml/QDomDocument>
#include <IOStream>
#include <QTextStream>
#include <QDirModel>
#include <QDir>
#include <QFileDialog>
#include <QFileInfoList>
#include <QCloseEvent>
#include <QThread>

class XmlNode
{
public:
    class Battery
    {
    public:
        QString Num;
        QString Volt;
    };

    class Temperature
    {
    public:
        QString Num;
        QString Temp;
    };

    class Voltage
    {
    public:
        QString Num;
        QString Volt;
    };

    class Current
    {
    public:
        QString Num;
        QString Curr;
    };
    public:
        QString Date;
        QString Time;

    QList<XmlNode::Battery> Batteries ;
    QList<XmlNode::Temperature> Temperatures;
    QList<XmlNode::Voltage> Voltages;
    QList<XmlNode::Current> Currents;
};


class XmlWriter
{
public:

    static QString dataSource[119];

    static XmlNode node;

    static bool ForceWrite;

    static bool WindowClose;

    static bool WriteBtnDisabled;

    static QString logBox;

    void XmlData(QString *tempData);

    void StartWrite();

    static bool IsWriting;

private:
    void WriteNewFile();

    QString StoreNewData();

    void InsertData(QString data, QString lastPath);
};

// 启动InsertData的后台线程
class StartInsertData : public QThread
{
protected:
    void run();
public:
    QString dataBase;
    QString lastFilePath;
};



#endif // XMLWRITER_H
