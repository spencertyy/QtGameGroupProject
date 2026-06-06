#ifndef BUCKET_H
#define BUCKET_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>
#include <QGraphicsScene>
#include <QTimer>

class bucket : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    bucket(QGraphicsItem *parent = nullptr);
    void setMovingLeft(bool v)  { movingLeft = v; }
    void setMovingRight(bool v) { movingRight = v; }

private slots:
    void updateMovement();

private:
    bool movingLeft = false;
    bool movingRight = false;
    QTimer *moveTimer;
};

#endif // BUCKET_H
