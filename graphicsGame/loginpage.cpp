#include "loginpage.h"
#include "ui_loginpage.h"
#include "profile.h"

loginPage::loginPage(UserManager *userManager, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::loginPage)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked, this, &loginPage::onLoginButtonClicked);
    connect(this, &loginPage::loginAttempt, userManager, &UserManager::authenticateUser);
    //KT: when login wiget it created, associate it with the usermanager process the data

}

loginPage::~loginPage()
{
    delete ui;
}
void loginPage::onLoginButtonClicked(){
    qDebug() << "user clicked loginButon";


    //KT: pull data out of form
    QString userName = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    //KT: emit signal for userHandler to hear
    emit loginAttempt(userName, password);

    qDebug() << "Signal was emitted";


    // profile* profilePage = new profile();
    // loginPage* myLoginPage = new loginPage();
    // profilePage->show();
    // myLoginPage->close();

    //TODO need to write the code for check if the user name and the passwork is correct

    // if( (true)) { // Replace true with actual condition check
    //     profilePage->show(); // Show the profile page
    //     profilePage->close(); // Close the login window
    // } else {
    //     QMessageBox::warning(profilePage, "Login Failed", "The username or password is incorrect.");
    // }
}


