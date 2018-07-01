#include "bullet.h"
#include <QList>
bullet::bullet()
{
    state=0;
}
bullet::bullet(QGraphicsScene *tmp)
{
    tmp_scene = tmp;
    state = 0;
}
QGraphicsScene* bullet::tmp_scene=0;//initialize static var
void bullet::fly(){


        QList<QGraphicsItem *>colliding_items = collidingItems();
        for(int i=0, n = colliding_items.size(); i<n ; ++i){
            if(typeid(*(colliding_items[i])) == typeid(jet)){
                jet *collide_jet = static_cast<jet *>(colliding_items[i]);

                if(collide_jet->live){
                    if(collide_jet->get_HP()>0){
                        collide_jet->minus_HP();
                        collide_jet->hp_progress->setValue(collide_jet->get_HP());

                        this->scene()->removeItem(this);
                        delete this;
                        return;//important or will shut down

                    }
                    if(collide_jet->get_HP()<=0){
                        score::add_score();

                        this->scene()->removeItem(colliding_items[i]);
                        this->scene()->removeItem(this);
                        delete collide_jet->hp_progress;
                        //delete colliding_items[i];
                        delete this;
                        //return;//important or will shut down
                    }
                }
                else
                {

                }
            }


            if(typeid(*(colliding_items[i])) == typeid(thanos)){
                    thanos *collide_thanos = static_cast<thanos *>(colliding_items[i]);


                        if(collide_thanos->get_HP()>0){
                            collide_thanos->minus_HP();
                            collide_thanos->hp_progress->setValue(collide_thanos->get_HP());

                            this->scene()->removeItem(this);
                            delete this;
                            return;//important or will shut down

                        }
                        if(collide_thanos->get_HP()<=0){
                            score::add_score();

                            this->scene()->removeItem(colliding_items[i]);
                            this->scene()->removeItem(this);
                            delete collide_thanos->hp_progress;
                            delete colliding_items[i];
                            delete this;

                            return;
                        }
                }

            if(typeid(*(colliding_items[i])) == typeid(thanos_son)){
                thanos_son *collide_thanos_son = static_cast<thanos_son *>(colliding_items[i]);


                    if(collide_thanos_son->get_HP()>0){
                        collide_thanos_son->minus_HP();
                        //collide_thanos_son->hp_progress->setValue(collide_thanos_son->get_HP());

                        this->scene()->removeItem(this);
                        delete this;
                        return;//important or will shut down

                    }
                    if(collide_thanos_son->get_HP()<=0){
                        score::add_score();

                        this->scene()->removeItem(colliding_items[i]);
                        this->scene()->removeItem(this);
                       // delete collide_thanos_son->hp_progress;
                        delete colliding_items[i];
                        delete this;

                        return;
                    }
            }


        }//end of for loop
        setPos(x()+18,y());
        if(x()>1800){
            this->scene()->removeItem(this);
            delete this;
        }

}
void bullet::effect(){

}
