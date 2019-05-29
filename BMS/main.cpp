#include "main_interface.h"
#include <QApplication>
#include "login.h"
#include <QtGui>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Main_Interface w;
    w.setWindowTitle(QObject::tr("钠硫电池并网在线监控系统"));
    Login login;
    QObject::connect(&w,SIGNAL(login_Show()),&login,SLOT(receive_Login_Show()));
    login.setWindowTitle(QObject::tr("钠硫电池并网在线监控系统"));
    login.setWindowFlag(Qt::WindowMaximizeButtonHint);
    login.setWindowFlag(Qt::WindowMinimizeButtonHint);
//    if(login.exec()==QDialog::Accepted)
//    {
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowMaximizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    w.setWindowFlags(flags);
    w.show();
    emit w.shown();
    return a.exec();
//    }

//    else return 0;
}
