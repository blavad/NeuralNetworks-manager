#include "BoiteChoixMultiple.hpp"

#ifndef __BOITE_CHOIX_COUCHE_HPP__
#define __BOITE_CHOIX_COUCHE_HPP__

using namespace std ;
/** 
 * \class BoiteChoixCouche
 * \brief Gestion de l'interaction Homme/Machine liée au choix des couches
 * \author Samra
 * \version 1.0 
 * \date avril 2019
 * 
 * Cette classe permet d'indiquer à l'utililsateur les differentes couches qu'il peut 
 * modifier et permet d'acceder à celle qu'il choisit
 * Cette classe hérite de BoiteChoixMultiple
 * 
 */
class BoiteChoixCouche: public BoiteChoixMultiple {

    /**
     * \fn BoiteChoixCouche(string ,vector<string> choix = vector<string>{})
     * \brief Constructeur d'une boite de choix de couche
     * \param nom un string correspondant au nom de la boite
     * \param choix la liste des choix possibles
     */
     BoiteChoixCouche(string nom, vector<string> choix = vector<string>{});

};

#endif
