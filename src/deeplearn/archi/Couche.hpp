#ifndef __COUCHE_HPP__
#define __COUCHE_HPP__

#include "DimTenseur.hpp"
#include "Tenseur.hpp"
#include <string>

/** 
 * \class Couche
 * \brief Classe abstraite définissant les fonctionalités d'une couche.
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
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

public:
  Couche(const std::string no="Couche");

  /**
   * \brief Constructeur d'une couche à partir de la taille des tenseurs d'entrée/sortie
   */
  Couche(DimTenseur din, DimTenseur dout, const std::string no="Couche");

  /**
   * \brief Methode virtuelle permettant la propagation d'une couche à une autre.
   * \fn virtual Tenseur* propagation(Tenseur* t)
   * \param t le tenseur d'entree
	 * \return la sortie de la couche
   */
  virtual Tenseur* propagation(Tenseur* t);

  /**
   * \fn virtual Tenseur* derivee(Tenseur* t)
   * \brief Methode virtuelle pour avoir la derivee de la couche
   * \param t le tenseur pour lequel on veut la derivee
   * \return la derivee de la couche
   */
  virtual Tenseur* derivee(Tenseur* t);
  
  /**
   * \fn virtual bool afficher()
   * \brief Méthode pour savoir si la couche est affichée ou non
   * \return booléen vérifiant si l'affiche s'est bien déroulé
   */
  virtual bool afficher();

  /**
   * \fn string getNom()
   * \brief Méthode pour obtenir le nom de la couche
   * \return Le nom de la couche
   */
  std::string getNom() const;

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
   * \fn string setNom(std::string nom)
   * \brief Méthode pour (re)définir le nom de la couche
   * \param Le nom de la couche
   */
  void setNom(std::string nom);

  /**
   * \fn void setDimInput(DimTenseur dimIn)
   * \brief Méthode pour fixer la taille du tenseur à l'entrée de la couche
   * \param dimIn La dimension du tenseur d'entrée
   */
  void setDimInput(DimTenseur dimIn);

  /**
   * \fn void setDimOutput(DimTenseur dimOut)
   * \brief Méthode pour fixer la taille du tenseur à la sortie de la couche
   * \param dimIn La dimension du tenseur de sortie
   */
  void setDimOutput(DimTenseur dimOut);

};
#endif
