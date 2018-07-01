#include "hulk_bullet.h"
#include "hulk.h"
#include "jet.h"
hulk_bullet::hulk_bullet()
{

}

void hulk_bullet::fly()
{
    QList<QGraphicsItem *>colliding_items = collidingItems();
/*    for(int i=0, n = colliding_items.size(); i<n ; ++i){
        if(typeid(*(colliding_items[i])) == typeid(hulk)){
            hulk *collide_hulk = static_cast<hulk *>(colliding_items[i]);

            if(collide_hulk->get_HP()>0){
                collide_hulk->minus_HP();
                collide_hulk->HP_bar->setValue(collide_hulk->get_HP());

                this->scene()->removeItem(this);
                delete this;
                return;//important or will shut down

            }
            if(collide_hulk->get_HP()<=0){}
        }
    }*/
    //QList<QGraphicsItem *>colliding_items = collidingItems();
    for(int i=0, n = colliding_items.size(); i<n ; ++i){
        if(typeid(*(colliding_items[i])) == typeid(jet)){
            jet *collide_jet = static_cast<jet *>(colliding_items[i]);

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
                delete colliding_items[i];
                delete this;
                return;//important or will shut down
            }
        }
    }
    setPos(x()+50,y());
    if(x()>1800){
        this->scene()->removeItem(this);
        delete this;
    }

}
