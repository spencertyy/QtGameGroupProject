#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QDateEdit>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QPixmap>

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

    void setupUI();
    void connectSignals();
    void setupDatabase();
    void onUploadButtonClicked();


};


#endif // SIGNUPDIALOG_H
