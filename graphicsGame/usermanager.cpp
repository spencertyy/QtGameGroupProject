#include "usermanager.h"

UserManager::UserManager(QObject *parent) : QObject(parent) {
     qDebug() << "UserManager object created";



     //add sample data for the sake of testing

    usernamesNpasswords.insert("admin", "password");
    usernamesNpasswords.insert("Bob", "abc");
    usernamesNpasswords.insert("Charlie", "efg");


    QPixmap profilePic("/Users/k80l80d/qtGameGroupProject/graphicsGame/smile.png");

    // Add sample user information data for each user
    UserInfo* adminInfo = new UserInfo("admin", "Admin", "Adminson", QDate(1990, 1, 1), {90, 85, 95},profilePic);
    UserInfo* bobInfo = new UserInfo("Bob", "Bob", "Smith", QDate(1985, 5, 15), {70, 75, 80}, profilePic);
    UserInfo* charlieInfo = new UserInfo("Charlie", "Charlie", "Brown", QDate(1978, 9, 30), {80, 85, 90},profilePic);

    usernameNuserInfo.insert("admin", adminInfo);
    usernameNuserInfo.insert("Bob", bobInfo);
    usernameNuserInfo.insert("Charlie", charlieInfo);
}


UserManager::~UserManager() {
    qDebug() << "UserManager object destroyed";
}

//handles user authentication on login page
void UserManager::authenticateUser(QString userName, QString password) {
    // Perform login logic here
    qDebug() << "user manager: Attempting to log in with username:" << userName << "and password:" << password;
    // Dummy logic for demonstration

    //username and password matches
    if(usernamesNpasswords.contains(userName) && password == usernamesNpasswords.value(userName)){
       qDebug() << "usermanager: Login successful!";

       //snatch user data for specific id from usersInfoMap
       UserInfo* userInfo = usernameNuserInfo.value(userName);


        emit userAuthenticated(userInfo);
    }
    //username or password incorrect! Send signal to sign in form
    else{
        emit userAuthenticationFailed();
    }
}

//helper method
void UserManager::printMap(QMap <QString, QString> usernameNpasswords){
    // Print the keys and values using a range-based for loop
    qDebug() << "Keys and values using range-based for loop:";
    for (const auto &key : usernameNpasswords.keys()) {
        qDebug() << "Key:" << key << ", Value:" << usernameNpasswords.value(key);
    }
}

//handles user sign up requests, upon signal sent from signup form
void UserManager::signUpUser(UserRequest* userRequest) {
    qDebug() << "UserManager: signal recieved! User wants to sign up ";
    qDebug() << "username: " << userRequest->userName;
    qDebug() << "password:" << userRequest->password;


    QString requestedUserName =  userRequest->userName;

    //TODO: KT after done testing, add check that no values inside userRequest are null?

    //username is taken, send signal to signup page
    if(usernamesNpasswords.contains(requestedUserName)){
        //emit signal
        emit userNameTaken();
        qDebug() << "UserManager: user name is taken signal sent";

    }
    //user signed up
    else{
        //add new users to "database"
        usernamesNpasswords.insert(requestedUserName, userRequest->password);
        qDebug() << "UserManager: new user: " << requestedUserName;

        //transfer only data needed to render profile,
        UserInfo* userInfo = new UserInfo(userRequest);
        UserInfo::print(userInfo);
        //signal sent to login page to render profile page
        emit userSignedUp(userInfo);
    }
}
 void UserInfo::print(const UserInfo* userInfo) {
    qDebug() << "Username:" << userInfo->username;
    qDebug() << "First Name:" << userInfo->firstName;
    qDebug() << "Last Name:" << userInfo->lastName;
    qDebug() << "Date of Birth:" << userInfo->dateOfBirth.toString("yyyy-MM-dd");
    qDebug() << "Score History:";
    for (int score : userInfo->scoreHistory) {
        qDebug() << score;
    }
    // Additional information about profile picture if needed
    //qDebug() << "Profile Picture:" << userInfo->profilePicture.isNull() ? "Not set" : "Set";
}


