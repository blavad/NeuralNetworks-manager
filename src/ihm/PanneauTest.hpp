#ifndef __PANNEAU_TEST_HPP__
#define __PANNEAU_TEST_HPP__


#include "Panneau.hpp"


using namespace std;
/** 
 * \class PanneauEntrainement
 * \brief Composant graphique principal de la partie entrainement du logiciel
 * \author Samra
 * \version 1.0 
 * \date avril 2019
 * 
 * Classe gerant l'IHM liee au test d'un Reseau de Neurones
 * 
 */

class PanneauTest : public Panneau
{

  protected:
    

  public:
    /**
     * \brief Constructeur du panneau de test.
     */
    PanneauTest();

    

     /**
     * \fn void afficherContenu()
     * \brief Affiche le contenu spécifique du panneau
     */
    void afficherContenu(int argc, char* argv[]);

};

#endif