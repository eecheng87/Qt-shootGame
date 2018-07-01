#include "thanos_bullet.h"
#include "player.h"
#include <QList>
thanos_bullet::thanos_bullet()
{
    set_attack_mode = false;
}

void thanos_bullet::fly()
{
    if(!set_attack_mode){
       attack_mode = qrand()%3;
       set_attack_mode = true;
    }
    QList<QGraphicsItem *>colliding_items = collidingItems();
    for(int i=0, n = colliding_items.size(); i<n ; ++i){
        if(typeid(*(colliding_items[i])) == typeid(player)){
            player *collide_iron = static_cast<player *>(colliding_items[i]);

            if(collide_iron->get_HP()>0){
                collide_iron->minus_HP();
                collide_iron->HP_bar->setValue(collide_iron->get_HP());
                this->scene()->removeItem(this);
                delete this;
                return;//important or will shut down

            }
            if(collide_iron->get_HP()<=0){
                this->scene()->removeItem(colliding_items[i]);
                this->scene()->removeItem(this);
                delete collide_iron->HP_bar;
                delete colliding_items[i];
                delete this;
                return;//important or will shut down
            }
        }
    }

    switch(attack_mode){
    case 0:
        setPos(x()-120,y()-50);
        if(x()<0){
            scene()->removeItem(this);
            delete this;
        }
        break;
    case 1:
        setPos(x()-120,y());
        if(x()<0){
            scene()->removeItem(this);
            delete this;
        }
        break;
    case 2:
        setPos(x()-120,y()+50);
        if(x()<0){
            scene()->removeItem(this);
            delete this;
        }
        break;


    }



}

