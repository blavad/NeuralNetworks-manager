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
 * Panneau contenant le contenant les différents contenus graphique (boites) du logiciel
 *
 */

class Panneau : public Gtk::Window
{

protected:
  /** \brief un Reseau de Neurones*/
  ReseauNeurones *reseauNeurones = new ReseauNeurones();

  /** \brief un objet de la classe apprentissage */
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

  void updateParams(Gtk::SpinButton *param, std::string type = "nb_epocs");
  void ajouterCouche();
  void changerErreur();
  void ouvrirRN();
  /**
    * \fn void sauvegarderRN()
    * \brief Méthode permettant la sauvegarde d'un Reseau de Neurones. 
    */
  void sauvegarderRN();
  void lancerEntrainement();
  void updateZoom(Gtk::Scale *zoom);

  /**
    * \fn ReseauNeurones getReseauNeurones()
    * \brief getteur permettant d'acceder au Reseau de Neurones en attribut de la classe
	  * \return le Reseau de neurones en attribut de la classe Panneau
    */
  ReseauNeurones *getReseauNeurones();
};

#endif
