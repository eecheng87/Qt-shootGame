#include "jet.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QMainWindow>
#include "mainwindow.h"
QGraphicsScene* jet::tmp_scene;//declare static variable
MainWindow* jet::tmp_window;
jet::jet(){

    HP=9;
    MP=5;
    stage=0;
}
jet::~jet()
{

};
jet::jet(QGraphicsScene *scene,MainWindow *window)
{
    HP=9;
    MP=5;
    stage=0;
    tmp_scene = scene;
    tmp_window = window;
    live=true;


}

int jet::get_HP()
{
    return HP;
}

void jet::minus_HP()
{
    HP=HP-3;
    if(HP<=0 && live){

        live=false;
        hp_progress->setVisible(false);
        emit explosion(coordinate.x(),coordinate.y());


    }
}

void jet::minus_MP()
{
    MP--;
}
void jet::incre_HP()
{
    HP++;
}
void jet::incre_MP()
{
    MP=MP+2;
}

void jet::add_bar(QGraphicsPixmapItem *tmp_pix)
{
    this->hp_progress = new QProgressBar(tmp_window);
    this->coordinate = tmp_pix->pos();//get current obj(jet) position
    this->hp_progress->setRange(1,9);
    this->hp_progress->setGeometry(this->coordinate.x()+60,this->coordinate.y()+10,70,20);
    //this->hp_progress->setGeometry(100,100,70,20);
    this->hp_progress->setValue(9);//initialize HP
    this->hp_progress->show();
    //qDebug()<<coordinate.x();
    //qDebug()<<tmp_window;
    //qDebug()<<tmp_pix;


}
void jet::move(){

    if(x()>=1400 && x()<=1700 && y()>=0 && y()<=760){//in range
        int weight = qrand()%4;

        switch(weight){

        case 0:
            setPos(x()+10,y()-10);
            coordinate.setX(x()+10);
            coordinate.setY(y()-10);
            if(live)
                hp_progress->setGeometry(x()+60,y()+10,70,20);
            break;
        case 1:
            setPos(x()+10,y()+10);
            coordinate.setX(x()+10);
            coordinate.setY(y()+10);
            if(live)
                hp_progress->setGeometry(x()+60,y()+10,70,20);
            break;
        case 2:
            setPos(x()-10,y()-10);
            coordinate.setX(x()-10);
            coordinate.setY(y()-10);
            if(live)
                hp_progress->setGeometry(x()+60,y()+10,70,20);
            break;
        case 3:
            setPos(x()-10,y()+10);
            coordinate.setX(x()-10);
            coordinate.setY(y()+10);
            if(live)
                hp_progress->setGeometry(x()+60,y()+10,70,20);
            break;
        }
    }else{//out of range
        int tmp=qrand()%650;
        setPos(1600,tmp);
        coordinate.setX(1200);
        coordinate.setY(tmp);
        if(live)
            hp_progress->setGeometry(x()+60,y()+10,70,20);
        }

}


