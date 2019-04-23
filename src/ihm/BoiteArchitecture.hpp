#ifndef __BOITE_ARCHITECTURE_HPP__
#define __BOITE_ARCHITECTURE_HPP__

#include "../deeplearn/archi/ReseauNeurones.hpp"
#include <gtkmm.h>

 using namespace std;

/** 
 * \class BoiteArchitecture
 * \brief Gestion de l'interaction Homme/Machine liée au choix de l architecture
 * \author Marion
 * \version 1.0 
 * \date avril 2019
 *
 * Ce module gere le choix de l architecture du reseau de neurones utilisé par le logiciel 
 * Cette classe hérite de Boite
 */

class Panneau : public Boite {

    public :

        /**
         * \brief Constructeur d'une boite d'architecture.
         */
        BoiteArchitecture();

        /**
         * \fn BoiteArchitecture(ReseauNeurones rn)
         * \brief Constucteur prenant en paramètre un reseau de neurones
         * \param rn un réseau de neurones préalablement défini
         */
        BoiteArchitecture(ReseauNeurones rn);


		/**
         * \fn void afficher(ReseauNeurones rn)
         * \brief Méthode permettant l'affichage d'un reseau de neurones
         * \param rn le réseau de neurones
         */
        void afficher(ReseauNeurones rn);
    

};
#endif
