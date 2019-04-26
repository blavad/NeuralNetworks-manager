#include "Panneau.hpp"
#include <vector>
#include <string>
#include "Boite.hpp"

#ifndef __BOITE_CHOIX_MULTIPLE_HPP__
#define __BOITE_CHOIX_MULTIPLE_HPP__

using namespace std ;
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
class BoiteChoixMultiple : public Boite {

    private :
        /** \brief Un vecteur contenant l'ensemble des choix offerts à l'utilisateur  */
        vector <string> choix;

        /** \brief Un bouton pour valider le choix de l'utilisateur */
        GtkButton validerSelection;

    public :

         /**
         * \fn BoiteChoixMultiple(string nom,vector<string> choix = vector<string>{})
         * \brief Constucteur prenant en paramètre un string
         * \param nom un string correspondant au nom de la boite
         * \param choix la liste des choix possibles
         */
         BoiteChoixMultiple(string nom, vector<strin> choix = vector<string>{});

         /**
         * \fn ajouterChoix(string nom)
         * \brief Méthode permettant d'ajouter des choix à la liste de choix
         * \param nom un string correspondant au nom du nouveau choix
         */
         void ajouterChoix(string nom);

         /**
         * \fn ajouterChoix(vector <string> liste_nom)
         * \brief Méthode permettant d'ajouter un ou plusieur choix à la liste de choix
         * \param liste_nom le vecteur contenant les nouveaux noms de choix
         */ 
         void ajouterChoix(vector <string> liste_nom);

         /**
         * \fn supprimerChoix(string nom)
         * \brief Méthode permettant de supprimer un choix du vecteur de choix
         * \param nom un string correspondant au nom du choix à retirer
         */
         void supprimerChoix(string nom);
 
         /**
         * \fn getValeurSectionnee()
         * \brief Méthode permettant la lecture du choix de l'utilisateur
	     * \return le choix de l'utilisateur
         */
         string getValeurSectionnee();

};

#endif
