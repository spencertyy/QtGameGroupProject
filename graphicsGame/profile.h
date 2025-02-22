#ifndef PROFILE_H
#define PROFILE_H

#include <QWidget>
#include <QPushButton>
#include "game1scene.h"
#include "usermanager.h"
#include <QLabel>
#include <QDateEdit>
#include <QDateTimeEdit>
#include <QDialog>
#include <QLineEdit>
#include <QBoxLayout>
#include "usermanager.h"
namespace Ui {
class profile;
}

class profile : public QWidget
{
    Q_OBJECT

public:
    QDialog *birthdayDialog;
    QLabel *birthdayImageLabel;
    QDateEdit *dobDateEdit;
    UserInfo* userInfo;

    //Scene for picture
    QGraphicsScene* scene;

    explicit profile(UserInfo* user,QWidget *parent = nullptr);
    ~profile();

    Ui::profile *ui;
    QPushButton *gameStartBtn; // Ensure this is properly connected to the UI
    void displayBirthdayMessage();
    void displayProfilePicture(const QPixmap& profilePic);

signals:
    //signal emited if its the users birthday today


public slots:
    void onGameStartBtnClicked();
};

#endif // PROFILE_H
