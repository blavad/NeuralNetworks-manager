#include "Panneau.hpp"
#include <vector>
#include "Boite.hpp"

#ifndef __PANNEAU_ARCHITECTURE_HPP__
#define __PANNEAU_ARCHITECTURE_HPP__


/** 
 * \class BoiteChoixMultiple
 * \brief Gestion de l'interaction Homme/Machine liée au choix de l'utilisateur
 * \author Samra
 * \version 1.0 
 * \date avril 2019
 * 
 * Cette classe permet d'indiquer à l'utililsateur les differentes options qui lui sont proposées et permet d'acceder à celle qu'il choisit
 * Cette classe hérite de Boite
 * 
 */
class BoiteChoixMultiple {

    private :
        /** \brief Un vecteur contenant l'emsemble des choix offerts à l'utilisateur  */
        vector <string> choix;

        /** \brief Un bouton pour valider le choix de l'utilisateur */
        Button validerSelection;

    public :

         /**
         * \fn BoiteChoixMultiple(String nom)
         * \brief Constucteur prenant en paramètre un string
         * \param Un string correspondant à un premier choix offert à l'utilisateur
         */
         BoiteChoixMultiple(String nom);

         /**
         * \fn ajouterChoix(string nom)
         * \brief Méthode permettant d'ajouter un string correpondant à un nouveau choix au vecteur de choix
         * \param Un string correspondant au nom du nouveau choix
         */
         void ajouterChoix(string nom);

         /**
         * \fn ajouterChoix(vector <string> liste_nom)
         * \brief Méthode permettant d'ajouter un plusieur string correpondant à des nouveaux choix au vecteur de choix
         * \param liste_nom le vecteur contenant les nouveaux noms de choix
         */ 
         void ajouterChoix(vector <string> liste_nom);

         /**
         * \fn supprimerChoix(string nom)
         * \brief Méthode permettant de supprimer un choix du vecteur de choix
         * \param un string correspondant au nom du choix à retirer
         */
         void supprimerChoix(string nom);
 
         /**
         * \fn getValeurSectionnee()
         * \brief Méthode permettant la lecture du choix de l'utilisateur
	 * \return le string choisie par l'utilisateur
         */
         string getValeurSectionnee();

};

#endif
