#include "BoiteChoixMultiple.hpp"

#ifndef __BOITE_ERREUR__HPP__
#define __BOITE_CHOIX_ERREUR_HPP__

using namespace std;
/** 
 * \class BoiteChoixErreur
 * \brief Composant graphique qui gère le choix de l'erreur (fonction de cout)
 * \author Samra
 * \version 1.0 
 * \date avril 2019
 * 
 * Cette classe permet à l'utilisateur de choisir la maniere dont il veut quantifier l'erreur
 * 
 */
class BoiteChoixErreur : public BoiteChoixMultiple
{

    /**
     * \fn BoiteChoixErreur(string nom,vector<string> choix = vector<string>{})
     * \brief Constructeur d'une boite de choix d'erreur
     * \param nom un string correspondant au nom de la boite
     * \param choix la liste des choix possibles
     */
    BoiteChoixErreur(string nom, vector<string> choix = vector<string>{});
};

#endif
