#ifndef __COUCHE_HPP__
#define __COUCHE_HPP__

#include "DimTenseur.hpp"
#include "Tenseur.hpp"
#include <string>

/** 
 * \class Couche
 * \brief Classe abstraite définissant les fonctionalités d'une couche.
 * \author David
 * \version 2.0 
 * \date juin 2019
 *
 * Cette classe permet de fixer les tailles (entrée/sortie) de la couche.
 * Une couche peut être dérivée et propagée.
 */
class Couche
{

protected:
  /** \brief La dimension du tenseur (= données) à l'entrée de la couche */
  DimTenseur dim_in;

  /** \brief La dimension du tenseur (= données) à la sortie de la couche */
  DimTenseur dim_out;

  /** \brief Le nom de la couche */
  std::string nom;

  /** \brief Garde La dernière entrée de la propagation utile à la rétropropagation */
  Tenseur entree;

  /** \brief Variable utilisée lors de la rétropropagation*/
  Tenseur tmp;

  /** \brief Les coordonnées x, y de la couche pour l'affichage */
  std::pair<double, double> coords;

public:

  /**
   * \brief Constructeur d'une couche par défault
   * \param no Le nom de la couche
   */
  Couche(const std::string no = "Couche");

  /**
   * \brief Constructeur d'une couche à partir de la taille des tenseurs d'entrée/sortie
   * \param din La dimension d'entrée
   * \param dout La dimension de sortie
   * \param no Le nom de la couche
   */
  Couche(DimTenseur din, DimTenseur dout, const std::string no = "Couche");

  /**
   * \brief Methode virtuelle permettant la propagation d'une couche à une autre.
   * \fn virtual Tenseur& propagation(Tenseur& t)
   * \param t Le tenseur d'entree
   * \return La sortie de la couche
   */
  virtual Tenseur &propagation(Tenseur &t);

  /**
   * \fn virtual Tenseur& derivee(Tenseur& t)
   * \brief Méthode virtuelle pour avoir la derivee de la couche
   * \param t Le tenseur pour lequel on veut la derivee
   * \return La derivee de la couche
   */
  virtual Tenseur& derivee(Tenseur &t);

  /**
   * \fn virtual void upDateDimOutput()
   * \brief Méthode virtuelle pour mettre à jour la dimension de sortie
   */
  virtual void upDateDimOutput();

  /**
   * \fn virtual std::string type()
   * \brief Méthode pour savoir le type de la couche
   * \return Le type de la couche
   */
  virtual std::string type();

  /**
   * \fn string getNom()
   * \brief Méthode pour obtenir le nom de la couche
   * \return Le nom de la couche
   */
  std::string getNom() const;
  
  /**
   * \fn string setNom(std::string nom)
   * \brief Méthode pour (re)définir le nom de la couche
   * \param Le nom de la couche
   */
  void setNom(std::string nom);

  /**
   * \fn DimTenseur getDimInput()
   * \brief Méthode pour obtenir la taille du tenseur à l'entrée de la couche
   * \return La taille du tenseur d'entrée
   */
  DimTenseur getDimInput() const;

  /**
   * \fn DimTenseur getDimOutput()
   * \brief Méthode pour obtenir la taille du tenseur à la sortie de la couche
   * \return La taille du tenseur de sortie
   */
  DimTenseur getDimOutput() const;


  /**
   * \fn void setDimInput(DimTenseur dimIn)
   * \brief Méthode pour fixer la taille du tenseur à l'entrée de la couche
   * \param dimIn La dimension du tenseur d'entrée
   */
  void setDimInput(DimTenseur dimIn);

  /**
   * \fn void setDimOutput(DimTenseur dimOut)
   * \brief Méthode pour fixer la taille du tenseur à la sortie de la couche
   * \param dimOut La dimension du tenseur de sortie
   */
  void setDimOutput(DimTenseur dimOut);

  /**
   * \fn int getX()
   * \brief Méthode pour obtenir la coordonnée x de la couche
   * \return La coordonnée x de la couche
   */
  double getX() const;

  /**
   * \fn int getY()
   * \brief Méthode pour obtenir la coordonnée y de la couche
   * \return La coordonnée y de la couche
   */
  double getY() const;

  /**
   * \fn void setPos(int, int);
   * \brief Méthode pour fixer les coordonnées de la couche
   * \param Les positions en x et en y 
   */
  void setPos(double, double);

  /**
  * \fn &getTmp
  * \brief Getter
  * \return L'attribut tmp
  */
  Tenseur &getTmp();

  /**
  * \brief Setter
  * \param Un tenseur
  */
  void setTmp(Tenseur t);

  /**
  * \brief Getter de la dernière entrée
  * \return  L'entrée de la couche
  */
  Tenseur getEntree() const;

  /**
  * \brief Setter de la dernière entrée 
  * \param Un tenseur
  */
  void setEntree(Tenseur t);

  /**
  * \brief Surcharge de l'opérateur <<
  */
  friend std::ostream &operator<<(std::ostream &os, const Couche &t);

};
#endif
