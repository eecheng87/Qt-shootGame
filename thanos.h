#ifndef THANOS_H
#define THANOS_H
#include<QGraphicsScene>
#include<QProgressBar>
#include<QGraphicsPixmapItem>
#include<QPointF>
#include"jet.h"
#include"thanos_bullet.h"
#include"thanos_son.h"
//#include"poly_enemy.h"
class MainWindow;
class thanos:public jet//must inherit pixmapitem,or cant static cast
{
    Q_OBJECT
public:
    thanos();
    QGraphicsPixmapItem *pix_jet;
    QProgressBar *hp_progress;

    ~thanos();
    thanos(QGraphicsScene *scene,MainWindow *window);
    int get_HP();
    void minus_HP();
   /* void minus_MP();
    void incre_HP();
    void incre_MP();*/

    void add_bar(QGraphicsPixmapItem *);
    //void set_explo_pos();
    //void call();
    int X;
    int Y;
    bool live;
    bool son_exist;


signals:
     void signal_call_son();
     void explosion(int,int);
public slots:
     void call_son();
     virtual void call();
     void move();
     void attack();

/*     void explo_effect();
     void explo_effect_i();
     void explo_effect_ii();
     void explo_effect_iii();
     void explo_effect_iv();
     void explo_effect_v();
     void set_explo_pos(int,int);*/


private:

    int HP;
    int MP;
    static QGraphicsScene *tmp_scene;
    static MainWindow *tmp_window;
    //static QWidget *tmp_widget;
    QGraphicsPixmapItem *explo;
    QTimer *thanos_move_timer;
    QTimer *attack_timer;
    QTimer *effect_tmr;
    QPointF coordinate;



};


#endif // THANOS_H
