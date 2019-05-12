#ifndef __BOITE_ARCHITECTURE_HPP__
#define __BOITE_ARCHITECTURE_HPP__

#include <gtkmm.h>
#include <gtkmm/drawingarea.h>
#include <vector>

#include <gtk/gtk.h>

#include "../deeplearn/archi/ReseauNeurones.hpp"

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
    static const int RAYON_COUCHE = 35;
    static const int EPAISSEUR_TRAIT = 2;
    double zoom = 1.;
    int height, width;

    ReseauNeurones *rn;

    Couche *selected_couche;
    Couche *input;
    Couche *output;


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

    bool on_button_press_event(GdkEventButton *event);
    bool on_key_press_event(GdkEventKey *event);
   
    void setReseauNeurones(ReseauNeurones *res);

    Couche *selectCouche(double x, double y);

    bool isInputSelected();

    bool isOutputSelected();

    bool on_draw(const Cairo::RefPtr<Cairo::Context> &cr) override;

    void draw_arcs(const Cairo::RefPtr<Cairo::Context> &cr);

    void draw_noeuds(const Cairo::RefPtr<Cairo::Context> &cr);

    void draw_text_couche(const Cairo::RefPtr<Cairo::Context> &cr, Couche *couche, int x, int y, int rayon);

    void draw_text(const Cairo::RefPtr<Cairo::Context> &cr, std::string str, int x, int y, int size = 6);

    void draw_circle(const Cairo::RefPtr<Cairo::Context> &cr, int x, int y, int rayon, double r = 0., double v = 0.6, double b = 0.6);
};
#endif
