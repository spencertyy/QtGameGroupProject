#include "usermanager.h"

UserManager::UserManager(QObject *parent) : QObject(parent) {
     qDebug() << "UserManager object created";
}
UserManager::~UserManager() {
    qDebug() << "UserManager object destroyed";
}
void UserManager::authenticateUser(QString userName, QString password) {
    // Perform login logic here
    qDebug() << "Attempting to log in with username:" << userName << "and password:" << password;
    // Dummy logic for demonstration
    if (userName == "admin" && password == "password") {
        qDebug() << "Login successful!";
    } else {
        qDebug() << "Login failed. Invalid credentials.";
    }
}
