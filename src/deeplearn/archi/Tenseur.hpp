#include <DimTenseur.hpp>

#ifndef __TENSEUR_HPP__
#define __TENSEUR_HPP__

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
   */
  Tenseur(int dim, ...);

  /**
   * \brief Constructeur d'un tenseur dont la taille est fixée grâce à un objet DimTenseur. 
   */
  Tenseur(DimTenseur dim);

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
};

#endif
