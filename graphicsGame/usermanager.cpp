#include "usermanager.h"

UserManager::UserManager(QObject *parent) : QObject(parent) {
     qDebug() << "UserManager object created";

    // Insert sample user data
    users.insert("Alice", "Alice userRequestInfo");
    users.insert("Bob", "Bob userRequestInfo");
    users.insert("Charlie", "Charlie userRequestInfo");

     //add some sample users to the list of users
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
        QDate today(2023, 4, 21);
        user->dateOfBirth = today;

        emit userAuthenticated(user);

    } else {
        qDebug() << "usermanager: Login failed. Invalid credentials.";
        emit userAuthenticationFailed();
    }
}


void UserManager::signUpUser(UserRequest* userRequest) {
    qDebug() << "UserManager: signal recieved! User wants to sign up ";
    qDebug() << "username: " << userRequest->userName;
    qDebug() << "password:" << userRequest->password;

    QString requestedUserName =  userRequest->userName;

    //TODO: KT after done testing, add check that no values inside userRequest are null

    //username is taken,
    if(users.contains(requestedUserName)){
        //emit signal
        emit userNameTaken();
        qDebug() << "UserManager: user name is taken signal sent";

    }
    else{
        //user added to database
        users.insert(requestedUserName, "User request Info");
        qDebug() << "UserManager: user signed up ";

        //transfer only data needed to render profile;

        UserInfo* userInfo = new UserInfo();
        userInfo->firstName = userRequest->firstName;
        userInfo->lastName = userRequest->lastName;
        emit userSignedUp(userInfo);
    }
}


