#ifndef __RESEAU_NEURONES_HPP__
#define __RESEAU_NEURONES_HPP__

#include <vector>

#include "Graphe.hpp"
#include "Couche.hpp"
#include "Tenseur.hpp"

/** 
 * \class ReseauNeurones
 * \brief Classe liée à la création du réseau de neurones.
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Cette classe permet de créer un réseau de neurones : on peut ajouter/supprimer des couches/noeuds/arcs. 
 * 
 */

class ReseauNeurones : public Graphe<Couche>, public Couche
{

private:
  /** \brief La liste correspondant à la première couche du réseau */
  std::vector<Couche> couche_initiale;

  /** \brief La liste correspondant à la dernière couche du réseau */
  std::vector<Couche> couche_finale;

  /** \brief Le nom du réseau*/
  std::string nom;

public:
  /**
   * \brief Constructeur du réseau vide.
   */
  ReseauNeurones();

  /**
   * \brief Constructeur du réseau à partir de couches déjà crées. 
   */
  ReseauNeurones(Couche, ...);

  /**
   * \fn Tenseur propagation(Tenseur t)
   * \brief Méthode permettant la propagation dans un reseau de neurone.
   * \param t l'entree du reseau de neurone
	 * \return la sortie du reseau de neurone
   */
  Tenseur propagation(Tenseur t);

  /**
   * \fn void ajouterCoucheInitiale(Couche c)
   * \brief Ajout d'une la couche initiale.
   * \param c une couche déjà créée.
   */
  void ajouterCoucheInitiale(Couche c);

  /**
   * \fn void ajouterCoucheFinale(Couche c)
   * \brief Ajout d'une couche finale.
   * \param c une couche déjà créée.
   */
  void ajouterCoucheFinale(Couche c);

  /**
   * \fn void supprimerCoucheInitiale(Couche c)
   * \brief Suppression d'une couche initiale.
   * \param c une couche présente dans le réseau.
   */
  void supprimerCoucheInitiale(Couche c);

  /**
   * \fn void supprimerCoucheFinale(Couche c)
   * \brief Suppression d'une couche finale.
   * \param c une couche présente dans le rése 
   */
  void supprimerCoucheFinale(Couche c);

  /**
   * \fn string getNom()
   * \brief Méthode pour obtenir le nom du reseau de neurones
   * \return Le nom du RN
   */
  std::string getNom();
};

#endif
