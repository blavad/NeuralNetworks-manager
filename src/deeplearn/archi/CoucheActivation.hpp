#ifndef __COUCHE_ACTIVATION_HPP__
#define __COUCHE_ACTIVATION_HPP__

#include <Couche.hpp>
#include <Tenseur.hpp>
#include <DimTenseur.hpp>


/** 
 * \class CoucheActivation
 * \brief Gestion d'une couche d'activation
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
     * \brief Constructeur d'une couche d'activation avec une dimension d'entree.
     */
    CoucheActivation(DimTenseur dim);
};

#endif
