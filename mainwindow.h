#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QColor>
#include <QBrush>
#include <QGraphicsTextItem>
#include "bullet.h"
#include <QKeyEvent>
#include <QProgressBar>
#include <QPushButton>
#include <QProcess>
#include <QApplication>
#include "hulk.h"
#include "score.h"
#include "hp_ball.h"
#include "thanos.h"
#include"poly_enemy.h"
class player;//if dont add, compiler cant realize who is class player
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    //MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addjet();

    player *tmp_player;
    jet *my_jet;
    //jet my_jet;

signals:
    void chang_attack_pix();


public slots:
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);
    void game_over_text();
    void restart();





private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *iron_pix;
    QGraphicsPixmapItem *background;
    QTimer *timer;


};

#endif // MAINWINDOW_H
