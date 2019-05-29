/********************************************************************************
** Form generated from reading UI file 'inverter_current_set.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVERTER_CURRENT_SET_H
#define UI_INVERTER_CURRENT_SET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Inverter_Current_Set
{
public:
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *set_Inverter_Current_OkBtn;
    QPushButton *set_Inverter_Current_QuitBtn;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *input_Inverter_Current;

    void setupUi(QDialog *Inverter_Current_Set)
    {
        if (Inverter_Current_Set->objectName().isEmpty())
            Inverter_Current_Set->setObjectName(QStringLiteral("Inverter_Current_Set"));
        Inverter_Current_Set->resize(400, 300);
        Inverter_Current_Set->setStyleSheet(QStringLiteral("background-color: rgb(85, 170, 255);"));
        label = new QLabel(Inverter_Current_Set);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 10, 151, 41));
        label->setStyleSheet(QLatin1String("background-color: rgb(170, 170, 127);\n"
"background-color: rgb(170, 170, 255);\n"
"background-color: rgb(85, 170, 255);"));
        label->setFrameShape(QFrame::WinPanel);
        label->setFrameShadow(QFrame::Raised);
        widget = new QWidget(Inverter_Current_Set);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(180, 240, 191, 51));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        set_Inverter_Current_OkBtn = new QPushButton(widget);
        set_Inverter_Current_OkBtn->setObjectName(QStringLiteral("set_Inverter_Current_OkBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(set_Inverter_Current_OkBtn->sizePolicy().hasHeightForWidth());
        set_Inverter_Current_OkBtn->setSizePolicy(sizePolicy);
        set_Inverter_Current_OkBtn->setMaximumSize(QSize(80, 40));
        set_Inverter_Current_OkBtn->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));

        horizontalLayout->addWidget(set_Inverter_Current_OkBtn);

        set_Inverter_Current_QuitBtn = new QPushButton(widget);
        set_Inverter_Current_QuitBtn->setObjectName(QStringLiteral("set_Inverter_Current_QuitBtn"));
        sizePolicy.setHeightForWidth(set_Inverter_Current_QuitBtn->sizePolicy().hasHeightForWidth());
        set_Inverter_Current_QuitBtn->setSizePolicy(sizePolicy);
        set_Inverter_Current_QuitBtn->setMaximumSize(QSize(80, 40));
        set_Inverter_Current_QuitBtn->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));

        horizontalLayout->addWidget(set_Inverter_Current_QuitBtn);

        widget1 = new QWidget(Inverter_Current_Set);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(50, 110, 291, 61));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(140, 40));
        label_2->setStyleSheet(QLatin1String("background-color: rgb(170, 85, 127);\n"
"background-color: rgb(85, 170, 127);"));
        label_2->setFrameShape(QFrame::Box);
        label_2->setFrameShadow(QFrame::Raised);

        horizontalLayout_2->addWidget(label_2);

        input_Inverter_Current = new QLineEdit(widget1);
        input_Inverter_Current->setObjectName(QStringLiteral("input_Inverter_Current"));
        input_Inverter_Current->setMaximumSize(QSize(80, 40));
        QFont font;
        font.setPointSize(15);
        input_Inverter_Current->setFont(font);
        input_Inverter_Current->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(input_Inverter_Current);


        retranslateUi(Inverter_Current_Set);

        set_Inverter_Current_OkBtn->setDefault(true);
        set_Inverter_Current_QuitBtn->setDefault(true);


        QMetaObject::connectSlotsByName(Inverter_Current_Set);
    } // setupUi

    void retranslateUi(QDialog *Inverter_Current_Set)
    {
        Inverter_Current_Set->setWindowTitle(QApplication::translate("Inverter_Current_Set", "Dialog", nullptr));
        label->setText(QApplication::translate("Inverter_Current_Set", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; color:#ffff00;\">\351\200\206\345\217\230\345\231\250\347\224\265\346\265\201\350\256\276\345\256\232</span></p></body></html>", nullptr));
        set_Inverter_Current_OkBtn->setText(QApplication::translate("Inverter_Current_Set", "\347\241\256\345\256\232", nullptr));
        set_Inverter_Current_QuitBtn->setText(QApplication::translate("Inverter_Current_Set", "\345\217\226\346\266\210", nullptr));
        label_2->setText(QApplication::translate("Inverter_Current_Set", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\347\224\265\346\265\201\350\256\276\345\256\232\345\200\274\357\274\210A\357\274\211\357\274\232</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Inverter_Current_Set: public Ui_Inverter_Current_Set {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVERTER_CURRENT_SET_H
