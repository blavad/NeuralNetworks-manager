#ifndef __PANNEAU_CPP__
#define __PANNEAU_CPP__

#include "Panneau.hpp"
#include <gtkmm.h>

Panneau::Panneau() : sauvegarder("sauvegarder"), boiteArchi() {

	
	boiteV.show();
	sauvegarder.show();
	boiteArchi.show();
	sauvegarder.set_can_focus(false);
	boiteV.pack_start(boiteArchi);
	boiteV.pack_end(sauvegarder);
	add(boiteV);


}

main(int argc, char* argv[]) {
	Gtk::Main app(argc, argv);
	Panneau p;
	Gtk::Main::run(p);

}
#endif
