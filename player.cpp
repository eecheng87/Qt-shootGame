#include "player.h"
#include "mainwindow.h"
player::player()
{

}
player::player(QGraphicsScene *scene, MainWindow *window){

    HP=15;
    MP=15;

    hulk_exist = false;

    tmp_scene = scene;
    tmp_window = window;
}

void player::show()
{
    setPixmap(QPixmap(":/res/Iron4.png").scaled(250,250));
    QGraphicsPixmapItem *tmp_pix = static_cast<QGraphicsPixmapItem*>(this);
    tmp_pix->setZValue(1);//for iron man's z-index
    tmp_scene->addItem(tmp_pix);
    setPos(100,0);

    //set HP,MP bar
    HP_bar = new QProgressBar(tmp_window);
    coordinate = tmp_pix->pos();//get current obj(jet) position
    HP_bar->setRange(1,15);
    HP_bar->setGeometry(coordinate.x()+60,coordinate.y(),70,20);//bar's position will be update in mainwindow keypress function
    //this->hp_progress->setGeometry(100,100,70,20);
    HP_bar->setValue(15);//initialize HP
    HP_bar->setStyleSheet("QProgressBar{border-radius:30px;text-align:center;}QProgressBar::chunk{background:#F65141;}");

    MP_bar = new QProgressBar(tmp_window);

    MP_bar->setRange(1,15);
    MP_bar->setGeometry(coordinate.x()+60,coordinate.y()+30,70,20);
    MP_bar->setValue(15);//initialize
    MP_bar->setStyleSheet("QProgressBar{border-radius:30px;text-align:center;}QProgressBar::chunk{background:#21D9D2;}");
}

void player::updata_coordinate(int x,int y)
{
    coordinate.setX(coordinate.x()+x);
    coordinate.setY(coordinate.y()+y);

}

void player::update_bar()
{
    HP_bar->setGeometry(coordinate.x()+60,coordinate.y(),70,20);
    MP_bar->setGeometry(coordinate.x()+60,coordinate.y()+30,70,20);
}

int player::get_HP()
{
    return HP;
}

int player::get_MP()
{
    return MP;
}

void player::minus_HP()
{
    HP--;
    if(HP<=0)
        emit game_over();
}

void player::minus_MP()
{
    MP--;
}

void player::add_HP()
{
    if(HP<=15)
    HP++;
}

void player::gene_hulk()
{
    hulk_exist = true ;//flag to check whether exist
    myHulk = new hulk(tmp_scene,tmp_window);
    myHulk->show();//make image show out
    myHulk->update_coordinate(coordinate.x()-20,coordinate.y()-80);
    myHulk->update_hulk_pos();
    connect(myHulk,SIGNAL(change_exist_flag()),this,SLOT(chang_flag()));


}

void player::minus_ten_mp()
{
    MP = MP - 10;
}

void player::chang_flag()
{
    hulk_exist = false;
}

void player::recover()
{
     MP++;
     MP_bar->setValue(MP);
}

void player::attack_mode()
{
    setPixmap(QPixmap(":/res/Iron3.png").scaled(300,320));
    QGraphicsPixmapItem *tmp_pix = static_cast<QGraphicsPixmapItem*>(this);
    tmp_pix->setZValue(1);//for iron man's z-index
    //tmp_scene->addItem(tmp_pix);
    coordinate = tmp_pix->pos();
    tmp_pix->setPos(coordinate.x(),coordinate.y());

    //shoot_effect = new QGraphicsPixmapItem(QPixmap(":/res/explosion2.png").scaled(390,250));
    //shoot_effect->setPixmap(QPixmap(":/res/explosion2.png").scaled(100,100));
    //shoot_effect->setZValue(1);
    //shoot_effect->setPos(coordinate.x()+80,coordinate.y()-30);
    //tmp_scene->addItem(shoot_effect);

    animate_timer = new QTimer;
    animate_timer->start(200);
    connect(animate_timer,SIGNAL(timeout()),this,SLOT(normal_mode()));
    //tmp_timer->stop();
    //tmp_scene->removeItem(shoot_effect);

}

void player::normal_mode()
{
    //tmp_scene->removeItem(shoot_effect);

    setPixmap(QPixmap(":/res/Iron2.png").scaled(300,320));
    QGraphicsPixmapItem *tmp_pix = static_cast<QGraphicsPixmapItem*>(this);
    tmp_pix->setZValue(1);//for iron man's z-index
    //tmp_scene->addItem(tmp_pix);
    coordinate = tmp_pix->pos();
    tmp_pix->setPos(coordinate.x(),coordinate.y());
    animate_timer->stop();
}




