#include "cadre_vote.h"

Cadre_vote::Cadre_vote(QWidget * parent) : QLabel(parent)
{   
    this->setText("");
    this->setAlignment(Qt::AlignCenter);

    QFont police = this->font();
    police.setPixelSize(20);
    this->setFont(police);

    choix_accuse = 12;
    ancien_choix = 12;

    this->setProperty("style", "cadrevote");
    this->setProperty("type","deplacable");

}

void Cadre_vote::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();

    this->setProperty("style", "cadrevoteEnterEvent");
    this->style()->unpolish(this);
    this->style()->polish(this);
}

void Cadre_vote::dragLeaveEvent(QDragLeaveEvent *event)
{
    if(choix_accuse == 12)
    {
        this->setProperty("style", "cadrevote");
    }
    else
    {
        this->setProperty("style", "cadrevoteRempli");
    }
    this->style()->unpolish(this);
    this->style()->polish(this);
}


void Cadre_vote::dropEvent(QDropEvent *event)
{

    //S'il y avait déjà quelque chose où on relache la souris, il faut échanger les places des deux
    ancien_choix = choix_accuse;

    event->setDropAction(Qt::MoveAction);
    event->accept();

    this->determiner_choix_accuse(event->mimeData()->text());

}

int Cadre_vote::get_choix_accuse()
{
    return choix_accuse;
}

int Cadre_vote::get_ancien_choix()
{
    return ancien_choix;
}

void Cadre_vote::reinitialiser_ancien_choix()
{
    ancien_choix = 12;
}

void Cadre_vote::determiner_choix_accuse(QString nom)
{
    if (nom == "Cafard")
    {
        choix_accuse = 0;
        this->setText(nom);
        this->setProperty("style", "cadrevoteRempli");
        this->style()->unpolish(this);
        this->style()->polish(this);
        return;
    }

    if (nom == "Chacal")
    {
        choix_accuse = 1;
        this->setText(nom);
        this->setProperty("style", "cadrevoteRempli");
        this->style()->unpolish(this);
        this->style()->polish(this);
        return;
    }

    if (nom == "Chien")
    {
        choix_accuse = 2;
        this->setText(nom);
        this->setProperty("style", "cadrevoteRempli");
        this->style()->unpolish(this);
        this->style()->polish(this);
        return;
    }

    if (nom == "Cochon")
    {
        choix_accuse = 3;
        this->setText(nom);
        this->setProperty("style", "cadrevoteRempli");
        this->style()->unpolish(this);
        this->style()->polish(this);
        return;
    }

    if (nom == "Hyène")
    {
        choix_accuse = 4;
        this->setText(nom);
        this->setProperty("style", "cadrevoteRempli");
        this->style()->unpolish(this);
        this->style()->polish(this);
        return;
    }

    if (nom == "Rat")
    {
        choix_accuse = 5;
        this->setText(nom);
        this->setProperty("style", "cadrevoteRempli");
        this->style()->unpolish(this);
        this->style()->polish(this);
        return;
    }

    if (nom == "Requin")
    {
        choix_accuse = 6;
        this->setText(nom);
        this->setProperty("style", "cadrevoteRempli");
        this->style()->unpolish(this);
        this->style()->polish(this);
        return;
    }

    if (nom == "Serpent")
    {
        choix_accuse = 7;
        this->setText(nom);
        this->setProperty("style", "cadrevoteRempli");
        this->style()->unpolish(this);
        this->style()->polish(this);
        return;
    }

    if (nom == "Vautour")
    {
        choix_accuse = 8;
        this->setText(nom);
        this->setProperty("style", "cadrevoteRempli");
        this->style()->unpolish(this);
        this->style()->polish(this);
        return;
    }

}

void Cadre_vote::vider_cadre()
{
    choix_accuse = 12;
    this->setText("");
    this->setProperty("style", "cadrevote");
    this->style()->unpolish(this);
    this->style()->polish(this);
}
