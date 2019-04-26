#include "Panneau.hpp"
#include "Boite.hpp"
#include "../deeplearn/train/ParametresApprentissage.hpp"

#ifndef __BOITE_PARAMETRAGE_HPP__
#define __BOITE_PARAMETRAGE_HPP__


/** 
 * \class BoiteChoixFichier
 * \brief Composant graphique qui gère le choix des paramètres d'apprentissage
 * \author Samra
 * \version 1.0 
 * \date avril 2019
 * 
 * Boite contenant les différents éléments graphique du choix des paramètres d'apprentissage
 * 
 */
class BoiteParametrage : public Boite{

    private :
        /** \brief Les parametres d'aprentissage  */
        ParametresApprentissage params;

    public :

         /**
         * \fn BoiteParametrage(Panneau parent)
         * \brief Constucteur prenant en paramètre un Panneau
         * \param parent un Panneau contenant déja un réseau de neurones
         */
        BoiteParametrage(Panneau parent);

         /**
         * \fn getParametrage()
         * \brief Getteur permettant d'acceder aux paramètres en attribut
	     * \return ParametresApprentissage
         */
         ParametresApprentissage getParametrage();

};

#endif
