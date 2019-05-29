#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_login_QuitBtn_clicked();

    void on_login_OkBtn_clicked();

    void receive_Login_Show();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
