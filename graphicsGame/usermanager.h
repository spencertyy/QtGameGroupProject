#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <QObject>
#include <QWidget>
#include <QDebug>

struct UserInfo {
    QString firstName;
    QString lastName;
};

class UserManager : public QObject {
    Q_OBJECT
public:
    explicit UserManager(QObject *parent = nullptr);
    ~UserManager();
//KT: added slot; authenticate user to be called by loginpage wiget upon sign-in button click
signals:
    //signal sent by manager to login page
    void userAuthenticated(UserInfo* user);
    void userAuthenticationFailed();

public slots:
    //responds to login page signal, verifies user
    void authenticateUser(QString userName, QString password);
};

#endif // USERMANAGER_H
