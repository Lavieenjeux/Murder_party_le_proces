#ifndef FENETRE_OPTIONS_H
#define FENETRE_OPTIONS_H

#include <QDialog>
#include <QComboBox>
#include "mainwindow.h"

namespace Ui {
class Fenetre_options;
}

class Fenetre_options : public QDialog
{
    Q_OBJECT

public:
    explicit Fenetre_options(MainWindow *parent = nullptr);
    ~Fenetre_options();


public slots:
    void fin_affichage();

private slots:
    void on_bouton_ok_code_admin_clicked();

    void on_bouton_changer_temps_votes_clicked();

    void on_bouton_changer_temps_instant_clicked();

    void on_bouton_retour_modif_votes_clicked();

    void on_bouton_valider_modif_votes_clicked();

    void on_bouton_fermer_clicked();

    void on_bouton_retour_temps_en_cours_clicked();

    void on_bouton_valider_temps_en_cours_clicked();

private:
    Ui::Fenetre_options *ui;
    MainWindow *m;
    int temps_actuel; //temps actuel du vote
    QVector<QComboBox*> combo_box_temps_votes; //Vecteur qui contient tous les combobox pour mieux les manipuler

    QEventLoop attente_fin_affichage;
};

#endif // FENETRE_OPTIONS_H
