#ifndef __TENSEUR_HPP__
#define __TENSEUR_HPP__

#include <vector>
#include "DimTenseur.hpp"

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
   double *valeur;

   /** \brief Dimension du tenseur */
   DimTenseur dimT;

 public:

  /**
   * \brief Constructeur par défault d'un tenseur. 
   */
  Tenseur();
   
   /**
   * \brief Constructeur d'un tenseur dont la taille est fixée dimension tensorielle est fixée grâce à la liste des dimensions dans cahque direction. 
   * \param dims suite de dimensions 
   */
   Tenseur(std::vector<int> dims);

   /**
   * \brief Constructeur d'un tenseur dont la taille est fixée grâce à un objet DimTenseur. 
   * \param di dimension tensorielle du tenseur
   */
   Tenseur(DimTenseur di);

   /**
   * \brief Destructeur d'un tenseur
   */
   ~Tenseur();

   /**
     *  \fn bool operator==(const Tenseur &)
     *  \brief Compare deux tenseurs
     *  \param t le tenseur à comparer
     *  \return booleen
     */
   bool operator==(const Tenseur &);

   /**
     *  \fn bool operator!=(const Tenseur &)
     *  \brief Compare deux tenseurs
     *  \param t le tenseur à comparer
     *  \return booleen
     */
   bool operator!=(const Tenseur &);

   /**
     *  \fn bool operator+(const Tenseur &, const Tenseur &)
     *  \brief Additionne deux tenseurs
     *  \param t1 le 1er tenseur de la addition
     *  \param t2 le 2nd tenseur de la addition
     *  \return l'addition des tenseurs
     */
   friend Tenseur operator+(const Tenseur &, const Tenseur &);

   /**
     *  \fn bool operator+(const Tenseur &, const Tenseur &)
     *  \brief Soustrait deux tenseurs
     *  \param t1 le 1er tenseur de la soustraction
     *  \param t2 le 2nd tenseur de la soustraction
     *  \return la soustraction
     */
   friend Tenseur operator-(const Tenseur &, const Tenseur &);

   /**
     *  \fn bool operator*(const Tenseur &, const Tenseur &)
     *  \brief Multiplie deux tenseurs
     *  \param t1 le 1er tenseur de la multiplication
     *  \param t2 le 2nd tenseur de la multiplication
     *  \return la multiplication
     */
   friend Tenseur operator*(const Tenseur &, const Tenseur &);

   /**
   * \fn bool nextInd(std::vector<int> &)
   * \brief Récupère l'indice suivant du tenseur
   * \param ind liste d'indices
   * \return booleen vérifiant si un indice suivant existe
   */
   bool nextInd(std::vector<int> &ind);

   /**
    * 
    */
   Tenseur appliquerFonction(double (*f)(double), Tenseur);

   /**
   * \fn void initValeurGaussienne()
   * \brief Initialise le tenseur selon une loi gaussienne
   */
   void initValeurGaussienne();

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
   * \fn void init()
   * \brief Alloue l'espace mémoire nécessaire au stockage du tenseur
   */
   void init();
};

#endif
