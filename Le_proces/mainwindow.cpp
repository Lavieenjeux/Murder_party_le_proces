#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fenetre_options.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    chemin_fichier_sauvegarde = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);

    QDir d{chemin_fichier_sauvegarde};
    d.mkpath(d.absolutePath());

    chemin_fichier_sauvegarde = chemin_fichier_sauvegarde + "/sauvegarde.txt";

    setAcceptDrops(true);

    cadres_vote_final.push_back(ui->cadre_1);
    cadres_vote_final.push_back(ui->cadre_2);
    cadres_vote_final.push_back(ui->cadre_3);
    cadres_vote_final.push_back(ui->cadre_4);
    cadres_vote_final.push_back(ui->cadre_5);
    cadres_vote_final.push_back(ui->cadre_6);
    cadres_vote_final.push_back(ui->cadre_7);
    cadres_vote_final.push_back(ui->cadre_8);

    labels_classement.push_back(ui->label_classement_1);
    labels_classement.push_back(ui->label_classement_2);
    labels_classement.push_back(ui->label_classement_3);
    labels_classement.push_back(ui->label_classement_4);
    labels_classement.push_back(ui->label_classement_5);
    labels_classement.push_back(ui->label_classement_6);
    labels_classement.push_back(ui->label_classement_7);
    labels_classement.push_back(ui->label_classement_8);

//-----------------------affichage des labels et des boutons---------------------------------------------

    //Classe pour la feuille de style
    ui->bouton_cafard->setProperty("style", "boutonvote");
    ui->bouton_chacal->setProperty("style", "boutonvote");
    ui->bouton_chien->setProperty("style", "boutonvote");
    ui->bouton_cochon->setProperty("style", "boutonvote");
    ui->bouton_hyene->setProperty("style", "boutonvote");
    ui->bouton_rat->setProperty("style", "boutonvote");
    ui->bouton_requin->setProperty("style", "boutonvote");
    ui->bouton_serpent->setProperty("style", "boutonvote");
    ui->bouton_vautour->setProperty("style", "boutonvote");

    ui->bouton_ok->setProperty("style", "boutonok");
    ui->bouton_ok_vote->setProperty("style", "boutonok");
    ui->bouton_ok_code_sc->setProperty("style", "boutonok");
    ui->bouton_oui->setProperty("style", "boutonok");
    ui->bouton_non->setProperty("style", "boutonok");

    ui->Bouton_annuler_1->setProperty("style", "boutonok");
    ui->Bouton_annuler_2->setProperty("style", "boutonok");
    ui->Bouton_annuler_3->setProperty("style", "boutonok");
    ui->Bouton_annuler_4->setProperty("style", "boutonok");
    ui->Bouton_annuler_5->setProperty("style", "boutonok");
    ui->Bouton_annuler_6->setProperty("style", "boutonok");
    ui->Bouton_annuler_7->setProperty("style", "boutonok");
    ui->Bouton_annuler_8->setProperty("style", "boutonok");

    ui->label_cafard_deplacable->setProperty("style", "labeldeplacable");
    ui->label_chacal_deplacable->setProperty("style", "labeldeplacable");
    ui->label_chien_deplacable->setProperty("style", "labeldeplacable");
    ui->label_cochon_deplacable->setProperty("style", "labeldeplacable");
    ui->label_hyene_deplacable->setProperty("style", "labeldeplacable");
    ui->label_rat_deplacable->setProperty("style", "labeldeplacable");
    ui->label_requin_deplacable->setProperty("style", "labeldeplacable");
    ui->label_serpent_deplacable->setProperty("style", "labeldeplacable");
    ui->label_vautour_deplacable->setProperty("style", "labeldeplacable");

    ui->label_cafard_deplacable->setProperty("type", "deplacable");
    ui->label_chacal_deplacable->setProperty("type", "deplacable");
    ui->label_chien_deplacable->setProperty("type", "deplacable");
    ui->label_cochon_deplacable->setProperty("type", "deplacable");
    ui->label_hyene_deplacable->setProperty("type", "deplacable");
    ui->label_rat_deplacable->setProperty("type", "deplacable");
    ui->label_requin_deplacable->setProperty("type", "deplacable");
    ui->label_serpent_deplacable->setProperty("type", "deplacable");
    ui->label_vautour_deplacable->setProperty("type", "deplacable");

    //Suppression du focus des QLineEdit
    ui->ligne_code->setAttribute(Qt::WA_MacShowFocusRect,0);
    ui->ligne_code_sc->setAttribute(Qt::WA_MacShowFocusRect,0);
    ui->ligne_code_sc_2->setAttribute(Qt::WA_MacShowFocusRect,0);

    //Les boutons du vote final ne doivent pas entrainer un recalul du layout quand ils apparaissent ou disparaissent
    QSizePolicy sp_retain = ui->label_cafard_deplacable->sizePolicy();
    sp_retain.setRetainSizeWhenHidden(true);

    ui->label_cafard_deplacable->setSizePolicy(sp_retain);
    ui->label_chacal_deplacable->setSizePolicy(sp_retain);
    ui->label_chien_deplacable->setSizePolicy(sp_retain);
    ui->label_cochon_deplacable->setSizePolicy(sp_retain);
    ui->label_hyene_deplacable->setSizePolicy(sp_retain);
    ui->label_rat_deplacable->setSizePolicy(sp_retain);
    ui->label_requin_deplacable->setSizePolicy(sp_retain);
    ui->label_serpent_deplacable->setSizePolicy(sp_retain);
    ui->label_vautour_deplacable->setSizePolicy(sp_retain);

    QSizePolicy sp_retain_2 = ui->label_vote_invalide->sizePolicy();
    sp_retain_2.setRetainSizeWhenHidden(true);

    ui->label_vote_invalide->setSizePolicy(sp_retain_2);

    QSizePolicy sp_retain_3 = labels_classement[0]->sizePolicy();
    sp_retain_3.setRetainSizeWhenHidden(true);

    //Masquaqe des labels classement
    for (int i=0; i<labels_classement.length(); i++)
    {
        labels_classement[i]->setSizePolicy(sp_retain_3);
        labels_classement[i]->setVisible(false);
    }

    //Les labels de résultat ne doivent pas entrainer un recalul du layout quand ils apparaissent ou disparaissent
    QSizePolicy sp_retain_4 = ui->label_resultats->sizePolicy();
    sp_retain_4.setRetainSizeWhenHidden(true);

    ui->label_resultats->setSizePolicy(sp_retain_4);

    QSizePolicy sp_retain_5 = ui->label_presentation_resultats->sizePolicy();
    sp_retain_5.setRetainSizeWhenHidden(true);

    ui->label_presentation_resultats->setSizePolicy(sp_retain_5);

    //Affichage du menu
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_intervote->setCurrentIndex(0);

//----------------------------------------------------------------------------------------------

// Déclaration des Timer

    //Temps discours initial
    temps_disours_initial = new QTimer(this);
    temps_disours_initial->setInterval(233000); //3 min 53s
    connect(temps_disours_initial, SIGNAL(timeout()), this, SLOT(fin_discours_initial()));

    //Temps appel accusés
    temps_appel_accuses = new QTimer(this);
    temps_appel_accuses->setInterval(35000); //35 secondes
    connect(temps_appel_accuses, SIGNAL(timeout()), this, SLOT(fin_appel_accuses()));


    //Temps intervote
    temps_intervote = new QTimer(this);
    temps_intervote->setInterval(1000); // Une seconde car l'affichage change toutes les secondes
    connect(temps_intervote, SIGNAL(timeout()), this, SLOT(compte_a_rebours_intervote()));

    temps_restant = 0;
    temps_restant_vote = 30;

    //Temps limite de vote
    temps_limite_vote = new QTimer(this);
    temps_limite_vote->setInterval(1000); // Une seconde car l'affichage change toutes les secondes
    connect(temps_limite_vote, SIGNAL(timeout()), this, SLOT(compte_a_rebours_vote()));

    // Temporisation de résultats
    temps_resultats = new QTimer(this);
    temps_resultats->setInterval(8000); //8 secondes
    connect(temps_resultats, SIGNAL(timeout()), this, SLOT(fin_temporisation()));

    // Temps affichage résultats du code de la seconde chance
    temps_affichage_resultats_code_sc = new QTimer(this);
    temps_affichage_resultats_code_sc->setInterval(5000); //5 secondes
    connect(temps_affichage_resultats_code_sc, SIGNAL(timeout()), this, SLOT(fin_temps_affichage_resultats_code_sc()));

    temps_ereur_seconde_chance = new QTimer(this);
    temps_ereur_seconde_chance->setInterval(2000); //2 secondes
    connect(temps_ereur_seconde_chance, SIGNAL(timeout()), this, SLOT(fin_temps_affichage_resultats_code_sc()));


    //Temps affichage des images de l'animation
    temps_animation_attente = new QTimer(this);
    temps_animation_attente->setInterval(150);
    connect(temps_animation_attente, SIGNAL(timeout()), this, SLOT(changement_image_attente()));

     num_vote = 0;
     nb_elimines = 0;
     numero_accuse_vote_contre = 10;
     ordre_vote_final = QVector <int> (8);

     code_seconde_chance_utilise = 0;

    souris = cursor(); //La variable souris contient le curseur

//Initialisation des vecteurs de temps de vote (les temps sont en secondes)

     temps_vote.push_back(1500);
     temps_vote.push_back(1200);
     temps_vote.push_back(1200);
     temps_vote.push_back(900);
     temps_vote.push_back(900);
     temps_vote.push_back(600);
     temps_vote.push_back(600);
     temps_vote.push_back(600);
     temps_vote.push_back(600);

     temps_vote_initiaux.push_back(1500);
     temps_vote_initiaux.push_back(1200);
     temps_vote_initiaux.push_back(1200);
     temps_vote_initiaux.push_back(900);
     temps_vote_initiaux.push_back(900);
     temps_vote_initiaux.push_back(600);
     temps_vote_initiaux.push_back(600);
     temps_vote_initiaux.push_back(600);
     temps_vote_initiaux.push_back(600);

     temps_vote_final = 1200;

