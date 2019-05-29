/********************************************************************************
** Form generated from reading UI file 'inverter_activepower_set.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVERTER_ACTIVEPOWER_SET_H
#define UI_INVERTER_ACTIVEPOWER_SET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Inverter_ActivePower_Set
{
public:
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *input_Inverter_ActivePower;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *set_Inverter_ActivePower_OkBtn;
    QPushButton *set_Inverter_ActivePower_QuitBtn;

    void setupUi(QDialog *Inverter_ActivePower_Set)
    {
        if (Inverter_ActivePower_Set->objectName().isEmpty())
            Inverter_ActivePower_Set->setObjectName(QStringLiteral("Inverter_ActivePower_Set"));
        Inverter_ActivePower_Set->resize(400, 300);
        Inverter_ActivePower_Set->setStyleSheet(QStringLiteral("background-color: rgb(85, 170, 255);"));
        label = new QLabel(Inverter_ActivePower_Set);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 10, 151, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 127);\n"
"background-color: rgb(170, 170, 127);\n"
"background-color: rgb(170, 170, 255);\n"
"background-color: rgb(85, 170, 255);\n"
"font: 16pt \"\346\245\267\344\275\223\";"));
        label->setFrameShape(QFrame::WinPanel);
        label->setFrameShadow(QFrame::Raised);
        widget = new QWidget(Inverter_ActivePower_Set);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(90, 110, 221, 61));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(120, 40));
        label_2->setStyleSheet(QLatin1String("background-color: rgb(85, 255, 255);\n"
"background-color: rgb(170, 85, 127);\n"
"background-color: rgb(85, 85, 255);\n"
"background-color: rgb(200, 124, 171);\n"
"background-color: rgb(170, 85, 127);\n"
"background-color: rgb(85, 170, 127);"));
        label_2->setFrameShape(QFrame::Box);
        label_2->setFrameShadow(QFrame::Raised);

        horizontalLayout_2->addWidget(label_2);

        input_Inverter_ActivePower = new QLineEdit(widget);
        input_Inverter_ActivePower->setObjectName(QStringLiteral("input_Inverter_ActivePower"));
        input_Inverter_ActivePower->setMaximumSize(QSize(80, 40));
        QFont font1;
        font1.setPointSize(15);
        input_Inverter_ActivePower->setFont(font1);
        input_Inverter_ActivePower->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(input_Inverter_ActivePower);

        widget1 = new QWidget(Inverter_ActivePower_Set);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(160, 240, 201, 51));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        set_Inverter_ActivePower_OkBtn = new QPushButton(widget1);
        set_Inverter_ActivePower_OkBtn->setObjectName(QStringLiteral("set_Inverter_ActivePower_OkBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(set_Inverter_ActivePower_OkBtn->sizePolicy().hasHeightForWidth());
        set_Inverter_ActivePower_OkBtn->setSizePolicy(sizePolicy);
        set_Inverter_ActivePower_OkBtn->setMaximumSize(QSize(80, 40));
        set_Inverter_ActivePower_OkBtn->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));

        horizontalLayout->addWidget(set_Inverter_ActivePower_OkBtn);

        set_Inverter_ActivePower_QuitBtn = new QPushButton(widget1);
        set_Inverter_ActivePower_QuitBtn->setObjectName(QStringLiteral("set_Inverter_ActivePower_QuitBtn"));
        sizePolicy.setHeightForWidth(set_Inverter_ActivePower_QuitBtn->sizePolicy().hasHeightForWidth());
        set_Inverter_ActivePower_QuitBtn->setSizePolicy(sizePolicy);
        set_Inverter_ActivePower_QuitBtn->setMaximumSize(QSize(80, 40));
        set_Inverter_ActivePower_QuitBtn->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));

        horizontalLayout->addWidget(set_Inverter_ActivePower_QuitBtn);


        retranslateUi(Inverter_ActivePower_Set);

        set_Inverter_ActivePower_OkBtn->setDefault(true);
        set_Inverter_ActivePower_QuitBtn->setDefault(true);


        QMetaObject::connectSlotsByName(Inverter_ActivePower_Set);
    } // setupUi

    void retranslateUi(QDialog *Inverter_ActivePower_Set)
    {
        Inverter_ActivePower_Set->setWindowTitle(QApplication::translate("Inverter_ActivePower_Set", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Inverter_ActivePower_Set", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; color:#ffff00;\">\346\234\211\345\212\237\345\212\237\347\216\207\350\256\276\347\275\256</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("Inverter_ActivePower_Set", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\350\256\276\345\256\232\345\200\274\357\274\210KW\357\274\211\357\274\232</span></p></body></html>", Q_NULLPTR));
        set_Inverter_ActivePower_OkBtn->setText(QApplication::translate("Inverter_ActivePower_Set", "\347\241\256\345\256\232", Q_NULLPTR));
        set_Inverter_ActivePower_QuitBtn->setText(QApplication::translate("Inverter_ActivePower_Set", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Inverter_ActivePower_Set: public Ui_Inverter_ActivePower_Set {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVERTER_ACTIVEPOWER_SET_H
