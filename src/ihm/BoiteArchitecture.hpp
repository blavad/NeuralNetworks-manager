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
 * \author David
 * \version 2.0 
 * \date juin 2019
 *
 * Ce module gère l'affichage de l architecture du reseau de neurones utilisé par le logiciel 
 */
class BoiteArchitecture : public Gtk::DrawingArea
{
protected:
    /**\brief Rayon du dessin d'une couche  */
    static const int RAYON_COUCHE = 35;
    /**\brief Epaisseur de trait de dessin  */
    static const int EPAISSEUR_TRAIT = 2;
    /**\brief Zoom actuel (entre 0.3 et 2.)  */
    double zoom = 1.;
    /**\brief Dimensions de la zone de dessin  */
    int height, width;

    /**\brief Fenetre parent de la zone de dessin  */
    Gtk::Window *parent;
    /**\brief Pointeur sur le réseau de neurones actuel */
    ReseauNeurones *rn;

    /**\brief Couche sélectionnée */
    Couche *selected_couche;
    /**\brief Entrée du réseau */
    Couche *input;
    /**\brief Sortie du réseau  */
    Couche *output;

public:
    /**
     * \brief Constructeur d'une boite d'architecture.
     * \param parent la fenetre appelante
     */
    BoiteArchitecture(Gtk::Window *parent);

    /**
     * \fn BoiteArchitecture(ReseauNeurones rn)
     * \brief Constucteur prenant en paramètre un reseau de neurones
     * \param rn un réseau de neurones préalablement défini
     */
    BoiteArchitecture(Gtk::Window *parent, ReseauNeurones *res);

    virtual ~BoiteArchitecture();

    /**
     * \fn bool on_button_press_event(GdkEventButton *event)
     * \brief méthode gérant les clics dans la zone graphique
     * \param event l'événement capté (contient le type d'événement, sa localisation, etc)
     * \return vrai s'il n'ya pas eu de problèmes
     */
    bool on_button_press_event(GdkEventButton *event);

    /**
     * \fn void setReseauNeurones(ReseauNeurones *res)
     * \brief setter du pointeur sur réseau de neurones
     */
    void setReseauNeurones(ReseauNeurones *res);

    /**
     * \fn Couche *selectCouche(double x, double y);
     * \brief Selectionne la couche présente en coordonnées x,y
     * \param x la coordonnée en x
     * \param y la coordonnée en y
     * \return la couche (si elle existe) à cette position
     */
    Couche *selectCouche(double x, double y);

    /**
     * \fn bool isInputSelected();
     * \brief Teste si l'entrée est sélectionnée
     * \return vrai si l'entrée est sélectionnée
     */
    bool isInputSelected();

    /**
     * \fn bool isOutputSelected();
     * \brief Teste si la sortie est sélectionnée
     * \return vrai si la sortie est sélectionnée
     */
    bool isOutputSelected();

    /**
     * \fn bool on_draw(const Cairo::RefPtr<Cairo::Context> &cr) override
     * \brief Redéfinition de la méthode on_draw pour dessiner le contenu de la zone de dessin
     * \return vrai s'il n y a pas eu de problème
     */
    bool on_draw(const Cairo::RefPtr<Cairo::Context> &cr) override;

    /**
     * \fn void draw_arcs(const Cairo::RefPtr<Cairo::Context> &cr)
     * \brief Dessine les arcs du réseau de neurones
     */
    void draw_arcs(const Cairo::RefPtr<Cairo::Context> &cr);

    /**
     * \fn void draw_noeuds(const Cairo::RefPtr<Cairo::Context> &cr)
     * \brief Dessine les noeuds du réseau de neurones
     */
    void draw_noeuds(const Cairo::RefPtr<Cairo::Context> &cr);

    /**
     * \fn void draw_text_couche(const Cairo::RefPtr<Cairo::Context> &cr, Couche *couche, int x, int y, int rayon)
     * \brief Dessine le texte présent dans une couche
     * \param couche le pointeur sur la couche pour laquelle on dessine le texte
     * \param x la position du texte en x
     * \param y la position du texte en y
     * \param rayon le rayon de la couche
     */
    void draw_text_couche(const Cairo::RefPtr<Cairo::Context> &cr, Couche *couche, int x, int y, int rayon);

    /**
     * \fn void draw_text(const Cairo::RefPtr<Cairo::Context> &cr, std::string str, int x, int y, int size = 6)
     * \brief Dessine un texte à une position donnée
     * \param str le texte à écrire
     * \param x la position du texte en x
     * \param y la position du texte en y
     * \param int la taille de police du texte
     */
    void draw_text(const Cairo::RefPtr<Cairo::Context> &cr, std::string str, int x, int y, int size = 6);

    /**
     * \fn void draw_circle(const Cairo::RefPtr<Cairo::Context> &cr, int x, int y, int rayon, double r = 0., double v = 0.6, double b = 0.6)
     * \brief Dessine un cercle à une position donnée, d'un rayon donné et d'une couleur donnée
     * \param x la position du texte en x
     * \param y la position du texte en y
     * \param rayon le rayon du cercle
     * \param r le taux de rouge
     * \param v le taux de vert
     * \param b le taux de bleu
     */
    void draw_circle(const Cairo::RefPtr<Cairo::Context> &cr, int x, int y, int rayon, double r = 0., double v = 0.6, double b = 0.6);

    /**
     * \fn void setZoom(double z)
     * \brief Change la valeur du zoom
     * \param z le zoom
     */
    void setZoom(double z);
};
#endif
