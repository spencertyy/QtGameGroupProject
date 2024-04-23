#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QPixmap>
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QSqlDatabase>
#include <QCoreApplication>
#include <QPushButton>

#include "loginpage.h"
#include "game1scene.h"
#include "signupdialog.h"
#include "ui_profile.h"

#include "profile.h"
#include "usermanager.h"
#include "levelofgame.h"
int  main(int argc, char **argv)
{
    QApplication app (argc, argv);

    // Create the main window for login/signup
    QMainWindow *loginWindow = new QMainWindow();
    loginWindow->setWindowTitle("Login or Sign Up");

    QPushButton *loginButton = new QPushButton("Login", loginWindow);
    QPushButton *signupButton = new QPushButton("Sign Up", loginWindow);
    QPushButton *playAsGuestButton = new QPushButton("play as guest", loginWindow);


    loginButton->setGeometry(100, 100, 100, 30);
    signupButton->setGeometry(100, 140, 100, 30);
    playAsGuestButton->setGeometry(100, 180, 100, 30);

    // Show the login window
    loginWindow->resize(300, 300);
    loginWindow->show();

    UserManager* userManager = new UserManager();

    // Slots to handle button clicks should close login window and show game view
    QObject::connect(loginButton, &QPushButton::clicked, [&](){
        loginWindow->close();
        loginPage* myLoginPage = new loginPage(userManager);
        myLoginPage->show();
        //view_obj->show();
    });

    //user clicks "sign up", takes them to sign-up dialogue
    QObject::connect(signupButton, &QPushButton::clicked, [&](){
        loginWindow->close();
        signupdialog* signUpDialog = new signupdialog(userManager);
        //KT: Don't think we need this line anymore? signUpDialog->setupDatabase(); // Assuming setupDatabase is safe to call multiple times
        signUpDialog->exec(); // Show the sign-up dialog modally
        //view_obj->show();
    });

    //user plays a guest, user passed in is null
    QObject::connect(playAsGuestButton, &QPushButton::clicked, [&](){
        loginWindow->close();
        //TODO: KT: add game scene constructor that does not need a user
        // game1scene *scene = new game1scene();
        levelOfGame* levelScene = new levelOfGame(nullptr);
        levelScene->show();
        // QGraphicsView* view_obj = new QGraphicsView(levelScene);
        // view_obj->setFixedSize(910,512);
        // view_obj->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
        // view_obj->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
        // view_obj->show();
    });
    return app.exec();
}