//--------------------------------------------------------------------------------

//Initialisation des accusés
        QString n("Cafard");
        QString c("arsenic67");
        Accuse* a_1 = new Accuse(n, 0, c);
        accuses.push_back(a_1);

        n = "Chacal";
        c = "curare32";
        Accuse* a_2 = new Accuse(n, 1, c);
        accuses.push_back(a_2);

        n = "Chien";
        c = "cyanure15";
        Accuse* a_3 = new Accuse(n, 2, c);
        accuses.push_back(a_3);

        n = "Cochon";
        c = "belladone46";
        Accuse* a_4 = new Accuse(n, 3, c);
        accuses.push_back(a_4);

        n = "Hyène";
        c = "ricine84";
        Accuse* a_5 = new Accuse(n, 4, c);
        accuses.push_back(a_5);

        n = "Rat";
        c = "thallium93";
        Accuse* a_6 = new Accuse(n, 5, c);
        accuses.push_back(a_6);

        n = "Requin";
        c = "muscarine71";
        Accuse* a_7 = new Accuse(n, 6, c);
        accuses.push_back(a_7);

        n = "Serpent";
        c = "sarin28";
        Accuse* a_8 = new Accuse(n, 7, c);
        accuses.push_back(a_8);

        n = "Vautour";
        c = "aconit59";
        Accuse* a_9 = new Accuse(n, 8, c);
        accuses.push_back(a_9);

//--------------Initialisation du ComboBox du code de la seconde chance----------------------
        ui->comboBox_code_seconde_chance->addItem("");
        for(int i=0; i<accuses.length(); i++)
        {
            ui->comboBox_code_seconde_chance->addItem(accuses[i]->get_nom(),i);
        }

//----------Initialisation des sons-----------
        discours_initial = new QSound(":/Sons/Explications_generales/Jeumeurtrierintroduction.wav");
        discours_initial_2 = new QSound(":/Sons/Explications_generales/Presentationpremiervote.wav");
        sonnerie = new QSound(":/Sons/Appels_pour_les_votes/Sonnerie.wav");
        jingle = new QSound(":/Sons/Explications_generales/Jingle.wav");
        fin_vote_proche = new QSound(":/Sons/Appels_pour_les_votes/4minpourvoter.wav");
        jingle_et_musique = new QSound(":/Sons/Explications_generales/Jingleetmusique.wav");
        remerciement = new QSound(":/Sons/Deroulement_des_votes/Voteprisencompte.wav");
        annonce_elimine = new QSound(":/Sons/Resultats_des_votes/Eliminevoteclassique.wav");

        code_sc_bon_usage = new QSound(":/Sons/Code_de_la_seconde_chance/Codesecondechancebonusage.wav");
        code_sc_usage_inutile = new QSound(":/Sons/Code_de_la_seconde_chance/Codesecondechanceinutileusage.wav");
        code_sc_mauvais_usage = new QSound(":/Sons/Code_de_la_seconde_chance/Codesecondechancemauvaisusage.wav");
        code_sc_ecarte = new QSound(":/Sons/Code_de_la_seconde_chance/Eliminecodesecondechance.wav");

        for(int i=0; i<accuses.length(); i++)
        {
            QSound *lancement_vote = new QSound(":/Sons/Deroulement_des_votes/Lancementvote"+QString::number(i+1)+".wav");
            annonce_attente_vote_suivant.push_back(lancement_vote);
        }

        QSound *attente_modifie_1 = new QSound(":/Sons/Appels_pour_les_votes/20minavantvote.wav");
        QSound *attente_modifie_2 = new QSound(":/Sons/Appels_pour_les_votes/15minavantvote.wav");
        QSound *attente_modifie_3 = new QSound(":/Sons/Appels_pour_les_votes/10minavantvote.wav");

        anonce_attente_vote_suivant_modifie.push_back(attente_modifie_1);
        anonce_attente_vote_suivant_modifie.push_back(attente_modifie_2);
        anonce_attente_vote_suivant_modifie.push_back(attente_modifie_3);

        annonce_premier_sauve = new QSound(":/Sons/Resultats_des_votes/Annoncepremiersauve.wav");
        presentation_vote_final = new QSound(":/Sons/Explications_generales/Presentationvotefinal.wav");

        appel_accuses = new QSound(":/Sons/Appels_pour_les_votes/Appelvote.wav");

        annonce_resultats_vote_final = new QSound(":/Sons/Resultats_des_votes/Resultatvotefinal.wav");
        annonce_deuxieme_sauve = new QSound(":/Sons/Resultats_des_votes/Annoncedeuxiemesauve.wav");

        discours_conclusion = new QSound(":/Sons/Explications_generales/Jeumeurtrierconclusion.wav");

//----------Initialisation de l'animation d'attente-----------
        QPixmap image;

        for(int i = 0; i<30; i++)
        {
            image = QPixmap(":/Apparence/Images du fond animé/Fond animé"+QString::number(i+1)+".png");
            images_d_attente.push_back(image);
        }

        ui->label_image->setPixmap(images_d_attente[0]);
        ui->label_image->setScaledContents(true);
        index_image = 0;
}

void MainWindow::positionner_boutons()
{
    int i;

    //gestion des cadres finaux
    for(i = 0; i<cadres_vote_final.length(); i++)
    {
        //les cadres pour le vote final doivent accepter les dropEvent
        cadres_vote_final[i]->setAcceptDrops(true);
    }

    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_intervote->setCurrentIndex(0);
}

void MainWindow::afficher_ecran_discours()
{
    ui->stackedWidget->setCurrentIndex(6);
    temps_animation_attente->start();
}

void MainWindow::afficher_compteur()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget_intervote->setCurrentIndex(0);
}

void MainWindow::afficher_boutons_code_vote()
{
    ui->ligne_code->setFocus();

    ui->stackedWidget_intervote->setCurrentIndex(1);
}

void MainWindow::masquer_boutons_code_vote()
{
    ui->ligne_code->setText("");
    this->setFocus();

    ui->stackedWidget_intervote->setCurrentIndex(0);
}

void MainWindow::afficher_boutons_vote()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::masquer_boutons_vote()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget_intervote->setCurrentIndex(0);
}

void MainWindow::masquer_boutons_code_sc()
{

    ui->comboBox_code_seconde_chance->setCurrentIndex(0);
    ui->ligne_code_sc_2->setText("");
    ui->ligne_code_sc->setText("");

    this->setFocus();
    ui->stackedWidget_intervote->setCurrentIndex(0);
}

void MainWindow::masquer_labels_deplacables()
{

    ui->label_cafard_deplacable->setVisible(true);
    ui->label_chacal_deplacable->setVisible(true);
    ui->label_chien_deplacable->setVisible(true);
    ui->label_cochon_deplacable->setVisible(true);
    ui->label_hyene_deplacable->setVisible(true);
    ui->label_rat_deplacable->setVisible(true);
    ui->label_requin_deplacable->setVisible(true);
    ui->label_serpent_deplacable->setVisible(true);
    ui->label_vautour_deplacable->setVisible(true);

    for(int i = 0; i<cadres_vote_final.length(); i++)
    {
        cadres_vote_final[i]->vider_cadre();
    }
}

QVector<int> MainWindow::get_temps_vote()
{
    return temps_vote;
}

int MainWindow::get_temps_vote_i(int i)
{
    return temps_vote[i];
}

void MainWindow::set_temps_vote_i(int t, int i)
{
    temps_vote[i] = t;
}

int MainWindow::get_temps_vote_final()
{
    return temps_vote_final;
}

void MainWindow::set_temps_vote_final(int t)
{
    temps_vote_final = t;
}

int MainWindow::get_temps_restant()
{
    return temps_restant;
}

void MainWindow::set_temps_restant(int t)
{
    temps_restant = t;
}

void MainWindow::demarer_compte_a_rebours_intervote(int t)
{
    temps_restant = t;

    QString minutes = QString("%1").arg(temps_restant/60, 2, 10, QChar('0'));
    QString secondes = QString("%1").arg(temps_restant%60, 2, 10, QChar('0'));
    ui->compteur_temps->display(minutes + ":" + secondes);

    temps_intervote->start();
}

void MainWindow::demarer_compte_a_rebours_vote()
{
    //Temps limite a disposition de l'accusé pour le vote
    temps_restant_vote = qMin(30, temps_restant);

    QString minutes = QString("%1").arg(temps_restant_vote/60, 2, 10, QChar('0'));
    QString secondes = QString("%1").arg(temps_restant_vote%60, 2, 10, QChar('0'));
    ui->compteur_temps_vote->display(minutes + ":" + secondes);

    temps_limite_vote->start();
}

void MainWindow::demarer_compte_a_rebours_vote_final()
{
    //Temps limite a disposition de l'accusé pour le vote
    temps_restant_vote = qMin(90, temps_restant);

    QString minutes = QString("%1").arg(temps_restant_vote/60, 2, 10, QChar('0'));
    QString secondes = QString("%1").arg(temps_restant_vote%60, 2, 10, QChar('0'));
    ui->compteur_temps_vote_final->display(minutes + ":" + secondes);

    temps_limite_vote->start();
}

void MainWindow::inter_vote()
{
    ui->label_phase->setText("VOTE " + QString::number(num_vote));
    ui->label_fin_vote->setText("Fin du vote " + QString::number(num_vote) + " dans");
    this->masquer_boutons_vote();
    this->afficher_compteur();
    this->demarer_compte_a_rebours_intervote(temps_vote[num_vote-1]);
}

void MainWindow::inter_vote_final()
{
    ui->label_phase->setText("VOTE FINAL");
    this->masquer_boutons_vote();
    this->afficher_compteur();
    this->demarer_compte_a_rebours_intervote(temps_vote_final);
}

