#include "game1scene.h"
#include "cloud.h"
#include "droplet.h"

game1scene::game1scene(QObject *parent):QGraphicsScene(parent) {

    setBackgroundBrush(QBrush(QImage(":/new/prefix1/images/beijing.jpg").scaledToHeight(512) .scaledToWidth(910)));

    // setBackgroundBrush(QPixmap(":/new/prefix1/images/background.jpg"));

    setSceneRect(0,0,908, 510);

    //add the bucket
    bucket *bucketItem = new bucket();
    bucketItem->setPos((910 - bucketItem->pixmap().width()) / 2, 512 - bucketItem->pixmap().height()); // Position at bottom center
    bucketItem->setFlag(QGraphicsItem::ItemIsFocusable);
    bucketItem->setFocus();
    addItem(bucketItem);

    QList<cloud*> clouds;  // 存储cloud list

    //add 3 cloud on different pos
    for (int i = 0; i < 3; ++i) {
        cloud* cloudItem = new cloud();
        int x_position = 100 + i * 250 - 50 ;  // 每朵云水平间隔250像素
        cloudItem->setPos(x_position, 7);  // (云都位于相同的垂直位置，高度)
        addItem(cloudItem);
        clouds.append(cloudItem);  // 将cloud添加到列表里面
    }

    // 创建定时器以随机从一朵云下方生成雨滴
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this, clouds]() {
        if (!clouds.isEmpty()) {
            int cloudIndex = rand() % clouds.size();  // 随机选择一朵云
            cloud* selectedCloud = clouds.at(cloudIndex);
            int dropletX = selectedCloud->x() + rand() % selectedCloud->pixmap().width();  // 在选中的云宽度范围内随机生成X坐标
            droplet* droplets = new droplet();
            droplets->setPos(dropletX, selectedCloud->y() + selectedCloud->pixmap().height());  // 从云的底部开始
            addItem(droplets);
        }

    });

     timer->start(200);//根据需要进行调整


   // bucket *item1 = new bucket();

    // item1->setPos(200,200);

    // addItem(item1);
}
