#ifndef __TENSEUR_HPP__
#define __TENSEUR_HPP__

#include <ostream>
#include <cstdarg>
#include <initializer_list>
#include <vector>
#include "DimTenseur.hpp"
#include "exception/DimensionsIncompatiblesException.hpp"

/**
 * \class Tenseur
 * \brief Module permettant la manipulation de tenseurs
 * \author Adrien
 * \author David
 * \version 1.0
 * \date avril 2019
 *
 * Module permettant la manipulation de tenseurs de la taille souhaitée.
 * Les tenseurs sont une généralisation des vecteurs (tenseur d'ordre 1) et matrices (tenseur d'ordre 2).
 *
 */
class Tenseur
{

protected:
  /** \brief valeur du tenseur */
  double *valeur = NULL;

  /** \brief Dimension du tenseur */
  DimTenseur dimT;

public:
  /**
   * \brief Constructeur par défaut d'un tenseur.
   */
  Tenseur();

  /**
   * \brief Constructeur d'un tenseur dont la dimension tensorielle est fixée grâce à la liste des dimensions dans cahque direction.
   * \param dims suite de dimensions
   */
  Tenseur(std::vector<int> dims);

  /**
   * \brief Constructeur d'un tenseur dont la dimension tensorielle est fixée grâce à une suite d'entier de type {5,5,3}.
   * \param dims suite de dimensions sous la forme d'un ensemble {d1,d2,d3}
   */
  Tenseur(std::initializer_list<int> dims);

  /**
   * \brief Constructeur d'un tenseur dont la taille est fixée grâce à un objet DimTenseur.
   * \param di dimension tensorielle du tenseur
   */
  Tenseur(DimTenseur di);

  /**
   * \brief Constructeur par recopie de Tenseur
   * \param t le tenseur par recopie
   */
  Tenseur(const Tenseur &t);

  /**
   * \brief Destructeur d'un tenseur
   */
  ~Tenseur();

  /**
   * \fn void allocate()
   * \brief Alloue l'espace mémoire nécessaire au stockage du tenseur
   */
  void allocate();

  /**
     *  \fn Tenseur &operator=(Tenseur &copy)
     *  \brief Affecte un Tenseur à un autre
     *  \param copy la référence sur le tenseur à affecter
     *  \return une référence sur un tenseur
     */
  Tenseur &operator=(const Tenseur &copy);

  /**
   *  \fn Tenseur &operator=(const double &v)
   *  \brief Affecte un Tenseur à un autre
   *  \param copy la référence sur le tenseur à affecter
   *  \return une référence sur un tenseur
   */
  Tenseur &operator=(const double &v);

  /**
     *  \fn bool operator==(Tenseur &t)
     *  \brief Compare deux tenseurs
     *  \param t le tenseur à comparer
     *  \return booleen
     */
  bool operator==(Tenseur &t);

  /**
     *  \fn bool operator!=(Tenseur &t)
     *  \brief Compare deux tenseurs
     *  \param t le tenseur à comparer
     *  \return booleen
     */
  bool operator!=(Tenseur &t);

  /**
     *  \fn virtual Tenseur &mulTermeATerme(Tenseur &tt)
     *  \brief Multiplie deux tenseurs terme à terme
     *  \param tt le 2nd tenseur de la multiplication
     *  \return la multiplication
     */
  virtual Tenseur &mulTermeATerme(Tenseur &tt);

  /**
     *  \fn Tenseur &operator+(Tenseur &t)
     *  \brief Additionne deux tenseurs
     *  \param t le tenseur a additionner
     *  \return l'addition des tenseurs
     */
  virtual Tenseur &operator+(Tenseur &t);

  /**
     *  \fn Tenseur &operator-(Tenseur &t);
     *  \brief Soustrait deux tenseurs
     *  \param t1 le tenseur a soustraire
     *  \return la soustraction
     */
  virtual Tenseur &operator-(Tenseur &t);

  /**
     *  \fn Tenseur &operator*(Tenseur &t)
     *  \brief Multiplie deux tenseurs
     *  \param t le 2nd tenseur de la multiplication
     *  \return la multiplication
     */
  virtual Tenseur &operator*(Tenseur &t);

