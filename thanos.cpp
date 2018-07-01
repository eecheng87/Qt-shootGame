#include "thanos.h"
#include"mainwindow.h"
QGraphicsScene* thanos::tmp_scene;//declare static variable
MainWindow* thanos::tmp_window;
thanos::thanos()
{

}

thanos::~thanos()
{

}

thanos::thanos(QGraphicsScene *scene, MainWindow *window)
{
    HP=10;
    tmp_scene = scene;
    tmp_window = window;
    live = true;
    son_exist = false;
}

int thanos::get_HP()
{
    return HP;
}

void thanos::minus_HP()
{
    HP=HP-3;
    if(HP<=5 && !son_exist){
        son_exist = true;
        emit signal_call_son();
    }


}

void thanos::add_bar(QGraphicsPixmapItem *tmp_pix)
{
    this->hp_progress = new QProgressBar(tmp_window);
    this->coordinate = tmp_pix->pos();//get current obj(jet) position
    this->hp_progress->setRange(1,HP);
    this->hp_progress->setGeometry(this->coordinate.x()+110,this->coordinate.y()+10,130,20);
    this->hp_progress->setValue(HP);//initialize HP
    this->hp_progress->show();
}

void thanos::call()
{
    setPixmap(QPixmap(":/res/thanos.png").scaled(350,380));
    QGraphicsPixmapItem *tmp_pix = static_cast<QGraphicsPixmapItem*>(this);
    tmp_scene->addItem(tmp_pix);
    setPos(1300,250);
    coordinate.setX(1300);
    coordinate.setY(250);

    attack_timer = new QTimer;
    attack_timer->start(1000);
    connect(attack_timer,SIGNAL(timeout()),this,SLOT(attack()));
    connect(this,SIGNAL(signal_call_son()),this,SLOT(call_son()));
    add_bar(tmp_pix);

}

void thanos::move()
{

}

void thanos::attack()
{
    thanos_bullet *THANOS_BULLET = new thanos_bullet;
    THANOS_BULLET->setPixmap(QPixmap(":/res/ROCK.png").scaled(180,140));
    QGraphicsPixmapItem *pix_bullet = static_cast<QGraphicsPixmapItem*>(THANOS_BULLET);//need pix mapitem to access position

    THANOS_BULLET->setPos(coordinate.x(),coordinate.y()+50);//the point jet_bullet start
    tmp_scene->addItem(pix_bullet);

    thanos_move_timer = new QTimer;//need to add Line this and next, or will crash(I dont know why)
    thanos_move_timer->start(500);
    connect(thanos_move_timer,SIGNAL(timeout()),THANOS_BULLET,SLOT(fly()));//control movement of jet bullet
}
void thanos::call_son(){

    thanos_son *my_son = new thanos_son(tmp_scene,tmp_window);
    my_son->call();
}
