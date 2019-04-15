#ifndef __COUCHE_CONVOLUTIVE_HPP__
#define __COUCHE_CONVOLUTIVE_HPP__

#include <Tenseur.hpp>
#include <DimTenseur.hpp>
#include <CoucheCombinaison.hpp>

/** 
 * \class CoucheConvolutive
 * \brief Création d'une couche convolutive
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Classe permettant la création d'une couche de combinaison de "type" convolutive.
 * 
 */

class CoucheConvolutive : public CoucheCombinaison
{

  private:
    /** \brief Le nombre de filtre de la couche */
    int nb_filtres;
    /** \brief La longueur de chaque filtre */
    int l_filtre;
    /** \brief La largeur de chaque filtre */
    int h_filtre;

  public:
    /**
     * \brief Constructeur d'une couche convolutive à partir de la longeur du filtre, de la hauteur du filtre et du nombre de filtres
     */
    CoucheConvolutive(int l_filtre, int h_filtre, int nb_filtres);

    /**
     * \brief Constructeur d'une couche convolutive à partir de la taille du tenseur d'entrée, de la longeur du filtre, de la hauteur du filtre et du nombre de     	 * filtres
     */
    CoucheConvolutive(DimTenseur di, int l_filtre, int h_filtre, int nb_filtres);

    /**
     * \fn Tenseur propagation(Tenseur t)
     * \brief Méthode permettant la propagation d'une couche a une autre.
     * \param t le tenseur d'entree
	 * \return la sortie de la couche
     */
    Tenseur propagation(Tenseur t);
};

#endif
