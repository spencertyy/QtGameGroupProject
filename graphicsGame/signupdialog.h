#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QDateEdit>
#include <QComboBox>
#include <QPushButton>
#include <QValidator>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QLabel>
#include <QFileDialog>
#include <QPixmap>
#include <QString>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QMessageBox>
//#include "profile.h"
#include <qdebug.h>
#include <usermanager.h>
class signupdialog : public QDialog {
    Q_OBJECT

public:

    signupdialog(UserManager* userManager, QWidget *parent = nullptr);

    //to package user data
    UserRequest* userRequest;
    UserManager* userManager;

    QLineEdit *firstNameLineEdit;
    QLineEdit *lastNameLineEdit;
    QDateEdit *dobDateEdit;
    QComboBox *genderComboBox;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *submitButton;
    QPushButton *cancelButton;
    QLabel* profilePictureLabel;
    QPushButton* uploadButton;
    //QValidator *passwordValidator;
    QRegularExpressionValidator *passwordValidator;
    //profile* profilePage;


    void setupUI();
    void connectSignals();
    void onUploadButtonClicked();
    void checkPasswordValidity();
    void onSubmitButtonClicked();


signals:
    void signUp(UserRequest* userRequest);

private slots:
    void displayUserNameTakenWarning();
    void showProfilePage(UserInfo* userInfo);
};


#endif // SIGNUPDIALOG_H
