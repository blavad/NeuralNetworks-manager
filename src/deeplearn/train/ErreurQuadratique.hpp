#ifndef __ERREUR_QUADRATIQUE_HPP__
#define __ERREUR_QUADRATIQUE_HPP__

#include "Erreur.hpp"

/** 
 * \class ErreurQuadratique
 * \brief Gère le calcul de l'erreur commise de facon quadratique lors d'un apprentissage.
 * \author Marion
 * \version 1.0 
 * \date avril 2019
 *
 * Module permettant le traitement de l'erreur quadratique commise lors d'un apprentissage.
 * Il permet également la récupération des données liées aux erreurs.
 * Il herite de la classe Erreur.
 * 
 * 
 */
class ErreurQuadratique : public Erreur
{

  public:
    /**
    * \brief Constructeur de l'erreur quadratique.
    * 
    */
    ErreurQuadratique();

    /**
      * \fn Tenseur eval(Tenseur sortieRN, Tenseur prediction)
      * \brief Methode pour evaluer l'erreur quadratique effectuee entre la sortie et la prediction.
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