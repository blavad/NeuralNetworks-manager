#ifndef __COUCHE_ACTIVATION_HPP__
#define __COUCHE_ACTIVATION_HPP__

#include "Couche.hpp"
#include "Tenseur.hpp"

/** 
 * \class CoucheActivation
 * \brief Classe abstraite définissant les couches d'activation
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Classe permettant la création d'une couche d'activation de trois types différents (sigmoid,tangente hyperbolique ou Rectified Linear Units)
 * Cette classe hérite de la classe Couche.
 */

class CoucheActivation : public Couche
{

public:
  /**
     * \brief Constructeur d'une couche d'activation 
     * \param no le nom de la couche
     */
  CoucheActivation(const std::string no = "Activation");

  /**
     * \brief Constructeur d'une couche d'activation avec une dimension d'entree.
     * \param din la dimension du tenseur d'entrée
     * \param no le nom de la couche
     */
  CoucheActivation(DimTenseur din, const std::string no = "Activation");

   std::string type();

  void upDateDimOutput();
};

#endif
