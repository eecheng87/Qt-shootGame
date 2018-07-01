#ifndef HP_BALL_H
#define HP_BALL_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPointF>
#include <QProgressBar>
#include "player.h"
class MainWindow;
class hp_ball: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    hp_ball();
    hp_ball(QGraphicsScene *,MainWindow *);
    QGraphicsPixmapItem *pix_jet;
    QProgressBar *hp_progress;
    QGraphicsPixmapItem *pixball;
public slots:
    void fly();
    void call();
private:
    static QGraphicsScene *tmp_scene;
    static MainWindow *tmp_window;
    QPointF coordinate;
    QTimer *fly_tmr;
};

#endif // HP_BALL_H
