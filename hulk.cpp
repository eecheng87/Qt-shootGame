#include "hulk.h"
#include"mainwindow.h"
hulk::hulk()
{

}

hulk::hulk(QGraphicsScene *scene, MainWindow *window)
{
    HP=10;
    tmp_scene = scene;
    tmp_window = window;
    life_timer = new QTimer;
    life_timer->start(1000);
    connect(life_timer,SIGNAL(timeout()),this,SLOT(minus_HP()));

}
void hulk::show(){

    setPixmap(QPixmap(":/res/war-machine.png").scaled(350,350));
    QGraphicsPixmapItem *tmp_pix = static_cast<QGraphicsPixmapItem*>(this);

    tmp_scene->addItem(tmp_pix);
    setPos(100,0);

    add_bar();

    attack_timer = new QTimer;//need to add Line this and next, or will crash(I dont know why)
    attack_timer->start(1000);
    connect(attack_timer,SIGNAL(timeout()),this,SLOT(attack()));
    connect(this,SIGNAL(hulk_hp_reach_zero()),this,SLOT(delete_hulk()));
}

void hulk::update_coordinate(int x,int y)
{
    coordinate.setX(coordinate.x()+x);
    coordinate.setY(coordinate.y()+y);

}


void hulk::update_hulk_pos()
{
    setPos(coordinate.x()-80,coordinate.y()-100);
}

void hulk::update_bar_pos()
{
    HP_bar->setGeometry(coordinate.x()-10,coordinate.y()-40,70,20);
}

void hulk::minus_HP()
{
    HP--;
    HP_bar->setValue(HP);
    if(HP<1){
        emit hulk_hp_reach_zero();
    }
}

void hulk::add_bar()
{
    HP_bar = new QProgressBar(tmp_window);
    HP_bar->setRange(1,10);
    HP_bar->setGeometry(coordinate.x()-10,coordinate.y()-40,70,20);
    HP_bar->setValue(10);
    HP_bar->setStyleSheet("QProgressBar{border-radius:30px;text-align:center;}QProgressBar::chunk{background:#F65141;}");
    HP_bar->show();

}

int hulk::get_HP()
{
    return HP;
}

void hulk::delete_hulk()
{
    emit change_exist_flag();
    delete HP_bar;
    this->scene()->removeItem(this);
    delete this;
    return;
}

void hulk::attack()
{

    hulk_bullet *HULK_BULLET = new hulk_bullet;
    HULK_BULLET->setPixmap(QPixmap(":/res/missile.png").scaled(250,250));
    QGraphicsPixmapItem *pix_missile = static_cast<QGraphicsPixmapItem*>(HULK_BULLET);//need pix mapitem to access position

    HULK_BULLET->setPos(coordinate.x()+140,coordinate.y()-80);//the point jet_bullet start
    tmp_scene->addItem(pix_missile);

    missile_move_timer = new QTimer;//need to add Line this and next, or will crash(I dont know why)
    missile_move_timer->start(100);
    connect(missile_move_timer,SIGNAL(timeout()),HULK_BULLET,SLOT(fly()));//control movement of jet bullet
}
