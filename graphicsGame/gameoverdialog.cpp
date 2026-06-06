#include "gameoverdialog.h"
#include <QVector>
#include <QApplication>
#include <algorithm>

GameOverDialog::GameOverDialog(int score, const QVector<int>& allScores, QWidget *parent)
    : QDialog(parent) {
    setupUi(score, allScores);
}

void GameOverDialog::setupUi(int score, const QVector<int>& allScores) {
    setWindowTitle("Time's Up!");
    setMinimumWidth(320);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setSpacing(10);

    QLabel *titleLabel = new QLabel("Time's Up!", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 22px; font-weight: bold;");
    layout->addWidget(titleLabel);

    QLabel *scoreLabel = new QLabel(
        QString("You caught <b>%1</b> droplets!").arg(score), this);
    scoreLabel->setAlignment(Qt::AlignCenter);
    scoreLabel->setStyleSheet("font-size: 16px; margin: 6px 0;");
    layout->addWidget(scoreLabel);

    QLabel *rankTitle = new QLabel("── Leaderboard ──", this);
    rankTitle->setAlignment(Qt::AlignCenter);
    rankTitle->setStyleSheet("font-size: 14px; color: #555; margin-top: 8px;");
    layout->addWidget(rankTitle);

    QVector<int> sorted = allScores;
    std::sort(sorted.begin(), sorted.end(), std::greater<int>());

    for (int i = 0; i < sorted.size() && i < 10; ++i) {
        QString medal;
        if (i == 0) medal = "🥇";
        else if (i == 1) medal = "🥈";
        else if (i == 2) medal = "🥉";
        else medal = QString("  %1.").arg(i + 1);

        QString rowText = QString("%1  %2 drops").arg(medal).arg(sorted[i]);
        QLabel *row = new QLabel(rowText, this);
        row->setAlignment(Qt::AlignCenter);

        if (sorted[i] == score) {
            row->setStyleSheet("font-size: 15px; font-weight: bold; color: #cc6600; background: #fff3cd; border-radius: 4px; padding: 2px;");
        } else {
            row->setStyleSheet("font-size: 14px; color: #333;");
        }
        layout->addWidget(row);
    }

    layout->addSpacing(10);

    QPushButton *restartButton = new QPushButton("Play Again", this);
    QPushButton *returnButton  = new QPushButton("Return to Login", this);
    QPushButton *closeButton   = new QPushButton("Quit Game", this);

    restartButton->setStyleSheet("font-size: 14px; padding: 6px;");
    returnButton->setStyleSheet("font-size: 14px; padding: 6px;");
    closeButton->setStyleSheet("font-size: 14px; padding: 6px; background: #cc3333; color: white;");

    connect(restartButton, &QPushButton::clicked, this, &GameOverDialog::onRestartClicked);
    connect(returnButton,  &QPushButton::clicked, this, &GameOverDialog::onReturnClicked);
    connect(closeButton,   &QPushButton::clicked, this, &GameOverDialog::onCloseClicked);

    layout->addWidget(restartButton);
    layout->addWidget(returnButton);
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
    QApplication::quit();
}
