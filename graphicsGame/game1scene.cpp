#include "game1scene.h"
#include "gameoverdialog.h"
#include "levelofgame.h"
#include "cloud.h"
#include "droplet.h"
#include "bucket.h"
#include <iostream>
#include "profile.h"
#include "history.h"

int game1scene::drops_collected = 0;
int game1scene::game_score = 0;
int game1scene::missed_droplets = 0;
int game1scene::windowHeight = 512;
int game1scene::windowWidth = 910;
bool game1scene::gameOver = false;
QMediaPlayer* game1scene::soundEffect1 = new QMediaPlayer();
QMediaPlayer* game1scene::soundEffect2 = new QMediaPlayer();
QMediaPlayer* game1scene::missingEffect = new QMediaPlayer();


game1scene::game1scene(UserInfo* userInfo, QObject *parent):QGraphicsScene(parent) {
    // this->level = level;

    this->userinfo = userInfo;

    // gameLevelint = 100;

    QTimer* scoreUpdateTimer = new QTimer(this);
    connect(scoreUpdateTimer, &QTimer::timeout, this, &game1scene::updateLabels);

    setSceneRect(0,0,908, 510);

    pointsLabel = new QLabel();
    missedLabel = new QLabel();
    pointsLabel->setFont(QFont("Arial", 16));
    missedLabel->setFont(QFont("Arial", 16));

    pointsLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    missedLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    // Set initial text for the labels
    updateLabels();

    // Add labels to the scene
    QGraphicsProxyWidget *dropsCollectedProxy = addWidget(pointsLabel);
    dropsCollectedProxy->setPos(70, 80);

    QGraphicsProxyWidget *missedDropletsProxy = addWidget(missedLabel);
    missedDropletsProxy->setPos(70, 100);

    scoreUpdateTimer->start(100);

    // soundEffect1 = new QMediaPlayer(this);
    QAudioOutput* audioOutput1 = new QAudioOutput;
    QAudioOutput* audioOutput2 = new QAudioOutput;
    QAudioOutput* missingOutput = new QAudioOutput;
    soundEffect1->setAudioOutput(audioOutput1);
    soundEffect2->setAudioOutput(audioOutput2);
    missingEffect->setAudioOutput(missingOutput);
    soundEffect1->setSource(QUrl("qrc:/new/prefix1/RaningMen.m4a"));
    soundEffect2->setSource(QUrl("qrc:/new/prefix2/HALLELUJAHH.m4a"));
    missingEffect->setSource(QUrl("qrc:/new/prefix3/MissingEffect.m4a"));

    audioOutput1->setVolume(10);
    audioOutput2->setVolume(10);
    missingOutput->setVolume(50);

    QPixmap background(":/new/prefix1/images/background.jpg");
    background = background.scaled(windowWidth, windowHeight, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    setBackgroundBrush(background);

    //add the bucket
    bucket *bucketItem = new bucket();
    bucketItem->setPos((910 - bucketItem->pixmap().width()) / 2, 512 - bucketItem->pixmap().height()); // Position at bottom center
    bucketItem->setFlag(QGraphicsItem::ItemIsFocusable);
    bucketItem->setFocus();
    addItem(bucketItem);

    QList<cloud*> clouds;

    //add 3 cloud on different pos
    for (int i = 0; i < 3; ++i) {
        cloud* cloudItem = new cloud();
        int x_position = 100 + i * 250 - 50 ;
        cloudItem->setPos(x_position, 7);
        addItem(cloudItem);
        clouds.append(cloudItem);
    }

    QTimer* missedDropletTimer = new QTimer(this);
    connect(missedDropletTimer, &QTimer::timeout, this, &game1scene::checkMissedDroplets);
    missedDropletTimer->start(300);


    //generating droplets
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this, clouds]() {
        if (!clouds.isEmpty() && !gameOver) {
            int cloudIndex = rand() % clouds.size();  // 随机选择一朵云
            cloud* selectedCloud = clouds.at(cloudIndex);
            int dropletX = selectedCloud->x() + rand() % selectedCloud->pixmap().width();
            droplet* droplets = new droplet(&gameOver);
            droplets->setPos(dropletX, selectedCloud->y() + selectedCloud->pixmap().height());
            addItem(droplets);
        }

    });
    timer->start(300);

    //set timer to run the two if statments, continouslly check
    QTimer* gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, [this]() {

         // std::cout << "Current missed droplets: " << missed_droplets << "\n";
        if (gameOver) {
          // game is already over, and dialog is displayed
        } else if (game_score >= 150) {
            bool didWin = true;
            onGameEnded(didWin);
            //end this widget
        } else if (missed_droplets >= 5) {
            bool didWin = false;
            onGameEnded(didWin);
             //end this widget
        }
     });

     gameTimer->start(100);
}

