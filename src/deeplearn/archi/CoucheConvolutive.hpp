#ifndef __COUCHE_CONVOLUTIVE_HPP__
#define __COUCHE_CONVOLUTIVE_HPP__

#include "CoucheCombinaison.hpp"

/**
 * \class CoucheConvolutive
 * \brief Gère les couche convolutive
 * \author Adrien
 * \version 2.0
 * \date juin 2019
 *
 * Classe permettant la création d'une couche de combinaison de "type" convolutive.
 *
 */
class CoucheConvolutive : public CoucheCombinaison
{

protected:
  /** \brief La longueur de chaque filtre */
  int l_filtre;
  /** \brief La hauteur de chaque filtre */
  int h_filtre;
  /** \brief Le nombre de filtres de la couche */
  int nb_filtres;
  /** \brief Le pas, le décalage appliqué */
  int pas;
  /** \brief Le "padding", la marge ajoutée */
  int padding;

public:
  /**
     * \brief Constructeur d'une couche convolutive à partir de la longueur du filtre, de la hauteur du filtre, du nombre de filtres
     */
  CoucheConvolutive(DimTenseur din, int l_fil, int h_fil, int nb_fil, std::string no, int pas = 1, int pad = 0);

  /**
     * \fn Tenseur& propagation(Tenseur &t)
     * \brief Méthode permettant la propagation dans la couche convolutive.
     * \param t le tenseur d'entree
     * \return la sortie de la couche
     */
  Tenseur &propagation(Tenseur &t);

  /**
   * \fn std::string type()
   * \brief Méthode qui donne le type de couche : CoucheConvolutive
   * \return string
   */
  std::string type();

  /**
     * \fn void setL_Filtre(int l_fil)
     * \brief Changer la longueur de chaque filtre
     */
  void setL_Filtre(int l_fil);

  /**
     * \fn void setH_Filtre(int h_fil)
     * \brief Changer la hauteur de chaque filtre
     */
  void setH_Filtre(int h_fil);

  /**
     * \fn void setNbFiltres(int nb_filtres)
     * \brief Changer le nombre de filtres
     */
  void setNbFiltres(int nb_filtres);

  /**
     * \fn void setPadding(int pad)
     * \brief Changer le padding
     */
  void setPadding(int pad);

  /**
     * \fn void setPas(int pas)
     * \brief Changer le pas
     */
  void setPas(int pas);

  /**
     * \fn void getL_Filtre()
     * \brief Recupere la longueur de chaque filtre
     */
  void getL_Filtre();

    /**
     * \fn void getH_Filtre()
     * \brief Recupere la hauteur de chaque filtre
     */
  void getH_Filtre();

  /**
     * \fn void getNbFiltres()
     * \brief Recupere le nombre de filtres
     */
  void getNbFiltres();

  /**
     * \fn void getPadding()
     * \brief Recupere le padding
     */
  void getPadding();

  /**
     * \fn void getPas()
     * \brief Recupere le pas
     */
  void setPas();
};

#endif
