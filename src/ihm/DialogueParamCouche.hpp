#ifndef __DIALOGUE_PARAM_COUCHE_HPP__
#define __DIALOGUE_PARAM_COUCHE_HPP__

#include <string>

#include <gtkmm.h>
#include "../deeplearn/archi/Couche.hpp"
#include "../deeplearn/archi/DimTenseur.hpp"

/**
 * Class DialogueParamCouche
 * \brief Gere le dialogue avec le choix des parametres des couches
 * \author David
 * \version 2.0
 * \date juin 2019 
 */

class DialogueParamCouche : public Gtk::Dialog
{
protected:
    Gtk::Box *boiteV;
    Gtk::Label lab_nom;
    Gtk::Entry nom_couche;
    Couche *couche;

    Glib::RefPtr<Gtk::Adjustment> ajustement;
    Gtk::SpinButton compteurNbOutput;

public:
    DialogueParamCouche(std::string titre, Gtk::Window *parent, Couche *new_c);
    std::string getNomC();
    DimTenseur getDimOutput();
    void updateParams();
};

#endif
