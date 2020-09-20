#include "accuse.h"

Accuse::Accuse()
{
}

Accuse::Accuse(QString n, int num, QString c)
{
    nom = n;
    numero = num;
    code = c;
    ecarte = false;
    sauve = false;
    num_vote_ecarte = 0;
    num_vote_ecarte_2 = 0;
    num_vote_code_sc = 0;
    effet_sc = 0;
    a_vote = false;
    vote = QVector <int> (9);
    nb_vote_contre = QVector <int> (10);
    vote_final = QVector <int> (8);
    QString nom_fichier = this->enlever_accents_et_maj(n);

    //appel = new QSound(":/Sons/Deroulement_des_votes/Atontour"+nom_fichier+".wav");
    appel_nom = new QSound(":/Sons/Noms_d_animaux/Accuse"+nom_fichier+".wav");
}

QString Accuse::get_nom()
{
    return nom;
}

QString Accuse::get_code()
{
    return code;
}

void Accuse::set_a_vote(bool e)
{
    a_vote = e;
}

bool Accuse::get_a_vote()
{
    return a_vote;
}

void Accuse::set_ecarte(bool e, int v)
{
    ecarte = e;

    if(e)
    {
        if(num_vote_ecarte == 0)
        {
            num_vote_ecarte = v;
        }
        else
        {
            num_vote_ecarte_2 = v;
        }
    }
}

bool Accuse::get_ecarte()
{
    return ecarte;
}

void Accuse::set_sauve()
{
    sauve = true;
}

bool Accuse::get_sauve()
{
    return sauve;
}

int Accuse::get_num_vote_ecarte()
{
    return num_vote_ecarte;
}

int Accuse::get_num_vote_ecarte_2()
{
    return num_vote_ecarte_2;
}

void Accuse::set_num_vote_code_sc(int v, int e_sc)
{
    num_vote_code_sc = v;
    effet_sc = e_sc;
}

int Accuse::get_num_vote_code_sc()
{
    return num_vote_code_sc;
}

void Accuse::set_effet_sc(int e)
{
    effet_sc = e;
}

int Accuse::get_effet_sc()
{
    return effet_sc;
}

int Accuse::get_vote_i(int i)
{
    return vote[i];
}

int Accuse::get_vote_final_i(int i)
{
    return vote_final[i];
}

void Accuse::remplir_vote_final(QVector <int> v)
{
    int i;

    for(i=0; i<v.length()-1; i++)
    {
        vote_final[i] = v[i];
    }

    if( (!ecarte) || (v.length() == 1))
    {
        //Si l'accusé est sauvé, il a un vote de plus que les autres
        vote_final[v.length()-1] = v[v.length()-1];
    }
}

void Accuse::ajouter_vote(int num_vote, int v)
{
    vote[num_vote] = v;
}

int Accuse::get_nb_vote_contre_i(int i)
{
    return nb_vote_contre[i];
}

int Accuse::get_numero()
{
    return numero;
}


void Accuse::ajouter_vote_contre(int num_vote)
{
    nb_vote_contre[num_vote]++;
}

void Accuse::ajouter_vote_contre_final(int poids)
{
    nb_vote_contre[9] = nb_vote_contre[9] + poids;
}

void Accuse::appel_voix()
{
    //appel->play();
}

void Accuse::appeler_nom()
{
    appel_nom->play();
}

QString Accuse::enlever_accents_et_maj(QString entree)
{
    entree.replace(QRegExp("[éèëê]"), "e");
    entree = entree.toLower();
    return entree;
}

QString Accuse::ecrire_resume_vote_final()
{
    QString ligne_resume = "Vote de " + nom + " :;";
    int i;
    int j;
    int classement;
    int taille_vecteur;

    //Si l'accusé n'a pas voté, on met juste 15 devant son nom
    if (vote_final[0] == numero)
    {
        for(i=0; i<9; i++)
        {
            if(i == numero)
            {
                ligne_resume += "15;";
            }
            else
            {
                ligne_resume += ";";
            }
        }
    }
    else
    {
        //On ne regarde que les 7 premiers éléments, sinon on regarde les 8
        if (num_vote_ecarte == 0)
        {
            taille_vecteur = vote_final.length();
        }
        else
        {
            taille_vecteur = vote_final.length() - 1;
        }

        for(i=0; i<9; i++)
        {
            classement = 0;
            for(j=0;j<taille_vecteur; j++)
            {
                if(vote_final[j] == i)
                {
                    classement = j + 1;
                }
            }

            if(classement > 0)
            {
                ligne_resume += QString::number(classement) + ";";
            }
            else
            {
                ligne_resume += ";";
            }
        }
    }

    return ligne_resume;
}
