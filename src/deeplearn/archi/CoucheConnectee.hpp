#ifndef __COUCHE_CONNECTEE_HPP__
#define __COUCHE_CONNECTEE_HPP__

#include "CoucheCombinaison.hpp"

/** 
 * \class CoucheConnectee
 * \brief Gère les couches connectées
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Classe permettant la création d'une couche de combinaison de "type" connectée : tous les neurones sont reliés d'une couche à une autre.
 * 
 */

class CoucheConnectee : public CoucheCombinaison
{

public:
  /**
     * \brief Constructeur d'une couche connectée à partir du nombre de sorties
     */
  CoucheConnectee(int nb_sorties, std::string no = "Fully Connected");

  /**
     * \brief Constructeur d'une couche connectée à partir du nombre de sorties
     */
  CoucheConnectee(DimTenseur din, int nb_sorties, std::string no = "Fully Connected");

  /**
     * \fn Tenseur* propagation(Tenseur* t)
     * \brief Methode permettant la propagation d'une couche à une autre.
     * \param t le tenseur d'entree
	   * \return la sortie de la couche
     */
  Tenseur &propagation(Tenseur &t);

  /**
   * \fn Tenseur* derivee(Tenseur* t)
   * \brief Methode pour avoir la derivee de la couche
   * \param t le tenseur pour lequel on veut la derivee
   * \return la derivee de la couche
   */
  Tenseur *derivee(Tenseur *t);

  void setDimInput(DimTenseur dimIn);

  std::string type();

  /**
   * \fn void upDateDimOutput()
   * \brief Méthode pour mettre à jour la dimension de sortie
   */
  void upDateDimOutput();
};

#endif
