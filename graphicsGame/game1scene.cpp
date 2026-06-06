#include "game1scene.h"
#include "gameoverdialog.h"
#include "levelofgame.h"
#include "cloud.h"
#include "droplet.h"
#include "bucket.h"
#include "profile.h"
#include "history.h"

#include "gameoverdialog.h"
#include <iostream>
#include <QLabel>
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include <QApplication>
#include <algorithm>


int game1scene::drops_collected = 0;
int game1scene::game_score = 0;
int game1scene::missed_droplets = 0;
int game1scene::windowHeight = 512;
int game1scene::windowWidth = 910;
int game1scene::timeRemaining = 120;
QMediaPlayer* game1scene::soundEffect1 = new QMediaPlayer();
QMediaPlayer* game1scene::soundEffect2 = new QMediaPlayer();
QMediaPlayer* game1scene::missingEffect = new QMediaPlayer();
QVector<int> game1scene::scoreHistory;


game1scene::game1scene(UserInfo* userInfo, QObject *parent):QGraphicsScene(parent) {
    // this->level = level;

    this->userinfo = userInfo;

    // gameLevelint = 100;

    drops_collected = 0;
    game_score = 0;
    missed_droplets = 0;
    timeRemaining = 60;
    gameEnded = false;

    setSceneRect(0, 0, 908, 510);

    // Score and missed labels
    pointsLabel = new QLabel();
    missedLabel = new QLabel();
    pointsLabel->setFont(QFont("Arial", 16));
    missedLabel->setFont(QFont("Arial", 16));
    pointsLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    missedLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    // 倒计时标签，和其他标签样式一致
    timerLabel = new QLabel();
    timerLabel->setFont(QFont("Arial", 16));
    timerLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    updateLabels();

    QGraphicsProxyWidget *dropsCollectedProxy = addWidget(pointsLabel);
    dropsCollectedProxy->setPos(5, 110);

    QGraphicsProxyWidget *missedDropletsProxy = addWidget(missedLabel);
    missedDropletsProxy->setPos(5, 130);

    QGraphicsProxyWidget *timerProxy = addWidget(timerLabel);
    timerProxy->setPos(5, 150);

    // 退出按钮：回到登录页
    QPushButton *exitBtn = new QPushButton("Exit");
    exitBtn->setFixedSize(70, 30);
    exitBtn->setStyleSheet("background-color: #cc3333; color: white; font-weight: bold; border-radius: 4px;");
    connect(exitBtn, &QPushButton::clicked, this, &game1scene::returnToLogin);
    QGraphicsProxyWidget *exitProxy = addWidget(exitBtn);
    exitProxy->setPos(windowWidth - 80, 10);

    // 音效
    QAudioOutput* audioOutput1 = new QAudioOutput;
    QAudioOutput* audioOutput2 = new QAudioOutput;
    QAudioOutput* missingOutput = new QAudioOutput;
    soundEffect1->setAudioOutput(audioOutput1);
    soundEffect2->setAudioOutput(audioOutput2);
    missingEffect->setAudioOutput(missingOutput);
    soundEffect1->setSource(QUrl("qrc:/new/prefix1/RaningMen.m4a"));
    soundEffect2->setSource(QUrl("qrc:/new/prefix2/HALLELUJAHH.m4a"));
    missingEffect->setSource(QUrl("qrc:/new/prefix3/MissingEffect.m4a"));

    QPixmap background(":/new/prefix1/images/beijing.jpg");
    background = background.scaled(windowWidth, windowHeight, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    setBackgroundBrush(background);

    // 水桶
    bucketItem = new bucket();
    bucketItem->setPos((910 - bucketItem->pixmap().width()) / 2, 512 - bucketItem->pixmap().height());
    addItem(bucketItem);

    // 3 朵云
    QList<cloud*> clouds;
    for (int i = 0; i < 3; ++i) {
        cloud* cloudItem = new cloud();
        cloudItem->setPos(100 + i * 250 - 50, 7);
        addItem(cloudItem);
        clouds.append(cloudItem);
    }

    // 清理超出屏幕的水滴（每 300ms）
    QTimer* cleanupTimer = new QTimer(this);
    connect(cleanupTimer, &QTimer::timeout, this, &game1scene::checkMissedDroplets);
    cleanupTimer->start(300);

    // 生成水滴（每 300ms）
    QTimer* spawnTimer = new QTimer(this);
    connect(spawnTimer, &QTimer::timeout, [this, clouds]() {
        if (gameEnded || clouds.isEmpty()) return;
        int cloudIndex = rand() % clouds.size();
        cloud* selectedCloud = clouds.at(cloudIndex);
        int dropletX = selectedCloud->x() + rand() % selectedCloud->pixmap().width();
        droplet* d = new droplet();
        d->setPos(dropletX, selectedCloud->y() + selectedCloud->pixmap().height());
        addItem(d);
    });
    spawnTimer->start(300);

    // 得分刷新（每 100ms）
    QTimer* labelTimer = new QTimer(this);
    connect(labelTimer, &QTimer::timeout, this, &game1scene::updateLabels);
    labelTimer->start(100);

    // 倒计时（每 1 秒）
    QTimer* countdownTimer = new QTimer(this);
    connect(countdownTimer, &QTimer::timeout, this, &game1scene::updateCountdown);
    countdownTimer->start(1000);
}

void game1scene::keyPressEvent(QKeyEvent *event) {
    if (!bucketItem) return;
    if (event->key() == Qt::Key_Left)  bucketItem->setMovingLeft(true);
    if (event->key() == Qt::Key_Right) bucketItem->setMovingRight(true);
}

void game1scene::keyReleaseEvent(QKeyEvent *event) {
    if (!bucketItem) return;
    if (event->key() == Qt::Key_Left)  bucketItem->setMovingLeft(false);
    if (event->key() == Qt::Key_Right) bucketItem->setMovingRight(false);
}

void game1scene::updateCountdown() {
    if (gameEnded) return;
    timeRemaining--;
    int minutes = timeRemaining / 60;
    int seconds = timeRemaining % 60;
    timerLabel->setText(QString("%1:%2").arg(minutes).arg(seconds, 2, 10, QChar('0')));
    if (timeRemaining <= 0) {
        endGame();
    }
}

void game1scene::checkMissedDroplets() {
    foreach (QGraphicsItem *item, items()) {
        droplet* d = dynamic_cast<droplet*>(item);
        if (d && d->y() > windowHeight) {
            missed_droplets++;
            removeItem(d);
            d->deleteLater();
        }
    }
}

void game1scene::endGame() {
    if (gameEnded) return;
    gameEnded = true;

    scoreHistory.append(drops_collected);

    QWidget* parentWidget = this->views().isEmpty() ? nullptr : this->views().first();
    GameOverDialog *dialog = new GameOverDialog(drops_collected, scoreHistory, parentWidget);
    connect(dialog, &GameOverDialog::restartGame, this, &game1scene::restartGame);
    connect(dialog, &GameOverDialog::returnToProfile, this, &game1scene::returnToProfile);
    connect(dialog, &GameOverDialog::viewHistory, this, &game1scene::viewHistory);
    dialog->exec();
}

int game1scene::gameLevel(std::string level) {
    if (level == "easy") return 100;
    else if (level == "medium") return 200;
    else return 300;
}

void game1scene::updateLabels() {
    pointsLabel->setText("Points: " + QString::number(game_score));
    missedLabel->setText("Missed Droplets: " + QString::number(missed_droplets));
    timerLabel->setText(QString("Time: %1:%2")
        .arg(timeRemaining / 60)
        .arg(timeRemaining % 60, 2, 10, QChar('0')));
}

void game1scene::restartGame() {
    drops_collected = 0;
    game_score = 0;
    missed_droplets = 0;
    timeRemaining = 60;
    gameEnded = false;
}


void game1scene::returnToProfile() {
    profile *profileWindow = new profile(nullptr, nullptr);
    profileWindow->setWindowTitle("Profile");
    profileWindow->show();
}

void game1scene::viewHistory() {
    history* h = new history();
    h->setWindowTitle("History");
    h->show();
}
