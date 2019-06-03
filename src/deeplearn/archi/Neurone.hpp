#ifndef __NEURONE_HPP__
#define __NEURONE_HPP__

#include "CoucheConnectee.hpp"

/**
 * \class CoucheConnectée
 * \brief Gère un neurone
 * \author Adrien
 * \version 2.0
 * \date juin 2019
 *
 * Classe permettant la création d'un neurone.
 * Cette classe hérite de la classe CoucheConnectée.
 */

class Neurone : public CoucheConnectee
{

public:
  /**
   * \brief Constructeur d'un neurone
   */
  Neurone(std::string no = "Neurone");

  /**
   * \fn std::string type()
   * \brief Méthode qui donne le type de couche : Neurone
   * \return string
   */
  std::string type();
};

#endif
