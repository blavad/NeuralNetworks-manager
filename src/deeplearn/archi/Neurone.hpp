#ifndef __NEURONE_HPP__
#define __NEURONE_HPP__

#include "CoucheConnectee.hpp"

/** 
 * \class CoucheConnectée
 * \brief Gère un neurone
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
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

  std::string type();
};

#endif
