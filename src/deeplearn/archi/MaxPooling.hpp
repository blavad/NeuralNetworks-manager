#ifndef __MAX_POOLING_HPP__
#define __MAX_POOLING_HPP__

#include <Tenseur.hpp>
#include <DimTenseur.hpp>
#include <Couche.hpp>

/** 
 * \class MaxPooling 
 * \brief Classe gérant une couche de MaxPooling.
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Classe qui va effectuer l'opération de redimensionnement des images par la technique du MaxPooling.
 * 
 */

class MaxPooling : public Couche
{

private:
  /** \brief Le nombre de pixels reduits a un seul dans la premiere direction*/
  int pool_x;
  /** \brief Le nombre de pixels reduits a un seul dans la seconde direction*/
  int pool_y;

public:
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
   * \brief Méthode permettant la propagation d'une couche à une autre.
   * \param t le tenseur d'entree
	 * \return la sortie de la couche
   */
  Tenseur propagation(Tenseur t);
};

#endif
