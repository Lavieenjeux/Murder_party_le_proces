#ifndef ACCUSE_H
#define ACCUSE_H

#include <QString>
#include <QVector>
#include <QSound>
#include <QDebug>
#include <time.h>
#include <iostream>

class Accuse
{
public:
    Accuse();
    Accuse(QString n, int num, QString c);

    QString get_nom();
    QString get_code();
    void set_a_vote(bool e);
    bool get_a_vote();
    void set_ecarte(bool e, int v);
    bool get_ecarte();
    void set_sauve();
    bool get_sauve();
    int get_num_vote_ecarte();
    int get_num_vote_ecarte_2();
    void set_num_vote_code_sc(int v, int e_sc);
    int get_num_vote_code_sc();
    void set_effet_sc(int e);
    int get_effet_sc();
    int get_vote_i(int i);
    int get_vote_final_i(int i);
    void remplir_vote_final(QVector <int> v);
    int get_numero();
    void ajouter_vote(int num_vote, int v);
    int get_nb_vote_contre_i(int i);
    void ajouter_vote_contre(int num_vote);
    void ajouter_vote_contre_final(int poids);
    void appel_voix(); //Appel de l'accusé par une voix
    void appeler_nom(); //Voix pour appeler le nom de l'accusé
    QString enlever_accents_et_maj(QString entree); //Met en forme les noms pour l'ouverture du fichier son
    QString ecrire_resume_vote_final();

private:
    int numero;
    QString nom;
    QString code;
    bool a_vote; //Pour savoir si l'accusé a voté ou non
    QVector <int> vote; //Contient le numéro de l'accusé contre lequel on a voté sur chacun des votes
    QVector <int> nb_vote_contre; //Contient le nombre de voix contre l'accusé sur chacun des votes
    QVector <int> vote_final; //Contient l'ordre des accusés choisis pour le vote final
    bool ecarte;
    bool sauve;
    int num_vote_ecarte;
    int num_vote_ecarte_2; //en cas d'utilisation du code de la seconde chance
    int num_vote_code_sc;
    int effet_sc;
    QSound *appel; //Appel de l'accuse
    QSound *appel_nom; //Nom de l'accuse


};

#endif // ACCUSE_H
