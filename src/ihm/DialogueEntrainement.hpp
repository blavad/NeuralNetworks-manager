#ifndef __DIALOGUE_ENTRAINEMENT_HPP__
#define __DIALOGUE_ENTRAINEMENT_HPP__

#include <gtkmm.h>
#include "BoiteChoixMultiple.hpp"
#include "Panneau.hpp"
#include <string>
#include <gtkmm.h>
#include <iostream>

class DialogueEntrainement : public Gtk::Dialog
{
public:
    Gtk::Label  lab_count_epochs, lab_count_donnees;
    Gtk::Window *parent;
    Gtk::Box *boiteV;

    int nb_epochs, nb_donnees, max_epochs, max_donnees;

public:
    DialogueEntrainement(std::string titre, Gtk::Window *parent);
    void nextData();
};

#endif
