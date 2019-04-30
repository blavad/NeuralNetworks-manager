#ifndef __SIGMOID_HPP__
#define __SIGMOID_HPP__

#include "CoucheActivation.hpp"
#include <math.h>

/** 
 * \class Sigmoid
 * \brief Création d'une couche Sigmoid
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Classe permettant la création d'une fonction sigmoid.
 * 
 */

class Sigmoid : public CoucheActivation
{

  public:
    /**
     * \brief Constructeur d'une fonction sigmoid.
     */
    Sigmoid(DimTenseur din, std::string no);

    /**
     * \fn Tenseur propagation(Tenseur t)
     * \brief Méthode permettant la propagation d'une couche à une autre.
     * \param t le tenseur d'entree
     * \return la sortie de la fonction sigmoid = 1./1-e^(-t)
     */
    Tenseur propagation(Tenseur t);

    /**
     * \fn Tenseur derivee(Tenseur t);
     * \brief Methode permettant de deriver les composantes d'un tenseur
     * \param t le tenseur d'entree
     * \return le tenseur avec toutes ses composantes derivees
     */
    Tenseur derivee(Tenseur t);

    /**
     * \fn double calcul(double d)
     * \brief Méthode qui calcule la valeur pour une fonction Sigmoid
     * \param d la valeur d'entrée
     * \return le résultat de la fonction
     */
    // double calcul(double x);
};

#endif
