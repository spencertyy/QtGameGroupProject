#ifndef GAMEOVERDIALOG_H
#define GAMEOVERDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QVector>

class GameOverDialog : public QDialog {
    Q_OBJECT

public:
    explicit GameOverDialog(int score, const QVector<int>& allScores, QWidget *parent = nullptr);

signals:
    void restartGame();
    void returnToProfile();
    void viewHistory();

private slots:
    void onRestartClicked();
    void onReturnClicked();
    void onViewHistoryClicked();
    void onCloseClicked();

private:
    void setupUi(int score, const QVector<int>& allScores);
};

#endif // GAMEOVERDIALOG_H
