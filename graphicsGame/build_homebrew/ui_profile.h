/********************************************************************************
** Form generated from reading UI file 'profile.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILE_H
#define UI_PROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_profile
{
public:
    QGraphicsView *picView;
    QPushButton *scoreHistoryBtn;
    QPushButton *gameStartBtn;
    QLabel *welcomeLabel;
    QFrame *line;
    QLabel *userNameLabel;
    QLabel *firstNameLabel;
    QLabel *lastNameLabel;
    QLineEdit *userNameEdit;
    QLineEdit *firstNameEdit;
    QLineEdit *lastNameEdit;
    QLabel *currentDate;
    QLineEdit *dobLineEdit;
    QDateTimeEdit *dateTimeEdit;
    QLabel *TodayLabel;

    void setupUi(QWidget *profile)
    {
        if (profile->objectName().isEmpty())
            profile->setObjectName("profile");
        profile->resize(400, 300);
        picView = new QGraphicsView(profile);
        picView->setObjectName("picView");
        picView->setGeometry(QRect(20, 70, 111, 81));
        scoreHistoryBtn = new QPushButton(profile);
        scoreHistoryBtn->setObjectName("scoreHistoryBtn");
        scoreHistoryBtn->setGeometry(QRect(30, 250, 100, 32));
        gameStartBtn = new QPushButton(profile);
        gameStartBtn->setObjectName("gameStartBtn");
        gameStartBtn->setGeometry(QRect(250, 250, 100, 32));
        welcomeLabel = new QLabel(profile);
        welcomeLabel->setObjectName("welcomeLabel");
        welcomeLabel->setGeometry(QRect(100, 10, 211, 21));
        line = new QFrame(profile);
        line->setObjectName("line");
        line->setGeometry(QRect(87, 30, 231, 20));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        userNameLabel = new QLabel(profile);
        userNameLabel->setObjectName("userNameLabel");
        userNameLabel->setGeometry(QRect(150, 70, 71, 16));
        firstNameLabel = new QLabel(profile);
        firstNameLabel->setObjectName("firstNameLabel");
        firstNameLabel->setGeometry(QRect(150, 100, 71, 16));
        lastNameLabel = new QLabel(profile);
        lastNameLabel->setObjectName("lastNameLabel");
        lastNameLabel->setGeometry(QRect(150, 130, 71, 16));
        userNameEdit = new QLineEdit(profile);
        userNameEdit->setObjectName("userNameEdit");
        userNameEdit->setGeometry(QRect(230, 70, 113, 21));
        firstNameEdit = new QLineEdit(profile);
        firstNameEdit->setObjectName("firstNameEdit");
        firstNameEdit->setGeometry(QRect(230, 100, 113, 21));
        lastNameEdit = new QLineEdit(profile);
        lastNameEdit->setObjectName("lastNameEdit");
        lastNameEdit->setGeometry(QRect(230, 130, 113, 21));
        currentDate = new QLabel(profile);
        currentDate->setObjectName("currentDate");
        currentDate->setGeometry(QRect(30, 180, 91, 16));
        dobLineEdit = new QLineEdit(profile);
        dobLineEdit->setObjectName("dobLineEdit");
        dobLineEdit->setGeometry(QRect(110, 180, 121, 21));
        dateTimeEdit = new QDateTimeEdit(profile);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setGeometry(QRect(80, 210, 151, 22));
        TodayLabel = new QLabel(profile);
        TodayLabel->setObjectName("TodayLabel");
        TodayLabel->setGeometry(QRect(30, 210, 91, 16));

        retranslateUi(profile);

        QMetaObject::connectSlotsByName(profile);
    } // setupUi

    void retranslateUi(QWidget *profile)
    {
        profile->setWindowTitle(QCoreApplication::translate("profile", "Form", nullptr));
        scoreHistoryBtn->setText(QCoreApplication::translate("profile", "Score History", nullptr));
        gameStartBtn->setText(QCoreApplication::translate("profile", "Start Game", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("profile", "Welcome to Water Droplet Game\360\237\222\227", nullptr));
        userNameLabel->setText(QCoreApplication::translate("profile", "UserName:", nullptr));
        firstNameLabel->setText(QCoreApplication::translate("profile", "FristName:", nullptr));
        lastNameLabel->setText(QCoreApplication::translate("profile", "LastName:", nullptr));
        currentDate->setText(QCoreApplication::translate("profile", "date of birth:", nullptr));
        TodayLabel->setText(QCoreApplication::translate("profile", "Today:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class profile: public Ui_profile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILE_H
