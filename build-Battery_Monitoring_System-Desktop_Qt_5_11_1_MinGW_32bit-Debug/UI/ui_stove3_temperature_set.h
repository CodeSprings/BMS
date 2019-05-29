/********************************************************************************
** Form generated from reading UI file 'stove3_temperature_set.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOVE3_TEMPERATURE_SET_H
#define UI_STOVE3_TEMPERATURE_SET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Stove3_Temperature_Set
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_17;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *input_Start_Temperature;
    QLineEdit *input_Time1;
    QLineEdit *input_Terminal_Temperature1;
    QLineEdit *input_Time2;
    QLineEdit *input_Terminal_Temperature2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QLabel *label_11;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_15;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *input_Time3;
    QLineEdit *input_Terminal_Temperature3;
    QLineEdit *input_Time4;
    QLineEdit *input_Terminal_Temperature4;
    QLineEdit *input_Time5;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *stove3_Temperature_Set_OkBtn;
    QPushButton *stove3_Temperature_Set_QuitBtn;

    void setupUi(QDialog *Stove3_Temperature_Set)
    {
        if (Stove3_Temperature_Set->objectName().isEmpty())
            Stove3_Temperature_Set->setObjectName(QStringLiteral("Stove3_Temperature_Set"));
        Stove3_Temperature_Set->resize(850, 600);
        Stove3_Temperature_Set->setMaximumSize(QSize(850, 600));
        Stove3_Temperature_Set->setStyleSheet(QStringLiteral("background-color: rgb(85, 170, 127);"));
        verticalLayout = new QVBoxLayout(Stove3_Temperature_Set);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 50, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_17 = new QLabel(Stove3_Temperature_Set);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setMaximumSize(QSize(220, 50));
        QFont font;
        font.setPointSize(17);
        label_17->setFont(font);
        label_17->setFrameShape(QFrame::WinPanel);
        label_17->setFrameShadow(QFrame::Raised);
        label_17->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_17);

        horizontalSpacer_2 = new QSpacerItem(40, 50, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(Stove3_Temperature_Set);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(120, 50));
        QFont font1;
        font1.setPointSize(18);
        label->setFont(font1);
        label->setFrameShape(QFrame::WinPanel);
        label->setFrameShadow(QFrame::Raised);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label);

        label_5 = new QLabel(Stove3_Temperature_Set);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(120, 50));
        label_5->setFont(font1);
        label_5->setFrameShape(QFrame::WinPanel);
        label_5->setFrameShadow(QFrame::Raised);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_5);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(Stove3_Temperature_Set);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(120, 50));
        QFont font2;
        font2.setPointSize(14);
        label_2->setFont(font2);
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 0);"));
        label_2->setFrameShape(QFrame::Box);
        label_2->setFrameShadow(QFrame::Plain);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_2);

        label_3 = new QLabel(Stove3_Temperature_Set);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(120, 50));
        label_3->setFont(font2);
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 255, 0);"));
        label_3->setFrameShape(QFrame::Box);
        label_3->setFrameShadow(QFrame::Plain);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        label_4 = new QLabel(Stove3_Temperature_Set);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(120, 50));
        label_4->setFont(font2);
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 0);"));
        label_4->setFrameShape(QFrame::Box);
        label_4->setFrameShadow(QFrame::Plain);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_4);

        label_6 = new QLabel(Stove3_Temperature_Set);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(120, 50));
        label_6->setFont(font2);
        label_6->setStyleSheet(QStringLiteral("color: rgb(255, 255, 0);"));
        label_6->setFrameShape(QFrame::Box);
        label_6->setFrameShadow(QFrame::Plain);
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_6);

        label_7 = new QLabel(Stove3_Temperature_Set);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(120, 50));
        label_7->setFont(font2);
        label_7->setStyleSheet(QStringLiteral("color: rgb(255, 255, 0);"));
        label_7->setFrameShape(QFrame::Box);
        label_7->setFrameShadow(QFrame::Plain);
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_7);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        input_Start_Temperature = new QLineEdit(Stove3_Temperature_Set);
        input_Start_Temperature->setObjectName(QStringLiteral("input_Start_Temperature"));
        input_Start_Temperature->setMaximumSize(QSize(120, 50));
        input_Start_Temperature->setFont(font2);
        input_Start_Temperature->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        input_Start_Temperature->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(input_Start_Temperature);

        input_Time1 = new QLineEdit(Stove3_Temperature_Set);
        input_Time1->setObjectName(QStringLiteral("input_Time1"));
        input_Time1->setMaximumSize(QSize(120, 50));
        input_Time1->setFont(font2);
        input_Time1->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        input_Time1->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(input_Time1);

        input_Terminal_Temperature1 = new QLineEdit(Stove3_Temperature_Set);
        input_Terminal_Temperature1->setObjectName(QStringLiteral("input_Terminal_Temperature1"));
        input_Terminal_Temperature1->setMaximumSize(QSize(120, 50));
        input_Terminal_Temperature1->setFont(font2);
        input_Terminal_Temperature1->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        input_Terminal_Temperature1->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(input_Terminal_Temperature1);

        input_Time2 = new QLineEdit(Stove3_Temperature_Set);
        input_Time2->setObjectName(QStringLiteral("input_Time2"));
        input_Time2->setMaximumSize(QSize(120, 50));
        input_Time2->setFont(font2);
        input_Time2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        input_Time2->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(input_Time2);

        input_Terminal_Temperature2 = new QLineEdit(Stove3_Temperature_Set);
        input_Terminal_Temperature2->setObjectName(QStringLiteral("input_Terminal_Temperature2"));
        input_Terminal_Temperature2->setMaximumSize(QSize(120, 50));
        input_Terminal_Temperature2->setFont(font2);
        input_Terminal_Temperature2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        input_Terminal_Temperature2->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(input_Terminal_Temperature2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_8 = new QLabel(Stove3_Temperature_Set);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMaximumSize(QSize(120, 50));
        label_8->setFont(font1);
        label_8->setFrameShape(QFrame::WinPanel);
        label_8->setFrameShadow(QFrame::Raised);
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_8);

        label_11 = new QLabel(Stove3_Temperature_Set);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMaximumSize(QSize(120, 50));
        label_11->setFont(font1);
        label_11->setFrameShape(QFrame::WinPanel);
        label_11->setFrameShadow(QFrame::Raised);
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_11);

        label_14 = new QLabel(Stove3_Temperature_Set);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMaximumSize(QSize(120, 50));
        label_14->setFont(font1);
        label_14->setFrameShape(QFrame::WinPanel);
        label_14->setFrameShadow(QFrame::Raised);
        label_14->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_14);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_9 = new QLabel(Stove3_Temperature_Set);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMaximumSize(QSize(120, 50));
        label_9->setFont(font2);
        label_9->setStyleSheet(QStringLiteral("color: rgb(255, 255, 0);"));
        label_9->setFrameShape(QFrame::Box);
        label_9->setFrameShadow(QFrame::Plain);
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_9);

        label_10 = new QLabel(Stove3_Temperature_Set);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMaximumSize(QSize(120, 50));
        label_10->setFont(font2);
        label_10->setStyleSheet(QStringLiteral("color: rgb(255, 255, 0);"));
        label_10->setFrameShape(QFrame::Box);
        label_10->setFrameShadow(QFrame::Plain);
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_10);

        label_12 = new QLabel(Stove3_Temperature_Set);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMaximumSize(QSize(120, 50));
        label_12->setFont(font2);
        label_12->setStyleSheet(QStringLiteral("color: rgb(255, 255, 0);"));
        label_12->setFrameShape(QFrame::Box);
        label_12->setFrameShadow(QFrame::Plain);
        label_12->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_12);

        label_13 = new QLabel(Stove3_Temperature_Set);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMaximumSize(QSize(120, 50));
        label_13->setFont(font2);
        label_13->setStyleSheet(QStringLiteral("color: rgb(255, 255, 0);"));
        label_13->setFrameShape(QFrame::Box);
        label_13->setFrameShadow(QFrame::Plain);
        label_13->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_13);

        label_15 = new QLabel(Stove3_Temperature_Set);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMaximumSize(QSize(120, 50));
        label_15->setFont(font2);
        label_15->setStyleSheet(QStringLiteral("color: rgb(255, 255, 0);"));
        label_15->setFrameShape(QFrame::Box);
        label_15->setFrameShadow(QFrame::Plain);
        label_15->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_15);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        input_Time3 = new QLineEdit(Stove3_Temperature_Set);
        input_Time3->setObjectName(QStringLiteral("input_Time3"));
        input_Time3->setMaximumSize(QSize(120, 50));
        input_Time3->setFont(font2);
        input_Time3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        input_Time3->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(input_Time3);

        input_Terminal_Temperature3 = new QLineEdit(Stove3_Temperature_Set);
        input_Terminal_Temperature3->setObjectName(QStringLiteral("input_Terminal_Temperature3"));
        input_Terminal_Temperature3->setMaximumSize(QSize(120, 50));
        input_Terminal_Temperature3->setFont(font2);
        input_Terminal_Temperature3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        input_Terminal_Temperature3->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(input_Terminal_Temperature3);

        input_Time4 = new QLineEdit(Stove3_Temperature_Set);
        input_Time4->setObjectName(QStringLiteral("input_Time4"));
        input_Time4->setMaximumSize(QSize(120, 50));
        input_Time4->setFont(font2);
        input_Time4->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        input_Time4->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(input_Time4);

        input_Terminal_Temperature4 = new QLineEdit(Stove3_Temperature_Set);
        input_Terminal_Temperature4->setObjectName(QStringLiteral("input_Terminal_Temperature4"));
        input_Terminal_Temperature4->setMaximumSize(QSize(120, 50));
        input_Terminal_Temperature4->setFont(font2);
        input_Terminal_Temperature4->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        input_Terminal_Temperature4->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(input_Terminal_Temperature4);

        input_Time5 = new QLineEdit(Stove3_Temperature_Set);
        input_Time5->setObjectName(QStringLiteral("input_Time5"));
        input_Time5->setMaximumSize(QSize(120, 50));
        input_Time5->setFont(font2);
        input_Time5->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        input_Time5->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(input_Time5);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        stove3_Temperature_Set_OkBtn = new QPushButton(Stove3_Temperature_Set);
        stove3_Temperature_Set_OkBtn->setObjectName(QStringLiteral("stove3_Temperature_Set_OkBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stove3_Temperature_Set_OkBtn->sizePolicy().hasHeightForWidth());
        stove3_Temperature_Set_OkBtn->setSizePolicy(sizePolicy);
        stove3_Temperature_Set_OkBtn->setMaximumSize(QSize(100, 50));
        QFont font3;
        font3.setPointSize(13);
        stove3_Temperature_Set_OkBtn->setFont(font3);
        stove3_Temperature_Set_OkBtn->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        horizontalLayout_8->addWidget(stove3_Temperature_Set_OkBtn);

        stove3_Temperature_Set_QuitBtn = new QPushButton(Stove3_Temperature_Set);
        stove3_Temperature_Set_QuitBtn->setObjectName(QStringLiteral("stove3_Temperature_Set_QuitBtn"));
        sizePolicy.setHeightForWidth(stove3_Temperature_Set_QuitBtn->sizePolicy().hasHeightForWidth());
        stove3_Temperature_Set_QuitBtn->setSizePolicy(sizePolicy);
        stove3_Temperature_Set_QuitBtn->setMaximumSize(QSize(100, 50));
        stove3_Temperature_Set_QuitBtn->setFont(font3);
        stove3_Temperature_Set_QuitBtn->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        horizontalLayout_8->addWidget(stove3_Temperature_Set_QuitBtn);


        verticalLayout->addLayout(horizontalLayout_8);


        retranslateUi(Stove3_Temperature_Set);

        stove3_Temperature_Set_OkBtn->setDefault(true);
        stove3_Temperature_Set_QuitBtn->setDefault(true);


        QMetaObject::connectSlotsByName(Stove3_Temperature_Set);
    } // setupUi

    void retranslateUi(QDialog *Stove3_Temperature_Set)
    {
        Stove3_Temperature_Set->setWindowTitle(QApplication::translate("Stove3_Temperature_Set", "Dialog", nullptr));
        label_17->setText(QApplication::translate("Stove3_Temperature_Set", "\347\202\211\345\255\220\345\215\207\351\231\215\346\270\251\350\256\276\347\275\2563", nullptr));
        label->setText(QApplication::translate("Stove3_Temperature_Set", "\347\254\254\344\270\200\351\230\266\346\256\265", nullptr));
        label_5->setText(QApplication::translate("Stove3_Temperature_Set", "\347\254\254\344\272\214\351\230\266\346\256\265", nullptr));
        label_2->setText(QApplication::translate("Stove3_Temperature_Set", "\350\265\267\345\247\213\346\270\251\345\272\246SP1", nullptr));
        label_3->setText(QApplication::translate("Stove3_Temperature_Set", "\347\273\217\345\216\206\346\227\266\351\225\277T1", nullptr));
        label_4->setText(QApplication::translate("Stove3_Temperature_Set", "\347\273\210\346\255\242\346\270\251\345\272\246SP2", nullptr));
        label_6->setText(QApplication::translate("Stove3_Temperature_Set", "\347\273\217\345\216\206\346\227\266\351\225\277T2", nullptr));
        label_7->setText(QApplication::translate("Stove3_Temperature_Set", "\347\273\210\346\255\242\346\270\251\345\272\246SP3", nullptr));
        label_8->setText(QApplication::translate("Stove3_Temperature_Set", "\347\254\254\344\270\211\351\230\266\346\256\265", nullptr));
        label_11->setText(QApplication::translate("Stove3_Temperature_Set", "\347\254\254\345\233\233\351\230\266\346\256\265", nullptr));
        label_14->setText(QApplication::translate("Stove3_Temperature_Set", "\347\254\254\344\272\224\351\230\266\346\256\265", nullptr));
        label_9->setText(QApplication::translate("Stove3_Temperature_Set", "\347\273\217\345\216\206\346\227\266\351\225\277T3", nullptr));
        label_10->setText(QApplication::translate("Stove3_Temperature_Set", "\347\273\210\346\255\242\346\270\251\345\272\246SP4", nullptr));
        label_12->setText(QApplication::translate("Stove3_Temperature_Set", "\347\273\217\345\216\206\346\227\266\351\225\277T4", nullptr));
        label_13->setText(QApplication::translate("Stove3_Temperature_Set", "\347\273\210\346\255\242\346\270\251\345\272\246SP5", nullptr));
        label_15->setText(QApplication::translate("Stove3_Temperature_Set", "\347\273\217\345\216\206\346\227\266\351\225\277T5", nullptr));
        stove3_Temperature_Set_OkBtn->setText(QApplication::translate("Stove3_Temperature_Set", "\347\241\256\345\256\232", nullptr));
        stove3_Temperature_Set_QuitBtn->setText(QApplication::translate("Stove3_Temperature_Set", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Stove3_Temperature_Set: public Ui_Stove3_Temperature_Set {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOVE3_TEMPERATURE_SET_H
