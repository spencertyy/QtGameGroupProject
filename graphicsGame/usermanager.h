#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <QObject>
#include <QWidget>
#include <QDebug>

class UserManager : public QObject {
    Q_OBJECT
public:
    explicit UserManager(QObject *parent = nullptr);
    ~UserManager();
//KT: added slot; authenticate user to be called by loginpage wiget upon sign-in button click
public slots:
    void authenticateUser(QString userName, QString password);
};

#endif // USERMANAGER_H
