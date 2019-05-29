/********************************************************************************
** Form generated from reading UI file 'inverter_controlmode.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVERTER_CONTROLMODE_H
#define UI_INVERTER_CONTROLMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Inverter_ControlMode
{
public:
    QLabel *label;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *Constant_Current_Charging_Btn;
    QRadioButton *Constant_Current_Discharge_Btn;
    QRadioButton *Constant_Power_Charging_Btn;
    QRadioButton *Constant_Power_Discharge_Btn;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Inverter_ControlMode_OkBtn;
    QPushButton *Inverter_ControlMode_QuitBtn;

    void setupUi(QDialog *Inverter_ControlMode)
    {
        if (Inverter_ControlMode->objectName().isEmpty())
            Inverter_ControlMode->setObjectName(QStringLiteral("Inverter_ControlMode"));
        Inverter_ControlMode->resize(400, 300);
        Inverter_ControlMode->setStyleSheet(QStringLiteral("background-color: rgb(85, 170, 255);"));
        label = new QLabel(Inverter_ControlMode);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 10, 171, 41));
        label->setStyleSheet(QLatin1String("background-color: rgb(255, 170, 127);\n"
"background-color: rgb(170, 170, 255);\n"
"background-color: rgb(85, 170, 255);\n"
""));
        label->setFrameShape(QFrame::WinPanel);
        label->setFrameShadow(QFrame::Raised);
        layoutWidget_2 = new QWidget(Inverter_ControlMode);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(110, 70, 145, 151));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Constant_Current_Charging_Btn = new QRadioButton(layoutWidget_2);
        Constant_Current_Charging_Btn->setObjectName(QStringLiteral("Constant_Current_Charging_Btn"));
        Constant_Current_Charging_Btn->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));

        verticalLayout->addWidget(Constant_Current_Charging_Btn);

        Constant_Current_Discharge_Btn = new QRadioButton(layoutWidget_2);
        Constant_Current_Discharge_Btn->setObjectName(QStringLiteral("Constant_Current_Discharge_Btn"));
        Constant_Current_Discharge_Btn->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));

        verticalLayout->addWidget(Constant_Current_Discharge_Btn);

        Constant_Power_Charging_Btn = new QRadioButton(layoutWidget_2);
        Constant_Power_Charging_Btn->setObjectName(QStringLiteral("Constant_Power_Charging_Btn"));
        Constant_Power_Charging_Btn->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));

        verticalLayout->addWidget(Constant_Power_Charging_Btn);

        Constant_Power_Discharge_Btn = new QRadioButton(layoutWidget_2);
        Constant_Power_Discharge_Btn->setObjectName(QStringLiteral("Constant_Power_Discharge_Btn"));
        Constant_Power_Discharge_Btn->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));

        verticalLayout->addWidget(Constant_Power_Discharge_Btn);

        widget = new QWidget(Inverter_ControlMode);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(190, 240, 181, 51));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Inverter_ControlMode_OkBtn = new QPushButton(widget);
        Inverter_ControlMode_OkBtn->setObjectName(QStringLiteral("Inverter_ControlMode_OkBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Inverter_ControlMode_OkBtn->sizePolicy().hasHeightForWidth());
        Inverter_ControlMode_OkBtn->setSizePolicy(sizePolicy);
        Inverter_ControlMode_OkBtn->setMaximumSize(QSize(80, 40));
        Inverter_ControlMode_OkBtn->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));

        horizontalLayout->addWidget(Inverter_ControlMode_OkBtn);

        Inverter_ControlMode_QuitBtn = new QPushButton(widget);
        Inverter_ControlMode_QuitBtn->setObjectName(QStringLiteral("Inverter_ControlMode_QuitBtn"));
        sizePolicy.setHeightForWidth(Inverter_ControlMode_QuitBtn->sizePolicy().hasHeightForWidth());
        Inverter_ControlMode_QuitBtn->setSizePolicy(sizePolicy);
        Inverter_ControlMode_QuitBtn->setMaximumSize(QSize(80, 40));
        Inverter_ControlMode_QuitBtn->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));

        horizontalLayout->addWidget(Inverter_ControlMode_QuitBtn);


        retranslateUi(Inverter_ControlMode);

        Inverter_ControlMode_OkBtn->setDefault(true);
        Inverter_ControlMode_QuitBtn->setDefault(true);


        QMetaObject::connectSlotsByName(Inverter_ControlMode);
    } // setupUi

    void retranslateUi(QDialog *Inverter_ControlMode)
    {
        Inverter_ControlMode->setWindowTitle(QApplication::translate("Inverter_ControlMode", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Inverter_ControlMode", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; color:#ffff00;\">\351\200\206\345\217\230\345\231\250\346\216\247\345\210\266\346\250\241\345\274\217\350\256\276\345\256\232</span></p></body></html>", Q_NULLPTR));
        Constant_Current_Charging_Btn->setText(QApplication::translate("Inverter_ControlMode", "\346\201\222\347\224\265\346\265\201\345\205\205\347\224\265", Q_NULLPTR));
        Constant_Current_Discharge_Btn->setText(QApplication::translate("Inverter_ControlMode", "\346\201\222\347\224\265\346\265\201\346\224\276\347\224\265", Q_NULLPTR));
        Constant_Power_Charging_Btn->setText(QApplication::translate("Inverter_ControlMode", "\346\201\222\345\212\237\347\216\207\345\205\205\347\224\265", Q_NULLPTR));
        Constant_Power_Discharge_Btn->setText(QApplication::translate("Inverter_ControlMode", "\346\201\222\345\212\237\347\216\207\346\224\276\347\224\265", Q_NULLPTR));
        Inverter_ControlMode_OkBtn->setText(QApplication::translate("Inverter_ControlMode", "\347\241\256\345\256\232", Q_NULLPTR));
        Inverter_ControlMode_QuitBtn->setText(QApplication::translate("Inverter_ControlMode", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Inverter_ControlMode: public Ui_Inverter_ControlMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVERTER_CONTROLMODE_H