void MainWindow::appeler_accuses()
{
    temps_limite_vote->stop();
    attente_vote.quit();

    this->masquer_labels_deplacables();
    this->masquer_boutons_code_sc();
    this->masquer_boutons_code_vote();

    if (nb_elimines == accuses.length() - 1)
    {
        ui->label_annonce_resultats->setText("VOTE FINAL");
    }
    else
    {
        ui->label_annonce_resultats->setText("VOTE " + QString::number(num_vote));
    }

    ui->label_presentation_resultats->setText("Le vote est maintenant terminé.");
    ui->label_resultats->setText("Accusés, veuillez rejoindre vos places.");

    ui->stackedWidget->setCurrentIndex(2);

    sonnerie->play();
    QTimer::singleShot(6000, this, SLOT(fin_sonnerie()));
    attente_fin_sonnerie.exec();

    appel_accuses->play();
    temps_appel_accuses->start();
}

void MainWindow::identifier_accuse()
{
    this->afficher_boutons_code_vote();
}

void MainWindow::vote_accuse(Accuse *a)
{
    this->masquer_boutons_code_vote();

    if(!a->get_a_vote()) //Si l'accusé n'a pas voté
    {
        a_vote = false;

        //Affichage des boutons de vote
        ui->stackedWidget->setCurrentIndex(3);

        //Demande à l'accusé de choisir son vote
        ui->label_demande_vote->setText(a->get_nom() + ", qui souhaites-tu écarter ?");


        //démarage du temps de vote
        this->demarer_compte_a_rebours_vote();

        //Attente du vote
        attente_vote.exec();

        //Si le vote a été coupé par la fin du temps, on ne finit pas la fonction
        if(temps_appel_accuses->isActive())
        {
            return;
        }

        //Une fois le vote terminé, on masque le compteur et les boutons
        this->masquer_boutons_vote();

        //Si l'accusé a voté, on le remercie, sinon on ne fait rien
        if(a_vote)
        {
            //On compte le vote de l'accusé
            a->set_a_vote(true);
            a->ajouter_vote(num_vote-1,numero_accuse_vote_contre);

            numero_accuse_vote_contre = 10;

            //Mise au milieu de la souris pour masquer le vote
            souris.setPos(this->width() / 2, this->height() / 2);
            setCursor(souris);

            ui->stackedWidget_intervote->setCurrentIndex(5);
            ui->label_remerciement->setText(a->get_nom() + " merci d'avoir voté.");

            QTimer::singleShot(2000, this, SLOT(fin_paroles()));
            attente_fin_paroles.exec();

            ui->stackedWidget_intervote->setCurrentIndex(0);

            if(temps_appel_accuses->isActive())
            {
                return;
            }
        }
    }
    else //S'il a déjà voté on lui dit et on ne fait rien
    {
        ui->stackedWidget_intervote->setCurrentIndex(5);
        ui->label_remerciement->setText("Tu as déjà voté !");

        QTimer::singleShot(2000, this, SLOT(fin_paroles()));
        attente_fin_paroles.exec();
        this->masquer_boutons_code_vote();

    }

}

void MainWindow::vote()
{
    int i;

    //Si un accusé n'a pas voté, le vote se retourne contre lui
    for(i=0; i<accuses.length(); i++)
    {
        if(accuses[i]->get_a_vote())
        {
            //S'il a voté, on réinitialise juste la valeur
            accuses[i]->set_a_vote(false);
        }
        else
        {
            //Sinon, on le fait voter contre lui-même
            accuses[i]->ajouter_vote_contre(num_vote - 1);
            accuses[i]->ajouter_vote(num_vote-1,accuses[i]->get_numero());
        }
    }

    //Si le code de la seconde chance a été utilisé, il faut faire les annonces correspondantes
    if(code_seconde_chance_utilise != 0)
    {
        switch (code_seconde_chance_utilise)
        {
            case 1:
            // Le code a été utilisé à bon escient
            jingle->play();
            QTimer::singleShot(2500, this, SLOT(fin_paroles()));
            attente_fin_paroles.exec();

            ui->label_presentation_resultats->setText(accuses[accuse_code_sc]->get_nom());
            ui->label_resultats->setVisible(false);
            ui->label_resultats->setText("est réhabilité grâce au code de la seconde chance.");

            accuses[accuse_code_sc]->appeler_nom();
            QTimer::singleShot(1000, this, SLOT(fin_paroles()));
            attente_fin_paroles.exec();

            ui->label_resultats->setVisible(true);

            code_sc_bon_usage->play();
            QTimer::singleShot(16000, this, SLOT(fin_paroles()));
            attente_fin_paroles.exec();

            this->rehabiliter_accuse(accuses[accuse_code_sc]);
            accuses[accuse_code_sc]->set_num_vote_code_sc(num_vote, code_seconde_chance_utilise);
            code_seconde_chance_utilise = 4;
            break;

            case 2:
            //Le code a été mal utilisé
            jingle->play();
            QTimer::singleShot(2500, this, SLOT(fin_paroles()));
            attente_fin_paroles.exec();

            ui->label_presentation_resultats->setText(accuses[accuse_code_sc]->get_nom());
            ui->label_presentation_resultats->setVisible(false);
            ui->label_resultats->setVisible(false);
            ui->label_resultats->setText("est écarté par le code de la seconde chance.");

            accuses[accuse_code_sc]->appeler_nom();
            QTimer::singleShot(1000, this, SLOT(fin_paroles()));
            attente_fin_paroles.exec();

            code_sc_mauvais_usage->play();
            QTimer::singleShot(16000, this, SLOT(fin_paroles()));
            attente_fin_paroles.exec();

            ui->label_presentation_resultats->setVisible(true);

            accuses[accuse_code_sc]->appeler_nom();
            QTimer::singleShot(1000, this, SLOT(fin_paroles()));
            attente_fin_paroles.exec();

            ui->label_resultats->setVisible(true);

            code_sc_ecarte->play();
            QTimer::singleShot(10000, this, SLOT(fin_paroles()));
            attente_fin_paroles.exec();

            this->ecarter_accuse(accuses[accuse_code_sc]);
            accuses[accuse_code_sc]->set_num_vote_code_sc(num_vote, code_seconde_chance_utilise);
            code_seconde_chance_utilise = 4;
            break;

            case 3:
            //Le code a été utilisé mais de manière inutile
            jingle->play();
            QTimer::singleShot(2500, this, SLOT(fin_paroles()));
            attente_fin_paroles.exec();

            ui->label_presentation_resultats->setText(accuses[accuse_code_sc]->get_nom());
            ui->label_resultats->setVisible(false);
            ui->label_resultats->setText("a utilisé le code de la seconde chance sans effet.");

            accuses[accuse_code_sc]->appeler_nom();
            QTimer::singleShot(1000, this, SLOT(fin_paroles()));
            attente_fin_paroles.exec();

            ui->label_resultats->setVisible(true);

            code_sc_usage_inutile->play();
            QTimer::singleShot(12000, this, SLOT(fin_paroles()));
            attente_fin_paroles.exec();

            accuses[accuse_code_sc]->set_num_vote_code_sc(num_vote, code_seconde_chance_utilise);
            code_seconde_chance_utilise = 4;
            break;

            case 4:
            //Les effets du code ont déjà été décrits donc on ne fait rien
            break;

        }
    }

    //Fin du vote, détermination du candidat écarté

    jingle->play();
    QTimer::singleShot(2500, this, SLOT(fin_paroles()));
    attente_fin_paroles.exec();

    int ecarte;
    ecarte = this->determiner_ecarte();
    this->ecarter_accuse(accuses[ecarte]);

    ui->label_presentation_resultats->setText("L'accusé écarté à l'issue de ce vote est :");

    ui->label_resultats->setVisible(false);
    QTimer::singleShot(1000, this, SLOT(fin_paroles()));
    attente_fin_paroles.exec();

    ui->label_resultats->setText(accuses[ecarte]->get_nom());

    ui->label_resultats->setVisible(true);

    accuses[ecarte]->appeler_nom();
    QTimer::singleShot(1000, this, SLOT(fin_paroles()));
    attente_fin_paroles.exec();

    annonce_elimine->play();
    QTimer::singleShot(13000, this, SLOT(fin_paroles()));
    attente_fin_paroles.exec();

    if(nb_elimines == accuses.length() - 1)
    {
        int sauve;

        for(i = 0; i<accuses.length(); i++)
        {
            if(!accuses[i]->get_ecarte())
            {
                sauve = i;
            }
        }

        accuses[sauve]->set_sauve();

        ui->label_presentation_resultats->setText("Le premier accusé sauvé est :");
        ui->label_resultats->setText(accuses[sauve]->get_nom());

        accuses[sauve]->appeler_nom();
        QTimer::singleShot(1000, this, SLOT(fin_paroles()));
        attente_fin_paroles.exec();

        annonce_premier_sauve->play();
        QTimer::singleShot(11000, this, SLOT(fin_paroles()));
        attente_fin_paroles.exec();

        this->afficher_ecran_discours();

        jingle->play();
        QTimer::singleShot(2500, this, SLOT(fin_paroles()));
        attente_fin_paroles.exec();

        presentation_vote_final->play();
        QTimer::singleShot(78500, this, SLOT(fin_paroles()));
        attente_fin_paroles.exec();
    }

    else
    {
        num_vote++;

        if(temps_vote[num_vote-1] == temps_vote_initiaux[num_vote-1])
        {
            annonce_attente_vote_suivant[num_vote-1]->play();
        }
        else
        {
            switch(temps_vote[num_vote-1])
            {

                case 1200 :
                    anonce_attente_vote_suivant_modifie[0]->play();
                    break;

                case 900 :
                    anonce_attente_vote_suivant_modifie[1]->play();
                    break;

                case 600 :
                    anonce_attente_vote_suivant_modifie[2]->play();
                    break;
            }
        }
    }

    //Passage au vote suivant
    temps_resultats->start();

    //Sauvegarde
    this->sauvegarder();

}

