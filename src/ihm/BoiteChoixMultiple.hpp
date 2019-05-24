// #include "Panneau.hpp"
#include <vector>
#include <string>
#include "Boite.hpp"

#ifndef __BOITE_CHOIX_MULTIPLE_HPP__
#define __BOITE_CHOIX_MULTIPLE_HPP__

using namespace std;

class Panneau;

/** 
 * \class BoiteChoixMultiple
 * \brief Composant graphique qui gère une boite de contenant un choix multiple
 * \author Samra
 * \version 1.0 
 * \date avril 2019
 * 
 * Cette classe permet d'indiquer à l'utililsateur les differentes options qui lui sont proposées et permet d'accéder à celle qu'il choisit
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

    void on_combo_changed();

    /**
     * \fn getValeurSectionnee()
     * \brief Méthode permettant la lecture du choix de l'utilisateur
	 * \return le choix de l'utilisateur
     */
    std::string getValeurSectionnee();

    void ajouterChoix(string valeur);
    void supprimerChoix(string valeur);
};

#endif
