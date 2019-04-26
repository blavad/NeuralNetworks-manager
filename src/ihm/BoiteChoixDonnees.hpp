
#ifndef __BOITE_CHOIX_DONNEES_HPP__
#define __BOITE_CHOIX_DONNEES_HPP__

#include "BoiteChoixFichier.hpp"

using namespace std;

/** 
 * \class BoiteChoixDonnees
 * \brief Composant graphique qui gère le choix du fichier de données
 * \author Samra
 * \version 1.0 
 * \date avril 2019
 * 
 * Ce module gere le choix des fichiers de données utilisés par le logiciel 
 * Cette classe hérite de BoiteChoixFichier
 * 
 */
class BoiteChoixDonnees : public BoiteChoixFichier {

        /**
         * \fn BoiteChoixDonnees(Panneau parent)
         * \brief Constucteur d'une boite de choix de fichier de données 
         * \param parent le panneau qui contient la boite
         */
         BoiteChoixDonnees(Panneau parent);

};

#endif
