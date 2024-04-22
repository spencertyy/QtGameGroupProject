#include "usermanager.h"



UserManager::UserManager(QObject *parent) : QObject(parent) {
     qDebug() << "UserManager object created";
}
UserManager::~UserManager() {
    qDebug() << "UserManager object destroyed";
}
void UserManager::authenticateUser(QString userName, QString password) {
    // Perform login logic here
    qDebug() << "user manager: Attempting to log in with username:" << userName << "and password:" << password;
    // Dummy logic for demonstration
    if (userName == "admin" && password == "password") {
        qDebug() << "usermanager: Login successful!";

        UserInfo* user = new UserInfo();
        user->firstName = "John";
        user->lastName = "Doe";
        emit userAuthenticated(user);

    } else {
        qDebug() << "usermanager: Login failed. Invalid credentials.";
        emit userAuthenticationFailed();
    }
}
