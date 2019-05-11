
#ifndef __BOITE_ARCHITECTURE_HPP__
#define __BOITE_ARCHITECTURE_HPP__

#include "../deeplearn/archi/ReseauNeurones.hpp"
#include <gtkmm.h>
#include <gtkmm/drawingarea.h>
#include <vector>


using namespace std;

/** 
 * \class BoiteArchitecture
 * \brief Composant graphique qui gère l'affichage du réseau de neurones
 * \author Marion
 * \version 1.0 
 * \date avril 2019
 *
 * Ce module gère l'affichage de l architecture du reseau de neurones utilisé par le logiciel 
 */

class BoiteArchitecture : public Gtk::DrawingArea
{
protected:

    static const int RAYON_COUCHE = 30;
    static const int EPAISSEUR_TRAIT = 3;
    double zoom = 1.;

    ReseauNeurones *rn;
    std::vector<std::pair<int,int>> coords;

public:
    /**
     * \brief Constructeur d'une boite d'architecture.
     */
    BoiteArchitecture();

    /**
     * \fn BoiteArchitecture(ReseauNeurones rn)
     * \brief Constucteur prenant en paramètre un reseau de neurones
     * \param rn un réseau de neurones préalablement défini
     */
    BoiteArchitecture(ReseauNeurones *res);

    virtual ~BoiteArchitecture();

    bool on_draw(const Cairo::RefPtr<Cairo::Context> &cr) override;
};
#endif
