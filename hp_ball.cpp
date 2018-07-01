#include "hp_ball.h"
#include<QDebug>
QGraphicsScene* hp_ball::tmp_scene;//declare static variable
MainWindow* hp_ball::tmp_window;
hp_ball::hp_ball()
{

}

hp_ball::hp_ball(QGraphicsScene *scene, MainWindow *window)
{
    tmp_scene = scene;
    tmp_window = window;
}

void hp_ball::fly()
{
    QList<QGraphicsItem *>colliding_items = collidingItems();
    for(int i=0, n = colliding_items.size(); i<n ; ++i){
        if(typeid(*(colliding_items[i])) == typeid(player)){
            player *collide_iron = static_cast<player *>(colliding_items[i]);
            if(collide_iron->get_HP()<16){
                collide_iron->add_HP();
                collide_iron->HP_bar->setValue(collide_iron->get_HP());
                this->scene()->removeItem(this);
                //delete fly_tmr;
                delete this;
                return;//important or will shut down

            }

        }
    }

    setPos(x()-120,y());
    if(x()<0){
        scene()->removeItem(this);
        delete this;
    }
}

void hp_ball::call()
{
    hp_ball *my_ball = new hp_ball(tmp_scene,tmp_window);
    my_ball->setPixmap(QPixmap(":/res/HP.png").scaled(150,150));
    my_ball->setPos(1600,qrand()%650);

    tmp_scene->addItem(static_cast<QGraphicsPixmapItem*>(my_ball));
    my_ball->pixball = static_cast<QGraphicsPixmapItem*>(my_ball);

    fly_tmr = new QTimer;
    fly_tmr->start(1000);
    connect(fly_tmr,SIGNAL(timeout()),my_ball,SLOT(fly()));
}
