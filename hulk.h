#ifndef HULK_H
#define HULK_H
#include<QGraphicsScene>
#include<QProgressBar>
#include<QGraphicsPixmapItem>
#include<QPointF>

#include"hulk_bullet.h"

class MainWindow;

class hulk: public QObject,public QGraphicsPixmapItem//must inherit pixmapitem,or cant static cast
{
    Q_OBJECT
public:
    hulk();
    hulk(QGraphicsScene*,MainWindow*);
    void show();//set image
    void update_coordinate(int,int);
    void update_hulk_pos();
    void update_bar_pos();
    void add_bar();
    int get_HP();
    QProgressBar *HP_bar;
    QPointF coordinate;
    QGraphicsScene *tmp_scene;
    MainWindow *tmp_window;
    QTimer *life_timer;
    QTimer *missile_move_timer;
    QTimer *attack_timer;
signals:
    void hulk_hp_reach_zero();
    void change_exist_flag();
public slots:
    void delete_hulk();
    void attack();
    void minus_HP();
 private:
    int HP;//will decrease each second,when reach 0,delete hulk
};

#endif // HULK_H
