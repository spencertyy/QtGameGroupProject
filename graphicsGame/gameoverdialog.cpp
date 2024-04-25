#include "gameoverdialog.h"


GameOverDialog::GameOverDialog(bool won, bool isGuest, QWidget *parent)
    : QDialog(parent) {
    setupUi(won, isGuest);
}

void GameOverDialog::setupUi(bool won, bool isGuest) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *messageLabel = new QLabel(won ? "Congratulations, you won!" : "Sorry, you lost. Try again?", this);

    QPushButton *restartButton = new QPushButton("Restart Game", this);

    QPushButton *closeButton = new QPushButton("Close Game", this);

    connect(restartButton, &QPushButton::clicked, this, &GameOverDialog::onRestartClicked);
    connect(closeButton, &QPushButton::clicked, this, &GameOverDialog::onCloseClicked);

    layout->addWidget(messageLabel);
    layout->addWidget(restartButton);

    if (!isGuest) {
        QPushButton *returnButton = new QPushButton("Return to Profile", this);
        QPushButton *historyButton = new QPushButton("View History", this);
        connect(returnButton, &QPushButton::clicked, this, &GameOverDialog::onReturnClicked);
        connect(historyButton, &QPushButton::clicked, this, &GameOverDialog::onViewHistoryClicked);
        layout->addWidget(returnButton);
        layout->addWidget(historyButton);
    }
    layout->addWidget(closeButton);

    setLayout(layout);
}

void GameOverDialog::onRestartClicked() {
    close();
    emit restartGame();
}

void GameOverDialog::onReturnClicked() {
    close();
    emit returnToProfile();
}

void GameOverDialog::onViewHistoryClicked() {
    close();
    emit viewHistory();
}

void GameOverDialog::onCloseClicked() {
    close();
}
