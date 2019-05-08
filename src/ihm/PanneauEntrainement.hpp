#ifndef __PANNEAU_ENTRAINEMENT_HPP__
#define __PANNEAU_ENTRAINEMENT_HPP__

//#include "BoiteChoixErreur.hpp"
//#include "BoiteChoixDonnees.hpp"
//#include "BoiteChoixReseauNeurones.hpp"
//#include "BoiteParametrage.hpp"
#include "Panneau.hpp"
//#include "../deeplearn/train/Apprentissage.hpp"

using namespace std;
/** 
 * \class PanneauEntrainement
 * \brief Composant graphique principal de la partie entrainement du logiciel
 * \author Samra
 * \version 1.0 
 * \date avril 2019
 * 
 * Classe gerant l'IHM liee a l'entrainement d'un Reseau de Neurones
 * 
 */

class PanneauEntrainement : public Panneau
{

  protected:
    /** \brief Apprentissage */
    //Apprentissage apprentissage;

    /** \brief Boite de choix de l'erreur*/
    //BoiteChoixErreur choixErreur;

    /** \brief Boite de choix des donnees*/
    //BoiteChoixDonnees choixDonnees;

    /** \brief Boite de choix du RN*/
    //BoiteReseauNeurones choixRN;

    /** \brief Bouton de démarrage de l'entrainement */
    //GtkButton demarrerEntrainement;

  public:
    /**
     * \brief Constructeur du panneau d'entrainement.
     */
    PanneauEntrainement();

    /**
     * \brief Méthode appelée après le choix de la fonction d'erreur. 
     */
    void ajouterErreur();

    /**
     * \brief Méthode appelée après le choix de donnees à ajouter. 
     */
    void ajouterDonnees();

    /**
     * \brief Méthode appelée après le choix d'un Reseau de Neurones. 
     */
    void ajouterRN();

    /**
     * \brief Méthode appelée lors du choix de sauvegarder le parametrage. 
     */
    void sauverParametrage();

    /**
     * \brief Méthode permettant de verifier si les parametres sont coherents. 
     */
    bool verifierOptions();


     /**
     * \fn void afficherContenu()
     * \brief Affiche le contenu spécifique du panneau
     */
    void afficherContenu(int argc, char* argv[]);

};

#endif