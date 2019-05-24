#ifndef __DIALOGUE_PARAM_DATA_HPP__
#define __DIALOGUE_PARAM_DATA_HPP__

#include <gtkmm.h>
#include "BoiteChoixMultiple.hpp"
#include "Panneau.hpp"
#include <string>
#include <gtkmm.h>
#include <iostream>

class DialogueParamData : public Gtk::Dialog
{
protected:
    Gtk::Window *parent;
    Gtk::Box *boiteV;
    Gtk::Button choisirFolder, supp;
    Gtk::ComboBoxText *listeDossiers;

    std::vector<std::string> dossiers;
    std::string type;
    int l, h;

    void suppressionDossier();
    void ajoutDossier();

public:
    DialogueParamData(std::string titre, Gtk::Window *parent, std::vector<string> doss = vector<string>());
    std::vector<std::string> getNomDossiers();
    std::string getTypeDonnees();
    std::vector<int> getDimDonneesEntree();
    void setDimsPhoto(Gtk::SpinButton *sp_b, int &v);
};

#endif
