#ifndef __SIGMOID_HPP__
#define __SIGMOID_HPP__

#include "CoucheActivation.hpp"
#include <math.h>

/**
 * \class Sigmoid
 * \brief Création d'une couche Sigmoid
 * \author Marion
 * \version 2.0
 * \date juin 2019
 *
 * Classe permettant la création d'une fonction sigmoid.
 *
 */
class Sigmoid : public CoucheActivation
{

public:
  /**
   * \brief Constructeur d'une fonction sigmoid
   * \param no : string
   */
  Sigmoid(std::string no = "Sigmoid");

  /**
   * \brief Constructeur d'une fonction sigmoid
   * \param din : DimTenseur
   * \param no : string
   */
  Sigmoid(DimTenseur din, std::string no = "Sigmoid");

  /**
     * \fn Tenseur& propagation(Tenseur &t)
     * \brief Méthode permettant la propagation d'une couche à une autre.
     * \param t le tenseur d'entree
     * \return la sortie de la fonction sigmoid = 1./1-e^(-t)
     */
  Tenseur &propagation(Tenseur &t);

  /**
     * \fn Tenseur& derivee(Tenseur &t);
     * \brief Methode permettant de deriver les composantes d'un tenseur
     * \param t le tenseur d'entree
     * \return le tenseur avec toutes ses composantes derivees
     */
  Tenseur& derivee(Tenseur &t);

};

#endif
