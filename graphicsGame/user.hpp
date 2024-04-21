#ifndef USER_HPP
#define USER_HPP

#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class userData;

class User : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    //constructor, destructor, equals
    explicit User(QObject *parent = nullptr);
    User(const User &);
    User &operator=(const User &);
    ~User();

    User(QString firstName, QString lastName,QDate dateOfBirth, )
    //Member Method
    void signUp();
    bool signIn(const QString& username, const QString& password);
    void playAsGuest();
    void displayProfile();
    void sendBirthdayGreetings();
    void viewGameHistory();

signals:

private:
    QString firstName;
    QString lastName;
    QDate dateOfBirth;
    QString gender;
    QPixmap profilePicture;
    QString username;
    QString password;

    QSharedDataPointer<userData> data;
};

#endif // USER_HPP

// -----------------------------------
//     |            User                |
//     -----------------------------------
//     | - firstName: string            |
//     | - lastName: string             |
//     | - dateOfBirth: Date            |
//     | - gender: string               |
//     | - profilePicture: Image        |
//     | - username: string             |
//     | - password: string             |
//     -----------------------------------
//     | + signUp(): void               |
//     | + signIn(username: string,password: string): boolean |
//     | + playAsGuest(): void          |
//     | + displayProfile(): void       |
//     | + sendBirthdayGreetings(): void|
//     | + viewGameHistory(): void     |
//     | - encryptPassword(password: string): string            |
//     -----------------------------------
