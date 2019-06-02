#ifndef __PANNEAU_HPP__
#define __PANNEAU_HPP__

//#include "../deeplearn/archi/ReseauNeurones.hpp"
#include <gtkmm.h>
#include "BoiteArchitecture.hpp"
#include <string>

#include "../deeplearn/archi/Couche.hpp"
#include "../deeplearn/archi/CoucheActivation.hpp"
#include "../deeplearn/archi/TanH.hpp"
#include "../deeplearn/archi/ReLU.hpp"
#include "../deeplearn/archi/Sigmoid.hpp"
#include "../deeplearn/archi/CoucheCombinaison.hpp"
#include "../deeplearn/archi/CoucheConnectee.hpp"
#include "../deeplearn/archi/Neurone.hpp"
#include "../deeplearn/archi/ReseauNeurones.hpp"
#include "../deeplearn/train/Apprentissage.hpp"
#include "../deeplearn/train/Erreur.hpp"
#include "../deeplearn/train/ErreurL1.hpp"
#include "../deeplearn/train/ErreurQuadratique.hpp"
#include "../deeplearn/train/ErreurEntropieCroisee.hpp"

using namespace std;

class BoiteChoixMultiple;

/** 
 * \class Panneau
 * \brief Composant graphique principal (qui contient tous les autres) 
 * \author Samra
 * \version 1.0 
 * \date avril 2019
 * 
 * Panneau contenant le contenant les différents contenus graphique (boites) du logiciel et les données.
 *
 */

class Panneau : public Gtk::Window
{

protected:
  /** \brief le réseau de neurones en cours */
  ReseauNeurones *reseauNeurones = new ReseauNeurones();

  /** \brief l'apprentissage et ses paramètres associés */
  Apprentissage *appr = new Apprentissage();

  /** Conteneur principal */
  Gtk::VBox boiteV1;

  /** Conteneur secondaire */
  Gtk::HBox conteneur_secondaire;

  /** \brief L'affichage de l'architecture du réseau de neurones */
  BoiteArchitecture boiteArchi;

  /** \brief La liste de couches possibles */
  BoiteChoixMultiple *choixCouche;

  /** \brief La liste des erreurs possibles */
  BoiteChoixMultiple *choixErreur;

public:
  /**
    * \brief Constructeur du panneau vide.
    */
  Panneau();

  /**
   * \fn void updateParams(Gtk::SpinButton *param, std::string type = "nb_epocs")
   * \brief Met à jour les paramètres de l'apprentissage selon les choix de l'utilisateur
   */
  void updateParams(Gtk::SpinButton *param, std::string type = "nb_epocs");

  /**
   * \fn void ajouterCouche()
   * \brief Méthode appelé lors du clic sur l'ajout d'une couche. 
   */
  void ajouterCouche();

  /**
   * \fn void ouvrirRN()
   * \brief Méthode appelé lors du clic sur le changement de fonction d'erreur. 
   */
  void changerErreur();

  /**
   * \fn void ouvrirRN()
   * \brief Méthode appelé lors du clic sur l'ouverture d'un réseau de neurones. 
   */
  void ouvrirRN();

  /**
   * \fn void sauvegarderRN()
   * \brief Méthode appelé lors du clic sur la sauvegarde du Reseau de Neurones actuel. 
   */
  void sauvegarderRN();

  /**
   * \fn void lancerEntrainement()
   * \brief Méthode appelé lors du clic sur le lancement de l'entrainement. 
   */
  void lancerEntrainement();

  /**
   * \fn void pdateZoom(Gtk::Scale *zoom)
   * \brief Méthode appelé lors du changement de position de la molette de zoom. 
   * \param zoom le pointeur sur l'élément graphique utilisé pour le zoom
   */
  void updateZoom(Gtk::Scale *zoom);

  /**
    * \fn ReseauNeurones getReseauNeurones()
    * \brief Getter permettant d'acceder au Reseau de Neurones en attribut de la classe
	  * \return le Reseau de neurones en attribut de la classe Panneau
    */
  Apprentissage *getApprentissage();
};

#endif
