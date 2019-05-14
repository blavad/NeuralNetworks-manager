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

  Apprentissage *appr = new Apprentissage();

  /** Conteneur principal */
  Gtk::VBox boiteV1;
  /** Conteneur secondaire */
  Gtk::HBox conteneur_secondaire;

  /** \brief L'affichage de l'architecture du réseau de neurones */
  BoiteArchitecture boiteArchi;

  /** \brief La liste de couches possibles */
  BoiteChoixMultiple *choixCouche;

  /** \brief Bouton de sauvegarde */
  Gtk::Button sauvegarder;

public:
  /**
    * \brief Constructeur du panneau vide.
    */
  Panneau();
  /**
    * \fn void sauvegarderRN()
    * \brief Méthode permettant la sauvegarde d'un Reseau de Neurones. 
    */
  void sauvegarderRN();
  /**
    * \fn void sauvegarderRN(string nomFichier)
    * \brief Méthode permettant la sauvegarde d'un reseau de neurones sous un nom donnée
    * \param nomFichier le nom du fichier en sortie
    */
  void sauvegarderRN(string nomFichier);
  /**
    * \fn ReseauNeurones getReseauNeurones()
    * \brief getteur permettant d'acceder au Reseau de Neurones en attribut de la classe
	  * \return le Reseau de neurones en attribut de la classe Panneau
    */
  ReseauNeurones *getReseauNeurones();
  void ajouterCouche();
};

#endif
