/********************************************************************************
** Form generated from reading UI file 'inverter_voltage_set.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVERTER_VOLTAGE_SET_H
#define UI_INVERTER_VOLTAGE_SET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Inverter_Voltage_Set
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *set_Inverter_Voltage_OkBtn;
    QPushButton *set_Inverter_Voltage_QuitBtn;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *input_Inverter_Voltage;

    void setupUi(QDialog *Inverter_Voltage_Set)
    {
        if (Inverter_Voltage_Set->objectName().isEmpty())
            Inverter_Voltage_Set->setObjectName(QStringLiteral("Inverter_Voltage_Set"));
        Inverter_Voltage_Set->resize(400, 300);
        Inverter_Voltage_Set->setStyleSheet(QStringLiteral("background-color: rgb(85, 170, 255);"));
        label = new QLabel(Inverter_Voltage_Set);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 20, 141, 41));
        label->setStyleSheet(QLatin1String("background-color: rgb(255, 170, 127);\n"
"background-color: rgb(170, 170, 255);\n"
"background-color: rgb(85, 170, 255);"));
        label->setFrameShape(QFrame::WinPanel);
        label->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(Inverter_Voltage_Set);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(160, 230, 231, 61));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        set_Inverter_Voltage_OkBtn = new QPushButton(layoutWidget);
        set_Inverter_Voltage_OkBtn->setObjectName(QStringLiteral("set_Inverter_Voltage_OkBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(set_Inverter_Voltage_OkBtn->sizePolicy().hasHeightForWidth());
        set_Inverter_Voltage_OkBtn->setSizePolicy(sizePolicy);
        set_Inverter_Voltage_OkBtn->setMaximumSize(QSize(80, 40));
        set_Inverter_Voltage_OkBtn->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));

        horizontalLayout->addWidget(set_Inverter_Voltage_OkBtn);

        set_Inverter_Voltage_QuitBtn = new QPushButton(layoutWidget);
        set_Inverter_Voltage_QuitBtn->setObjectName(QStringLiteral("set_Inverter_Voltage_QuitBtn"));
        sizePolicy.setHeightForWidth(set_Inverter_Voltage_QuitBtn->sizePolicy().hasHeightForWidth());
        set_Inverter_Voltage_QuitBtn->setSizePolicy(sizePolicy);
        set_Inverter_Voltage_QuitBtn->setMaximumSize(QSize(80, 40));
        set_Inverter_Voltage_QuitBtn->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));

        horizontalLayout->addWidget(set_Inverter_Voltage_QuitBtn);

        widget = new QWidget(Inverter_Voltage_Set);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(60, 130, 281, 61));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(140, 40));
        label_2->setStyleSheet(QLatin1String("background-color: rgb(170, 170, 255);\n"
"background-color: rgb(85, 170, 127);\n"
"background-color: rgb(170, 85, 127);\n"
"background-color: rgb(85, 170, 127);"));
        label_2->setFrameShape(QFrame::Box);
        label_2->setFrameShadow(QFrame::Raised);

        horizontalLayout_2->addWidget(label_2);

        input_Inverter_Voltage = new QLineEdit(widget);
        input_Inverter_Voltage->setObjectName(QStringLiteral("input_Inverter_Voltage"));
        input_Inverter_Voltage->setMaximumSize(QSize(80, 40));
        QFont font;
        font.setPointSize(15);
        input_Inverter_Voltage->setFont(font);
        input_Inverter_Voltage->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(input_Inverter_Voltage);


        retranslateUi(Inverter_Voltage_Set);

        set_Inverter_Voltage_OkBtn->setDefault(true);
        set_Inverter_Voltage_QuitBtn->setDefault(true);


        QMetaObject::connectSlotsByName(Inverter_Voltage_Set);
    } // setupUi

    void retranslateUi(QDialog *Inverter_Voltage_Set)
    {
        Inverter_Voltage_Set->setWindowTitle(QApplication::translate("Inverter_Voltage_Set", "Dialog", nullptr));
        label->setText(QApplication::translate("Inverter_Voltage_Set", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; color:#ffff00;\">\351\200\206\345\217\230\345\231\250\347\224\265\345\216\213\350\256\276\345\256\232</span></p></body></html>", nullptr));
        set_Inverter_Voltage_OkBtn->setText(QApplication::translate("Inverter_Voltage_Set", "\347\241\256\345\256\232", nullptr));
        set_Inverter_Voltage_QuitBtn->setText(QApplication::translate("Inverter_Voltage_Set", "\345\217\226\346\266\210", nullptr));
        label_2->setText(QApplication::translate("Inverter_Voltage_Set", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\347\224\265\345\216\213\350\256\276\345\256\232\345\200\274\357\274\210V\357\274\211\357\274\232</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Inverter_Voltage_Set: public Ui_Inverter_Voltage_Set {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVERTER_VOLTAGE_SET_H
