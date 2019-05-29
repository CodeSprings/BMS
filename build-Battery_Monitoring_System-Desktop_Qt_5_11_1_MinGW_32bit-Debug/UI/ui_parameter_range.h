/********************************************************************************
** Form generated from reading UI file 'parameter_range.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETER_RANGE_H
#define UI_PARAMETER_RANGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Parameter_Range_Set
{
public:
    QPushButton *InsertParameter;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_9;
    QLabel *label_14;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_13;
    QLabel *label_3;
    QLabel *label_8;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_12;
    QLabel *label_11;
    QLabel *label_10;
    QLineEdit *UrgentAlarm_Temp_H;
    QLineEdit *Alarm_Temp_H;
    QLineEdit *UrgentAlarm_SumVolt_H;
    QLineEdit *Alarm_SumVolt_H;
    QLineEdit *Alarm_SumVolt_L;
    QLineEdit *UrgentAlarm_SumVolt_L;
    QLineEdit *Alarm_SumCurr_H;
    QLineEdit *UrgentAlarm_SumCurr_H;
    QLineEdit *UrgentAlarm_Temp_L;
    QLineEdit *UrgentAlarm_Volt_H;
    QLineEdit *Alarm_Temp_L;
    QLineEdit *Alarm_Volt_L;
    QLineEdit *UrgentAlarm_Volt_L;
    QLineEdit *Alarm_SumCurr_L;
    QLineEdit *Alarm_Volt_H;
    QLineEdit *UrgentAlarm_SumCurr_L;

    void setupUi(QDialog *Parameter_Range_Set)
    {
        if (Parameter_Range_Set->objectName().isEmpty())
            Parameter_Range_Set->setObjectName(QStringLiteral("Parameter_Range_Set"));
        Parameter_Range_Set->resize(636, 484);
        InsertParameter = new QPushButton(Parameter_Range_Set);
        InsertParameter->setObjectName(QStringLiteral("InsertParameter"));
        InsertParameter->setGeometry(QRect(250, 420, 91, 41));
        layoutWidget = new QWidget(Parameter_Range_Set);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 20, 451, 387));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setMaximumSize(QSize(80, 30));
        QFont font;
        font.setPointSize(12);
        font.setKerning(true);
        label_9->setFont(font);
        label_9->setAutoFillBackground(false);
        label_9->setAlignment(Qt::AlignCenter);
        label_9->setOpenExternalLinks(false);

        gridLayout->addWidget(label_9, 5, 1, 1, 1);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMaximumSize(QSize(500, 30));
        QFont font1;
        font1.setPointSize(16);
        label_14->setFont(font1);
        label_14->setAlignment(Qt::AlignCenter);
        label_14->setOpenExternalLinks(false);

        gridLayout->addWidget(label_14, 0, 3, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMaximumSize(QSize(80, 30));
        label_7->setFont(font);
        label_7->setAutoFillBackground(false);
        label_7->setAlignment(Qt::AlignCenter);
        label_7->setOpenExternalLinks(false);

        gridLayout->addWidget(label_7, 3, 1, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMaximumSize(QSize(80, 30));
        label_6->setFont(font);
        label_6->setAutoFillBackground(false);
        label_6->setAlignment(Qt::AlignCenter);
        label_6->setOpenExternalLinks(false);

        gridLayout->addWidget(label_6, 2, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        label->setOpenExternalLinks(false);

        gridLayout->addWidget(label, 5, 0, 2, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setOpenExternalLinks(false);

        gridLayout->addWidget(label_2, 1, 0, 2, 1);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font1);
        label_13->setAlignment(Qt::AlignCenter);
        label_13->setOpenExternalLinks(false);

        gridLayout->addWidget(label_13, 0, 2, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 3, 0, 2, 1, Qt::AlignVCenter);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setMaximumSize(QSize(80, 30));
        label_8->setFont(font);
        label_8->setAutoFillBackground(false);
        label_8->setAlignment(Qt::AlignCenter);
        label_8->setOpenExternalLinks(false);

        gridLayout->addWidget(label_8, 4, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMaximumSize(QSize(80, 30));
        label_5->setFont(font);
        label_5->setAutoFillBackground(false);
        label_5->setAlignment(Qt::AlignCenter);
        label_5->setOpenExternalLinks(false);

        gridLayout->addWidget(label_5, 1, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);
        label_4->setOpenExternalLinks(false);

        gridLayout->addWidget(label_4, 7, 0, 2, 1);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);
        label_12->setMaximumSize(QSize(80, 30));
        label_12->setFont(font);
        label_12->setAutoFillBackground(false);
        label_12->setAlignment(Qt::AlignCenter);
        label_12->setOpenExternalLinks(false);

        gridLayout->addWidget(label_12, 8, 1, 1, 1);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setMaximumSize(QSize(80, 30));
        label_11->setFont(font);
        label_11->setAutoFillBackground(false);
        label_11->setAlignment(Qt::AlignCenter);
        label_11->setOpenExternalLinks(false);

        gridLayout->addWidget(label_11, 7, 1, 1, 1);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setMaximumSize(QSize(80, 30));
        label_10->setFont(font);
        label_10->setAutoFillBackground(false);
        label_10->setAlignment(Qt::AlignCenter);
        label_10->setOpenExternalLinks(false);

        gridLayout->addWidget(label_10, 6, 1, 1, 1);

        UrgentAlarm_Temp_H = new QLineEdit(layoutWidget);
        UrgentAlarm_Temp_H->setObjectName(QStringLiteral("UrgentAlarm_Temp_H"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(UrgentAlarm_Temp_H->sizePolicy().hasHeightForWidth());
        UrgentAlarm_Temp_H->setSizePolicy(sizePolicy1);
        UrgentAlarm_Temp_H->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(UrgentAlarm_Temp_H, 3, 3, 1, 1);

        Alarm_Temp_H = new QLineEdit(layoutWidget);
        Alarm_Temp_H->setObjectName(QStringLiteral("Alarm_Temp_H"));
        sizePolicy1.setHeightForWidth(Alarm_Temp_H->sizePolicy().hasHeightForWidth());
        Alarm_Temp_H->setSizePolicy(sizePolicy1);
        Alarm_Temp_H->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(Alarm_Temp_H, 3, 2, 1, 1);

        UrgentAlarm_SumVolt_H = new QLineEdit(layoutWidget);
        UrgentAlarm_SumVolt_H->setObjectName(QStringLiteral("UrgentAlarm_SumVolt_H"));
        sizePolicy1.setHeightForWidth(UrgentAlarm_SumVolt_H->sizePolicy().hasHeightForWidth());
        UrgentAlarm_SumVolt_H->setSizePolicy(sizePolicy1);
        UrgentAlarm_SumVolt_H->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(UrgentAlarm_SumVolt_H, 5, 3, 1, 1);

        Alarm_SumVolt_H = new QLineEdit(layoutWidget);
        Alarm_SumVolt_H->setObjectName(QStringLiteral("Alarm_SumVolt_H"));
        sizePolicy1.setHeightForWidth(Alarm_SumVolt_H->sizePolicy().hasHeightForWidth());
        Alarm_SumVolt_H->setSizePolicy(sizePolicy1);
        Alarm_SumVolt_H->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(Alarm_SumVolt_H, 5, 2, 1, 1);

        Alarm_SumVolt_L = new QLineEdit(layoutWidget);
        Alarm_SumVolt_L->setObjectName(QStringLiteral("Alarm_SumVolt_L"));
        sizePolicy1.setHeightForWidth(Alarm_SumVolt_L->sizePolicy().hasHeightForWidth());
        Alarm_SumVolt_L->setSizePolicy(sizePolicy1);
        Alarm_SumVolt_L->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(Alarm_SumVolt_L, 6, 2, 1, 1);

        UrgentAlarm_SumVolt_L = new QLineEdit(layoutWidget);
        UrgentAlarm_SumVolt_L->setObjectName(QStringLiteral("UrgentAlarm_SumVolt_L"));
        sizePolicy1.setHeightForWidth(UrgentAlarm_SumVolt_L->sizePolicy().hasHeightForWidth());
        UrgentAlarm_SumVolt_L->setSizePolicy(sizePolicy1);
        UrgentAlarm_SumVolt_L->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(UrgentAlarm_SumVolt_L, 6, 3, 1, 1);

        Alarm_SumCurr_H = new QLineEdit(layoutWidget);
        Alarm_SumCurr_H->setObjectName(QStringLiteral("Alarm_SumCurr_H"));
        sizePolicy1.setHeightForWidth(Alarm_SumCurr_H->sizePolicy().hasHeightForWidth());
        Alarm_SumCurr_H->setSizePolicy(sizePolicy1);
        Alarm_SumCurr_H->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(Alarm_SumCurr_H, 7, 2, 1, 1);

        UrgentAlarm_SumCurr_H = new QLineEdit(layoutWidget);
        UrgentAlarm_SumCurr_H->setObjectName(QStringLiteral("UrgentAlarm_SumCurr_H"));
        sizePolicy1.setHeightForWidth(UrgentAlarm_SumCurr_H->sizePolicy().hasHeightForWidth());
        UrgentAlarm_SumCurr_H->setSizePolicy(sizePolicy1);
        UrgentAlarm_SumCurr_H->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(UrgentAlarm_SumCurr_H, 7, 3, 1, 1);

        UrgentAlarm_Temp_L = new QLineEdit(layoutWidget);
        UrgentAlarm_Temp_L->setObjectName(QStringLiteral("UrgentAlarm_Temp_L"));
        sizePolicy1.setHeightForWidth(UrgentAlarm_Temp_L->sizePolicy().hasHeightForWidth());
        UrgentAlarm_Temp_L->setSizePolicy(sizePolicy1);
        UrgentAlarm_Temp_L->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(UrgentAlarm_Temp_L, 4, 3, 1, 1);

        UrgentAlarm_Volt_H = new QLineEdit(layoutWidget);
        UrgentAlarm_Volt_H->setObjectName(QStringLiteral("UrgentAlarm_Volt_H"));
        sizePolicy1.setHeightForWidth(UrgentAlarm_Volt_H->sizePolicy().hasHeightForWidth());
        UrgentAlarm_Volt_H->setSizePolicy(sizePolicy1);
        UrgentAlarm_Volt_H->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(UrgentAlarm_Volt_H, 1, 3, 1, 1);

        Alarm_Temp_L = new QLineEdit(layoutWidget);
        Alarm_Temp_L->setObjectName(QStringLiteral("Alarm_Temp_L"));
        sizePolicy1.setHeightForWidth(Alarm_Temp_L->sizePolicy().hasHeightForWidth());
        Alarm_Temp_L->setSizePolicy(sizePolicy1);
        Alarm_Temp_L->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(Alarm_Temp_L, 4, 2, 1, 1);

        Alarm_Volt_L = new QLineEdit(layoutWidget);
        Alarm_Volt_L->setObjectName(QStringLiteral("Alarm_Volt_L"));
        sizePolicy1.setHeightForWidth(Alarm_Volt_L->sizePolicy().hasHeightForWidth());
        Alarm_Volt_L->setSizePolicy(sizePolicy1);
        Alarm_Volt_L->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(Alarm_Volt_L, 2, 2, 1, 1);

        UrgentAlarm_Volt_L = new QLineEdit(layoutWidget);
        UrgentAlarm_Volt_L->setObjectName(QStringLiteral("UrgentAlarm_Volt_L"));
        sizePolicy1.setHeightForWidth(UrgentAlarm_Volt_L->sizePolicy().hasHeightForWidth());
        UrgentAlarm_Volt_L->setSizePolicy(sizePolicy1);
        UrgentAlarm_Volt_L->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(UrgentAlarm_Volt_L, 2, 3, 1, 1);

        Alarm_SumCurr_L = new QLineEdit(layoutWidget);
        Alarm_SumCurr_L->setObjectName(QStringLiteral("Alarm_SumCurr_L"));
        sizePolicy1.setHeightForWidth(Alarm_SumCurr_L->sizePolicy().hasHeightForWidth());
        Alarm_SumCurr_L->setSizePolicy(sizePolicy1);
        Alarm_SumCurr_L->setMaximumSize(QSize(150, 30));
        Alarm_SumCurr_L->setFocusPolicy(Qt::StrongFocus);

        gridLayout->addWidget(Alarm_SumCurr_L, 8, 2, 1, 1);

        Alarm_Volt_H = new QLineEdit(layoutWidget);
        Alarm_Volt_H->setObjectName(QStringLiteral("Alarm_Volt_H"));
        sizePolicy1.setHeightForWidth(Alarm_Volt_H->sizePolicy().hasHeightForWidth());
        Alarm_Volt_H->setSizePolicy(sizePolicy1);
        Alarm_Volt_H->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(Alarm_Volt_H, 1, 2, 1, 1);

        UrgentAlarm_SumCurr_L = new QLineEdit(layoutWidget);
        UrgentAlarm_SumCurr_L->setObjectName(QStringLiteral("UrgentAlarm_SumCurr_L"));
        sizePolicy1.setHeightForWidth(UrgentAlarm_SumCurr_L->sizePolicy().hasHeightForWidth());
        UrgentAlarm_SumCurr_L->setSizePolicy(sizePolicy1);
        UrgentAlarm_SumCurr_L->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(UrgentAlarm_SumCurr_L, 8, 3, 1, 1);

        QWidget::setTabOrder(Alarm_Volt_H, UrgentAlarm_Volt_H);
        QWidget::setTabOrder(UrgentAlarm_Volt_H, Alarm_Volt_L);
        QWidget::setTabOrder(Alarm_Volt_L, UrgentAlarm_Volt_L);
        QWidget::setTabOrder(UrgentAlarm_Volt_L, Alarm_Temp_H);
        QWidget::setTabOrder(Alarm_Temp_H, UrgentAlarm_Temp_H);
        QWidget::setTabOrder(UrgentAlarm_Temp_H, Alarm_Temp_L);
        QWidget::setTabOrder(Alarm_Temp_L, UrgentAlarm_Temp_L);
        QWidget::setTabOrder(UrgentAlarm_Temp_L, Alarm_SumVolt_H);
        QWidget::setTabOrder(Alarm_SumVolt_H, UrgentAlarm_SumVolt_H);
        QWidget::setTabOrder(UrgentAlarm_SumVolt_H, Alarm_SumVolt_L);
        QWidget::setTabOrder(Alarm_SumVolt_L, UrgentAlarm_SumVolt_L);
        QWidget::setTabOrder(UrgentAlarm_SumVolt_L, Alarm_SumCurr_H);
        QWidget::setTabOrder(Alarm_SumCurr_H, UrgentAlarm_SumCurr_H);
        QWidget::setTabOrder(UrgentAlarm_SumCurr_H, Alarm_SumCurr_L);
        QWidget::setTabOrder(Alarm_SumCurr_L, UrgentAlarm_SumCurr_L);
        QWidget::setTabOrder(UrgentAlarm_SumCurr_L, InsertParameter);

        retranslateUi(Parameter_Range_Set);

        QMetaObject::connectSlotsByName(Parameter_Range_Set);
    } // setupUi

    void retranslateUi(QDialog *Parameter_Range_Set)
    {
        Parameter_Range_Set->setWindowTitle(QApplication::translate("Parameter_Range_Set", "Dialog", nullptr));
        InsertParameter->setText(QApplication::translate("Parameter_Range_Set", "\347\241\256\345\256\232", nullptr));
        label_9->setText(QApplication::translate("Parameter_Range_Set", "\344\270\212\351\231\220", nullptr));
        label_14->setText(QApplication::translate("Parameter_Range_Set", "\351\253\230\347\272\247\346\212\245\350\255\246", nullptr));
        label_7->setText(QApplication::translate("Parameter_Range_Set", "\344\270\212\351\231\220", nullptr));
        label_6->setText(QApplication::translate("Parameter_Range_Set", "\344\270\213\351\231\220", nullptr));
        label->setText(QApplication::translate("Parameter_Range_Set", " \346\200\273\347\224\265\345\216\213", nullptr));
        label_2->setText(QApplication::translate("Parameter_Range_Set", " \345\215\225\344\275\223\347\224\265\345\216\213", nullptr));
        label_13->setText(QApplication::translate("Parameter_Range_Set", "\346\212\245\350\255\246", nullptr));
        label_3->setText(QApplication::translate("Parameter_Range_Set", "\346\270\251\345\272\246", nullptr));
        label_8->setText(QApplication::translate("Parameter_Range_Set", "\344\270\213\351\231\220", nullptr));
        label_5->setText(QApplication::translate("Parameter_Range_Set", "\344\270\212\351\231\220", nullptr));
        label_4->setText(QApplication::translate("Parameter_Range_Set", " \346\200\273\347\224\265\346\265\201", nullptr));
        label_12->setText(QApplication::translate("Parameter_Range_Set", "\344\270\213\351\231\220", nullptr));
        label_11->setText(QApplication::translate("Parameter_Range_Set", "\344\270\212\351\231\220", nullptr));
        label_10->setText(QApplication::translate("Parameter_Range_Set", "\344\270\213\351\231\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Parameter_Range_Set: public Ui_Parameter_Range_Set {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETER_RANGE_H
