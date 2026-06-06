#ifndef GAME1SCENE_H
#define GAME1SCENE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QVBoxLayout>
#include "usermanager.h"
#include <QWidget>
#include <QDebug>
#include "levelofgame.h"
#include <QGraphicsView>
#include <QVector>

#include "bucket.h"
#include "droplet.h"
#include "usermanager.h"

class game1scene : public QGraphicsScene
{
    Q_OBJECT

public:
    QLabel *pointsLabel;
    QLabel *missedLabel;
    QLabel *timerLabel;
    UserManager *user = new UserManager;
    bool gameEnded = false;

    bucket *bucketItem = nullptr;

    void checkMissedDroplets();
    int gameLevel(std::string level);
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void updateLabels();
    void endGame();
    void restartGame();
    void returnToProfile();
    void viewHistory();
    void setUser(UserManager *user);

    QGraphicsView* view;
    static int windowWidth;
    static int windowHeight;
    static int drops_collected;
    static int game_score;
    static int missed_droplets;
    static int timeRemaining;
    static QMediaPlayer* soundEffect1;
    static QMediaPlayer* soundEffect2;
    static QMediaPlayer* missingEffect;
    static QVector<int> scoreHistory;

signals:
    void returnToLogin();

private slots:
    void updateCountdown();
};

#endif // GAME1SCENE_H


