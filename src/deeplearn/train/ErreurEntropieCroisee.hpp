#ifndef __ERREUR_ENTROPIE_CROISEE_HPP__
#define __ERREUR_ENTROPIE_CROISEE_HPP__

#include "Erreur.hpp"

/** 
 * \class ErreurEntropieCroisee
 * \brief Gère le calcul de l'erreur commise suivant l'entropie croisee lors d'un apprentissage.
 * \author Marion
 * \version 1.0 
 * \date avril 2019
 *
 * Module permettant le traitement de l'erreur commise suivant l'entropie croisee lors d'un apprentissage.
 * Il permet également la récupération des données liées aux erreurs.
 * Il herite de la classe Erreur.
 * 
 * 
 */
class ErreurEntropieCroisee : public Erreur
{

  public:
    /**
    * \brief Constructeur de l'erreur d'entropie croisee.
    * 
    */
    ErreurEntropieCroisee();
};

#endif