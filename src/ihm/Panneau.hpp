#ifndef __RESEAUNEURONES_HPP__
#define __RESEAUNEURONES_HPP__

#include "../deeplearn/archi/ReseauNeurones.hpp"
#include <gtkmm.h>
#include "BoiteArchitecture.hpp"

 using namespace std;

/** 
 * \class Panneau
 * \brief Gestion du type Panneau
 * \author Samra
 * \version 1.0 
 * \date avril 2019
 *
 */

class Panneau {

    private :
        /** \brief Bouton de sauvegarde */
        GtkButton sauvegarder;

        /** \brief un Reseau de Neurones*/
        ReseauNeurones reseauNeurones;
        
        /** \brief une Boite Architecture */
        BoiteArchitecture boiteArchi;


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
        void sauvegarderRN(string nomFichier);


         /**
         * \brief getteur permettant d'acceder au Reseau de Neurones en attribut de la classe
	 * \return le Reseau de neurones en attribut de la classe Panneau
         */
       ReseauNeurones getReseauNeurones();


    

};
#endif
