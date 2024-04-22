#ifndef GAMEOVERDIALOG_H
#define GAMEOVERDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class GameOverDialog : public QDialog {
    Q_OBJECT

public:
    explicit GameOverDialog(bool won, QWidget *parent = nullptr);

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
    void setupUi(bool won);
};

#endif // GAMEOVERDIALOG_H
