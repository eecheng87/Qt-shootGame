#ifndef POLY_ENEMY_H
#define POLY_ENEMY_H
#include<QObject>
#include<QGraphicsPixmapItem>
class poly_enemy:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    poly_enemy();
public slots:
    virtual void call();
};

#endif // POLY_ENEMY_H
