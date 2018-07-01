#ifndef FIGHTER_H
#define FIGHTER_H
#include "enemy.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
class fighter:public enemy,public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    fighter();
    void attack();
    int getHP();
    void minus_HP();
    int HP;
    int X;
    int Y;
public slots:
    void move();
private:
    QGraphicsPixmapItem *plane;
};

#endif // FIGHTER_H
