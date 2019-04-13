#include <Couche.hpp>
#include <Tenseur.hpp>
#include <DimTenseur.hpp>

#ifndef __COUCHECOMBINAISON_HPP__
#define __COUCHECOMBINAISON_HPP__


/** 
 * \class CoucheCombinaison
 * \brief Gestion d'une couche de combinaison
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Classe permettant la création d'une couche de combinaison de deux types différents (convolutive ou connectée)
 * Cette classe hérite de la classe Couche.
 */

class CoucheActivation {


   private :
        /** \brief Le tenseur "décrivant" la couche */
        Tenseur params


    public :

        /**
         * \brief Constructeur d'une couche de combinaison avec une taille fixée.
         */
        CoucheCombinaison(DimTenseur di, DimTenseur do);

        /**
         * \fn Tenseur propagation(Tenseur t)
         * \brief Méthode permettant la propagation d'une couche à une autre.
         * \param t le tenseur
	 * \return Le tenseur à l'étape d'après
         */
        Tenseur propagation(Tenseur t);
};

#endif
