#-------------------------------------------------
#
# Project created by QtCreator 2018-05-25T12:25:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = shoot_game
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    bullet.cpp \
    jet.cpp \
    jet_bullet.cpp \
    player.cpp \
    hulk.cpp \
    hulk_bullet.cpp \
    score.cpp \
    effect.cpp \
    thanos.cpp \
    thanos_bullet.cpp \
    thanos_son.cpp \
    thanos_son_bullet.cpp \
    hp_ball.cpp \
    poly_enemy.cpp

HEADERS += \
        mainwindow.h \
    bullet.h \
    jet.h \
    jet_bullet.h \
    player.h \
    hulk.h \
    hulk_bullet.h \
    score.h \
    effect.h \
    thanos.h \
    thanos_bullet.h \
    thanos_son.h \
    thanos_son_bullet.h \
    hp_ball.h \
    poly_enemy.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    res.qrc
