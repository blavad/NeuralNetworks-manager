#ifndef __PANNEAU_MENU_PRINCIPAL_CPP__
#define __PANNEAU_MENU_PRINCIPAL_CPP__

#include "PanneauMenuPrincipal.hpp"
#include <gtkmm.h>

PanneauMenuPrincipal::PanneauMenuPrincipal(){

}


void PanneauMenuPrincipal::afficherContenu(int argc, char* argv[]){

	//Initialisation de la fenetre
	Gtk::Main app(argc, argv);
	Gtk::Window fenetre;
	fenetre.set_border_width(10);
	fenetre.resize(640, 480);
	fenetre.set_position(Gtk::WIN_POS_CENTER);


	//Boite verticale
	Gtk::VBox boiteV(true);
	Gtk::Label questionMenu("Que voulez vous faire ?");

	//Boite horizontale	
	Gtk::HButtonBox boiteH(Gtk::BUTTONBOX_SPREAD,10);
	Gtk::Button boutonCreer("Créer");
	boutonCreer.set_can_focus(false);
    Gtk::Button boutonEntrainer("Entraîner");
    boutonEntrainer.set_can_focus(false);
    Gtk::Button boutonTester("Tester");
    boutonTester.set_can_focus(false);
    
    //Redimensionnement
    questionMenu.set_size_request(10,10);
    boutonCreer.set_size_request(150,150);
    boutonEntrainer.set_size_request(150,150);
    boutonTester.set_size_request(150,150);

    //Fusion des containers
    boiteH.pack_start(boutonCreer); 
    boiteH.pack_start(boutonEntrainer); 
    boiteH.pack_start(boutonTester); 

    boiteV.pack_start(questionMenu);
    boiteV.pack_end(boiteH);


    //Mise en place de la fenetre
    fenetre.add(boiteV); 
    fenetre.show_all();
	fenetre.set_title("Menu principal");
	Gtk::Main::run(fenetre);

}



#endif