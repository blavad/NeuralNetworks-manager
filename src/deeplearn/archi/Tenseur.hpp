#ifndef __TENSEUR_HPP__
#define __TENSEUR_HPP__

#include <vector>
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

protected:
  /** \brief valeur du tenseur */
  double *valeur;

  /** \brief Dimension du tenseur */
  DimTenseur dimT;

public:
  /**
   * \brief Constructeur d'un tenseur dont la taille est fixée grâce à des entiers. 
   * \param dims suite de dimensions 
   */
  Tenseur(std::vector<int> dims);

  /**
   * \brief Constructeur d'un tenseur dont la taille est fixée grâce à un objet DimTenseur. 
   */
  Tenseur(double *val, DimTenseur di);

  /**
   * \brief Destructeur d'un tenseur
   */
  ~Tenseur();

  /**
     *  \fn bool operator==(const Tenseur &)
     *  \param t le tenseur à comparer
     *  \return booleen
     */
  bool operator==(const Tenseur &);

  /**
     *  \fn bool operator!=(const Tenseur &)
     *  \param t le tenseur à comparer
     *  \return booleen
     */
  bool operator!=(const Tenseur &);

  /**
     *  \fn bool operator+(const Tenseur &, const Tenseur &)
     *  \param t1 et t2 les tenseurs à additioner
     *  \return l'addition des tenseurs
     */
  friend Tenseur operator+(const Tenseur &, const Tenseur &);

  /**
     *  \fn bool operator+(const Tenseur &, const Tenseur &)
     *  \param t1 et t2 les tenseurs à soustraire
     *  \return la soustraction
     */
  friend Tenseur operator-(const Tenseur &, const Tenseur &);

  /**
     *  \fn bool operator*(const Tenseur &, const Tenseur &)
     *  \param t1 et t2 les tenseurs à multiplier
     *  \return la multiplication
     */
  friend Tenseur operator*(const Tenseur &, const Tenseur &);

  /**
   * 
   */
  Tenseur operator[](const int);

  /**
   * \fn bool nextInd(std::vector<int> &)
   * \param liste d'indices
   * \return booleen verifiant si un indice suivant existe
   */
  bool nextInd(std::vector<int> &);

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
   * \fn double get(std::vector<int>)
   * \brief Recupere la valeur grace à un un multi-indice donnee
   * \param indices vecteur d'indices
   */
  double getValeur(std::vector<int> indices) const;

  /**
   * \fn void setValeur(double val, std::vector<int>)
   * \brief Met à jour la valeur grace à un un multi-indice donnee
   * \param val nouvelle valeur
   * \param indices vecteur d'indices
   */
  void setValeur(double val, std::vector<int> indices) const;

  /**
  * \fn void setValeur(void* vl)
  * \brief Méthode pour fixer la valeur du Tenseur
  * \param vl La valeur du tenseur
  */
  void setValeurs(double *vl) const;

  /**
  * \fn DimTenseur getDim()
  * \brief Méthode pour obtenir la dimension du Tenseur
  * \return La dimension du Tenseur
  */
  DimTenseur getDim() const;

  /**
  * \fn void setDim(DimTenseur di)
  * \brief Méthode pour fixer la dimension du Tenseur
  * \param vl La dimension du tenseur
  */
  void setDim(DimTenseur di);

  /**
   * \fn int getInd(std::vector<int> indices)
   * \brief Méthode permettant de passer de la représentation multi-indices à un indice unique
   * \param La liste d'indices
   */
  int getInd(std::vector<int> indices) const;
};

#endif
