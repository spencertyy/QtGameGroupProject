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
#include "cloud.h"
#include "droplet.h"
#include "bucket.h"
#include "gameoverdialog.h"
#include <iostream>
#include <QLabel>
#include <QGraphicsProxyWidget>
#include "profile.h"
#include "history.h"


class game1scene : public QGraphicsScene
{
    Q_OBJECT

public:
    QLabel *pointsLabel;
    QLabel *missedLabel;
    UserInfo* userinfo;
    int level; //chooses the game level

    game1scene(UserInfo* userInfo, QObject *parent = nullptr);
    // game1scene(UserInfo* userInfo, int level, QObject *parent = nullptr);

    void checkMissedDroplets();
    void winningGame();
    void loosingGame();
    int gameLevel();
    void updateLabels();
    void onGameEnded(bool won);
    void restartGame();
    void returnToProfile();
    void viewHistory();
    void setView(QGraphicsView* view);
    void cleanup();

    QGraphicsView* view;
    static int windowWidth;
    static int windowHeight;
    static int drops_collected;
    static int game_score;
    static int missed_droplets;
    static int *gameLevelint;
    static bool gameOver;
    static QMediaPlayer* soundEffect1;
    static QMediaPlayer* soundEffect2;
    static QMediaPlayer* missingEffect;

signals:
    //upont loosing signal add score to userInfo record history?
    //pass userInfo back to profile creator when game ends
    void loosingSignal(int value);
    void winningSignal(int value);
};

#endif // GAME1SCENE_H


