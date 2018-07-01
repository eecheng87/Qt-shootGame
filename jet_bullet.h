#ifndef JET_BULLET_H
#define JET_BULLET_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class jet_bullet : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    jet_bullet();
private slots:
    void fly();
};

#endif // JET_BULLET_H
