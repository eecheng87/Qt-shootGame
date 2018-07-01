#ifndef SCORE_H
#define SCORE_H

#include <QLabel>
#include <QLineEdit>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QFont>
class MainWindow;
class score:public QGraphicsTextItem
{
    Q_OBJECT
public:
    score();
    score(MainWindow*);
    static void add_score();
    static void add_ten_score();
    static int get_score();
    static int jet_num;
    QLabel *score_t;
    bool thanos_live;
public slots:
    void update_score();
    void distance_score();

signals:
    void call_thanos();
private:
    static int SCORE;
    MainWindow *tmp_window;
};

#endif // SCORE_H
