#ifndef CADRE_VOTE_H
#define CADRE_VOTE_H

#include <QFrame>
#include <QDebug>
#include <QLabel>
#include <QDrag>
#include <QString>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QMimeData>
#include <QPalette>
#include <QStyleOption>
#include <QPainter>


class Cadre_vote : public QLabel
{

private:
    int choix_accuse;
    int ancien_choix; //Variable pour gérer l'échange d'accusés

public:
    Cadre_vote(QWidget * parent);
    int get_choix_accuse();
    int get_ancien_choix();
    void reinitialiser_ancien_choix();
    void determiner_choix_accuse(QString nom);
    void vider_cadre();

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dropEvent(QDropEvent *event);

};

#endif // CADRE_VOTE_H
