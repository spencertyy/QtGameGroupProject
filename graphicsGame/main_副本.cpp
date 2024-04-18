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


#include "game1scene.h"
#include "signupdialog.h"


int  main(int argc, char **argv)
{
    QApplication app (argc, argv);

    // Create the main window for login/signup
    QMainWindow *loginWindow = new QMainWindow();
    loginWindow->setWindowTitle("Login or Sign Up");

    QPushButton *loginButton = new QPushButton("Login", loginWindow);
    QPushButton *signupButton = new QPushButton("Sign Up", loginWindow);
    loginButton->setGeometry(100, 100, 100, 30);
    signupButton->setGeometry(100, 140, 100, 30);

    // Show the login window
    loginWindow->resize(300, 300);
    loginWindow->show();

    SignUpDialog signUpDialog;
    signUpDialog.setupDatabase();
    //signUpDialog.exec();

    game1scene *scene = new game1scene();
    QGraphicsView* view_obj = new QGraphicsView(scene);

    view_obj->setFixedSize(910,512);

    view_obj->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view_obj->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    // view_obj->show();

    // Slots to handle button clicks should close login window and show game view
    QObject::connect(loginButton, &QPushButton::clicked, [&](){
        loginWindow->close();
        view_obj->show();
    });
    QObject::connect(signupButton, &QPushButton::clicked, [&](){
        signUpDialog.setupDatabase(); // Assuming setupDatabase is safe to call multiple times
        signUpDialog.exec(); // Show the sign-up dialog modally
        //view_obj->show();
    });



    return app.exec();
}
