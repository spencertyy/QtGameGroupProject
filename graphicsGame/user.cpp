#include "user.hpp"

class userData : public QSharedData
{
public:

};

User::User(QObject *parent)
    : QObject{parent}, data(new userData)
{

}

User::User(const User &rhs)
    : data{rhs.data}
{

}

User &User::operator=(const User &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

User::~User()
{

}

void User::signUp() {
    // Implementation for signing up
}

bool User::signIn(const QString& username, const QString& password) {
    // Implementation for signing in
    return false; // Placeholder for now
}

void User::playAsGuest() {
    // Implementation for playing as a guest
}

void User::displayProfile() {
    // Implementation for displaying user profile
}

void User::sendBirthdayGreetings() {
    // Implementation for sending birthday greetings
}

void User::viewGameHistory() {
    // Implementation for viewing game history
}
