#ifndef LEVELOFGAME_H
#define LEVELOFGAME_H

#include <QWidget>
#include "usermanager.h"

namespace Ui {
class levelOfGame;
}

class levelOfGame : public QWidget
{
    Q_OBJECT

public:
    explicit levelOfGame(UserInfo* userinfo, QWidget *parent = nullptr);
    ~levelOfGame();
    UserInfo* userinfo;

private slots:
    void on_hardButton_clicked();

    void on_mediumButton_clicked();

    void on_easyButton_clicked();

private:
    Ui::levelOfGame *ui;
};

#endif // LEVELOFGAME_H
