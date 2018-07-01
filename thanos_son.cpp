#include "thanos_son.h"
#include "mainwindow.h"
QGraphicsScene* thanos_son::tmp_scene;//declare static variable
MainWindow* thanos_son::tmp_window;
thanos_son::thanos_son()
{

}

thanos_son::thanos_son(QGraphicsScene *scene, MainWindow *window)
{
    tmp_scene = scene;
    tmp_window = window;
    HP = 10;
}

thanos_son::~thanos_son()
{

}

void thanos_son::call()
{
    setPixmap(QPixmap(":/res/thanos_son2.png").scaled(210,240));
    QGraphicsPixmapItem *tmp_pix = static_cast<QGraphicsPixmapItem*>(this);
    tmp_scene->addItem(tmp_pix);
    setPos(1200,500);
    coordinate.setX(1200);
    coordinate.setY(500);

    attack_timer = new QTimer;
    attack_timer->start(5000);
    connect(attack_timer,SIGNAL(timeout()),this,SLOT(attack()));
    connect(attack_timer,SIGNAL(timeout()),this,SLOT(attack_mode()));

}

void thanos_son::attack()
{

    thanos_son_bullet *THANOS_SON_BULLET1 = new thanos_son_bullet;
    thanos_son_bullet *THANOS_SON_BULLET2 = new thanos_son_bullet;
    thanos_son_bullet *THANOS_SON_BULLET3 = new thanos_son_bullet;
    THANOS_SON_BULLET1->setPixmap(QPixmap(":/res/7.png").scaled(100,60));
    THANOS_SON_BULLET2->setPixmap(QPixmap(":/res/7.png").scaled(100,60));
    THANOS_SON_BULLET3->setPixmap(QPixmap(":/res/7.png").scaled(100,60));
    QGraphicsPixmapItem *pix_bullet1 = static_cast<QGraphicsPixmapItem*>(THANOS_SON_BULLET1);//need pix mapitem to access position
    QGraphicsPixmapItem *pix_bullet2 = static_cast<QGraphicsPixmapItem*>(THANOS_SON_BULLET2);
    QGraphicsPixmapItem *pix_bullet3 = static_cast<QGraphicsPixmapItem*>(THANOS_SON_BULLET3);
    THANOS_SON_BULLET1->setPos(coordinate.x()-130,coordinate.y()+65);//the point jet_bullet start
    THANOS_SON_BULLET2->setPos(coordinate.x()-100,coordinate.y()+55);
    THANOS_SON_BULLET3->setPos(coordinate.x()-100,coordinate.y()+75);
    tmp_scene->addItem(pix_bullet1);
    tmp_scene->addItem(pix_bullet2);
    tmp_scene->addItem(pix_bullet3);

    son_move_timer = new QTimer;//need to add Line this and next, or will crash(I dont know why)
    son_move_timer->start(500);
    connect(son_move_timer,SIGNAL(timeout()),THANOS_SON_BULLET1,SLOT(fly()));//control movement of jet bullet
    connect(son_move_timer,SIGNAL(timeout()),THANOS_SON_BULLET2,SLOT(fly()));
    connect(son_move_timer,SIGNAL(timeout()),THANOS_SON_BULLET3,SLOT(fly()));
}

void thanos_son::attack_mode()
{
    animate_tmr = new QTimer;
    animate_tmr->start(500);
    setPixmap(QPixmap(":/res/thanos_son3.png").scaled(280,290));
    setPos(1110,470);
    connect(animate_tmr,SIGNAL(timeout()),this,SLOT(normal_mode()));


}

void thanos_son::normal_mode()
{
    setPixmap(QPixmap(":/res/thanos_son2.png").scaled(210,240));
    setPos(1200,500);
    animate_tmr->stop();
}
