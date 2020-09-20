#include "fenetre_options.h"
#include "ui_fenetre_options.h"

Fenetre_options::Fenetre_options(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::Fenetre_options)
{
    ui->setupUi(this);
    this->setWindowTitle("Options");
    ui->stackedWidget->setCurrentIndex(0);
    m = parent;
    temps_actuel = 300; //Par défaut on met 5 min

    int i;

    QSizePolicy sp_retain = ui->label_code_errone->sizePolicy();
    sp_retain.setRetainSizeWhenHidden(true);

    ui->label_code_errone->setSizePolicy(sp_retain);

    ui->label_code_errone->setVisible(false);

    //Remplissage du vecteur des combo-boxes
    combo_box_temps_votes.push_back(ui->comboBox_vote_1);
    combo_box_temps_votes.push_back(ui->comboBox_vote_2);
    combo_box_temps_votes.push_back(ui->comboBox_vote_3);
    combo_box_temps_votes.push_back(ui->comboBox_vote_4);
    combo_box_temps_votes.push_back(ui->comboBox_vote_5);
    combo_box_temps_votes.push_back(ui->comboBox_vote_6);
    combo_box_temps_votes.push_back(ui->comboBox_vote_7);
    combo_box_temps_votes.push_back(ui->comboBox_vote_8);
    combo_box_temps_votes.push_back(ui->comboBox_vote_9);
    combo_box_temps_votes.push_back(ui->comboBox_vote_final);


    for(i=0; i<m->get_temps_vote().length(); i++)
    {
        combo_box_temps_votes[i]->addItem("10 min");
        combo_box_temps_votes[i]->addItem("15 min");
        combo_box_temps_votes[i]->addItem("20 min");

        if(i == 0)
        {
            combo_box_temps_votes[i]->addItem("25 min");
        }

        switch(m->get_temps_vote_i(i))
        {
            case 1500 :
                combo_box_temps_votes[i]->setCurrentIndex(3);
                break;

            case 1200 :
                combo_box_temps_votes[i]->setCurrentIndex(2);
                break;

            case 900 :
                combo_box_temps_votes[i]->setCurrentIndex(1);
                break;

            case 600 :
                combo_box_temps_votes[i]->setCurrentIndex(0);
                break;
        }
    }
    combo_box_temps_votes[9]->addItem("20 min");
    combo_box_temps_votes[i]->setCurrentIndex(0);

    ui->ligne_nombre_minutes->setText("5");
    ui->ligne_nombre_minutes->setValidator(new QIntValidator(0, 2000, this));

}

Fenetre_options::~Fenetre_options()
{
    delete ui;
}

void Fenetre_options::fin_affichage()
{
    attente_fin_affichage.quit();
}

void Fenetre_options::on_bouton_ok_code_admin_clicked()
{
    if(ui->ligne_code_admin->text().toLower() == "tartan")
    {
        ui->label_code_admin->setText("");
        ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
        ui->ligne_code_admin->setText("");
        ui->label_code_errone->setVisible(true);

        QTimer::singleShot(2000, this, SLOT(fin_affichage()));
        attente_fin_affichage.exec();

        ui->label_code_errone->setVisible(false);
    }
}

void Fenetre_options::on_bouton_changer_temps_votes_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}



void Fenetre_options::on_bouton_changer_temps_instant_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Fenetre_options::on_bouton_retour_modif_votes_clicked()
{
    int i;

    for(i=0; i<m->get_temps_vote().length(); i++)
    {

        switch(m->get_temps_vote_i(i))
        {
            case 1500 :
                combo_box_temps_votes[i]->setCurrentIndex(3);
                break;

            case 1200 :
                combo_box_temps_votes[i]->setCurrentIndex(2);
                break;

            case 900 :
                combo_box_temps_votes[i]->setCurrentIndex(1);
                break;

            case 600 :
                combo_box_temps_votes[i]->setCurrentIndex(0);
                break;
        }
    }
    ui->stackedWidget->setCurrentIndex(1);
}

void Fenetre_options::on_bouton_valider_modif_votes_clicked()
{
    int i;

    for(i=1; i<combo_box_temps_votes.length()-1; i++)
    {
        switch(combo_box_temps_votes[i]->currentIndex())
        {
            case 0 :
                m->set_temps_vote_i(600,i);
                break;

            case 1 :
                m->set_temps_vote_i(900,i);
                break;

            case 2 :
                m->set_temps_vote_i(1200,i);
                break;
        }

        ui->stackedWidget->setCurrentIndex(1);
    }
}


void Fenetre_options::on_bouton_fermer_clicked()
{
    this->close();
}

void Fenetre_options::on_bouton_retour_temps_en_cours_clicked()
{
    ui->ligne_nombre_minutes->setText("5");
    ui->stackedWidget->setCurrentIndex(1);
}

void Fenetre_options::on_bouton_valider_temps_en_cours_clicked()
{
    int t = ui->ligne_nombre_minutes->text().toInt();
    t = t * 60;
    m->set_temps_restant(t);
    ui->ligne_nombre_minutes->setText("5");
    ui->stackedWidget->setCurrentIndex(1);
}
