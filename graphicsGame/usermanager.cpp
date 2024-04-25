#include "usermanager.h"

//User data is stored on disk
UserManager::UserManager(QObject *parent) : QObject(parent) {
     qDebug() << "UserManager object created";
    // Get the current working directory
    PATH = QDir::currentPath();
    qDebug() << "UserManager Path to user data saved on disk: " + PATH;
    deserialize();
}


UserManager::~UserManager() {
    qDebug() << "UserManager object destroyed";
}

//handles user authentication on login page (slot connected to signal from login form)
void UserManager::authenticateUser(QString userName, QString password) {
    // Perform login logic here
    qDebug() << "user manager: Attempting to log in with username:" << userName << "and password:" << password;
    // Dummy logic for demonstration
    print();
    //username and password matches
    if(usernameNuserInfo.contains(userName) && password == usernameNuserInfo.value(userName)->password){
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

//handles user sign up requests, upon signal sent from signup form (slot connected to signal from signup page)
void UserManager::signUpUser(UserRequest* userRequest) {
    qDebug() << "UserManager: signal recieved! User wants to sign up ";
    qDebug() << "username: " << userRequest->userName;
    qDebug() << "password:" << userRequest->password;



    QString requestedUserName =  userRequest->userName;

    //check password is 8 chars, with at least on capital letter and one number
    if(!isStrongPassword(userRequest->password)){
        //if user password is not strong enough, this signal emited to signup form slot that will display warning to user
        emit userPasswordNotStrongEnough();
    }
    //username is taken, send signal to signup page
    if(usernameNuserInfo.contains(requestedUserName)){
        //emit signal
        emit userNameTaken();
        qDebug() << "UserManager: user name is taken signal sent";

    }

    //only sign up user's purposed password is strong and their username is unique
    if(isStrongPassword(userRequest->password) && !usernameNuserInfo.contains(requestedUserName)){
        //add new users to "database"
        qDebug() << "UserManager: new user: " << requestedUserName;

        //transfer only data needed to render profile,
        UserInfo* userInfo = new UserInfo(this, userRequest);
        UserInfo::print(userInfo);
        usernameNuserInfo.insert(requestedUserName, userInfo);
        serialize();
        //signal sent to login page to render profile page
        emit userSignedUp(userInfo);
    }
}


// static method to check if password is at least 8 charachters and has at least one upper case letter and one number
bool UserManager::isStrongPassword(QString password) {
    bool hasUpperCase = false;
    bool hasNumber = false;

    // Check the length of the password
    if (password.length() < 8) {
        return false; // Password is not strong if it's less than 8 characters
    }

    // Check each character of the password
    for (QChar ch : password) {
        if (ch.isUpper()) {
            hasUpperCase = true;
        } else if (ch.isDigit()) {
            hasNumber = true;
        }
    }

    // Return true if the password meets all criteria
    return hasUpperCase && hasNumber;
}

void UserInfo::addScore(int score) {
    scoreHistory.append(score);
    UserManager* userManagr = (UserManager*)manager;
    userManagr->serialize();
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

 void UserManager::print() {
     qDebug() << "printing user manager data";
     for (UserInfo* user : usernameNuserInfo) {
         UserInfo::print(user);
    }
 }
//takes all users and seralizes them and puts them in a file on disk
void UserManager::serialize() {
    QJsonObject userMap = QJsonObject();

    //seralize each user in the master list of users
    for (UserInfo* user : usernameNuserInfo) {
        QJsonObject userInfoJson;
        userInfoJson["username"] = user->username;
        userInfoJson["firstname"] = user->firstName;
        userInfoJson["lastname"] = user->lastName;
        userInfoJson["password"] = user->password;
        userInfoJson["dob"] = user->dateOfBirth.toString();

        //save profile picture
        bool picExists = !user->profilePicture.isNull();
        userInfoJson["picture"] = picExists;
        if (picExists) {
            QFile picFile(QString(PATH) + QString("/") + QString(user->username) + QString(".png"));
            if (!picFile.open(QFile::WriteOnly | QIODevice::Text)) {
                if (!picFile.open(QFile::WriteOnly | QIODevice::Text |  QIODevice::Truncate)) {
                    qDebug() << "Failed to open or create file for writing.";
                    continue;
                }
            }
            user->profilePicture.save(&picFile, "PNG");
            qDebug() << "wrote profile picture to file";
        }
        //save scores history info
        QJsonArray scoresJson = QJsonArray();
        for (int score : user->scoreHistory) {
            scoresJson.append(score);
        }
        userInfoJson["scores"] = scoresJson;
        userMap[user->username] = userInfoJson; //<key = username> <value = userInfoJson>
    }

    //convert that user mapping into a JSON document
    QJsonDocument jsonDoc = QJsonDocument(userMap);
    //Open a file called userMapping.json
    QFile file(QString(PATH) + QString("/userMapping.json"));

    // if (!file.open(QFile::WriteOnly | QIODevice::Text)) {
    //     if (!file.open(QFile::WriteOnly | QIODevice::Text | QIODevice::NewOnly)) {
    //         qDebug() << "Failed to open or create file for writing.";
    //     }
    //     return;
    // }

    if (!file.open(QFile::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        qDebug() << "Failed to open or create file for writing.";
        return;
    }

    file.write(jsonDoc.toJson());
    file.close();
    qDebug() << "User data written to file";
}

void UserManager::deserialize() {
    QFile file(QString(PATH) + QString("/userMapping.json"));

    //no users have signed up yet, so don't try to read in user data file
    if(!QFile::exists(PATH + QString("/userMapping.json"))){
        qDebug() << "No users data yet. Create a new file to store data once user sign up and close application.";
        return;
    }


    //reading in user datat from the file
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for reading.";
        return;
    }

    // Read the entire file content, should contain all user data
    QByteArray fileData = file.readAll();
    file.close();

    // Parse the JSON data into a QJsonDocument
    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData, &parseError);

    //error check
    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "Failed to parse JSON:" << parseError.errorString();
    }

    // If the JSON document is not an object create a new one
    if (!jsonDoc.isObject()) {
        qDebug() << "JSON document is not an object.";
        jsonDoc = QJsonDocument(QJsonObject());
    }

    // Get that jsonDocument and turn it into a object
    QJsonObject jsonObj = jsonDoc.object();

    //clear any previous data stored in the process list of users
    usernameNuserInfo.clear();

    //the key should be the username and the value should be the user data
    for (QString key : jsonObj.keys()) {
        QJsonValue userJson = jsonObj.value(key);
        if (!userJson.isObject()) {
            qDebug() << "JSON document is improperly formmatted";
            continue;
        }
        //check that the user data has all appropriate fields
        QJsonObject userJsonObj = userJson.toObject();
        if (!userJsonObj.keys().contains("username") ||
            !userJsonObj.keys().contains("firstname") ||
            !userJsonObj.keys().contains("lastname") ||
            !userJsonObj.keys().contains("password") ||
            !userJsonObj.keys().contains("dob") ||
            !userJsonObj.keys().contains("scores") ||
            !userJsonObj.keys().contains("picture")) {
            qDebug() << "JSON user info missing fields";
            continue;
        }
        //check that those fields are the proper types
        QJsonValue usernameJson = userJsonObj.value("username");
        QJsonValue firstNameJson = userJsonObj.value("firstname");
        QJsonValue lastNameJson = userJsonObj.value("lastname");
        QJsonValue passwordJson = userJsonObj.value("password");
        QJsonValue dobJson = userJsonObj.value("dob");
        QJsonValue scoresJson = userJsonObj.value("scores");
        QJsonValue pictureJson = userJsonObj.value("picture");
        if (!usernameJson.isString() ||
            !firstNameJson.isString() ||
            !lastNameJson.isString() ||
            !passwordJson.isString() ||
            !dobJson.isString() ||
            !scoresJson.isArray() ||
            !pictureJson.isBool()) {
            qDebug() << "JSON user info fields invalid";
            continue;
        }
        //after all checks, load user JSON objects into process repsentation of users
        QString username = usernameJson.toString();
        QString firstName = firstNameJson.toString();
        QString lastName = lastNameJson.toString();
        QString password = passwordJson.toString();
        QDate dob = QDate::fromString(dobJson.toString());
        bool picExists = pictureJson.toBool();
        QPixmap picture;
        //load in picture
        if (picExists) {
            picture = QPixmap(QString(PATH) + QString("/") + username + QString(".png"));
        } else {
            picture = QPixmap();
        }
        //load in score history
        QJsonArray scoresJsonArr = scoresJson.toArray();
        QVector<int> scores = QVector<int>();
        for (QJsonValue scoreJson : scoresJsonArr) {
            if (!scoreJson.isDouble()) {
                qDebug() << "JSON score improperly formatted";
                continue;
            }
            int score = scoreJson.toInt();
            scores.append(score);
        }
        //create a process reprsentation of the user and add them to the list of all users
        UserInfo* userInfo = new UserInfo(this, username, firstName, lastName, password, dob, scores, picture);
        usernameNuserInfo.insert(username, userInfo);
    }
    qDebug() << "user data read from file";
}

