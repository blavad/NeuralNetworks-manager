#ifndef __TANH_HPP__
#define __TANH_HPP__

#include "CoucheActivation.hpp"
#include <math.h>

/**
 * \class TanH
 * \brief Création d'une fonction tangente hyperbolique
 * \author Marion
 * \version 2.0
 * \date juin 2019
 *
 * Classe permettant la création d'une fonction tangente hyperbolique
 * Cette classe hérite de la classe CoucheActivation.
 */
class TanH : public CoucheActivation
{
public:
  /**
   * \brief Constructeur d'une fonction tangente hyperbolique.
   * \param no : string
   */
  TanH(std::string no="TanH");

  /**
     * \brief Constructeur d'une fonction tangente hyperbolique.
     * \param din : DimTenseur
     * \param no : string
     */
  TanH(DimTenseur din, std::string no="TanH");

  /**
     * \fn Tenseur& propagation(Tenseur &t)
     * \brief Methode permettant la propagation d'une couche a une autre.
     * \param t le tenseur d'entree
     * \return la sortie de la fonction tanH
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
