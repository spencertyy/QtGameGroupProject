#include "loginpage.h"
#include "ui_loginpage.h"
#include "profile.h"

loginPage::loginPage(UserManager *userManager, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::loginPage)
{
    ui->setupUi(this);

    //requesta to authenticate username and password, upon button press
    connect(ui->pushButton,&QPushButton::clicked, this, &loginPage::onLoginButtonClicked);
    connect(this, &loginPage::loginAttempt, userManager, &UserManager::authenticateUser);

    //handles sucesfull authntication, displays user profile
    connect(userManager, &UserManager::userAuthenticated, this, &loginPage::displayUserProfile);

    //handles authentication failures, displays failure message
    connect(userManager, &UserManager::userAuthenticationFailed, this, &loginPage::loginFailed);
}

loginPage::~loginPage()
{
    delete ui;
}
void loginPage::onLoginButtonClicked(){
    qDebug() << "loginPage: user clicked loginButon";


    //KT: pull data out of form
    QString userName = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    //KT: emit signal for userHandler to hear
    emit loginAttempt(userName, password);


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
void loginPage::displayUserProfile(UserInfo* userInfo){
    qDebug() << "loginPage: User profile displayed";
    qDebug() << "first: " << userInfo->firstName;
    qDebug() << "last: " << userInfo->lastName;
}

void loginPage::loginFailed(){
      qDebug() << "loginPage: user login Failed!!";
}


