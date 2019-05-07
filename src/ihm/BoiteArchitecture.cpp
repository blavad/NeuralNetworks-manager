#ifndef __BOITE_ARCHITECTURE_CPP__
#define __BOITE_ARCHITECTURE_CPP__

#include "../deeplearn/archi/ReseauNeurones.hpp"
#include <gtkmm.h>
#include "BoiteArchitecture.hpp"
#include "Boite.hpp"
 using namespace std;

BoiteArchitecture::BoiteArchitecture() : Boite ("Boite Architecture") {} 

/*BoiteArchitecture::BoiteArchitecture() : nomCouche(), labelnomCouche(){
	set_label("Boite Architecture");

	labelnomCouche.set_label("label 1");
	
	nomCouche.pack_start(labelnomCouche);
	labelnomCouche.set_label("label");
	nomCouche.pack_start(labelnomCouche);
	dimE.pack_start(labeldimE);
	dimS.pack_start(labeldimS);
	
	add(nomCouche);
	add(dimE);
	add(dimS);
	
	show_all();
} 

BoiteArchitecture::BoiteArchitecture(ReseauNeurones rn) {

	set_label("Boite Architecture");
	
	Gtk::VBox nomCouche;
	Gtk::VBox dimE;
	Gtk::VBox dimS;
	Gtk::Label labelnomCouche("1");
	Gtk::Label labeldimE("1");
	Gtk::Label labeldimS("1");
	
	nomCouche.pack_start(labelnomCouche);
	dimE.pack_start(labeldimE);
	dimS.pack_start(labeldimS);
	
	add(nomCouche);
	add(dimE);
	add(dimS);
	
	show_all();

	//for taille rn :
	//	nomCouche.pack_start()

	//Gtk::Grid g;
	
	//add(grid);

} */



#endif


/*
main(int argc, char* argv[]) {
	
	Gtk::Main app(argc, argv);
	Gtk::Window fenetre;
	BoiteArchitecture b;
	b.show();
	fenetre.add(b);

	/*Gtk::VBox boiteV(true);
	Gtk::Label l("label");
	boiteV.pack_end(l);
	fenetre.add(boiteV);///

	fenetre.show_all();
	Gtk::Main::run(fenetre);
}*/

