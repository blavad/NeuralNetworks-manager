#ifndef __BOITE_ARCHITECTURE_HPP__
#define __BOITE_ARCHITECTURE_HPP__

#include "../deeplearn/archi/ReseauNeurones.hpp"
#include <gtkmm.h>

 using namespace std;

/** 
 * \class BoiteArchitecture
 * \brief Boite contenant l'affichage du réseau de neurones
 * \author Marion
 * \version 1.0 
 * \date avril 2019
 *
 * Ce module gère l'affichage de l architecture du reseau de neurones utilisé par le logiciel 
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
