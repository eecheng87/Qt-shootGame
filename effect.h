#ifndef EFFECT_H
#define EFFECT_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

class effect : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    effect();
    int explo_pos_x;
    int explo_pos_y;

public slots:
    void explo_effect();
    void explo_effect_i();
    void explo_effect_ii();
    void set_explo_pos(int,int);
};

#endif // EFFECT_H
