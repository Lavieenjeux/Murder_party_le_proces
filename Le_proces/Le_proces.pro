#-------------------------------------------------
#
# Project created by QtCreator 2016-09-28T22:51:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = Le_proces
TEMPLATE = app


SOURCES += main.cpp\
    fenetre_options.cpp \
        mainwindow.cpp \
    accuse.cpp \
    cadre_vote.cpp

HEADERS  += mainwindow.h \
    accuse.h \
    cadre_vote.h \
    fenetre_options.h

FORMS    += mainwindow.ui \
    fenetre_options.ui

CONFIG += resources_big

RESOURCES += \
    Apparence.qrc \
    sons.qrc

ICON = icones.icns
RC_ICONS = Icone_le_proces.ico
