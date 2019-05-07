#ifndef __BOITE_CPP__
#define __BOITE_CPP__

#include <gtkmm.h>
#include <gtkmm/frame.h>
#include <string>
#include "Panneau.hpp"
#include "Boite.hpp"
 
Boite::Boite(string nom) {
	set_label(nom);
	show();
} 


#endif

/*
main(int argc, char* argv[]) {
	Gtk::Main app(argc, argv);
	Gtk::Window fenetre;
	Boite b("ma boite");
	fenetre.add(b);
	Gtk::Main::run(fenetre);
}*/
