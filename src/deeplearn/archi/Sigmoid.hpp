#ifndef __SIGMOID_HPP__
#define __SIGMOID_HPP__

#include "CoucheActivation.hpp"

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
    Sigmoid(DimTenseur din, DimTenseur dout, std::string no);

    /**
     * \fn Tenseur propagation(Tenseur t)
     * \brief Méthode permettant la propagation d'une couche à une autre.
     * \param t le tenseur d'entree
     * \return la sortie de la fonction sigmoid = 1./1-e^(-t)
     */
    Tenseur propagation(Tenseur t);
};

#endif
