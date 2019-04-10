#include <Tenseur.hpp>
#include <DimTenseur.hpp>
#include <Couche.hpp>

#ifndef __MAXPOOLING_HPP__
#define __MAXPOOLING_HPP__


/** 
 * \class MaxPooling 
 * \brief Classe liée au redimensionnement des images.
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Classe qui va effectuer l'opération de redimensionnement des images par la technique du MaxPooling.
 * Cette classe hérite de la classe Couche.
 * 
 */

class MaxPooling {

    public :

        /**
         * \brief Constructeur afin d'obtenir une image de taille pool_x par pool_y.
         */
        MaxPooling(DimTenseur dio, int pool_x, int pool_y);

       /**
         * \brief Constructeur afin d'obtenir une image de taille pool par pool.
         */
        MaxPooling(DimTenseur dio, int pool);
	
	/**
         * \fn Tenseur propagation(Tenseur t)
         * \brief Méthode permettant la propagation du réseau d'une étape à une autre.
         * \param t le tenseur
	 * \return Le tenseur à l'étape d'après
         */
        Tenseur propagation(Tenseur t);
};

#endif
