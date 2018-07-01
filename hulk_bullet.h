#ifndef HULK_BULLET_H
#define HULK_BULLET_H
#include<QGraphicsScene>
#include<QProgressBar>
#include<QGraphicsPixmapItem>
#include<QPointF>
#include<QList>
#include"score.h"
class hulk_bullet: public QObject,public QGraphicsPixmapItem//must inherit pixmapitem,or cant static cast
{
    Q_OBJECT
public:
    hulk_bullet();
private slots:
    void fly();

};

#endif // HULK_BULLET_H
