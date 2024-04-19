#include "loginpage.h"
#include "ui_loginpage.h"
#include "profile.h"


loginPage::loginPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::loginPage)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked, this, &loginPage::onLoginButtonClicked);

}

loginPage::~loginPage()
{
    delete ui;
}
void loginPage::onLoginButtonClicked(){
    profile* profilePage = new profile();
    loginPage* myLoginPage = new loginPage();

    profilePage->show();
    myLoginPage->close();
    // if( (true)) { // Replace true with actual condition check
    //     profilePage->show(); // Show the profile page
    //     profilePage->close(); // Close the login window
    // } else {
    //     QMessageBox::warning(profilePage, "Login Failed", "The username or password is incorrect.");
    // }
}


