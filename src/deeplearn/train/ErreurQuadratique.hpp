#ifndef __ERREUR_QUADRATIQUE_HPP__
#define __ERREUR_QUADRATIQUE_HPP__

#include "Erreur.hpp"

/** 
 * \class ErreurQuadratique
 * \brief Gère le calcul de l'erreur commise de facon quadratique lors d'un apprentissage.
 * \author Marion
 * \version 2.0 
 * \date juin 2019
 *
 * Module permettant le traitement de l'erreur quadratique commise lors d'un apprentissage.
 * Il permet également la récupération des données liées aux erreurs.
 * Il hérite de la classe Erreur.
 * 
 * 
 */
class ErreurQuadratique : public Erreur
{

  public:
    /**
    * \brief Constructeur de l'erreur quadratique
    * 
    */
    ErreurQuadratique();

    /**
      * \fn Tenseur eval(Tenseur sortieRN, Tenseur prediction)
      * \brief Methode pour évaluer l'erreur quadratique effectuée entre la sortie et la prediction
      * \param sortieRN Le tenseur de sortie du reseau de neurones
      * \param label La sortie souhaitée du reseau de neurones
      */
    Tenseur eval(Tenseur sortieRN, Tenseur label);

    /**
      * \fn void derivee(Tenseur sortieRN, Tenseur label)
      * \brief Méthode pour avoir la dérivée de l'erreur effectuée entre la sortie et la prédiction
      * \param sortieRN Le tenseur de sortie du reseau de neurones
      * \param label La sortie souhaitée du reseau de neurones
      */
    Tenseur derivee(Tenseur sortieRN, Tenseur label);
};

#endif
