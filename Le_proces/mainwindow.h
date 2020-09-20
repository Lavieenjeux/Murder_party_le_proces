#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QDebug>
#include <QStandardPaths>
#include <QTimer>
#include <QComboBox>
#include <QtMath>
#include <QDrag>
#include <QDropEvent>
#include <QDragMoveEvent>
#include <QMimeData>
#include <QFile>
#include <QDate>
#include <QFileDialog>
#include <QTextStream>
#include <QIODevice>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <QEventLoop>
#include <QSound>
#include <QThread>
#include <QCursor>
#include <QMessageBox>
#include "accuse.h"
#include "cadre_vote.h"


using namespace std;

class Accuse;
class Cadre_vote;

//Structure créant l'aléatoire pour random_shuffle
struct Gen {
  mt19937 g;
  Gen()
   : g(static_cast<uint32_t>(time(0)))
  {
  }
  size_t operator()(size_t n)
  {
    uniform_int_distribution<size_t> d(0, n ? n-1 : 0);
    return d(g);
  }
};


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void positionner_boutons();
    void afficher_ecran_discours();
    void afficher_compteur();
    void afficher_boutons_code_vote();
    void masquer_boutons_code_vote();
    void afficher_boutons_vote();
    void masquer_boutons_vote();
    void masquer_boutons_code_sc();
    void masquer_labels_deplacables();
    QVector<int> get_temps_vote();
    int get_temps_vote_i(int i);
    void set_temps_vote_i(int t, int i);
    int get_temps_vote_final();
    void set_temps_vote_final(int t);
    int get_temps_restant();
    void set_temps_restant(int t);
    void demarer_compte_a_rebours_intervote(int t); //le t est en secondes
    void demarer_compte_a_rebours_vote(); //temps limite de vote
    void demarer_compte_a_rebours_vote_final(); //temps limite pour le vote final
    void inter_vote(); //la méthode qui gère les intervotes
    void inter_vote_final(); //L'intervote du vote final
    void appeler_accuses(); //la méthode qui appelle les accusés
    void identifier_accuse(); //La méthode qui identifie l'accusé qui vote
    void vote_accuse(Accuse* a); //La méthode qui permet à un accusé de voter
    void vote(); //la méthode qui gère les résultats des votes
    void vote_final_accuse(Accuse* a); //La méthode qui permet à un accusé de réaliser le vote final
    void vote_final(); //la méthode qui gère les résultats du vote final
    void ajouter_vote(int p);
    void masquer_labels_deplacables_inutiles(Accuse* a);
    void valider_vote_final();
    void compter_votes_finaux(); //méthode qui compte le nombre de pts pour chaque accusé
    void ecarter_accuse(Accuse* a, int v = 0);
    void rehabiliter_accuse(Accuse* a, int v = 0);
    int determiner_ecarte();
    void decompte_final();
    void code_seconde_chance();
    void valider_code_seconde_chance();
    void effets_code_seconde_chance();
    void appuyer_bouton_annuler(int n);
    int trouver_ancien_choix(); //méthode pour l'échange d'accusés dans le vote final
    void gerer_deplacement_labels_deplacables(int n, bool a);
    void conclusion();
    void sauvegarder();
    void charger();
    void quitter();

public slots:
    void compte_a_rebours_intervote(); //compte à rebours intervote
    void fin_discours_initial();
    void fin_appel_accuses();
    void fin_temporisation();
    void fin_temps_affichage_resultats_code_sc();
    void changement_image_attente();
    void compte_a_rebours_vote(); //compte à rebours vote d'un accusé
    void fin_paroles();
    void fin_sonnerie();
    void fin_jeu(); //affiche le bouton pour quitter le jeu

