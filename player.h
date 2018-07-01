#ifndef PLAYER_H
#define PLAYER_H
#include<QGraphicsScene>
#include<QProgressBar>
#include<QGraphicsPixmapItem>
#include<QPointF>
#include"hulk.h"
class MainWindow;
class player: public QObject,public QGraphicsPixmapItem//must inherit pixmapitem,or cant static cast
{
    Q_OBJECT

public:
    player();
    player(QGraphicsScene*,MainWindow*);
    QGraphicsPixmapItem *iron_pix;
    QPointF coordinate;
    QProgressBar *HP_bar;
    QProgressBar *MP_bar;

    hulk *myHulk;
    void show();
    void updata_coordinate(int,int);
    void update_bar();
    int get_HP();
    int get_MP();
    void minus_HP();
    void minus_MP();
    void add_HP();
    void gene_hulk();
    void minus_ten_mp();
    bool hulk_exist;
public slots:
    void chang_flag();
    void recover();
    void attack_mode();
    void normal_mode();

signals:
    void game_over();
private:
    QGraphicsScene *tmp_scene;
    MainWindow *tmp_window;
    QTimer *animate_timer;
    QGraphicsPixmapItem *shoot_effect;



    int HP;
    int MP;

};

#endif // PLAYER_H
