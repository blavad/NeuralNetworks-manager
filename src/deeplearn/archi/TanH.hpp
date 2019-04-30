#ifndef __TANH_HPP__
#define __TANH_HPP__

#include "CoucheActivation.hpp"
#include <math.h>

/** 
 * \class TanH
 * \brief Création d'une fonction tangente hyperbolique
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Classe permettant la création d'une fonction tangente hyperbolique
 * Cette classe hérite de la classe CoucheActivation.
 */

class TanH : public CoucheActivation
{
  public:
    /**
     * \brief Constructeur d'une fonction tangente hyperbolique.
     */
    TanH(DimTenseur din, std::string no);

    /**
     * \fn Tenseur propagation(Tenseur t)
     * \brief Méthode permettant la propagation d'une couche à une autre.
     * \param t le tenseur d'entree
     * \return la sortie de la fonction tanH
     */
    Tenseur propagation(Tenseur t);

    /**
     * \fn double calcul(double d)
     * \brief Méthode qui calcule la valeur pour une fonction tangente hyperbolique
     * \param d la valeur d'entrée
     * \return le résultat de la fonction
     */
    // double calcul(double x);
};

#endif
