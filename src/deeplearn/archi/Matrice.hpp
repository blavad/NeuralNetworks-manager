#ifndef __MATRICE_HPP__
#define __MATRICE_HPP__

#include "Tenseur.hpp"
#include "Vecteur.hpp"
#include "DimTenseur.hpp"
#include "exception/DimensionsIncompatiblesException.hpp"
#include "exception/MethodeNonImplException.hpp"

/**
 * \class Matrice
 * \brief Module permettant la manipulation de matrices
 * \author Marion
 * \version 2.0
 * \date juin 2019
 *
 * Classe qui crée un tenseur d'ordre 2 (= une matrice).
 *
 */
class Matrice : public Tenseur
{

public:
  /**
     * \brief Constructeur par défaut d'une matrice
     */
  Matrice();

  /**
     * \brief Constructeur d'une matrice de taille lxc
     * \param l : le nombre de lignes
     * \param c : le nombre de colonnes
     */
  Matrice(int l, int c);

  /**
     * \brief Constructeur d'une matrice de taille lxc avec des valeurs
     * \param valeur : les valeurs
     * \param l : le nombre de lignes
     * \param c : le nombre de colonnes
     */
  Matrice(double *valeur, int l, int c);

//   virtual Matrice operator=(const Matrice copy);

  /**
   *  \fn virtual Matrice &operator+(const Matrice &m)
   *  \brief Fait la somme de 2 matrices
   *  \param m la matrice à ajouter
   *  \return une matrice
   */
  virtual Matrice &operator+(const Matrice &m);

  /**
   *  \fn virtual Matrice &operator-(const Matrice &m)
   *  \brief Fait la différence de 2 matrices
   *  \param m la matrice à soustraire
   *  \return une matrice
   */
  virtual Matrice &operator-(const Matrice &m);

  /**
   *  \fn virtual Tenseur &operator*(Tenseur &t)
   *  \brief Multiplie une matrice avec un tenseur
   *  \param t le tenseur à multiplier
   *  \return un tenseur
   */
  virtual Tenseur &operator*(Tenseur &t);

  /**
   *  \fn int getNbLignes() const
   *  \brief Renvoie le nombre de lignes de la matrice
   *  \return un entier : le nombre de lignes
   */
  int getNbLignes() const;

  /**
   *  \fn int getNbColonnes() const
   *  \brief Renvoie le nombre de colonnes de la matrice
   *  \return un entier : le nombre de colonnes
   */
  int getNbColonnes() const;

};

#endif