void MainWindow::vote_final_accuse(Accuse* a)
{
    this->masquer_boutons_code_vote();

    if(!a->get_a_vote()) //Si l'accusé n'a pas voté
    {
        a_vote = false;

        //Affichage des boutons de vote
        ui->stackedWidget->setCurrentIndex(4);

        //this->afficher_labels_deplacables();
        this->masquer_labels_deplacables_inutiles(a);

        ui->label_vote_invalide->setVisible(false);

        //Si c'est l'accusé qui est déjà sauvé, il faut afficher 8 choix
        if (!(a->get_ecarte()))
        {
            cadres_vote_final[cadres_vote_final.length()-1]->setVisible(true);
            ui->Bouton_annuler_8->setVisible(true);
        }
        else
        {
            cadres_vote_final[cadres_vote_final.length()-1]->setVisible(false);
            ui->Bouton_annuler_8->setVisible(false);
        }

        ui->label_demande_vote_2->setText(a->get_nom() + ", à toi de voter !");

        //démarage du temps de vote
        this->demarer_compte_a_rebours_vote_final();

        //Attente du vote
        attente_vote_final.exec();

        //Si le vote a été coupé par la fin du temps, on ne finit pas la fonction
        if(temps_appel_accuses->isActive())
        {
            return;
        }

        //On masque le compteur et les boutons
        this->masquer_boutons_vote();
        this->masquer_labels_deplacables();

        if(a_vote)
        {
            //On compte le vote de l'accusé
            a->set_a_vote(true);
            a->remplir_vote_final(ordre_vote_final);

            for(int i=0; i<ordre_vote_final.length(); i++)
            {
                ordre_vote_final[i] = 0;
            }

            ui->label_remerciement->setText(a->get_nom() + " merci d'avoir voté.");

            ui->stackedWidget_intervote->setCurrentIndex(5);

            //Mise au milieu de la souris pour masquer le vote
            souris.setPos(this->width() / 2, this->height() / 2);
            setCursor(souris);

            //Remerciement vote
            QTimer::singleShot(2000, this, SLOT(fin_paroles()));
            attente_fin_paroles.exec();

            ui->stackedWidget_intervote->setCurrentIndex(0);

            if(temps_appel_accuses->isActive())
            {
                return;
            }
        }

    }
    else //S'il a déjà voté on lui dit et on ne fait rien
    {
        ui->stackedWidget_intervote->setCurrentIndex(5);
        ui->label_remerciement->setText("Tu as déjà voté !");

        QTimer::singleShot(2000, this, SLOT(fin_paroles()));
        attente_fin_paroles.exec();
        this->masquer_boutons_code_vote();
    }

}

void MainWindow::vote_final()
{

    ui->label_phase->setText("VOTE FINAL");

    for(int i=0; i<accuses.length(); i++)
    {
        if(accuses[i]->get_a_vote())
        {
            //S'il a voté, on réinitialise juste la valeur
            accuses[i]->set_a_vote(false);
        }
        else
        {
            //Sinon, on lui ajoute 15 points
            QVector <int> acc;

            acc.push_back(accuses[i]->get_numero());

            accuses[i]->ajouter_vote_contre_final(15);
            accuses[i]->remplir_vote_final(acc);
        }
    }

    //Fin du vote, décompte du vote et annonce des résultats
    ui->stackedWidget->setCurrentIndex(7);

    this->decompte_final();

}

int MainWindow::determiner_ecarte()
{
    QVector <int> ecartes;
    int max_vote_contre = 0;
    int vote_contre;
    int i;
    for (i=0; i<accuses.length(); i++)
    {
        if(!accuses[i]->get_ecarte())
            //On ne compte que les voix contre les accusés non écartés
            //La distinction existe quand un accusé est écarté suite à une mauvaise utilisation du code de la seconde chance
        {
            vote_contre = accuses[i]->get_nb_vote_contre_i(num_vote - 1);
            if (vote_contre > max_vote_contre)
            {
                max_vote_contre = vote_contre;
                ecartes.clear();
                ecartes.push_back(i);
            }
            else if (vote_contre == max_vote_contre)
            {
                ecartes.push_back(i);
            }
        }
    }

    if(ecartes.length()>1)
    {
        //Si il y a égalité, on en choisit un au hasard
        random_shuffle(ecartes.begin(), ecartes.end(),Gen());
    }

    return ecartes[0];
}


void MainWindow::decompte_final()
{
    //Réalise le décompte du vote final pour trouver le deuxième sauvé

    int i,j;
    int indice_courant = 0;
    int max_courant = 0;
    int min;
    QVector<Accuse*> resume_accuses; //Vecteur pour collecter les données
    QVector<Accuse*> accuses_ordonnes; //Vecteur avec les accusés ordonnés
    QVector<Accuse*> accuses_a_egalite;

    //Remplissage du vecteur de résumé
    for(i=0;i<accuses.length(); i++)
    {
        if(accuses[i]->get_ecarte())
        {
            resume_accuses.push_back(accuses[i]);
        }
    }

    //Remplissage du vecteur ordonné.
    for(i=0;i<accuses.length()-1; i++)
    {
        for(j=0;j<resume_accuses.length();j++)
        {
            if(resume_accuses[j]->get_nb_vote_contre_i(9)>max_courant)
            {
                indice_courant = j;
                max_courant = resume_accuses[j]->get_nb_vote_contre_i(9);
            }
        }

        accuses_ordonnes.push_back(resume_accuses[indice_courant]);

        resume_accuses.remove(indice_courant);

        max_courant = 0;
        indice_courant = 0;
    }

    //S'il y a des égalités, on choisit au hasard parmis celles-ci pour désigner l'accusé sauvé
    min = accuses_ordonnes[accuses_ordonnes.length()-1]->get_nb_vote_contre_i(9);

    i = accuses_ordonnes.length()-1;

    while(accuses_ordonnes[i]->get_nb_vote_contre_i(9) == min)
    {
        accuses_a_egalite.push_back(accuses_ordonnes[i]);
        accuses_ordonnes.remove(i);
        i--;
        if (accuses_ordonnes.isEmpty())
        {
            break;
        }
    }

    if(accuses_a_egalite.length()>1)
    {
        random_shuffle(accuses_a_egalite.begin(), accuses_a_egalite.end(),Gen());

        for(i=0; i<accuses_a_egalite.length(); i++)
        {
            accuses_ordonnes.push_back(accuses_a_egalite[i]);
        }
    }
    else
    {
        accuses_ordonnes.push_back(accuses_a_egalite[0]);
    }

    jingle->play();
    QTimer::singleShot(2500, this, SLOT(fin_paroles()));
    attente_fin_paroles.exec();

    annonce_resultats_vote_final->play();
    QTimer::singleShot(20000, this, SLOT(fin_paroles()));
    attente_fin_paroles.exec();

    //Annonce des résultats
    for(i=0;i<accuses_ordonnes.length();i++)
    {
        labels_classement[labels_classement.length() - 1 - i]->setText(accuses_ordonnes[i]->get_nom());
        labels_classement[labels_classement.length() - 1 - i]->setVisible(true);
        accuses_ordonnes[i]->appeler_nom();
        QTimer::singleShot(2000, this, SLOT(fin_paroles()));
        attente_fin_paroles.exec();
    }

    //Temporisation entre les annonces
    QTimer::singleShot(1000, this, SLOT(fin_paroles()));
    attente_fin_paroles.exec();

    accuses_ordonnes[accuses_ordonnes.length()-1]->set_sauve();

    ui->label_presentation_resultats->setText("Le deuxième accusé sauvé est :");
    ui->label_resultats->setText(accuses_ordonnes[accuses_ordonnes.length()-1]->get_nom());
    ui->stackedWidget->setCurrentIndex(2);

    accuses_ordonnes[accuses_ordonnes.length()-1]->appeler_nom();
    QTimer::singleShot(1000, this, SLOT(fin_paroles()));
    attente_fin_paroles.exec();

    annonce_deuxieme_sauve->play();
    QTimer::singleShot(10000, this, SLOT(fin_paroles()));
    attente_fin_paroles.exec();

    this->conclusion();
}

void MainWindow::ajouter_vote(int p)
{
    accuses[p]->ajouter_vote_contre(num_vote - 1);
    a_vote = true;
    numero_accuse_vote_contre = accuses[p]->get_numero();
    attente_vote.quit();
}

void MainWindow::masquer_labels_deplacables_inutiles(Accuse *a)
{
    int numero_sauve;

    for(int i = 0; i<accuses.length(); i++)
    {
        if(!accuses[i]->get_ecarte())
        {
            numero_sauve = i;
        }
    }

    this->gerer_deplacement_labels_deplacables(numero_sauve, false);
    this->gerer_deplacement_labels_deplacables(a->get_numero(), false);
}

void MainWindow::valider_vote_final()
{
    //il faut d'abord vérifier si le vote est valide
    bool valide = true;

    for(int i = 0; i<cadres_vote_final.length(); i++)
    {
        if(cadres_vote_final[i]->isVisible() && cadres_vote_final[i]->get_choix_accuse() == 12)
        {
            valide = false;
        }
    }

    if(valide)
    {
        this->compter_votes_finaux();
        a_vote = true;
        attente_vote_final.quit();
    }
    else
    {
        ui->label_vote_invalide->setVisible(true);
        QTimer::singleShot(2000, this, SLOT(fin_paroles()));
        attente_fin_paroles.exec();
        ui->label_vote_invalide->setVisible(false);
    }

}

