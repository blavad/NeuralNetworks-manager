#ifndef __ERREUR_L1_HPP__
#define __ERREUR_L1_HPP__

#include "Erreur.hpp"

/** 
 * \class ErreurL1
 * \brief Gère le calcul de l'erreur commise lors d'un apprentissage suivant la norme L1.
 * \author Marion
 * \version 1.0 
 * \date avril 2019
 *
 * Module permettant le traitement de l'erreur commise lors d'un apprentissage suivant la norme L1.
 * Il permet également la récupération des données liées aux erreurs.
 * Il hérite de la classe Erreur.
 * 
 * 
 */
class ErreurL1 : public Erreur{

  public:
    /**
    * \brief Constructeur de l'erreur L1
    * 
    */
    ErreurL1();

    /**
      * \fn Tenseur eval(Tenseur sortieRN, Tenseur prediction)
      * \brief Methode Pour évaluer l'erreur L1 effectuée entre la sortie et la prediction
      * \param sortieRN Le tenseur de sortie du reseau de neurones
      * \param label La sortie souhaitée du réseau de neurones
      */
    Tenseur eval(Tenseur sortieRN, Tenseur label);

    /**
      * \fn void derivee(Tenseur sortieRN, Tenseur label)
      * \brief Méthode pour avoir la derivée de l'erreur effectuée entre la sortie et la prédiction
      * \param sortieRN Le tenseur de sortie du reseau de neurones
      * \param label La sortie souhaitée du reseau de neurones
      */
    Tenseur derivee(Tenseur sortieRN, Tenseur label);
};

#endif
