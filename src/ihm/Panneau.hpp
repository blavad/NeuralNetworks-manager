#include "ReseauNeuronnes.hpp"
#include <gtkmm.h>

#ifndef __RESEAUNEURONES_HPP__
#define __RESEAUNEURONES_HPP__


/** 
 * \class Panneau
 * \brief Gestion du type Panneau
 * \author Samra
 * \version 1.0 
 * \date avril 2019
 *
 * ??
 * Cette classe hérite de ?? 
 */

class Panneau {

    private :
        /** \brief Bouton de sauvegarde */
        Button sauvegarder;

        /** \brief un Reseau de */
        ReseauNeurones reseauNeurones;


    public :

        /**
         * \brief Constructeur du panneau vide.
         */
        Panneau();

        /**
         * \brief Méthode permettant la sauvegarde d'un Reseau de Neurones. 
         */
        void sauvegarderRN();


  	/**
         * \fn void sauvegarderRN(String nomFichier)
         * \brief Méthode permettant la sauvegarde d'un reseau de neurones sous un nom donnée
         * \param nomFichier le nom du fichier en sortie
         */
        void sauvegarderRN(String nomFichier);


         /**
         * \brief getteur permettant d'acceder au Reseau de Neurones en attribut de la classe
	 * \return le Reseau de neurones en attribut de la classe Panneau
         */
       ReseauNeurones getReseauNeurones();


    

};
#endif
