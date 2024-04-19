#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>

namespace Ui {
class loginPage;
}

class loginPage : public QWidget
{
    Q_OBJECT

    //Methods
    void onLoginButtonClicked();
public:
    explicit loginPage(QWidget *parent = nullptr);
    ~loginPage();

private:
    Ui::loginPage *ui;
    // QLineEdit* usernameLineEdit;
    // QLineEdit* passwordLineEdit;
    //QPushButton* loginButton;
};

#endif // LOGINPAGE_H
