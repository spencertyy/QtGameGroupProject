#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include <QString>

#include "usermanager.h"

namespace Ui {
class loginPage;
}

class loginPage : public QWidget
{
    Q_OBJECT

    //Methods
    void onLoginButtonClicked();
public:
    explicit loginPage(UserManager *userManager, QWidget *parent = nullptr);
    ~loginPage();

signals:
    //KT: login page should send this signal to the user manager
    void loginAttempt(QString userName, QString password);

private:
    Ui::loginPage *ui;
    //adding a textbox to display if login fails
private slots:
    void displayUserProfile(UserInfo* userInfo);
    void loginFailed();
};

#endif // LOGINPAGE_H
