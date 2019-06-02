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
     * \param no : string
     */
  ReLU(const std::string no="ReLU");

  /**
     * \brief Constructeur de la fonction ReLU
     * \param dout : la dimension de sortie
     * \param no : string
     */
  ReLU(DimTenseur dout, const std::string no="ReLU");

  /**
     * \fn Tenseur& propagation(Tenseur &t)
     * \brief Méthode permettant la propagation d'une couche à une autre.
     * \param t le tenseur d'entree
     * \return la sortie de la fonction ReLU
     */
  Tenseur& propagation(Tenseur &t);

  /**
     * \fn Tenseur& derivee(Tenseur &t);
     * \brief Methode permettant la derivation des composantes d'un tenseur
     * \param t le tenseur d'entree
     * \return le tenseur avec toutes ses composantes derivees
     */
  Tenseur& derivee(Tenseur &t);
};

#endif