  /**
   * \fn friend std::ostream &operator<<(std::ostream &os, Tenseur &t)
   * \brief Redéfinition de l'opérateur d'affichage sur un flux
   * \param os le flux de sortie
   * \param t le tenseur a afficher
   * \return le flux
   */
  friend std::ostream &operator<<(std::ostream &os, Tenseur &t);

  /**
     *  \fn Tenseur &transpose(int d1 = 0, int d2 = 1))
     *  \brief Transpose le tenseur selon la direction d1->d2
     *  \return le tenseur transposé
     */
  Tenseur &transpose(int d1 = 0, int d2 = 1);

  /**
   * \fn bool nextInd(std::vector<int> &)
   * \brief Récupère l'indice suivant du tenseur
   * \param ind liste d'indices
   * \return booleen vérifiant si un indice suivant existe
   */
  bool nextInd(std::vector<int> &ind) const;
  bool nextInd(DimTenseur &dind) const;

  /**
    * \fn Tenseur* appliquerFonction((double (*f)(double))
    * \param f l'adresse de la fonction
    * \return le résultat de l'application de la fonction à tous les coefs du tenseur
    */
  Tenseur *appliquerFonction(double (*f)(double));

  /**
   * \fn void initValeurGaussienne()
   * \brief Initialise le tenseur selon une loi gaussienne
   */
  void initValeurGaussienne();

  /**
   * \fn void initValeurConstant(double)
   * \brief Initialise le tenseur avec des valeurs données en paramètre
   */
  void initValeurConstant(double v);

  /**
   * \fn void initValeurNulle()
   * \brief Initialise le tenseur avec des valeurs nulles
   */
  void initValeurNulle();

  /**
   * \fn void initValeurUnif()
   * \brief Initialise le tenseur selon une loi uniforme
   */
  void initValeurUnif();

  /**
   * \fn double get(std::vector<int>)
   * \brief Récupère la valeur grâce à un un multi-indice donnée
   * \param indices vecteur d'indices
   * \return la valeur à cette position
   */
  double getValeur(std::vector<int> indices) const;

  /**
   * \fn void setValeur(double val, std::vector<int>)
   * \brief Met à jour la valeur grâce à un un multi-indice donnée
   * \param val nouvelle valeur
   * \param indices vecteur d'indices
   */
  void setValeur(double val, std::vector<int> indices) const;

  /**
  * \fn DimTenseur getDim()
  * \brief Méthode pour obtenir la dimension du Tenseur
  * \return La dimension du Tenseur
  */
  DimTenseur getDim() const;

  /**
  * \fn int getDim(int)
  * \brief Méthode pour obtenir la i ème dimension tensorielle
  * \param i l'indice de la dimension
  * \return La ième dimension
  */
  int getDim(int i) const;

  /**
  * \fn int getOrdre()
  * \brief Méthode pour obtenir l'ordre du tenseur
  * \return L'ordre
  */
  int getOrdre() const;

  /**
  * \fn void setDim(DimTenseur di)
  * \brief Méthode pour fixer la dimension du Tenseur
  * \param di La dimension du tenseur
  */
  void setDim(DimTenseur di);

  /**
   * \fn int getInd(std::vector<int> indices)
   * \brief Passe de la représentation multi-indices à un indice unique
   * \param indices La liste d'indices
   * \return l'indice absolue
   */
  int getInd(std::vector<int> indices) const;

  /**
   * \fn int getTaille()
   * \brief Récupère le nombre de valeurs présentent dans le tenseur
   */
  int getTaille() const;

  /**
   * \fn setValeur(double val, int indice)
   * \brief Modifie la valeur d'un parametre
   * \param val la nouvelle valeur
   * \param indice la position absolu (indice de la représentation physique)
   */
  void setValeur(double val, int indice);

  double getValeur(int i) const;

  /**
   * \fn void lineariser()
   * \brief Linearise le tenseur
   */
  void lineariser();

  /**
   * \fn Tenseur concatener(Tenseur t2)
   * \brief Concatene deux tenseur
   * \param t2 le tenseur a concatener
   * \return le résultat de la concaténation
   */
  Tenseur concatener(Tenseur t2);

  /**
   * \fn Tenseur copie(int debut, int fin)
   * \brief Copie une partie d'un tenseur
   * \param debut l'indice de début
   * \param fin l'indice de fin
   * \return un tenseur contenant les indices copiés
   */
  Tenseur copie(int debut, int fin);
};

#endif
