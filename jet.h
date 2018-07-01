#ifndef JET_H
#define JET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPointF>
#include <QProgressBar>

#include "poly_enemy.h"
#include "jet_bullet.h"

class MainWindow;//if not add this,project dont know who is mainwindow

class jet:public poly_enemy//,public QGraphicsPixmapItem//,public QObject
{
    Q_OBJECT
public:
    QGraphicsPixmapItem *pix_jet;
    QProgressBar *hp_progress;
    jet();
    ~jet();
    jet(QGraphicsScene *scene,MainWindow *window);
    int get_HP();
    void minus_HP();
    void minus_MP();
    void incre_HP();
    void incre_MP();

    void add_bar(QGraphicsPixmapItem *);
    //void set_explo_pos();
    //void call();
    int X;
    int Y;
    bool live;


signals:
    void explosion(int,int);
public slots:
     virtual void call();
     void move();
     void attack();

     void explo_effect();
     void explo_effect_i();
     void explo_effect_ii();
     void explo_effect_iii();
     void explo_effect_iv();
     void explo_effect_v();
     void set_explo_pos(int,int);


private:

    int HP;
    int MP;
    int stage;
    static QGraphicsScene *tmp_scene;
    static MainWindow *tmp_window;
    //static QWidget *tmp_widget;
    QGraphicsPixmapItem *explo;
    QTimer *jet_move_timer;
    QTimer *attack_timer;
    QTimer *effect_tmr;
    QPointF coordinate;



};



#endif // JET_H
