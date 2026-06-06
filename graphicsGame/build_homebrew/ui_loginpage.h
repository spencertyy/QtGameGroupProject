/********************************************************************************
** Form generated from reading UI file 'loginpage.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPAGE_H
#define UI_LOGINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginPage
{
public:
    QPushButton *pushButton;
    QLineEdit *userNameEdit;
    QLineEdit *passwordEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *loginSatus;

    void setupUi(QWidget *loginPage)
    {
        if (loginPage->objectName().isEmpty())
            loginPage->setObjectName("loginPage");
        loginPage->resize(358, 394);
        pushButton = new QPushButton(loginPage);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(100, 290, 131, 31));
        userNameEdit = new QLineEdit(loginPage);
        userNameEdit->setObjectName("userNameEdit");
        userNameEdit->setGeometry(QRect(140, 140, 131, 31));
        passwordEdit = new QLineEdit(loginPage);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setGeometry(QRect(140, 190, 131, 31));
        label = new QLabel(loginPage);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 40, 41, 31));
        label_2 = new QLabel(loginPage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 130, 91, 41));
        label_3 = new QLabel(loginPage);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 190, 91, 41));
        loginSatus = new QLabel(loginPage);
        loginSatus->setObjectName("loginSatus");
        loginSatus->setGeometry(QRect(60, 250, 261, 16));

        retranslateUi(loginPage);

        QMetaObject::connectSlotsByName(loginPage);
    } // setupUi

    void retranslateUi(QWidget *loginPage)
    {
        loginPage->setWindowTitle(QCoreApplication::translate("loginPage", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("loginPage", "Login", nullptr));
        userNameEdit->setText(QString());
        passwordEdit->setText(QString());
        label->setText(QCoreApplication::translate("loginPage", "LOGIN ", nullptr));
        label_2->setText(QCoreApplication::translate("loginPage", "User name:", nullptr));
        label_3->setText(QCoreApplication::translate("loginPage", "Password:", nullptr));
        loginSatus->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class loginPage: public Ui_loginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
