#include "droplet.h"

droplet::droplet(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent) {

    setPixmap(QPixmap(":/new/prefix1/images/water.gif").scaled(30,30));
    QTimer *timer = new QTimer();
    connect(timer, &QTimer::timeout, this ,&droplet::move);
    timer->start(50);
}



void droplet::move(){
    setPos(x(),y() +5);
    QList<QGraphicsItem*> colliding_item = collidingItems();
    for(QGraphicsItem* item : colliding_item){
        bucket* bucketItem = dynamic_cast<bucket*>(item);
        if(bucketItem){
            scene()->removeItem(this);
            deleteLater();
        }
    }
    if(y()>512){ //场景高度是512
        scene()->removeItem(this);
        delete this;
    }

}