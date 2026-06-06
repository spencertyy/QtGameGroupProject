#include "bucket.h"

bucket::bucket(QGraphicsItem *parent):QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/new/prefix1/images/bucket.png").scaled(150,150));

    moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &bucket::updateMovement);
    moveTimer->start(16);
}

void bucket::updateMovement(){
    int stepSize = 6;
    if(movingLeft && x() >= stepSize)
        setPos(x() - stepSize, y());
    if(movingRight && scene() && x() + pixmap().width() + stepSize <= scene()->width())
        setPos(x() + stepSize, y());
}
