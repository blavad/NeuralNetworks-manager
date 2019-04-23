
#ifndef __PANNEAU_ENTRAINEMENT_HPP__
#define __PANNEAU_ENTRAINEMENT_HPP__

#include "BoiteChoixErreur.hpp"
#include "BoiteChoixDonnees.hpp"
#include "BoiteChoixReseauNeurones.hpp"
#include "BoiteParametrage.hpp"
#include "Panneau.hpp"
#include "../deeplearn/archi/Apprentissage.hpp"

using namespace std;
/** 
 * \class PanneauEntrainement
 * \brief Gestion du type PanneauEntrainement
 * \author Samra
 * \version 1.0 
 * \date avril 2019
 * 
 *Classe gerant l'IHM liee a l'entrainement d'un Reseau de Neurones
 * 
 */

class PanneauEntrainement : public Panneau{

    private :
	
	/** \brief Apprentissage */
	Apprentissage apprentissage;
	
	/** \brief Boite de choix de l'erreur*/
	BoiteChoixErreur choixErreur

	/** \brief Boite de choix des donnees*/
	BoiteChoDonnees choixDonnees

	/** \brief Boite de choix du RN*/
	BoiteReseauNeurones choixRN


        /** \brief Bouton de demarrage de l'entrainement */
        GtkButton demarrerEntrainement;

	

    public :

	/**
         * \brief Constructeur du panneau d'entrainement.
         */
        PanneauEntrainement();

        /**
         * \brief Méthode permettant l'ajout d'une erreur. 
         */
        void ajouterErreur();

        /**
         * \brief Méthode permettant l'ajout de donnees. 
         */
        void ajouterDonnees();

        /**
         * \brief Méthode permettant l'ajout d'un Reseau de Neurones. 
         */
        void ajouterRN();

        /**
         * \brief Méthode permettant de sauvegarder le parametre. 
         */
        void sauverParametrage();

        /**
         * \brief Méthode permettant de verifier si les parametres sont coherents. 
         */
        bool verifierOptions();
        
