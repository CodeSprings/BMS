/********************************************************************************
** Form generated from reading UI file 'inverter_switch.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVERTER_SWITCH_H
#define UI_INVERTER_SWITCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Inverter_Switch
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Inverter_Switch_OkBtn;
    QPushButton *Inverter_Switch_QuitBtn;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *Inverter_Open_Btn;
    QRadioButton *Inverter_Close_Btn;

    void setupUi(QDialog *Inverter_Switch)
    {
        if (Inverter_Switch->objectName().isEmpty())
            Inverter_Switch->setObjectName(QStringLiteral("Inverter_Switch"));
        Inverter_Switch->resize(400, 300);
        Inverter_Switch->setStyleSheet(QStringLiteral("background-color: rgb(85, 170, 255);"));
        label = new QLabel(Inverter_Switch);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 10, 141, 41));
        label->setStyleSheet(QLatin1String("background-color: rgb(255, 170, 127);\n"
"background-color: rgb(170, 170, 255);\n"
"background-color: rgb(85, 255, 127);\n"
"background-color: rgb(170, 170, 255);\n"
"background-color: rgb(85, 170, 255);"));
        label->setFrameShape(QFrame::WinPanel);
        label->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(Inverter_Switch);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(170, 230, 211, 61));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Inverter_Switch_OkBtn = new QPushButton(layoutWidget);
        Inverter_Switch_OkBtn->setObjectName(QStringLiteral("Inverter_Switch_OkBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Inverter_Switch_OkBtn->sizePolicy().hasHeightForWidth());
        Inverter_Switch_OkBtn->setSizePolicy(sizePolicy);
        Inverter_Switch_OkBtn->setMaximumSize(QSize(80, 40));
        Inverter_Switch_OkBtn->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));

        horizontalLayout->addWidget(Inverter_Switch_OkBtn);

        Inverter_Switch_QuitBtn = new QPushButton(layoutWidget);
        Inverter_Switch_QuitBtn->setObjectName(QStringLiteral("Inverter_Switch_QuitBtn"));
        sizePolicy.setHeightForWidth(Inverter_Switch_QuitBtn->sizePolicy().hasHeightForWidth());
        Inverter_Switch_QuitBtn->setSizePolicy(sizePolicy);
        Inverter_Switch_QuitBtn->setMaximumSize(QSize(80, 40));
        Inverter_Switch_QuitBtn->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));

        horizontalLayout->addWidget(Inverter_Switch_QuitBtn);

        layoutWidget_2 = new QWidget(Inverter_Switch);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(160, 80, 91, 81));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Inverter_Open_Btn = new QRadioButton(layoutWidget_2);
        Inverter_Open_Btn->setObjectName(QStringLiteral("Inverter_Open_Btn"));
        sizePolicy.setHeightForWidth(Inverter_Open_Btn->sizePolicy().hasHeightForWidth());
        Inverter_Open_Btn->setSizePolicy(sizePolicy);
        Inverter_Open_Btn->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));

        verticalLayout->addWidget(Inverter_Open_Btn);

        Inverter_Close_Btn = new QRadioButton(layoutWidget_2);
        Inverter_Close_Btn->setObjectName(QStringLiteral("Inverter_Close_Btn"));
        sizePolicy.setHeightForWidth(Inverter_Close_Btn->sizePolicy().hasHeightForWidth());
        Inverter_Close_Btn->setSizePolicy(sizePolicy);
        Inverter_Close_Btn->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));

        verticalLayout->addWidget(Inverter_Close_Btn);


        retranslateUi(Inverter_Switch);

        Inverter_Switch_OkBtn->setDefault(true);
        Inverter_Switch_QuitBtn->setDefault(true);


        QMetaObject::connectSlotsByName(Inverter_Switch);
    } // setupUi

    void retranslateUi(QDialog *Inverter_Switch)
    {
        Inverter_Switch->setWindowTitle(QApplication::translate("Inverter_Switch", "Dialog", nullptr));
        label->setText(QApplication::translate("Inverter_Switch", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; color:#ffff00;\">\351\200\206\345\217\230\345\231\250\345\220\257\345\201\234\350\256\276\347\275\256</span></p></body></html>", nullptr));
        Inverter_Switch_OkBtn->setText(QApplication::translate("Inverter_Switch", "\347\241\256\345\256\232", nullptr));
        Inverter_Switch_QuitBtn->setText(QApplication::translate("Inverter_Switch", "\345\217\226\346\266\210", nullptr));
        Inverter_Open_Btn->setText(QApplication::translate("Inverter_Switch", "\346\211\223\345\274\200", nullptr));
        Inverter_Close_Btn->setText(QApplication::translate("Inverter_Switch", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Inverter_Switch: public Ui_Inverter_Switch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVERTER_SWITCH_H
