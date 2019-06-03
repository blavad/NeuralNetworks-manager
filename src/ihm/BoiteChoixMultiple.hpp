// #include "Panneau.hpp"
#include <vector>
#include <string>
#include <gtkmm.h>

#ifndef __BOITE_CHOIX_MULTIPLE_HPP__
#define __BOITE_CHOIX_MULTIPLE_HPP__

using namespace std;

class Panneau;

/** 
 * \class BoiteChoixMultiple
 * \brief Composant graphique qui gère la possibilité de choisir parmis différents choix et appliquer un traitement lors de la validation du choix.
 * \author Samra
 * \version 2.0 
 * \date juin 2019
 * 
 * Cette classe permet d'indiquer à l'utililsateur les differentes options qui lui sont proposées et permet d'aappliquer un traitement au clic sur le bouton valider.
 * 
 */
class BoiteChoixMultiple : public Gtk::Frame
{

protected:

    /** \brief Une VBox pour agencer la liste et le bouton l'un au dessus de l'autre */
    Gtk::VBox agencement;
    /** \brief La liste des choix possibles */
    Gtk::ComboBoxText listeChoix;
    /** \brief Un bouton pour valider le choix de l'utilisateur */
    Gtk::Button validerSelection;
    /** Panneau qui appel */
    Panneau *parent;
    /** Fonction a appliquer lors de la validation */
    void (Panneau::*f)(void);

public:
    /**
     * \fn BoiteChoixMultiple(string nom,vector<string> choix = vector<string>{})
     * \brief Constucteur prenant en paramètre un string
     * \param nom un string correspondant au nom de la boite
     * \param choix la liste des choix possibles
     */
    BoiteChoixMultiple(class Panneau *parent, void (Panneau::*f)(void), string nom, vector<string> choix = vector<string>{});

    /**
     * \fn void on_combo_changed()
     * \brief Traite le changement de choix sélectionner.
     * 
     */
    void on_combo_changed();

    /**
     * \fn getValeurSectionnee()
     * \brief Méthode permettant la lecture du choix de l'utilisateur sous forme de string.
	 * \return le choix de l'utilisateur
     */
    std::string getValeurSectionnee();

    /**
     * \fn void ajouterChoix(string valeur)
     * \brief Permet d'ajouter un choix à la liste de choix de la boite.
     * \param valeur la valeur du choix
     */
    void ajouterChoix(string valeur);

    /**
     * \fn void supprimerChoix(string valeur)
     * \brief Permet de supprimer un choix à la liste de choix de la boite.
     * \param valeur la valeur du choix
     */
    void supprimerChoix(string valeur);
};

#endif
