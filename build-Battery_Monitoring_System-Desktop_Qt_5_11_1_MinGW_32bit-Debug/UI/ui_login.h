/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *input_User;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *input_Password;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *login_OkBtn;
    QPushButton *login_QuitBtn;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(1200, 700);
        Login->setStyleSheet(QStringLiteral("background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(16, 150, 255, 69), stop:0.423533 rgba(0, 164, 255, 145), stop:0.45 rgba(0, 164, 255, 208), stop:0.477581 rgba(71, 151, 255, 130), stop:0.518717 rgba(71, 197, 255, 130), stop:0.55 rgba(0, 153, 255, 255), stop:0.57754 rgba(0, 186, 255, 130), stop:0.625 rgba(0, 164, 255, 69), stop:1 rgba(255, 255, 0, 69));"));
        verticalLayout_2 = new QVBoxLayout(Login);
        verticalLayout_2->setSpacing(50);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(100, -1, 100, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(50, -1, 50, 150);
        label_4 = new QLabel(Login);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(150, 50));
        label_4->setStyleSheet(QStringLiteral("image: url(:/image/DongFang.jpg);"));

        horizontalLayout->addWidget(label_4);

        label = new QLabel(Login);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(430, 50));
        label->setFrameShape(QFrame::WinPanel);
        label->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(label);

        label_5 = new QLabel(Login);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(150, 50));
        label_5->setStyleSheet(QStringLiteral("image: url(:/image/UESTC.jpg);"));

        horizontalLayout->addWidget(label_5);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(330, -1, 330, -1);
        label_2 = new QLabel(Login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(100, 50));
        label_2->setStyleSheet(QString::fromUtf8("font: 18pt \"\346\245\267\344\275\223\";"));
        label_2->setFrameShape(QFrame::Box);
        label_2->setFrameShadow(QFrame::Raised);

        horizontalLayout_2->addWidget(label_2);

        input_User = new QLineEdit(Login);
        input_User->setObjectName(QStringLiteral("input_User"));
        input_User->setMaximumSize(QSize(150, 50));
        QFont font;
        font.setPointSize(18);
        input_User->setFont(font);
        input_User->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(input_User);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(330, -1, 330, -1);
        label_3 = new QLabel(Login);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(100, 50));
        label_3->setStyleSheet(QString::fromUtf8("font: 18pt \"\346\245\267\344\275\223\";"));
        label_3->setFrameShape(QFrame::Box);
        label_3->setFrameShadow(QFrame::Raised);

        horizontalLayout_3->addWidget(label_3);

        input_Password = new QLineEdit(Login);
        input_Password->setObjectName(QStringLiteral("input_Password"));
        input_Password->setMaximumSize(QSize(150, 50));
        input_Password->setFont(font);
        input_Password->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(input_Password);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(340, -1, 340, -1);
        login_OkBtn = new QPushButton(Login);
        login_OkBtn->setObjectName(QStringLiteral("login_OkBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(login_OkBtn->sizePolicy().hasHeightForWidth());
        login_OkBtn->setSizePolicy(sizePolicy);
        login_OkBtn->setMaximumSize(QSize(100, 50));
        login_OkBtn->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_4->addWidget(login_OkBtn);

        login_QuitBtn = new QPushButton(Login);
        login_QuitBtn->setObjectName(QStringLiteral("login_QuitBtn"));
        sizePolicy.setHeightForWidth(login_QuitBtn->sizePolicy().hasHeightForWidth());
        login_QuitBtn->setSizePolicy(sizePolicy);
        login_QuitBtn->setMaximumSize(QSize(100, 50));
        login_QuitBtn->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_4->addWidget(login_QuitBtn);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalLayout_2->setStretch(0, 2);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 1);

        retranslateUi(Login);

        login_OkBtn->setDefault(true);
        login_QuitBtn->setDefault(true);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Dialog", nullptr));
        label_4->setText(QString());
        label->setText(QApplication::translate("Login", "<html><head/><body><p align=\"center\"><span style=\" font-size:22pt; color:#ffff00;\">\351\222\240\347\241\253\345\202\250\350\203\275\347\224\265\346\261\240\345\271\266\347\275\221\345\234\250\347\272\277\347\233\221\346\216\247\347\263\273\347\273\237</span></p></body></html>", nullptr));
        label_5->setText(QString());
        label_2->setText(QApplication::translate("Login", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; color:#ffff00;\">\347\224\250\346\210\267\345\220\215\357\274\232</span></p></body></html>", nullptr));
        label_3->setText(QApplication::translate("Login", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; color:#ffff00;\">\345\257\206\347\240\201\357\274\232</span></p></body></html>", nullptr));
        login_OkBtn->setText(QApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        login_QuitBtn->setText(QApplication::translate("Login", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
