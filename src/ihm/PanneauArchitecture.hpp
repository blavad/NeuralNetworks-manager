#ifndef __PANNEAU_ARCHITECTURE_HPP__
#define __PANNEAU_ARCHITECTURE_HPP__

#include "BoiteChoixCouche.hpp"
#include "../deeplearn/archi/Couche.hpp"
#include "BoiteChoixReseauNeurones.hpp"
#include "BoiteConnexionCouche.hpp"
#include "Panneau.hpp"

using namespace std;

/** 
 * \class PanneauArchitecture  
 * \brief Composant graphique principal de la partie création d'architecture du logiciel
 * \author David
 * \version 1.0 
 * \date avril 2019
 * 
 * Regroupe les differentes boites ( choix couche, RN ,connexion, etc ) dans un même Panneau
 * 
 */
class PanneauArchitecture : public Panneau {

    protected :
        /** \brief Boite de choix des couches à travailler */
        BoiteChoixCouche choixCouche;

        /** \brief Boite de choix du Reseau de Neurone à travailler */
        BoiteChoixReseauNeurones choixRN;

        /** \brief Boite de choix du Reseau de Neurone à travailler */
        BoiteConnexionCouche choixConnexion;

        /** \brief une Couche  */
        Couche* couche;
        
        /** \brief une paire de Couche*/
        pair < Couche*, Couche*> liaisonSelect; 

    public :

        /**
         * \brief Constructeur du panneau vide.
         */
        PanneauArchitecture();

        /**
         * \brief Méthode appelée lors du choix de l'ajout d'une couche. 
         */
        void ajouterCouche();
        
        /**
         * \brief Méthode appelée lors du choix de l'ajout d'un Reseau de Neurones.
         */
        void ajouterRN();
        
        /**
         * \brief Méthode appelée lors du choix d'ajouter une liaison
         */
        void ajouterLiaison();

        /**
         * \brief Méthode appelée lors du choix de la suppression d'une couche. 
         */
        void supprimerCouche();
        
        /**
         * \brief Méthode appelée lors de la suppression d'une liaison
         */
        void supprimerLiaison();
        
        /**
         * \brief Méthode mettant à jour la couche selectionnée
         */
        void selectCouche(Couche*);     
        
        /**
         * \brief Méthode mettant à jour la liaison selectionnée
         */
        void selectLiaison(Couche*,Couche*);     
        
		/**
         * \brief Méthode permettant d'acceder a la couche selectionnée
         */
        Couche* getCoucheSelectionnee();     
        
        /**
         * \brief Méthode permettant d'acceder à la liaisonn selectionnée
         */
        pair<Couche*, Couche*> getLiaison();    
        
    
};

#endif
