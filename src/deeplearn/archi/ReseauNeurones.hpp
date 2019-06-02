#ifndef __RESEAU_NEURONES_HPP__
#define __RESEAU_NEURONES_HPP__

#include <vector>

#include "Graphe.hpp"
#include "Couche.hpp"
#include "Tenseur.hpp"

using namespace std;

/** 
 * \class ReseauNeurones
 * \brief Module permettant la manipulation de réseaux de neurones.
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Cette classe permet de créer un réseau de neurones : on peut ajouter/supprimer des couches/noeuds/arcs. 
 * 
 */

class ReseauNeurones : public Graphe<Couche *>, public Couche
{

protected:
  /** \brief La liste correspondant à la première couche du réseau */
  std::vector<Couche *> couche_initiale;

  /** \brief La liste correspondant à la dernière couche du réseau */
  std::vector<Couche *> couche_finale;

  /** \brief La liste des tenseurs de sortie avec leur couche */
  std::vector<std::pair<Couche *, Tenseur *>> l;

  /** \brief La liste des couches visitees */
  std::vector<std::pair<Couche *, Couche *>> visite;

public:
  /**
   * \brief Constructeur du réseau vide.
   */
  ReseauNeurones(const std::string no = "ReseauNeurones");

  /**
   * \brief Constructeur du réseau à partir de couches déjà créées. 
   */
  ReseauNeurones(std::vector<Couche *> couches, const std::string no = "ReseauNeurones");

  // --------------------------------------------------------
  // --------- Redéfinition méthodes de Couche --------------
  // --------------------------------------------------------

  /**
   * \fn Tenseur* propagation(Tenseur* t)
   * \brief Méthode permettant la propagation dans un reseau de neurone.
   * \param t l'entree du reseau de neurone
	 * \return la sortie du reseau de neurones
   */
  Tenseur &propagation(Tenseur &t);
  void propagation(Couche *c, Tenseur &t);
  void propagation(Couche *cIn, Couche *cOut, Tenseur &t);

  /**
   * \fn Tenseur* derivee(Tenseur* t);
   * \brief Methode permettant la backpropagation d'un réseau de neurones
   * \param t le tenseur d'entree
   * \return le tenseur avec toutes ses composantes derivees
   */
  Tenseur &derivee(Tenseur &t);

  /**
   * \fn void upDateDimOutput()
   * \brief Met à jour la dimension de sortie du réseau de neurones
   */
  void upDateDimOutput();

  /**
   * \fn std::string type()
   * \brief Méthode pour savoir le type de la couche
   * \return le type de la couche
   */
  std::string type();

  /**
   * \fn void miseAJourDims()
   * \brief Met à jour les dimensions dans tout le réseau de neurones
   */
  void miseAJourDims();

  void retro(std::vector<Couche *> liste_Couches, Couche *f, Tenseur &t, double alpha);

  void retro(Couche *d, Tenseur &t, double alpha);

  // -----------------------------------------------------------------
  // --------- Redéfinition méthodes de Graphe<Couche*> --------------
  // -----------------------------------------------------------------

  /**
   * \fn void supprimerNoeud(Couche* noeud)
   * \brief Suppression d'un noeud du réseau de neurones.
   * \param noeud un noeud du Réseau de neurones.
   */
  void supprimerNoeud(Couche *noeud);

  /**
   * \fn void ajouterArc(Couche noeud_init,Couche noeud_final)
   * \brief Ajout d'une connexion entre couches.
   * \param noeud_init la couche d'où sortent les données.
   * \param noeud_final la couche où entrent les données.
   */
  void ajouterArc(Couche *noeud_init, Couche *noeud_final);

  /**
   * \fn void supprimerArc(Couche noeud_init,Couche noeud_final)
   * \brief Suppression d'une connexion entre couches.
   * \param noeud_init la couche d'où sortent les données.
   * \param noeud_final la couche où entrent les données.
   */
  void supprimerArc(Couche *noeud_init, Couche *noeud_final);

  /**
   * \fn void ajouterCoucheInitiale(Couche *c)
   * \brief Ajout d'une la couche initiale.
   * \param c une couche déjà créée.
   */
  void ajouterCoucheInitiale(Couche *c);

  /**
   * \fn void ajouterCoucheFinale(Couche *c)
   * \brief Ajout d'une couche finale.
   * \param c une couche déjà créée.
   */
  void ajouterCoucheFinale(Couche *c);

  /**
   * \fn void supprimerCoucheInitiale(Couche c)
   * \brief Suppression d'une couche initiale.
   * \param c une couche présente dans le réseau.
   */
  void supprimerCoucheInitiale(Couche *c);

  /**
   * \fn void supprimerCoucheFinale(Couche c)
   * \brief Suppression d'une couche finale.
   * \param c une couche présente dans le réseau.
   */
  void supprimerCoucheFinale(Couche *c);

  /**
   * \fn void sauvegarderReseau(Reseau reseau)
   * \brief Sauvegarde d'un réseau de neurones.
   * \param reseau le réseau qu'on veut sauvegarder.
   */
  void sauvegarderReseau(ReseauNeurones reseau);

  /**
   * \fn std::vector<Couche*> getCouchesInitiales()
   * \brief Retourne la liste des couches initiales
   * \return la liste des couches initiales
   */
  std::vector<Couche *> getCouchesInitiales();

  /**
   * \fn std::vector<Couche*> getCouchesFinales()
   * \brief Retourne la liste des couches finales
   * \return la liste des couches finales
   */
  std::vector<Couche *> getCouchesFinales();

  /** 
   * \fn bool isInitiale(Couche *c)
   * \brief teste si la couche est initiale
   * \return vrai si c'est une couche initiale
   */
  bool isInitiale(Couche *c);

  /** 
   * \fn bool isFinale(Couche *c)
   * \brief teste si la couche est finale
   * \return vrai si c'est une couche finale
   */
  bool isFinale(Couche *c);

  void display();

  bool tousArcsAntVisites(Couche *s);
  void miseAJourDims(Couche *c);
  void miseAJourDims(Couche *cIn, Couche *cOut);
  friend std::ostream &operator<<(std::ostream &os, const ReseauNeurones &r);
};

#endif
