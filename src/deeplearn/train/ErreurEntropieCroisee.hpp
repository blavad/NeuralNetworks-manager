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

    /**
      * \fn Tenseur eval(Tenseur sortieRN, Tenseur prediction)
      * \brief Methode pour evaluer l'erreur entropie croisee effectuee entre la sortie et la prediction.
      * \param sortieRN le tenseur de sortie du reseau de neurones.
      * \param label la sortie souhaitée du reseau de neurones.
      */
    Tenseur eval(Tenseur sortieRN, Tenseur label);

    /**
      * \fn void derivee(Tenseur t)
      * \brief Méthode pour avoir la derivee d'un tenseur donnee en entree
      * \param t le tenseur pour lequel on veut la derivee
      */
    Tenseur derivee(Tenseur t);
};

#endif