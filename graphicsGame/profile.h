#ifndef PROFILE_H
#define PROFILE_H

#include <QWidget>
#include <QPushButton>
#include "game1scene.h"
#include "usermanager.h"
namespace Ui {
class profile;
}

class profile : public QWidget
{
    Q_OBJECT

public:
    explicit profile(UserInfo* user,QWidget *parent = nullptr);
    ~profile();

    Ui::profile *ui;
    QPushButton *gameStartBtn; // Ensure this is properly connected to the UI
public slots:
    void onGameStartBtnClicked();


};

#endif // PROFILE_H
