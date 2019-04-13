#include <Tenseur.hpp>
#include <DimTenseur.hpp>
#include <CoucheCombinaison.hpp>

#ifndef __COUCHECONVOLUTIVE_HPP__
#define __COUCHECONVOLUTIVE_HPP__


/** 
 * \class CoucheConvolutive
 * \brief Création d'une couche convolutive
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Classe permettant la création d'une couche de combinaison de "type" convolutive.
 * Cette classe hérite de la classe CoucheCombinaison.
 */

class CoucheConvolutive {


    public :

        /**
         * \brief Constructeur d'une couche convolutive à partir de la longeur du filtre, de la hauteur du filtre et du nombre de filtres
         */
        CoucheConvolutive(int l_filtre,int h_filtre,int nb_filtres);

        /**
         * \brief Constructeur d'une couche convolutive à partir de la taille du tenseur d'entrée, de la longeur du filtre, de la hauteur du filtre et du nombre de     	 * filtres
         */
        CoucheConvolutive(DimTenseur di,int l_filtre,int h_filtre,int nb_filtres);

        /**
         * \fn Tenseur propagation(Tenseur t)
         * \brief Méthode permettant la propagation d'une couche à une autre.
         * \param t le tenseur
	 * \return Le tenseur à l'étape d'après
         */
        Tenseur propagation(Tenseur t);
};

#endif
