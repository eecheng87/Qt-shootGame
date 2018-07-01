#ifndef ENEMY_H
#define ENEMY_H


class enemy
{
public:
    enemy();

    void attack();
    void minus_HP();
    int getHP();
private:
    int HP;
};

#endif // ENEMY_H
