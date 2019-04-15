#ifndef __ReLU_HPP__
#define __ReLU_HPP__

#include <CoucheActivation.hpp>

/** 
 * \class Sigmoid
 * \brief Création de la fonction ReLU
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
    ReLU();

    /**
     * \fn Tenseur propagation(Tenseur t)
     * \brief Méthode permettant la propagation d'une couche à une autre.
     * \param t le tenseur d'entree
	 * \return la sortie de la fonction ReLU
     */
    Tenseur propagation(Tenseur t);
};

#endif
