#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->input_Password->setEchoMode(QLineEdit::Password);

}

Login::~Login()
{
    delete ui;
}

void Login::on_login_QuitBtn_clicked()
{
    this->close();
}

void Login::on_login_OkBtn_clicked()
{
    if(ui->input_User->text()==tr("UESTC")&&ui->input_Password->text()==tr("123"))
     {
        accept();
    }
    else
    {
        QMessageBox::warning(this,tr("warning"),tr("user name or passsword error !"),QMessageBox::Yes);
        ui->input_User->clear();
        ui->input_Password->clear();
        ui->input_User->setFocus();
    }
}

void Login::receive_Login_Show()
{
    this->show();
    ui->input_User->clear();
    ui->input_Password->clear();
    ui->input_User->setFocus();
}