void MainWindow::compter_votes_finaux()
{
    int i;
    for(i = 0; i<cadres_vote_final.length(); i++)
    {
        if(cadres_vote_final[i]->isVisible())
        {
            accuses[cadres_vote_final[i]->get_choix_accuse()]->ajouter_vote_contre_final(i+1);
            ordre_vote_final[i] = accuses[cadres_vote_final[i]->get_choix_accuse()]->get_numero();
        }
    }
}

void MainWindow::ecarter_accuse(Accuse *a, int v)
{
    if (v == 0)
    {
        v = num_vote;
    }

    nb_elimines++;
    a->set_ecarte(true, v);
    switch (a->get_numero()) {
    case 0:
        ui->bouton_cafard->setEnabled(false);
        break;
    case 1:
        ui->bouton_chacal->setEnabled(false);
        break;
    case 2:
        ui->bouton_chien->setEnabled(false);
        break;
    case 3:
        ui->bouton_cochon->setEnabled(false);
        break;
    case 4:
        ui->bouton_hyene->setEnabled(false);
        break;
    case 5:
        ui->bouton_rat->setEnabled(false);
        break;
    case 6:
        ui->bouton_requin->setEnabled(false);
        break;
    case 7:
        ui->bouton_serpent->setEnabled(false);
        break;
    case 8:
        ui->bouton_vautour->setEnabled(false);
        break;
    }
}

void MainWindow::rehabiliter_accuse(Accuse *a, int v)
{
    if (v == 0)
    {
        v = num_vote;
    }

    nb_elimines--;
    a->set_ecarte(false, v);
    switch (a->get_numero()) {
    case 0:
        ui->bouton_cafard->setEnabled(true);
        break;
    case 1:
        ui->bouton_chacal->setEnabled(true);
        break;
    case 2:
        ui->bouton_chien->setEnabled(true);
        break;
    case 3:
        ui->bouton_cochon->setEnabled(true);
        break;
    case 4:
        ui->bouton_hyene->setEnabled(true);
        break;
    case 5:
        ui->bouton_rat->setEnabled(true);
        break;
    case 6:
        ui->bouton_requin->setEnabled(true);
        break;
    case 7:
        ui->bouton_serpent->setEnabled(true);
        break;
    case 8:
        ui->bouton_vautour->setEnabled(true);
        break;
    }
}

void MainWindow::compte_a_rebours_intervote()
{
    if(temps_restant > 1)
    {
        temps_restant--;
        QString minutes = QString("%1").arg(temps_restant/60, 2, 10, QChar('0'));
        QString secondes = QString("%1").arg(temps_restant%60, 2, 10, QChar('0'));
        ui->compteur_temps->display(minutes+":"+ secondes);
        ui->compteur_temps_ecarte->display(minutes+":"+ secondes);
        ui->compteur_temps_ecarte_2->display(minutes+":"+ secondes);

        if(temps_restant == 240)
        {
            fin_vote_proche->play();
        }
    }
    else
    {
        ui->compteur_temps->display("00:00");
        ui->compteur_temps_ecarte->display("00:00");
        ui->compteur_temps_ecarte_2->display("00:00");
        temps_intervote->stop();
        this->appeler_accuses();
    }
}

void MainWindow::compte_a_rebours_vote()
{
    if(temps_restant_vote > 1)
    {
        temps_restant_vote--;
        QString minutes = QString("%1").arg(temps_restant_vote/60, 2, 10, QChar('0'));
        QString secondes = QString("%1").arg(temps_restant_vote%60, 2, 10, QChar('0'));
        ui->compteur_temps_vote->display(minutes+":"+ secondes);
        ui->compteur_temps_vote_final->display(minutes+":"+ secondes);
    }
    else
    {
        ui->compteur_temps_vote->display("00:00");
        ui->compteur_temps_vote_final->display("00:00");
        temps_limite_vote->stop();
        attente_vote.quit();
        attente_vote_final.quit();
    }
}

void MainWindow::fin_discours_initial()
{
    temps_disours_initial->stop();
    num_vote++;
    this->inter_vote();
}

void MainWindow::fin_appel_accuses()
{
    temps_appel_accuses->stop();

    //Si tous les candidats éliminés sauf un, on passe au vote final, sinon on continue
    if(nb_elimines == accuses.length() - 1)
    {
        this->vote_final();
    }
    else
    {
        this->vote();
    }
}

void MainWindow::fin_temporisation()
{
    temps_resultats->stop();

    //Si tous les candidats éliminés sauf un, on passe au vote final, sinon on continue
    if(nb_elimines == accuses.length() - 1)
    {
        this->inter_vote_final();
    }
    else
    {
        this->inter_vote();
    }
}

void MainWindow::fin_temps_affichage_resultats_code_sc()
{
    temps_affichage_resultats_code_sc->stop();
    temps_ereur_seconde_chance->stop();
    this->masquer_boutons_code_sc();
    ui->stackedWidget_intervote->setCurrentIndex(0);
}

void MainWindow::changement_image_attente()
{
    if(ui->stackedWidget->currentIndex() == 6)
    {
        index_image++;
        if(index_image == images_d_attente.length())
        {
            index_image = 0;
        }
        ui->label_image->setPixmap(images_d_attente[index_image]);
    }
    else
    {
        temps_animation_attente->stop();
        index_image = 0;
    }
}

void MainWindow::fin_paroles()
{
    attente_fin_paroles.quit();
}

void MainWindow::fin_sonnerie()
{
    attente_fin_sonnerie.quit();
}

void MainWindow::fin_jeu()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::code_seconde_chance()
{
    ui->ligne_code_sc->setFocus();

    ui->stackedWidget_intervote->setCurrentIndex(2);
}

void MainWindow::valider_code_seconde_chance()
{

    if(ui->ligne_code_sc->text().toLower() == "replay")
    {
        if(code_seconde_chance_utilise != 0)
        {
            this->masquer_boutons_code_sc();
            ui->label_remerciement->setText("Code déjà utilisé !");
            ui->stackedWidget_intervote->setCurrentIndex(5);
            temps_ereur_seconde_chance->start();
        }
        else if(nb_elimines == accuses.length() - 1)
        {
            ui->label_remerciement->setText("C'est trop tard pour utiliser ce code !");
            ui->stackedWidget_intervote->setCurrentIndex(5);
            temps_ereur_seconde_chance->start();
        }
        else
        {
            ui->stackedWidget_intervote->setCurrentIndex(3);
        }
    }
    else
    {
        this->masquer_boutons_code_sc();
        ui->label_remerciement->setText("Code invalide !");
        ui->stackedWidget_intervote->setCurrentIndex(5);

        temps_ereur_seconde_chance->start();
    }
}

void MainWindow::effets_code_seconde_chance()
{
    ui->stackedWidget_intervote->setCurrentIndex(5);

    if(num_vote<6)
    {
        //Si le code est utilisé avant le 6ème vote, il a un effet négatif
        if(accuses[ui->comboBox_code_seconde_chance->itemData(ui->comboBox_code_seconde_chance->currentIndex()).toInt()]->get_ecarte())
        {
            //Si l'accusé est écarté, le code n'a pas d'effet
            ui->label_remerciement->setText("Le code de la seconde chance a bien été pris en compte. Il ne peut plus être utilisé.");
            code_seconde_chance_utilise = 3;
            accuse_code_sc = ui->comboBox_code_seconde_chance->itemData(ui->comboBox_code_seconde_chance->currentIndex()).toInt();
        }
        else
        {
            //Si l'accusé n'est pas écarté, il le devient
            ui->label_remerciement->setText("Le code de la seconde chance a bien été pris en compte. Il ne peut plus être utilisé.");
            code_seconde_chance_utilise = 2;
            accuse_code_sc = ui->comboBox_code_seconde_chance->itemData(ui->comboBox_code_seconde_chance->currentIndex()).toInt();
        }
    }
    else
    {
        //Si le code est utilisé à partir du 6ème vote
        if(accuses[ui->comboBox_code_seconde_chance->itemData(ui->comboBox_code_seconde_chance->currentIndex()).toInt()]->get_ecarte())
        {
            //Si l'accusé était écarté, il ne l'est plus
            int num_accuse = ui->comboBox_code_seconde_chance->itemData(ui->comboBox_code_seconde_chance->currentIndex()).toInt();
            ui->label_remerciement->setText("Le code de la seconde chance a bien été pris en compte. Il ne peut plus être utilisé.");
            code_seconde_chance_utilise = 1;
            accuse_code_sc = num_accuse;
        }
        else
        {
            //Si l'accusé n'est pas condamné, le code n'a pas d'effet
            ui->label_remerciement->setText("Le code de la seconde chance a bien été pris en compte. Il ne peut plus être utilisé.");
            code_seconde_chance_utilise = 3;
            accuse_code_sc = ui->comboBox_code_seconde_chance->itemData(ui->comboBox_code_seconde_chance->currentIndex()).toInt();
        }
    }

    temps_affichage_resultats_code_sc->start();
}

void MainWindow::conclusion()
{
    int i;
    int sauve_1 = accuses.length();
    int sauve_2 = accuses.length();

    for(i=0; i<accuses.length(); i++)
    {
        if(accuses[i]->get_sauve())
        {
            if(sauve_1 == accuses.length())
            {
                sauve_1 = i;
            }
            else
            {
                sauve_2 = i;
            }
        }
    }

    ui->label_sauve_1->setText(accuses[sauve_1]->get_nom());
    ui->label_sauve_2->setText(accuses[sauve_2]->get_nom());
    ui->stackedWidget->setCurrentIndex(8);

    jingle->play();
    QTimer::singleShot(2500, this, SLOT(fin_paroles()));
    attente_fin_paroles.exec();

    discours_conclusion->play();
    QTimer::singleShot(15000, this, SLOT(fin_paroles()));
    attente_fin_paroles.exec();

    ui->stackedWidget->setCurrentIndex(9);

    jingle_et_musique->play();

    QTimer::singleShot(120000, this, SLOT(fin_jeu()));

}

