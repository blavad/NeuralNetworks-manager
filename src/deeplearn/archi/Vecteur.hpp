#ifndef __VECTEUR_HPP__
#define __VECTEUR_HPP__

#include "Tenseur.hpp"

/**
 * \class Vecteur
 * \brief Module qui permet la manipulation de vecteur
 * \author Marion
 * \version 2.0
 * \date juin 2019
 *
 * Classe qui crée un tenseur d'ordre 1 (= vecteur)
 *
 */
class Vecteur : public Tenseur
{

public:
  /**
     * \brief Constructeur d'un vecteur de longueur l
     * \param l : la longueur
     */
  Vecteur(int l);

  // virtual Vecteur operator=(const Vecteur copy);

  /**
     *  \fn virtual Vecteur &operator+(const Vecteur &v)
     *  \brief Somme de 2 vecteurs
     *  \param v le vecteur à additionner
     *  \return Vecteur
     */
  virtual Vecteur &operator+(const Vecteur &v);

  /**
     *  \fn virtual Vecteur &operator-(const Vecteur &v)
     *  \brief Différence de 2 vecteurs
     *  \param v le vecteur à soustraire
     *  \return Vecteur
     */
  virtual Vecteur &operator-(const Vecteur &v);

  /**
     *  \fn virtual Tenseur &operator*(Tenseur &t)
     *  \brief Multiplication d'un vecteur et d'un tenseur
     *  \param t le tenseur à multiplier
     *  \return Tenseur
     */
  virtual Tenseur &operator*(Tenseur &t);

  /**
     *  \fn int getLength() const
     *  \brief Renvoie la longueur du vecteur
     *  \return int : la longueur du vecteur
     */
  int getLength() const;

  };

#endif
