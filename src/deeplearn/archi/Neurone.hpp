#include <Tenseur.hpp>
#include <DimTenseur.hpp>
#include <CoucheConnectée.hpp>

#ifndef __NEURONE_HPP__
#define __NEURONE_HPP__


/** 
 * \class CoucheConnectée
 * \brief Création d'un neurone
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Classe permettant la création d'un neurone.
 * Cette classe hérite de la classe CoucheConnectée.
 */

class CoucheConnectée {


    public :

        /**
         * \brief Constructeur d'une couche connectée à partir du nombre de sorties
         */
        CoucheConnectée(int nb_out);


        /**
         * \fn Tenseur propagation(Tenseur t)
         * \brief Méthode permettant la propagation d'un neurone à un autre.
         * \param t le tenseur
	 * \return Le tenseur à l'étape d'après
         */
        Tenseur propagation(Tenseur t);
};

#endif
