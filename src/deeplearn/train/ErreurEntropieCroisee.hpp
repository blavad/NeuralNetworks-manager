#ifndef __ERREUR_ENTROPIE_CROISEE_HPP__
#define __ERREUR_ENTROPIE_CROISEE_HPP__

#include "Erreur.hpp"
#include <math.h>
#include "../archi/Tenseur.hpp"

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

    /**
      * \fn Tenseur eval(Tenseur sortieRN, Tenseur prediction)
      * \brief Methode pour evaluer l'erreur entropie croisee effectuee entre la sortie et la prediction.
      * \param sortieRN le tenseur de sortie du reseau de neurones.
      * \param label la sortie souhaitée du reseau de neurones.
      */
    Tenseur eval(Tenseur sortieRN, Tenseur label);

    /**
      * \fn void derivee(Tenseur sortieRN, Tenseur label)
      * \brief Méthode pour avoir la derivee de l'erreur effectuee entre la sortie et la prediction
      * \param sortieRN le tenseur de sortie du reseau de neurones.
      * \param label la sortie souhaitée du reseau de neurones.
      */
    Tenseur derivee(Tenseur sortieRN, Tenseur label);
};

#endif