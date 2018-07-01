#include "score.h"
#include "mainwindow.h"
#include<QFontDatabase>
#include<QDebug>
int score::SCORE;
score::score()
{
    SCORE=0;
    setPlainText(QString("Score:")+ QString::number(SCORE));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));

}

score::score(MainWindow *window)
{
    SCORE = 0;
    tmp_window = window;
    thanos_live = false;
    //score_text = new QLabel(tmp_window);
    //score_text->setGeometry(200,200,60,20);
    //score_text->setText(QString::number(SCORE));
    //score_text->setText("tset");
    //score_text->show();
    setPlainText(QString("Score")+ QString::number(SCORE));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));

}

void score::add_score()
{
    SCORE = SCORE + 1000;
}

void score::add_ten_score()
{
    SCORE = SCORE + 100;
}

int score::get_score()
{
    return SCORE;
}

void score::update_score()
{
    setPlainText(QString("Score")+":"+ QString::number(SCORE));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("Times [Adobe]",16));
    if(SCORE>=1000 && !thanos_live){
        emit call_thanos();
        thanos_live=true;


    }

}//"Times [Adobe]", "Times [Cronyx]", "Palatino".

void score::distance_score()
{
    SCORE = SCORE + 10;
}
