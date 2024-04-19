#ifndef GAME1SCENE_H
#define GAME1SCENE_H

//#include <QGraphicsScene>
//#include <QGraphicsPixmapItem>
#include "cloud.h"
#include "droplet.h"
#include "bucket.h"



class game1scene : public QGraphicsScene
{
    Q_OBJECT
public:
    game1scene(QObject *parent = nullptr);

};

#endif // GAME1SCENE_H
