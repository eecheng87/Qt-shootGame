#ifndef THANOS_BULLET_H
#define THANOS_BULLET_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>


class thanos_bullet: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    thanos_bullet();
    bool set_attack_mode;
    int attack_mode;
public slots:
    void fly();
};

#endif // THANOS_BULLET_H