void MainWindow::sauvegarder()
{
    /* Structure du fichier de sauvegarde :
     * num_vote
     * code_seconde_chance_utilise
     * Pour chaque accusé dans l'ordre :
     * ecarte (0 ou 1), num_vote_ecarte, num_vote_ecarte_2, num_vote_code_sc, effet_sc
     * trois lignes par accusé avec le contenu des votes (donnés et reçus) + le vote final
     * */

    QFile fichier_sauvegarde(chemin_fichier_sauvegarde);
    QString texte ="";
    QString texte2 ="";
    QString texte3 ="";

    fichier_sauvegarde.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream flux(&fichier_sauvegarde);
    flux << num_vote;
    flux << "\n";
    flux << code_seconde_chance_utilise;
    flux << "\n";

    for(int i=0; i<accuses.length(); i++)
    {
        texte = "";

        if(accuses[i]->get_ecarte())
        {
           texte += "1;";
        }
        else
        {
            texte += "0;";
        }
        texte += QString::number(accuses[i]->get_num_vote_ecarte()) + ";" + QString::number(accuses[i]->get_num_vote_ecarte_2()) + ";" + QString::number(accuses[i]->get_num_vote_code_sc()) + ";" + QString::number(accuses[i]->get_effet_sc());

        flux << texte;
        flux << "\n";
    }

    for(int i=0; i<accuses.length(); i++)
    {
        texte ="";
        texte2 ="";
        texte3 ="";

        for(int j=0; j < 9; j++)
        {
            texte += QString::number(accuses[i]->get_vote_i(j));
            texte2 += QString::number(accuses[i]->get_nb_vote_contre_i(j));

            if(j != 8)
            {
                texte += ";";
                texte2 += ";";
                texte3 += QString::number(accuses[i]->get_vote_final_i(j)) + ";";
            }
            else
            {
                texte3 += QString::number(accuses[i]->get_nb_vote_contre_i(9));
            }
        }
        flux << texte;
        flux << "\n";
        flux << texte2;
        flux << "\n";
        flux << texte3;
        flux << "\n";
    }

    fichier_sauvegarde.close();
}

void MainWindow::charger()
{
    QFile fichier_sauvegarde(chemin_fichier_sauvegarde);

    if(!fichier_sauvegarde.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::question(this, "Pas de partie sauvegardée", "Il n'y a pas de fichier de sauvegarde.", QMessageBox::Close);
        return;
    }


    QTextStream flux(&fichier_sauvegarde);
    QString ligne;
    int etat;

    ligne = flux.readLine();
    num_vote = ligne.toInt();

    ligne = flux.readLine();
    code_seconde_chance_utilise = ligne.toInt();

    for(int i=0; i<accuses.length(); i++)
    {
        ligne = flux.readLine();

        //Ecartement des accusés déjà écartés
        etat = ligne[0].digitValue();
        if(etat == 1)
        {
            this->ecarter_accuse(accuses[i], ligne[2].digitValue());

            if (ligne[4].digitValue() != 0)
            {
                //L'accusé a utilisé le code de la seconde chance et a été écarté une seconde fois
                this->rehabiliter_accuse(accuses[i], ligne[6].digitValue());
                this->ecarter_accuse(accuses[i], ligne[4].digitValue());
            }
        }
        else if (ligne[2].digitValue() != 0)
        {
            //L'accusé a été éliminé puis réhabilité par le code de la seconde chance
            this->ecarter_accuse(accuses[i], ligne[2].digitValue());
            this->rehabiliter_accuse(accuses[i], ligne[6].digitValue());
        }
        accuses[i]->set_num_vote_code_sc(ligne[6].digitValue(), ligne[8].digitValue());
    }

    for(int i=0; i<accuses.length(); i++)
    {
       //Reconstruction du vecteur vote
        ligne = flux.readLine();
        for(int j=0; j < 9; j++)
        {
            etat = ligne[2*j].digitValue();
            accuses[i]->ajouter_vote(j,etat);
        }

        //Reconstruction du vecteur nb_vote_contre
        ligne = flux.readLine();
         for(int j=0; j < 9; j++)
         {
             etat = ligne[2*j].digitValue();
             for (int k=0; k < etat; k++)
             {
                accuses[i]->ajouter_vote_contre(j);
             }
         }
         //Il n'y a pas besoin de charger les votes finaux car s'ils sont sauvegardés c'est que le jeu est fini !
         //On saute donc juste la ligne
         ligne = flux.readLine();
    }

    fichier_sauvegarde.close();
}

void MainWindow::quitter()
{
    QMessageBox msgbox;
    //int reponse = QMessageBox::question(this, "Quitter le programme", "Êtes-vous sûr·e de vouloir quitter ?", QMessageBox::No | QMessageBox::Yes, QMessageBox::No);

    msgbox.setWindowTitle("Quitter le programme");
    msgbox.setText("Êtes-vous sûr·e de vouloir quitter ?");

    msgbox.addButton(tr("Options"), QMessageBox::AcceptRole);

    msgbox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
    msgbox.setDefaultButton(QMessageBox::No);

    int reponse = msgbox.exec();

    if (reponse == QMessageBox::Yes)
    {
        this->close();
    }
    else if(reponse == QMessageBox::AcceptRole)
    {
        Fenetre_options f(this);
        f.exec();
    }

}

void MainWindow::appuyer_bouton_annuler(int n)
{

    switch (cadres_vote_final[n]->get_choix_accuse())
    {
        case 0:
        ui->label_cafard_deplacable->setVisible(true);
        break;

        case 1:
        ui->label_chacal_deplacable->setVisible(true);
        break;

        case 2:
        ui->label_chien_deplacable->setVisible(true);
        break;

        case 3:
        ui->label_cochon_deplacable->setVisible(true);
        break;

        case 4:
        ui->label_hyene_deplacable->setVisible(true);
        break;

        case 5:
        ui->label_rat_deplacable->setVisible(true);
        break;

        case 6:
        ui->label_requin_deplacable->setVisible(true);
        break;

        case 7:
        ui->label_serpent_deplacable->setVisible(true);
        break;

        case 8:
        ui->label_vautour_deplacable->setVisible(true);
        break;
    }
    cadres_vote_final[n]->vider_cadre();
    cadres_vote_final[n]->repaint();
}

int MainWindow::trouver_ancien_choix()
{
    int i;
    int c;

    for(i=0; i<cadres_vote_final.length(); i++)
    {
        if(cadres_vote_final[i]->get_ancien_choix() < 12)
        {
            c = cadres_vote_final[i]->get_ancien_choix();
            cadres_vote_final[i]->reinitialiser_ancien_choix();
            return c;
        }
    }

    return 12;
}

