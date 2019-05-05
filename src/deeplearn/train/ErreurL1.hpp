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
 * Il herite de la classe Erreur.
 * 
 * 
 */
class ErreurL1 : public Erreur{

  public:
    /**
    * \brief Constructeur de l'erreur L1.
    * 
    */
    ErreurL1();

    /**
      * \fn Tenseur eval(Tenseur sortieRN, Tenseur prediction)
      * \brief Methode pour evaluer l'erreur L1 effectuee entre la sortie et la prediction.
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