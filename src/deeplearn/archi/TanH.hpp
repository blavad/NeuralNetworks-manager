#ifndef __TANH_HPP__
#define __TANH_HPP__

#include <CoucheActivation.hpp>

/** 
 * \class TanH
 * \brief Création d'une fonction tangente hyperbolique
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Classe permettant la création d'une fonction tangente hyperbolique
 * Cette classe hérite de la classe CoucheActivation.
 */

class TanH : public CoucheActivation
{
  public:
    /**
     * \brief Constructeur d'une fonction tangente hyperbolique.
     */
    TanH();

    /**
     * \fn Tenseur propagation(Tenseur t)
     * \brief Méthode permettant la propagation d'une couche à une autre.
     * \param t le tenseur d'entree
     * \return la sortie de la fonction tanH
     */
    Tenseur propagation(Tenseur t);
};

#endif
