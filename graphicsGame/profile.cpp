#include "profile.h"
#include "ui_profile.h"


profile::profile(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::profile)
{
    ui->setupUi(this);
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    connect(ui->gameStartBtn, &QPushButton::clicked, this, &profile::onGameStartBtnClicked);
}

profile::~profile()
{
    delete ui;
}

void profile::onGameStartBtnClicked(){

    game1scene *scene = new game1scene();
    QGraphicsView *view_obj = new QGraphicsView(scene);

    view_obj->setFixedSize(910,512);

    view_obj->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view_obj->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));

    if (!view_obj) {
        view_obj = new QGraphicsView;
    }
    view_obj->show(); // Shows the main game view
    this->hide();
}

