#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QDate>
#include <QComboBox>
#include <QMap>
#include <QString>

struct UserRequest {
    QString userName;
    QString password;

    QString firstName;
    QString lastName;
    QDate dob;
    // QComboBox *gender;
    // QPixmap pic;

};



struct UserInfo {
    QString firstName;
    QString lastName;
    //TODO: add the rest of the userInfo feilds
    QDate dateOfBirth;
    // QPixmap profilePicture;
    // QString username;
    //TODO: add game history records
};

class UserManager : public QObject {
    Q_OBJECT
public:
    explicit UserManager(QObject *parent = nullptr);
    ~UserManager();
    QMap<QString, QString> users;


//KT: added slot; authenticate user to be called by loginpage wiget upon sign-in button click
signals:
    //signal sent by manager to login page
    void userAuthenticated(UserInfo* user);
    void userAuthenticationFailed();
    void userNameTaken();
    void userSignedUp(UserInfo* userInfo);

public slots:
    //responds to login page signal, verifies user
    void authenticateUser(QString userName, QString password);
    void signUpUser(UserRequest* userRequest);

};

#endif // USERMANAGER_H
