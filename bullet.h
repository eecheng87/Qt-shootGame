#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

#include "thanos.h"
#include "thanos_son.h"
#include "jet.h"
#include "score.h"

class bullet : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bullet();
    bullet(QGraphicsScene*);
    QTimer *effect_timer;
    //QGraphicsPixmapItem *tmp_item;
    static QGraphicsScene *tmp_scene;
    int state;
signals:

public slots:
    void fly();
    void effect();
};

#endif // BULLET_H
