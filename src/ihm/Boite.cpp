#ifndef __BOITE_CPP__
#define __BOITE_CPP__

#include <gtkmm.h>
#include <string>
#include "Panneau.hpp"
#include "Boite.hpp"
 
Boite::Boite(string nom) {
	set_label(nom);
	show();
} 




/*
main(int argc, char* argv[]) {
	Gtk::Main app(argc, argv);
	Gtk::Window fenetre;
	fenetre.resize(640, 480);


	Gtk::Button bouton("Test"); 
    
    bouton.set_can_focus(false); 
	bouton.show(); 






	Gtk::VBox boiteV(true);
	Gtk::Label questionMenu("Que voulez vous faire ?");
	
	Gtk::HBox boiteH(true);
	Gtk::Button boutonCreer("Créer");
    Gtk::Button boutonEntrainer("Entraîner");
    Gtk::Button boutonTester("Tester");


    boiteH.pack_start(boutonCreer); 
    boiteH.pack_start(boutonEntrainer); 
    boiteH.pack_start(boutonTester); 

    boiteV.pack_start(questionMenu);
    boiteV.pack_start(boiteH);


    Gtk::Frame fra;
    fra.add(boiteV);

    fenetre.add(fra); 
    fenetre.show_all();

	
	fenetre.set_title("Menu principal");
	Gtk::Main::run(fenetre);
}
*/

#endif