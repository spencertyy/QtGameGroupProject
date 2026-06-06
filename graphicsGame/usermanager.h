#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QDate>
#include <QComboBox>
#include <QMap>
#include <QString>
#include <QVector>
#include "QtCore/qjsonarray.h"
#include <QFile> //create file objects
#include <QJsonObject> //creates Json Objects
#include <qjsondocument>
#include <QCoreApplication> //used to get relative path
#include <QDir>

struct UserRequest {
    QString userName;
    QString password;
    QString firstName;
    QString lastName;
    QDate dob;
    QString gender;
    QPixmap pic;

    // Constructor with default parameter values
    UserRequest(const QString& uname = "", const QString& pwd = "",
                const QString& fname = "", const QString& lname = "",
                const QDate& dob = QDate(), const QString& gender = "",
                const QPixmap& pic = QPixmap())
        : userName(uname), password(pwd), firstName(fname), lastName(lname),
        dob(dob), gender(gender), pic(pic) {}
};

struct UserInfo {
    QString username;
    QString firstName;
    QString lastName;
    QString password;
    QDate dateOfBirth;
    QVector<int> scoreHistory;//track game history of player
    QPixmap profilePicture;
    void* manager;

    // Constructor
    UserInfo(void* manager, const QString& uname = "", const QString& fname = "", const QString& lname = "", const QString& pw = "", const QDate& dob = QDate(), const QVector<int>& scores = QVector<int>(), const QPixmap& picture = QPixmap())
        : username(uname), firstName(fname), lastName(lname), password(pw), dateOfBirth(dob), scoreHistory(scores), profilePicture(picture), manager(manager) {}

    // Constructor from UserRequest pointer
    UserInfo(void* manager, const UserRequest* request)
        : username(request->userName),
        firstName(request->firstName),
        lastName(request->lastName),
        password(request->password),
        dateOfBirth(request->dob),
        scoreHistory(QVector<int>()),
        profilePicture(request->pic), // Initialize with empty score history
        manager(manager) {}

    void addScore(int score);

    //    // Static print method
    static void print(const UserInfo* userInfo);
};

class UserManager : public QObject {
    Q_OBJECT
public:
    QString PATH;
    QMap<QString, UserInfo*> usernameNuserInfo;
    explicit UserManager(QObject *parent = nullptr);
    ~UserManager();
    void print();
    void serialize();
    void deserialize();
    static bool isStrongPassword(QString password);

signals:
    //signal sent by manager to login page
    void userAuthenticated(UserInfo* user);
    void userAuthenticationFailed();
    void userNameTaken(); //singal emited to sign up form
    void userSignedUp(UserInfo* userInfo); //singal emited to sign up form slot, which will display user profile
    void userPasswordNotStrongEnough();//signal emited to sign up form slot which will display user warining

public slots:
    //responds to login page signal, verifies user
    void authenticateUser(QString userName, QString password);
    void signUpUser(UserRequest* userRequest);


};

#endif // USERMANAGER_H