void jet::call(){
    if(score::jet_num<=4){
        score::jet_num++;
        jet *my_jet = new jet(tmp_scene,tmp_window);
        my_jet->setPixmap(QPixmap(":/res/spaceship.png").scaled(300,150));
        my_jet->setPos(1600,qrand()%650);

        tmp_scene->addItem(static_cast<QGraphicsPixmapItem*>(my_jet));
        my_jet->pix_jet = static_cast<QGraphicsPixmapItem*>(my_jet);

        my_jet->add_bar(my_jet->pix_jet);

        jet_move_timer = new QTimer;
        jet_move_timer->start(200);
        attack_timer = new QTimer;
        attack_timer->start(1500);
        connect(jet_move_timer,SIGNAL(timeout()),my_jet,SLOT(move()));//becareful,is my_jet,instead of this
        connect(attack_timer,SIGNAL(timeout()),my_jet,SLOT(attack()));

        connect(my_jet,SIGNAL(explosion(int,int)),my_jet,SLOT(set_explo_pos(int,int)));

    }
    /*jet *my_jet = new jet(tmp_scene,tmp_window);
    my_jet->setPixmap(QPixmap(":/res/spaceship.png").scaled(300,150));
    my_jet->setPos(1600,qrand()%650);

    tmp_scene->addItem(static_cast<QGraphicsPixmapItem*>(my_jet));
    my_jet->pix_jet = static_cast<QGraphicsPixmapItem*>(my_jet);

    my_jet->add_bar(my_jet->pix_jet);

    jet_move_timer = new QTimer;
    jet_move_timer->start(200);
    attack_timer = new QTimer;
    attack_timer->start(1500);
    connect(jet_move_timer,SIGNAL(timeout()),my_jet,SLOT(move()));//becareful,is my_jet,instead of this
    connect(attack_timer,SIGNAL(timeout()),my_jet,SLOT(attack()));

    connect(my_jet,SIGNAL(explosion(int,int)),my_jet,SLOT(set_explo_pos(int,int)));*/

}
void jet::attack(){

        jet_bullet *JET_BULLET = new jet_bullet;
        JET_BULLET->setPixmap(QPixmap(":/res/jet_bullet.png").scaled(180,140));
        QGraphicsPixmapItem *pix_bullet = static_cast<QGraphicsPixmapItem*>(JET_BULLET);//need pix mapitem to access position

        JET_BULLET->setPos(coordinate.x(),coordinate.y()+50);//the point jet_bullet start
        tmp_scene->addItem(pix_bullet);

        jet_move_timer = new QTimer;//need to add Line this and next, or will crash(I dont know why)
        jet_move_timer->start(500);
        connect(jet_move_timer,SIGNAL(timeout()),JET_BULLET,SLOT(fly()));//control movement of jet bullet

}

void jet::set_explo_pos(int x, int y)
{
    X=x;
    Y=y;

    explo_effect();
}

void jet::explo_effect()
{
    effect_tmr = new QTimer;
    effect_tmr->start(500);

    setPixmap(QPixmap(":/res/explosion1").scaled(400,400));
    setPos(X,Y);
    //tmp_scene->addItem();
    connect(effect_tmr,SIGNAL(timeout()),this,SLOT(explo_effect_i()));

    //effect_tmr->stop();
}

void jet::explo_effect_i()
{

    effect_tmr = new QTimer;
    effect_tmr->start(500);
    setPixmap(QPixmap(":/res/explosion1").scaled(350,350));
    setPos(X,Y);
    //tmp_scene->addItem(explo);
    connect(effect_tmr,SIGNAL(timeout()),this,SLOT(explo_effect_ii()));

}

void jet::explo_effect_ii()
{

    effect_tmr = new QTimer;
    effect_tmr->start(500);
    setPixmap(QPixmap(":/res/explosion1").scaled(270,270));
    setPos(X,Y);
    //tmp_scene->addItem(explo);
    connect(effect_tmr,SIGNAL(timeout()),this,SLOT(explo_effect_iii()));
}

void jet::explo_effect_iii()
{
    effect_tmr = new QTimer;
    effect_tmr->start(500);
    setPixmap(QPixmap(":/res/explosion1").scaled(170,170));
    setPos(X,Y);
    //tmp_scene->addItem(explo);
    connect(effect_tmr,SIGNAL(timeout()),this,SLOT(explo_effect_iv()));
}

void jet::explo_effect_iv()
{
    effect_tmr = new QTimer;
    effect_tmr->start(500);
    setPixmap(QPixmap(":/res/explosion1").scaled(130,130));
    setPos(X,Y);
    connect(effect_tmr,SIGNAL(timeout()),this,SLOT(explo_effect_v()));
}

void jet::explo_effect_v()
{
    score::jet_num--;
    delete hp_progress;
    delete this;
    return;
}