private:
    Ui::MainWindow *ui;
    QString chemin_fichier_sauvegarde;
    QVector<Accuse*> accuses;
    QVector<Cadre_vote*> cadres_vote_final; //les cadres pour choisir les votes finaux
    QVector<int> temps_vote_initiaux; //contient tous les temps en secondes initiaux par vote
    QVector<int> temps_vote; //contient tous les temps en secondes par vote si modifiés dans les options
    QVector<QLabel*> labels_classement; //Contient les labels pour l'affichage du classement final
    int temps_vote_final; //contient le temps du vote final
    int num_vote;
    int nb_elimines; //nombre d'accusés éliminés
    int code_seconde_chance_utilise; //Vaut:
                                        //0 si le code de la seconde chance n'a pas été utilisé
                                        //1 si le code de la seconde chance a bien été utilisé
                                        //2 si le code de la seconde chance a mal été utilisé
                                        //3 si le code de la seconde chance n'a pas eu d'effet
                                        //4 si le code a été utilisé et les effets déjà décrits
    int accuse_code_sc; //index de l'accusé ayant utilisé le code de la seconde chance
    bool a_vote; //vaut vrai si le condamne a voté
    int numero_accuse_vote_contre; //numéro de l'accusé contre lequel on a voté
    QVector <int> ordre_vote_final;
    QCursor souris; //Variable qui sert à repositionner la souris au centre après un vote
    QEventLoop attente_vote;
    QEventLoop attente_vote_final;
    QEventLoop attente_fin_paroles;
    QEventLoop attente_fin_sonnerie;
    int temps_restant; //temps restant au timer en secondes
    int temps_restant_vote; //temps restant pour voter en secondes
    //timers
    QTimer *temps_disours_initial; //Temps du discours initial
    QTimer *temps_appel_accuses; //Temps d'appel des accusés
    QTimer *temps_intervote; //Temps avant le prochain vote
    QTimer *temps_limite_vote; //Temps limite de vote d'un joueur
    QTimer *temps_resultats; //temps d'affichage des résultats du vote
    QTimer *temps_affichage_resultats_code_sc; //temps d'affichage des résultats du code de la seconde chance
    QTimer *temps_ereur_seconde_chance; //temps d'affichage des résultats en erreur du code de la seconde chance
    QTimer *temps_animation_attente;
    //Sons du programme
    QSound *discours_initial;
    QSound *discours_initial_2;
    QSound *sonnerie;
    QSound *jingle;
    QSound *jingle_et_musique;
    QSound *fin_vote_proche;
    QSound *appel_accuses;
    QSound *remerciement;
    QSound *vote_termine;
    QSound *annonce_elimine;
    QVector<QSound*> annonce_attente_vote_suivant;
    QVector<QSound*> anonce_attente_vote_suivant_modifie;
    QSound *code_sc_bon_usage;
    QSound *code_sc_usage_inutile;
    QSound *code_sc_mauvais_usage;
    QSound *code_sc_ecarte;
    QSound *annonce_premier_sauve;
    QSound *presentation_vote_final;
    QSound *appel_suivant;
    QSound *annonce_resultats_vote_final;
    QSound *annonce_deuxieme_sauve;
    QSound *discours_conclusion;
    //Animation d'attente
    QVector<QPixmap> images_d_attente;
    int index_image;

protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

private slots:
    void on_bouton_cafard_clicked();
    void on_bouton_chacal_clicked();
    void on_bouton_chien_clicked();
    void on_bouton_cochon_clicked();
    void on_bouton_hyene_clicked();
    void on_bouton_rat_clicked();
    void on_bouton_requin_clicked();
    void on_bouton_serpent_clicked();
    void on_bouton_vautour_clicked();
    void on_bouton_valider_vote_final_clicked();
    void on_bouton_oui_clicked();
    void on_bouton_non_clicked();
    void on_bouton_ok_clicked();
    void on_bouton_demarrer_clicked();
    void on_Bouton_annuler_1_clicked();
    void on_Bouton_annuler_2_clicked();
    void on_Bouton_annuler_3_clicked();
    void on_Bouton_annuler_4_clicked();
    void on_Bouton_annuler_5_clicked();
    void on_Bouton_annuler_6_clicked();
    void on_Bouton_annuler_7_clicked();
    void on_Bouton_annuler_8_clicked();
    void on_bouton_quitter_clicked();
    void on_bouton_ok_vote_clicked();
    void on_bouton_ok_code_sc_clicked();
    void on_bouton_voter_clicked();
    void on_bouton_reporter_vote_clicked();
    void on_bouton_reporter_vote_final_clicked();
    void on_bouton_charger_clicked();
    void on_bouton_rapport_clicked();
    void on_bouton_test_clicked();
    void on_bouton_option_clicked();
};

#endif // MAINWINDOW_H
