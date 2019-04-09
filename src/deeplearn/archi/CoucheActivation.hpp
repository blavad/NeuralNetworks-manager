#include <Couche.hpp>


#ifndef __COUCHEACTIVATION_HPP__
#define __COUCHEACTIVATION_HPP__


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

class CoucheActivation {

    public :

        /**
         * \brief Constructeur d'une couche d'activation avec une taille fixée.
         */
        CoucheActivation(DimTenseur dim);

        /**
         * \fn Tenseur propagation(Tenseur t)
         * \brief Méthode permettant la propagation de la couche d'une étape à une autre.
         * \param t le tenseur
	 * \return Le tenseur à l'étape d'après
         */
        Tenseur propagation(Tenseur t);
};

#endif
