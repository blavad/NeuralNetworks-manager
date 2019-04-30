#ifndef __ReLU_HPP__
#define __ReLU_HPP__

#include "CoucheActivation.hpp"
#include <algorithm>

/** 
 * \class Sigmoid
 * \brief Gère la couche Rectified Linear Unit 
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Classe permettant la création d'une couche de type ReLU (= Rectified Linear Unit). C'est à dire f(x)=max(0,x)
 * 
 */

class ReLU : public CoucheActivation
{

  public:
    /**
     * \brief Constructeur de la fonction ReLU
     */
    ReLU(DimTenseur din, std::string no);

    /**
     * \fn Tenseur propagation(Tenseur t)
     * \brief Méthode permettant la propagation d'une couche à une autre.
     * \param t le tenseur d'entree
	   * \return la sortie de la fonction ReLU
     */
    Tenseur propagation(Tenseur t);

    /**
     * \fn double calcul(double d)
     * \brief Méthode qui calcule la valeur pour une fonction ReLu
     * \param d la valeur d'entrée
     * \return le résultat de la fonction
     */
    // double calcul(double x);
};

#endif
