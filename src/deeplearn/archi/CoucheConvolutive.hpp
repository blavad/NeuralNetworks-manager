#ifndef __COUCHE_CONVOLUTIVE_HPP__
#define __COUCHE_CONVOLUTIVE_HPP__

#include "CoucheCombinaison.hpp"

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

    /** \brief La longueur de chaque filtre */
    int l_filtre;
    /** \brief La largeur de chaque filtre */
    int h_filtre;
    /** \brief Le nombre de filtre de la couche */
    int nb_filtres;


  public:
    /**
     * \brief Constructeur d'une couche convolutive à partir de la longeur du filtre, de la hauteur du filtre et du nombre de filtres
     */
    //CoucheConvolutive(int l_fil, int h_fil, int nb_fil);

    /**
     * \brief Constructeur d'une couche convolutive à partir de la taille du tenseur d'entrée, de la longeur du filtre, de la hauteur du filtre et du nombre de     	 * filtres
     */
    CoucheConvolutive(DimTenseur din, DimTenseur dout, std::string no, Tenseur par, int l_fil, int h_fil, int nb_fil);

    /**
     * \fn Tenseur propagation(Tenseur t)
     * \brief Méthode permettant la propagation d'une couche a une autre.
     * \param t le tenseur d'entree
	 * \return la sortie de la couche
     */
    Tenseur propagation(Tenseur t);



    /**
     * \fn void setL_Filtre()
     * \brief Changer la longueur de chaque filtre
     */
    void setL_Filtre(int l_fil);


    /**
     * \fn void setParams()
     * \brief Changer la largeur de chaque filtre
     */
    void setH_Filtre(int h_fil);



    /**
     * \fn void setParams()
     * \brief Changer le nombre de filtres
     */
    void setParams(int nb_filtres);
};

#endif
