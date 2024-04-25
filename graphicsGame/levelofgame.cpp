#include "levelofgame.h"
#include "ui_levelofgame.h"
#include "game1scene.h"
#include "usermanager.h"
#include <QGraphicsView>
levelOfGame::levelOfGame(UserInfo* userinfo, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::levelOfGame)
{
    this->userinfo = userinfo;
    ui->setupUi(this);
}

levelOfGame::~levelOfGame()
{
    delete ui;
}

void levelOfGame::on_hardButton_clicked()
{
    close();
    //smaller number, harder
    game1scene* game = new game1scene(userinfo);
    QGraphicsView* view_obj = new QGraphicsView(game);
    game->setView(view_obj);
    // game1scene::gameLevelint = 100;
    view_obj->setFixedSize(910,512);
    view_obj->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view_obj->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view_obj->show();
}




void levelOfGame::on_mediumButton_clicked()
{
    close();
    //smaller number, harder
    game1scene* game = new game1scene(userinfo);
    QGraphicsView* view_obj = new QGraphicsView(game);
    game->setView(view_obj);
    // game1scene::gameLevelint = 500;
    view_obj->setFixedSize(910,512);
    view_obj->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view_obj->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view_obj->show();
}


void levelOfGame::on_easyButton_clicked()
{
    close();
    //smaller number, harder
    game1scene* game = new game1scene(userinfo);
    QGraphicsView* view_obj = new QGraphicsView(game);
    game->setView(view_obj);
    // game1scene::gameLevelint = 1000;
    view_obj->setFixedSize(910,512);
    view_obj->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view_obj->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view_obj->show();
}

