#include <Tenseur.hpp>
#include <DimTenseur.hpp>
#include <CoucheCombinaison.hpp>

#ifndef __COUCHECONNECTEE_HPP__
#define __COUCHECONNECTEE_HPP__


/** 
 * \class CoucheConnectée
 * \brief Création d'une couche connectée
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Classe permettant la création d'une couche de combinaison de "type" connectée : tous les neurones sont reliés d'une couche à une autre.
 * Cette classe hérite de la classe CoucheCombinaison.
 */

class CoucheConnectée {


    public :

        /**
         * \brief Constructeur d'une couche connectée à partir du nombre de sorties
         */
        CoucheConnectée(int nb_out);

        /**
         * \brief Constructeur d'une couche connectée à partir de la taille du tenseur d'entrée et du nombre de sorties
         */
        CoucheConnectée(DimTenseur di,int nb_out);

        /**
         * \fn Tenseur propagation(Tenseur t)
         * \brief Méthode permettant la propagation d'une couche à une autre.
         * \param t le tenseur
	 * \return Le tenseur à l'étape d'après
         */
        Tenseur propagation(Tenseur t);
};

#endif
