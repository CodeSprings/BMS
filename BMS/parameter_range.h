#ifndef PARAMETER_RANGE_H
#define PARAMETER_RANGE_H

#include <QDialog>
#include <QMessageBox>
#include <QMetaType>
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QDateTime>
#include <QDir>
#include <QStandardPaths>


namespace Ui {
class Parameter_Range_Set;
}

class Parameter_Range_Set : public QDialog
{
    Q_OBJECT

public:
    explicit Parameter_Range_Set(QWidget *parent = 0);
    ~Parameter_Range_Set();

    //double ParaData[16];

    QString ParaData[16];

    void Set_Parameter_Range();

    void Set_Parameter_Range_Dialog();

    void ReadPara();

signals:
    void SuccessWriting();

private slots:
    void on_InsertParameter_clicked();

private:
    Ui::Parameter_Range_Set *ui;
protected:

};

#endif // PARAMETER_RANGE_H