void MainWindow::gerer_deplacement_labels_deplacables(int n, bool a)
{
    switch (n)
    {
        case 0:
        ui->label_cafard_deplacable->setVisible(a);
        break;

        case 1:
        ui->label_chacal_deplacable->setVisible(a);
        break;

        case 2:
        ui->label_chien_deplacable->setVisible(a);
        break;

        case 3:
        ui->label_cochon_deplacable->setVisible(a);
        break;

        case 4:
        ui->label_hyene_deplacable->setVisible(a);
        break;

        case 5:
        ui->label_rat_deplacable->setVisible(a);
        break;

        case 6:
        ui->label_requin_deplacable->setVisible(a);
        break;

        case 7:
        ui->label_serpent_deplacable->setVisible(a);
        break;

        case 8:
        ui->label_vautour_deplacable->setVisible(a);
        break;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape) // si c'est echap on quitte
    {
        this->quitter();
    }

    if(event->key() == Qt::Key_S) //Si c'est S on rentre le code de la seconde chance
    {
        if(ui->bouton_voter->isVisible())
        {
            this->masquer_boutons_code_sc();
            this->code_seconde_chance();
        }
    }

    if(event->key() == Qt::Key_Return)
    {
        if(ui->ligne_code->hasFocus())
        {
            this->on_bouton_ok_vote_clicked();
        }
        else if(ui->ligne_code_sc->hasFocus())
        {
            this->on_bouton_ok_clicked();
        }
        else if(ui->ligne_code_sc_2->hasFocus())
        {
            this->on_bouton_ok_code_sc_clicked();
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    bool debut_deplacement = false;
    int numero_label_deplace;
    int indice_cadre_provenance = cadres_vote_final.length();
    int i;
    QLabel *enfant = 0;
    QPoint hotSpot;

    if(!(event->button() == Qt::LeftButton))
    {
        return;
    }

    enfant = qobject_cast<QLabel*>(childAt(event->pos()));

    if (!enfant)
    {
        return;
    }

    if(!(enfant->property("type") == "deplacable"))
    {
        return;
    }

        if (ui->label_cafard_deplacable->geometry().contains(event->pos() - ui->stackedWidget->pos())
                && (ui->label_cafard_deplacable->isVisible()))
        {
            debut_deplacement = true;
            numero_label_deplace = 0;
            ui->label_cafard_deplacable->setVisible(false);
        }
        else if(ui->label_chacal_deplacable->geometry().contains(event->pos() - ui->stackedWidget->pos())
                && (ui->label_chacal_deplacable->isVisible()))
            {
                debut_deplacement = true;
                numero_label_deplace = 1;
                ui->label_chacal_deplacable->setVisible(false);
            }
        else if(ui->label_chien_deplacable->geometry().contains(event->pos() - ui->stackedWidget->pos())
                && (ui->label_chien_deplacable->isVisible()))
            {
                debut_deplacement = true;
                numero_label_deplace = 2;
                ui->label_chien_deplacable->setVisible(false);
            }
        else if(ui->label_cochon_deplacable->geometry().contains(event->pos() - ui->stackedWidget->pos())
                && (ui->label_cochon_deplacable->isVisible()))
            {
                debut_deplacement = true;
                numero_label_deplace = 3;
                ui->label_cochon_deplacable->setVisible(false);
            }
        else if(ui->label_hyene_deplacable->geometry().contains(event->pos() - ui->stackedWidget->pos())
                && (ui->label_hyene_deplacable->isVisible()))
            {
                debut_deplacement = true;
                numero_label_deplace = 4;
                ui->label_hyene_deplacable->setVisible(false);
            }
        else if(ui->label_rat_deplacable->geometry().contains(event->pos() - ui->stackedWidget->pos())
                && (ui->label_rat_deplacable->isVisible()))
            {
                debut_deplacement = true;
                numero_label_deplace = 5;
                ui->label_rat_deplacable->setVisible(false);
            }
        else if(ui->label_requin_deplacable->geometry().contains(event->pos() - ui->stackedWidget->pos())
                && (ui->label_requin_deplacable->isVisible()))
            {
                debut_deplacement = true;
                numero_label_deplace = 6;
                ui->label_requin_deplacable->setVisible(false);
            }
        else if(ui->label_serpent_deplacable->geometry().contains(event->pos() - ui->stackedWidget->pos())
                && (ui->label_serpent_deplacable->isVisible()))
            {
                debut_deplacement = true;
                numero_label_deplace = 7;
                ui->label_serpent_deplacable->setVisible(false);
            }
        else if(ui->label_vautour_deplacable->geometry().contains(event->pos() - ui->stackedWidget->pos())
                && (ui->label_vautour_deplacable->isVisible()))
            {
                debut_deplacement = true;
                numero_label_deplace = 8;
                ui->label_vautour_deplacable->setVisible(false);
            }
        else
        {
            for(i=0; i<cadres_vote_final.length(); i++)
            {
                if(cadres_vote_final[i]->geometry().contains(event->pos() - ui->stackedWidget->pos())
                        && cadres_vote_final[i]->isVisible()
                        && cadres_vote_final[i]->get_choix_accuse() != 12)
                {
                    debut_deplacement = true;
                    indice_cadre_provenance = i;
                    numero_label_deplace = cadres_vote_final[i]->get_choix_accuse();
                }
            }
        }

        if(!debut_deplacement)
        {
            return;
        }

        QDrag *drag = new QDrag(this);
        QMimeData *mimeData = new QMimeData;

        hotSpot = event->pos() - enfant->pos() - ui->stackedWidget->pos();

       QPixmap pixmap(enfant->size());
       enfant->render(&pixmap);
        mimeData->setText(enfant->text());
        drag->setMimeData(mimeData);
        drag->setPixmap(pixmap);
        drag->setHotSpot(hotSpot);

        if(indice_cadre_provenance < cadres_vote_final.length())
        {
            cadres_vote_final[indice_cadre_provenance]->setText("");
        }

            Qt::DropAction dropAction = drag->exec(Qt::MoveAction);

            if(dropAction == Qt::MoveAction)
            {
                int precedent_choix = this->trouver_ancien_choix();

                if(precedent_choix < 12)
                {
                    if(indice_cadre_provenance < cadres_vote_final.length())
                    {
                        cadres_vote_final[indice_cadre_provenance]->vider_cadre();
                        cadres_vote_final[indice_cadre_provenance]->determiner_choix_accuse(accuses[precedent_choix]->get_nom());
                    }
                    else
                    {
                        this->gerer_deplacement_labels_deplacables(precedent_choix, true);
                    }
                }
                else
                {
                   if(indice_cadre_provenance < cadres_vote_final.length())
                   {
                       cadres_vote_final[indice_cadre_provenance]->vider_cadre();
                   }
                }
                this->gerer_deplacement_labels_deplacables(numero_label_deplace, false);
            }
            else
            {
                if(indice_cadre_provenance < cadres_vote_final.length())
                {
                    cadres_vote_final[indice_cadre_provenance]->vider_cadre();
                }

                this->gerer_deplacement_labels_deplacables(numero_label_deplace, true);
            }
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
}

void MainWindow::dropEvent(QDropEvent *event)
{
    event->setDropAction(Qt::IgnoreAction);
    event->accept();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bouton_cafard_clicked()
{
    this->ajouter_vote(0);
}

void MainWindow::on_bouton_serpent_clicked()
{
    this->ajouter_vote(7);
}

void MainWindow::on_bouton_rat_clicked()
{
    this->ajouter_vote(5);
}

void MainWindow::on_bouton_hyene_clicked()
{
    this->ajouter_vote(4);
}

void MainWindow::on_bouton_requin_clicked()
{
    this->ajouter_vote(6);
}

void MainWindow::on_bouton_chien_clicked()
{
    this->ajouter_vote(2);
}

void MainWindow::on_bouton_chacal_clicked()
{
    this->ajouter_vote(1);
}

void MainWindow::on_bouton_cochon_clicked()
{
    this->ajouter_vote(3);
}

void MainWindow::on_bouton_vautour_clicked()
{
    this->ajouter_vote(8);
}

void MainWindow::on_bouton_valider_vote_final_clicked()
{
    this->valider_vote_final();
}

void MainWindow::on_bouton_oui_clicked()
{
    if(ui->comboBox_code_seconde_chance->currentIndex() != 0)
    {
        ui->stackedWidget_intervote->setCurrentIndex(4);
        ui->label_code_final_sc->setText(accuses[ui->comboBox_code_seconde_chance->itemData(ui->comboBox_code_seconde_chance->currentIndex()).toInt()]->get_nom() + ", entre ton code personnel pour valider :");
    }
}

void MainWindow::on_bouton_non_clicked()
{
    this->masquer_boutons_code_sc();

    ui->label_remerciement->setText("Opération annulée.");
    ui->stackedWidget_intervote->setCurrentIndex(5);
    temps_affichage_resultats_code_sc->start();
}

void MainWindow::on_bouton_ok_clicked()
{
    this->valider_code_seconde_chance();
}

void MainWindow::on_bouton_demarrer_clicked()
{
    //Démarage du discours initial
    this->afficher_ecran_discours();

    //------Début du jeu et présentation initiale------
    sonnerie->play();
    temps_disours_initial->start();
    discours_initial->play();

    QTimer::singleShot(80000, this, SLOT(fin_paroles()));
    attente_fin_paroles.exec();

    discours_initial_2->play();
    QTimer::singleShot(144000, this, SLOT(fin_paroles()));
    attente_fin_paroles.exec();

    annonce_attente_vote_suivant[0]->play();
}

void MainWindow::on_Bouton_annuler_1_clicked()
{
    this->appuyer_bouton_annuler(0);
}

void MainWindow::on_Bouton_annuler_2_clicked()
{
    this->appuyer_bouton_annuler(1);
}

void MainWindow::on_Bouton_annuler_3_clicked()
{
    this->appuyer_bouton_annuler(2);
}

void MainWindow::on_Bouton_annuler_4_clicked()
{
    this->appuyer_bouton_annuler(3);
}

void MainWindow::on_Bouton_annuler_5_clicked()
{
    this->appuyer_bouton_annuler(4);
}

void MainWindow::on_Bouton_annuler_6_clicked()
{
    this->appuyer_bouton_annuler(5);
}

void MainWindow::on_Bouton_annuler_7_clicked()
{
    this->appuyer_bouton_annuler(6);
}

void MainWindow::on_Bouton_annuler_8_clicked()
{
    this->appuyer_bouton_annuler(7);
}

void MainWindow::on_bouton_quitter_clicked()
{
    this->quitter();
}

void MainWindow::on_bouton_ok_vote_clicked()
{
    //Vérifie le code de l'accusé pour lui permettre de voter
    QString code = ui->ligne_code->text().toLower();
    bool code_bon = false;

    for (int i = 0; i<accuses.length(); i++)
    {
        if(code == accuses[i]->get_code())
        {
            //Si le code est bon, on lance l'interface de vote
            if(nb_elimines == accuses.length() - 1)
            {
                this->vote_final_accuse(accuses[i]);
                code_bon = true;
                break;
            }
            else
            {
                this->vote_accuse(accuses[i]);
                code_bon = true;
                break;
            }
        }
    }

     if(!code_bon) //Si le code est mauvais on informe code invalide et les lignes s'effacent
     {
         ui->stackedWidget_intervote->setCurrentIndex(5);
         ui->label_remerciement->setText("Code invalide !");

         QTimer::singleShot(2000, this, SLOT(fin_paroles()));
         attente_fin_paroles.exec();
         this->masquer_boutons_code_vote();

     }
}

void MainWindow::on_bouton_ok_code_sc_clicked()
{
    //Vérifie le code de l'accusé pour valider le code de la seconde chance

    if(ui->ligne_code_sc_2->text().toLower() == accuses[ui->comboBox_code_seconde_chance->itemData(ui->comboBox_code_seconde_chance->currentIndex()).toInt()]->get_code())
    {
        this->effets_code_seconde_chance();
    }

     else //Si le code est mauvais on informe code invalide et les lignes s'effacent
     {
         this->masquer_boutons_code_sc();
        ui->stackedWidget_intervote->setCurrentIndex(5);
        ui->label_remerciement->setText("Code invalide !");

         QTimer::singleShot(2000, this, SLOT(fin_paroles()));
         attente_fin_paroles.exec();
         ui->stackedWidget_intervote->setCurrentIndex(0);

     }
}

void MainWindow::on_bouton_voter_clicked()
{
    this->identifier_accuse();
}

void MainWindow::on_bouton_reporter_vote_clicked()
{
    temps_limite_vote->stop();
    attente_vote.quit();
    attente_vote_final.quit();
    temps_restant_vote = 0;
}

void MainWindow::on_bouton_reporter_vote_final_clicked()
{
    temps_limite_vote->stop();
    attente_vote.quit();
    attente_vote_final.quit();
    temps_restant_vote = 0;
}

void MainWindow::on_bouton_charger_clicked()
{
    this->charger();

    //Si on n'a pas réussi à chargé on s'arrête là
    if(num_vote == 0)
    {
        return;
    }

    //Pour test du rapport final
    //ui->bouton_rapport->setVisible(true);

    //Si tous les candidats éliminés sauf un, on passe au vote final, sinon on continue
    if(nb_elimines == accuses.length() - 1)
    {
        for(int i=0; i<accuses.length(); i++)
        {
            if(!accuses[i]->get_ecarte())
            {
                accuses[i]->set_sauve();
            }
        }
        ui->label_phase->setText("VOTE FINAL");

        this->afficher_ecran_discours();

        ui->label_discours->setText("VOTE FINAL");

        jingle->play();
        QTimer::singleShot(2500, this, SLOT(fin_paroles()));
        attente_fin_paroles.exec();

        presentation_vote_final->play();
        QTimer::singleShot(86500, this, SLOT(fin_paroles()));
        attente_fin_paroles.exec();

        this->inter_vote_final();
    }
    else
    {
        if(temps_vote[num_vote-1] == temps_vote_initiaux[num_vote-1])
        {
            annonce_attente_vote_suivant[num_vote-1]->play();
        }
        else
        {
            switch(temps_vote[num_vote-1])
            {

                case 1200 :
                    anonce_attente_vote_suivant_modifie[0]->play();
                    break;

                case 900 :
                    anonce_attente_vote_suivant_modifie[1]->play();
                    break;

                case 600 :
                    anonce_attente_vote_suivant_modifie[2]->play();
                    break;
            }
        }

        ui->label_phase->setText("VOTE " + QString::number(num_vote));

        this->inter_vote();
    }
}

void MainWindow::on_bouton_rapport_clicked()
{
    //écrit un fichier pour rappel des évènements de la murder
    QFileDialog filedial;
    filedial.setFocus();
    QString nom_fichier = filedial.getSaveFileName(this, tr("Sauvegarder rapport"), "",tr("Fichiers csv (*.csv)"));
    int i;
    int j;
    int k;
    QString ligne;
    QString ligne2;
    QString ecarte;
    QString phrase_sc;
    bool code_sc;
    bool pluriel;
    QVector<bool> accuses_ecartes;
    int sauve;
    int sauve_2;

    if(!nom_fichier.isEmpty())
    {

        QFile fichier_rapport(nom_fichier);

        fichier_rapport.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream flux(&fichier_rapport);
        flux << "Rapport de partie Le Proces";
        flux << "\n";
        flux << "\n";
        QString date = QDate::currentDate().toString("dd/MM/yyyy");
        flux << "Date : " + date;
        flux << "\n";
        flux << "\n";
        flux << "Joueurs et joueuses (a completer) :";
        flux << "\n";
        flux << "\n";

        for(i=0; i<accuses.length(); i++)
        {
            flux << accuses[i]->get_nom() + " :";
            flux << "\n";
        }
        flux << "\n";
        flux << "\n";

        for(i=0; i<accuses.length(); i++)
        {
            accuses_ecartes.push_back(false);
        }

        for(i=0; i<num_vote; i++)
        {
            pluriel = false;

            ligne = ";";
            ligne2 = ";";
            flux << "********** Vote " + QString::number(i+1) + " **********";
            flux << "\n";
            flux << "\n";

            for(j=0; j<accuses.length(); j++)
            {
                ligne += accuses[j]->get_nom();
                ligne += ";";
                if (accuses_ecartes[j])
                {
                    ligne2 += "ecarte;";
                }
                else
                {
                    ligne2 += ";";
                }
            }
            flux << ligne;
            flux << "\n";
            flux << ligne2;
            flux << "\n";

            for(j=0; j<accuses.length(); j++)
            {
                ligne = "Vote de " + accuses[j]->get_nom() + " :;";
                for(k=0; k<accuses[j]->get_vote_i(i); k++)
                {
                    ligne += ";";
                }
                ligne += "1";
                flux << ligne;
                flux << "\n";
            }

            ligne = "Total votes contre :;";
            ecarte = "";
            code_sc = false;
            for(j=0; j<accuses.length(); j++)
            {
                ligne += QString::number(accuses[j]->get_nb_vote_contre_i(i));
                ligne += ";";

                //Si c'est l'accusé qui a utilisé le code de la seconde chance, il faut déterminer si les effets on eu lieu ce vote-ci
                if(accuses[j]->get_num_vote_code_sc() == i+1)
                {
                    switch(accuses[j]->get_effet_sc())
                    {
                        case 1 :
                        phrase_sc = "Pendant le vote, " + accuses[j]->get_nom() + " a utilise le code de la seconde chance a bon escient et a donc ete rehabilite";
                        accuses_ecartes[j] = false;
                        code_sc = true;
                        break;

                        case 2 :
                        phrase_sc = "Pendant le vote, " + accuses[j]->get_nom() + " a utilise le code de la seconde chance a mauvais escient et a donc ete ecarte";
                        accuses_ecartes[j] = true;
                        code_sc = true;
                        break;

                        case 3 :
                        phrase_sc = "Pendant le vote, " + accuses[j]->get_nom() + " a utilise le code de la seconde chance mais, comme il n'etait pas ecarte, cela n'a eu aucun effet";
                        code_sc = true;
                        break;

                    }
                }

                if(accuses[j]->get_num_vote_ecarte() == i+1)
                {
                    if(ecarte.isEmpty())
                    {
                        ecarte += accuses[j]->get_nom();
                    }
                    else
                    {
                        ecarte += ", " + accuses[j]->get_nom();
                        pluriel = true;
                    }
                    accuses_ecartes[j] = true;
                }
                else if(accuses[j]->get_num_vote_ecarte_2() == i+1)
                {
                    if(ecarte.isEmpty())
                    {
                        ecarte += accuses[j]->get_nom();
                    }
                    else
                    {
                        ecarte += ", " + accuses[j]->get_nom();
                        pluriel = true;
                    }
                    accuses_ecartes[j] = true;
                }
            }
            flux << ligne;
            flux << "\n";
            flux << "\n";
            if (code_sc)
            {
                flux << phrase_sc;
                flux << "\n";
                flux << "\n";
            }

            if (pluriel)
            {
                flux << "Les accuses ecartes a l'issue de ce vote sont : " + ecarte;
            }
            else
            {
                flux << "L'accuse ecarte a l'issue de ce vote est : " + ecarte;
            }

            flux << "\n";
            flux << "\n";
            flux << "\n";
        }

        ligne = ";";
        ligne2 = ";";
        flux << "\n";
        flux << "\n";
        flux << "\n";

        for(i=0; i<accuses.length(); i++)
        {
            if(!accuses[i]->get_ecarte())
            {
                sauve = i;
            }
        }

        flux << "A l'issue des premiers votes le premier accuse sauve est : " + accuses[sauve]->get_nom();
        flux << "\n";
        flux << "\n";
        flux << "\n";
        flux << "********** Vote final **********";
        flux << "\n";
        flux << "\n";

        for(i=0; i<accuses.length(); i++)
        {
            ligne += accuses[i]->get_nom();
            ligne += ";";
            if (accuses_ecartes[i])
            {
                ligne2 += "ecarte;";
            }
            else
            {
                ligne2 += ";";
            }
        }
        flux << ligne;
        flux << "\n";
        flux << ligne2;
        flux << "\n";

        for(i=0; i<accuses.length(); i++)
        {
            flux << accuses[i]->ecrire_resume_vote_final();
            flux << "\n";
        }

        ligne = "Total votes pour :;";
        for(i=0; i<accuses.length(); i++)
        {
           ligne += QString::number(accuses[i]->get_nb_vote_contre_i(9)) + ";";
        }
        flux << ligne;
        flux << "\n";
        flux << "\n";

        for(i=0; i<accuses.length(); i++)
        {
            if((accuses[i]->get_sauve()) && (i != sauve))
            {
                sauve_2 = i;
            }
        }

        flux << "A l'issue du vote final le deuxieme accuse sauve est : " + accuses[sauve_2]->get_nom();


        fichier_rapport.close();
    }
}

void MainWindow::on_bouton_test_clicked()
{
    //Quand on lance le test, on change juste les valeurs de temps des votes
     temps_vote[0] = 180;
     temps_vote[1] = 180;
     temps_vote[2] = 180;
     temps_vote[3] = 180;
     temps_vote[4] = 180;
     temps_vote[5] = 180;
     temps_vote[6] = 180;
     temps_vote[7] = 180;
     temps_vote[8] = 180;

     temps_vote_final = 480;

     temps_appel_accuses->setInterval(7000); //7 secondes

    //Démarage du discours initial
     this->afficher_ecran_discours();

    //------Début du jeu et présentation initiale------
    sonnerie->play();
    temps_disours_initial->start();
    discours_initial->play();

    QTimer::singleShot(80000, this, SLOT(fin_paroles()));
    attente_fin_paroles.exec();

    discours_initial_2->play();
    QTimer::singleShot(144000, this, SLOT(fin_paroles()));
    attente_fin_paroles.exec();

    annonce_attente_vote_suivant[0]->play();

    //------------------------------------

    //------Pour test du vote final------
//    num_vote = 9;
//    for(int i=1; i<accuses.length();i++)
//    {
//        this->ecarter_accuse(accuses[i]);
//    }

//    ui->label_Accuse1->setVisible(false);
//    ui->label_Accuse2->setVisible(false);
//    ui->label_phase->setVisible(true);
//    this->inter_vote_final();

    //------------------------------------

    //------Pour test en plein milieu d'un vote------
//    num_vote = 5;
//    for(int i=1; i<5;i++)
//    {
//        this->ecarter_accuse(accuses[i]);
//    }
//    ui->label_Accuse1->setVisible(false);
//    ui->label_Accuse2->setVisible(false);
//    ui->label_phase->setVisible(true);
//    annonce_attente_vote_suivant[num_vote-1]->play();
//    this->inter_vote();

    //------------------------------------

}

void MainWindow::on_bouton_option_clicked()
{
    Fenetre_options f(this);
    f.exec();
}
