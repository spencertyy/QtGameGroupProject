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

    //pull data out of form
    QString userName = ui->userNameEdit->text();
    QString password = ui->passwordEdit->text();

    //emit signal for userHandler to authenticate username and password
    emit loginAttempt(userName, password);


}
void loginPage::displayUserProfile(UserInfo* userInfo){
    qDebug() << "loginPage: User profile displayed";
    qDebug() << "first: " << userInfo->firstName;
    qDebug() << "last: " << userInfo->lastName;


    //generates a profile out of the user info
    qDebug() << "Login Page: opening user profile";
    profile* profilePage = new profile(userInfo);
    profilePage->show();// Show the profile page
    this->close(); // Close the login window

}

void loginPage::loginFailed(){
    qDebug() << "loginPage: user login Failed!!";
    ui->loginSatus->setText("username or password was incorrect!!!");
    //QMessageBox::warning(profilePage, "Login Failed", "The username or password is incorrect.")
}


