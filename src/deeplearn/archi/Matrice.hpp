#ifndef __MATRICE_HPP__
#define __MATRICE_HPP__

#include "Tenseur.hpp"
#include "DimTenseur.hpp"
#include "exception/DimensionsIncompatiblesException.hpp"

/** 
 * \class Matrice
 * \brief Module permettant la manipulation de matrices
 * \author Adrien
 * \author David
 * \version 1.0 
 * \date avril 2019
 *
 * Classe qui crée un tenseur d'ordre 2 (= une matrice).
 *
 */
class Matrice : public Tenseur
{

  public:
    /**
     * \brief Constructeur d'une matrice de taille lxc
     */
    Matrice(int l, int c);
    
    /**
     * \brief Constructeur d'une matrice de taille lxc
     */
    Matrice(double *valeur, int l, int c);
    
    /**
     *  \fn Tenseur operator*'(const Tenseur &)
     *  \brief Multiplie deux tenseurs
     *  \param t le 2nd tenseur de la multiplication
     *  \return la multiplication
     */
   Tenseur operator*(const Tenseur &t);
};

#endif
