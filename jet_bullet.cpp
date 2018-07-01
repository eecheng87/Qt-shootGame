#include "jet_bullet.h"
#include <QList>
#include "player.h"
jet_bullet::jet_bullet()
{

}
void jet_bullet::fly(){

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

    setPos(x()-120,y());
    if(x()<0){
        scene()->removeItem(this);
        delete this;
    }
}
