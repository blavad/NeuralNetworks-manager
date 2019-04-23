#ifndef __TENSEUR_HPP__
#define __TENSEUR_HPP__

#include "DimTenseur.hpp"

/** 
 * \class Tenseur
 * \brief Classe liée à la manipulation de tenseurs
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Cette classe permet de créer un tenseur de la taille souhaitée.
 * On peut initialiser un tenseur de trois façons différentes (uniforme,nulle,gaussienne).
 */

class Tenseur
{

private:
  /** \brief valeur du tenseur */
  void *valeur;

  /** \brief Dimension du tenseur */
  DimTenseur dim;

public:
  /**
   * \brief Constructeur d'un tenseur dont la taille est fixée grâce à des entiers. 
   * \param dim suite de dimensions 
   *
  Tenseur(int dim);/

  /**
   * \brief Constructeur d'un tenseur dont la taille est fixée grâce à un objet DimTenseur. 
   */
  Tenseur(void* val, DimTenseur di);

  /**
   * \fn void initValeurGaussienne()
   * \brief Initialisation du tenseur selon une loi gaussienne
   */
  void initValeurGaussienne();

  /**
   * \fn void initValeurNulle()
   * \brief Initialisation du tenseur avec des valeurs nulles
   */
  void initValeurNulle();

  /**
   * \fn void initValeurUnif()
   * \brief Initialisation du tenseur selon une loi uniforme
   */
  void initValeurUnif();


  /**
  * \fn void setValeur(void* vl)
  * \brief Méthode pour fixer la valeur du Tenseur
  * \param vl La valeur du tenseur
  */
  void setValeur(void* vl);


  /**
  * \fn void setDim(DimTenseur di)
  * \brief Méthode pour fixer la dimension du Tenseur
  * \param vl La dimension du tenseur
  */
  void setDim(DimTenseur di);


  /**
  * \fn int getValeur()
  * \brief Méthode pour obtenir la valeur du Tenseur
  * \return La valeur du Tenseur
  */
  void* getValeur();



  /**
  * \fn DimTenseur getDim()
  * \brief Méthode pour obtenir la dimension du Tenseur
  * \return La dimension du Tenseur
  */
  DimTenseur getDim();

};

#endif
