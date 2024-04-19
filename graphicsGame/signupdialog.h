#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QDateEdit>
#include <QComboBox>
#include <QPushButton>
#include <QValidator>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QLabel>
#include <QFileDialog>
#include <QPixmap>
#include <QString>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QMessageBox>



class SignUpDialog : public QDialog {
public:
    SignUpDialog(QWidget *parent = nullptr);

    QLineEdit *firstNameLineEdit;
    QLineEdit *lastNameLineEdit;
    QDateEdit *dobDateEdit;
    QComboBox *genderComboBox;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *submitButton;
    QPushButton *cancelButton;
    QLabel* profilePictureLabel;
    QPushButton* uploadButton;
    QValidator *passwordValidator;


    void setupUI();
    void connectSignals();
    void setupDatabase();
    void onUploadButtonClicked();
    void checkPasswordValidity(const QString &password);


};


#endif // SIGNUPDIALOG_H
