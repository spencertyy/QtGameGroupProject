#include "history.h"
#include "ui_history.h"


history::history(UserInfo* userinfo, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::history)
{
    this->userinfo = userinfo;
    ui->setupUi(this);
    QString out = QString("");
    for (auto score : userinfo->scoreHistory) {
        out = out + QString("score: ") + QString::number(score) + QString("\n");
    }
    ui->textOut->setText(out);
}

history::~history()
{
    delete ui;
}
