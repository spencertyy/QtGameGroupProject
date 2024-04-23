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
    QDate dateOfBirth;
    QVector<int> scoreHistory;//track game history of player
    QPixmap profilePicture;

    // Constructor
    UserInfo(const QString& uname = "", const QString& fname = "", const QString& lname = "", const QDate& dob = QDate(), const QVector<int>& scores = QVector<int>(), const QPixmap& picture = QPixmap())
        : username(uname), firstName(fname), lastName(lname), dateOfBirth(dob), scoreHistory(scores), profilePicture(picture) {}

    // Constructor from UserRequest pointer
    UserInfo(const UserRequest* request)
        : username(request->userName),
        firstName(request->firstName),
        lastName(request->lastName),
        dateOfBirth(request->dob),
        scoreHistory(QVector<int>()), // Initialize with empty score history
        profilePicture(request->pic) {}

    //    // Static print method
    static void print(const UserInfo* userInfo);
};

class UserManager : public QObject {
    Q_OBJECT
public:
    explicit UserManager(QObject *parent = nullptr);
    ~UserManager();

    //KT TODO: add users and password to this list  during sign up process
    QMap<QString, QString> usernamesNpasswords;
    QMap<QString, UserInfo*> usernameNuserInfo;

    //KT: TODO: make private later
    static void printMap(QMap <QString, QString> usernameNpasswords);

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
