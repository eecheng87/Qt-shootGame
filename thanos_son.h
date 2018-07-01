#ifndef THANOS_SON_H
#define THANOS_SON_H
#include<QGraphicsScene>
#include<QProgressBar>
#include<QGraphicsPixmapItem>
#include<QPointF>
#include"jet.h"
#include"thanos_son_bullet.h"
class MainWindow;
class thanos_son:public jet
{
    Q_OBJECT
public:
    thanos_son();
    thanos_son(QGraphicsScene *scene,MainWindow *window);
    ~thanos_son();
    //int get_HP();
    //void minus_HP();
   /* void minus_MP();
    void incre_HP();
    void incre_MP();*/

    void add_bar(QGraphicsPixmapItem *);
    //void set_explo_pos();
    //void call();
    int X;
    int Y;
    bool live;


signals:
     void explosion(int,int);
public slots:
     void call();
    // void move();
     void attack();
     void attack_mode();
     void normal_mode();

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
    QTimer *son_move_timer;
    QTimer *attack_timer;
    QTimer *animate_tmr;
    QPointF coordinate;

};

#endif // THANOS_SON_H