void game1scene::checkMissedDroplets(){
    // std::cout << "check function being called" << "\n";
    foreach(QGraphicsItem *item, items()) {
        droplet* dropletItem = dynamic_cast<droplet*>(item);
        if (dropletItem) {

            // Check missing by reaching out of bound
            if (dropletItem->y() > windowHeight) {
                //missingEffect->play();
                missed_droplets++;
                removeItem(dropletItem);
                //scene->removeItem(dropletItem);
                // delete this;
            }
        }
    }
}

//results window should listen for the winning game signal to display
void game1scene::winningGame(){ 
    emit winningSignal(game_score);
    std::cout << "Congradulations! you win the game!" << "\n";

        //TODO: winning game widget
}

//results window should listen for this signal
void game1scene::loosingGame(){
    emit loosingSignal(game_score);
        std::cout << "You lose the game" << "\n";
        //TODO: loosing game widget

}


// int game1scene::gameLevel(){
//     if (gameLevelint == 1){
//         return 100;
//     }
//     else if (gameLevelint == 2){
//         return 200;
//     }
//     else {
//         return 300;
//     }
// }



void game1scene::updateLabels()
{
    pointsLabel->setText("Points: " + QString::number(game_score));
    missedLabel->setText("Missed Droplets: " + QString::number(missed_droplets));
}
// ... inside your game logic ...

void game1scene::onGameEnded(bool won) {
    QWidget* parentWidget = this->views().isEmpty() ? nullptr : this->views().first();
    GameOverDialog *dialog = new GameOverDialog(won,  parentWidget);
    connect(dialog, &GameOverDialog::restartGame, this, &game1scene::restartGame);
    connect(dialog, &GameOverDialog::returnToProfile, this, &game1scene::returnToProfile);
    connect(dialog, &GameOverDialog::viewHistory, this, &game1scene::viewHistory);
    dialog->exec(); // Use exec for a modal dialog that blocks the rest of the application
}


void game1scene::restartGame() {
    // Reset all game variables to their initial state.
    // If using scenes, clear the current scene and set up a new one.
    // If you have timers, reset them.
    // Basically, reinitialize everything needed to start the game from scratch.

}

void game1scene::returnToProfile() {
    // Hide or close the current game window or scene.
    // Show the profile window. This could be done by emitting a signal that the main application listens to and then shows the profile UI.
}

void game1scene::viewHistory() {
    // Again, hide or close the current game window or scene.
    // Display the history window where you might list past game scores, achievements, etc.
}

void game1scene::setView(QGraphicsView* view) {
    this->view = view;
}


void game1scene::onGameEnded(bool won) {
    qDebug() << "game1scene onGameEnded";
    gameOver = true;

    QWidget* parentWidget = this->views().isEmpty() ? nullptr : this->views().first();

    bool isGuest = (userinfo == nullptr);
    GameOverDialog *dialog = new GameOverDialog(won, isGuest, parentWidget);
    if (!isGuest) {
        userinfo->addScore(game_score);
    }

    this->view->close();


    connect(dialog, &GameOverDialog::restartGame, this, &game1scene::restartGame);
    connect(dialog, &GameOverDialog::returnToProfile, this, &game1scene::returnToProfile);
    connect(dialog, &GameOverDialog::viewHistory, this, &game1scene::viewHistory);
    dialog->exec(); // Use exec for a modal dialog that blocks the rest of the application
}

void game1scene::cleanup() {
    drops_collected = 0;
    game_score = 0;
    missed_droplets = 0;
    gameOver = false;
    delete this;
}

void game1scene::restartGame() {
    qDebug() << "game scene: restart game";
    levelOfGame* levelScene = new levelOfGame(userinfo);
    cleanup();
    levelScene->show();

    // Reset all game variables to their initial state.
    // If using scenes, clear the current scene and set up a new one.
    // If you have timers, reset them.
    // Basically, reinitialize everything needed to start the game from scratch.

}


void game1scene::returnToProfile() {
    qDebug() << "game scene: return to profile";
    profile *profileWindow = new profile(userinfo);
    cleanup();
    profileWindow->setWindowTitle("Profile");
    profileWindow->show();
    // Hide or close the current game window or scene.
    // Show the profile window. This could be done by emitting a signal that the main application listens to and then shows the profile UI*/.
}

void game1scene::viewHistory() {
    qDebug() << "game scene: view history";
    //TODO: show text Edit widget, add records there
    history* History = new history(userinfo);
    cleanup();
    History->setWindowTitle("Profile");
    History->show();
}




