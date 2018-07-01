#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "jet.h"
#include "player.h"
#include <QDebug>
#include <QObject>
#include <QGraphicsItem>

int score::jet_num=0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(0,0,2000,800)),
    timer(new QTimer)
{

    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    //set background image
    background = new QGraphicsPixmapItem(QPixmap(":/res/back.jpg").scaled(1900,870));
    scene->addItem(background);
    background->setPos(0,0);

    score *score_text = new score();
    scene->addItem(score_text);

    timer->start(10);
    QTimer *current_score_timer = new QTimer;
    current_score_timer->start(1000);
    connect(current_score_timer,SIGNAL(timeout()),score_text,SLOT(distance_score()));
    connect(current_score_timer,SIGNAL(timeout()),score_text,SLOT(update_score()));

    thanos *my_thanos = new thanos(scene,this);
    //thanos my_thanos(scene,this);

   // connect(score_text,SIGNAL(call_thanos()),my_thanos,SLOT(call()));

    player *iron_man = new player(scene,this);
    tmp_player = iron_man;
    iron_man->show();
    iron_pix = static_cast<QGraphicsPixmapItem*>(iron_man);
    //iron_man->gene_hulk();
    //tmp_player->myHulk->add_bar();
    //player = new QGraphicsPixmapItem(QPixmap(":/res/normalshoot.png").scaled(200,200));
    //scene->addItem(player);
    //player->setPos(100,0);
    connect(this,SIGNAL(chang_attack_pix()),iron_man,SLOT(attack_mode()));

    connect(iron_man,SIGNAL(game_over()),this,SLOT(game_over_text()));
    connect(current_score_timer,SIGNAL(timeout()),iron_man,SLOT(recover()));
    //start to add monster
    QTimer *jet_time = new QTimer;
    jet_time->start(3000);
    my_jet = new jet(scene,this);
    //jet my_jet(scene,this);

    poly_enemy *my_poly = my_thanos;
    connect(score_text,SIGNAL(call_thanos()),my_poly,SLOT(call()));
    poly_enemy *my_poly2 = my_jet;
    connect(jet_time,SIGNAL(timeout()),my_poly2,SLOT(call()));

    hp_ball *tmp_ball = new hp_ball(scene,this);
    connect(jet_time,SIGNAL(timeout()),tmp_ball,SLOT(call()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::keyPressEvent(QKeyEvent *e){

    switch(e->key()){
    case Qt::Key_W:
        iron_pix->setPos(iron_pix->x(),iron_pix->y()-10);
        tmp_player->updata_coordinate(0,-10);
        tmp_player->update_bar();
        if(tmp_player->hulk_exist){
            tmp_player->myHulk->update_coordinate(0,-10);
            tmp_player->myHulk->update_hulk_pos();
            tmp_player->myHulk->update_bar_pos();
        }
        break;
    case Qt::Key_S:
        iron_pix->setPos(iron_pix->x(),iron_pix->y()+10);
        tmp_player->updata_coordinate(0,10);
        tmp_player->update_bar();
        if(tmp_player->hulk_exist){
            tmp_player->myHulk->update_coordinate(0,10);
            tmp_player->myHulk->update_hulk_pos();
            tmp_player->myHulk->update_bar_pos();
        }
        break;
    case Qt::Key_A:
        iron_pix->setPos(iron_pix->x()-10,iron_pix->y());
        tmp_player->updata_coordinate(-10,0);
        tmp_player->update_bar();
        if(tmp_player->hulk_exist){
            tmp_player->myHulk->update_coordinate(-10,0);
            tmp_player->myHulk->update_hulk_pos();
            tmp_player->myHulk->update_bar_pos();
        }
        break;
    case Qt::Key_D:
        iron_pix->setPos(iron_pix->x()+10,iron_pix->y());
        tmp_player->updata_coordinate(10,0);
        tmp_player->update_bar();
        if(tmp_player->hulk_exist){
            tmp_player->myHulk->update_coordinate(10,0);
            tmp_player->myHulk->update_hulk_pos();
            tmp_player->myHulk->update_bar_pos();
        }
        break;
    case Qt::Key_X://for "HULK" skill!
        if(tmp_player->get_MP()>=15  && !tmp_player->hulk_exist){
            tmp_player->gene_hulk();
            //tmp_player->myHulk->add_bar();
            tmp_player->minus_ten_mp();
            tmp_player->MP_bar->setValue(tmp_player->get_MP());
        }
        break;
    }
}
void MainWindow::mousePressEvent(QMouseEvent *e){

    bullet *b = new bullet;

    emit chang_attack_pix();
    //generate new obj
    b->setPixmap(QPixmap(":/res/iron_bullet.png").scaled(300,150));
    b->setPos(iron_pix->x() + iron_pix->pixmap().width() -100 , iron_pix->y()+iron_pix->pixmap().height()/2 -150);
    b->connect(timer,SIGNAL(timeout()),b,SLOT(fly()));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(b));


    b->effect_timer = new QTimer;
    b->effect_timer->start(500);
    //connect(b->effect_timer,SIGNAL(timeout()),b,SLOT(effect()));

}

void MainWindow::game_over_text()
{
    QGraphicsRectItem *panel = new QGraphicsRectItem(300,400,900,300);
    QBrush brush;
    QGraphicsTextItem *text = new QGraphicsTextItem("Game is over,push and button to quit");
    QPushButton *my_btn = new QPushButton("play again",this);
    my_btn->setGeometry(400,450,100,70);
    my_btn->show();
    text->setPos(670,430);
    brush.setColor(Qt::gray);
    panel->setBrush(brush);
    scene->addItem(text);
    scene->addItem(panel);
    connect(my_btn,SIGNAL(clicked()),this,SLOT(restart()));
}

void MainWindow::restart()
{
    QProcess::startDetached(QApplication::applicationFilePath());
    exit(12);
}







