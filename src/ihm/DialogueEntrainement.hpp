#ifndef __DIALOGUE_ENTRAINEMENT_HPP__
#define __DIALOGUE_ENTRAINEMENT_HPP__

#include <gtkmm.h>
#include "BoiteChoixMultiple.hpp"
#include "Panneau.hpp"
#include <string>
#include <gtkmm.h>
#include <iostream>

/**
 * Class DialogueEntrainement
 * \brief Gere le dialogue avec les fonctions d'entrainement
 * \author David
 * \version 2.0
 * \date juin 2019 
 */

class DialogueEntrainement : public Gtk::Dialog
{
public:
    Gtk::Label  lab_count_epochs, lab_count_donnees;
    Gtk::Window *parent;
    Gtk::Box *boiteV;

    int nb_epochs, nb_donnees, max_epochs, max_donnees;

public:
    DialogueEntrainement(std::string titre, Gtk::Window *parent,int m_d = 0, int m_e = 0);
    void nextData();
};

#endif
