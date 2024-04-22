#include "gameoverdialog.h"



GameOverDialog::GameOverDialog(bool won, QWidget *parent)
    : QDialog(parent) {
    setupUi(won);
}

void GameOverDialog::setupUi(bool won) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *messageLabel = new QLabel(won ? "Congratulations, you won!" : "Sorry, you lost. Try again?", this);

    QPushButton *restartButton = new QPushButton("Restart Game", this);
    QPushButton *returnButton = new QPushButton("Return to Profile", this);
    QPushButton *historyButton = new QPushButton("View History", this);
    QPushButton *closeButton = new QPushButton("Close Game", this);

    connect(restartButton, &QPushButton::clicked, this, &GameOverDialog::onRestartClicked);
    connect(returnButton, &QPushButton::clicked, this, &GameOverDialog::onReturnClicked);
    connect(historyButton, &QPushButton::clicked, this, &GameOverDialog::onViewHistoryClicked);
    connect(closeButton, &QPushButton::clicked, this, &GameOverDialog::onCloseClicked);

    layout->addWidget(messageLabel);
    layout->addWidget(restartButton);
    layout->addWidget(returnButton);
    layout->addWidget(historyButton);
    layout->addWidget(closeButton);

    setLayout(layout);
}

void GameOverDialog::onRestartClicked() {
    emit restartGame();
    close();
}

void GameOverDialog::onReturnClicked() {
    emit returnToProfile();
    close();
}

void GameOverDialog::onViewHistoryClicked() {
    emit viewHistory();
    close();
}

void GameOverDialog::onCloseClicked() {
    close();
}
