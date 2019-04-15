#include "Boite.hpp"

#ifndef __PANNEAU_ARCHITECTURE_HPP__
#define __PANNEAU_ARCHITECTURE_HPP__


/** 
 * \class BoiteChoixFichier
 * \brief Gestion de l'interaction Homme/Machine liée au choix de fichier
 * \author Samra
 * \version 1.0 
 * \date avril 2019
 * 
 * Ce module gere le choix des fichiers (de donnée ou de reseau de neurones) utilisés par le logiciel 
 * Cette classe hérite de Boite
 * 
 */
class BoiteChoixFichier {

    private :
        /** 
        *\ brief Un string correspondant au choix du fichier  
        */
        string nomFichier;

    public :

         /**
         * \fn BoiteChoixFichier(Panneau parent)
         * \brief Constucteur prenant en paramètre un Panneau
         * \param parent un Panneau préalablement défini
         */
         BoiteChoixFichier(Panneau parent);

 
 
         /**
         * \fn getNomFichier()
         * \brief getteur permettant d'acceder au nom du fichier en attribut
	 * \return le string correspondant au nom du fichier
         */
         string getNomFichier();

};

#endif
