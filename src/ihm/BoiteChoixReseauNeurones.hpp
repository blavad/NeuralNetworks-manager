
#ifndef __BOITE_CHOIX_RN_HPP__
#define __BOITE_CHOIX_RN_HPP__

#include "BoiteChoixFichier.hpp"

using namespace std;

/** 
 * \class BoiteChoixReseauNeurones
 * \brief Composant graphique qui gère le choix du fichier de RN
 * \author Samra
 * \version 1.0 
 * \date avril 2019
 * 
 * Ce module gere le choix des fichiers de reseau de neurones utilisés par le logiciel 
 * Cette classe hérite de BoiteChoixFichier
 * 
 */
class BoiteChoixReseauNeurones : public BoiteChoixFichier {

        /**
         * \fn BoiteChoixReseauNeurones(Panneau parent)
         * \brief Constucteur d'une boite de choix de fichier de réseau de neurones 
         * \param parent le panneau qui contient la boite
         */
         BoiteChoixReseauNeurones(Panneau parent);

};

#endif
