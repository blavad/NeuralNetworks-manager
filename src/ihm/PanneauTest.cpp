#ifndef __PANNEAU_TEST_CPP__
#define __PANNEAU_TEST_CPP__

#include "PanneauTest.hpp"
#include <gtkmm.h>

PanneauTest::PanneauTest(){

}


void PanneauTest::afficherContenu(int argc, char* argv[]){

	//Initialisation de la fenetre
	Gtk::Main app(argc, argv);
	Gtk::Window fenetre;
	fenetre.set_border_width(10);
	fenetre.resize(640, 480);
	fenetre.set_position(Gtk::WIN_POS_CENTER);

	//Premiere boite verticale
	Gtk::VBox boiteV1(true);
	Gtk::Label questionMenu("Que voulez vous faire ?");
	Gtk::Label zoneArchitecture("\"VISUALISATION DU RESEAU\"");
	
	//Deuxieme boite verticale
	Gtk::VButtonBox boiteV2(Gtk::BUTTONBOX_START,5);
	Gtk::Label labelAjoutReseauNeurones("Ajouter Réseau de neurones");
	Gtk::Button boutonAjoutReseauNeurones("...");
    boutonAjoutReseauNeurones.set_can_focus(false);
    Gtk::Label labelSelectionnerDonnees("Selectionner données");
    Gtk::Button boutonSelectionnerDonnees("...");
    boutonSelectionnerDonnees.set_can_focus(false);
    Gtk::Button boutonLancerTest("Lancer test");
    boutonLancerTest.set_can_focus(false);
    Gtk::Button boutonSauvegarder("Sauvegarder");
    boutonSauvegarder.set_can_focus(false);

    

    //Fusion des containers
    boiteV2.pack_start(labelAjoutReseauNeurones); 
    boiteV2.pack_start(boutonAjoutReseauNeurones); 
    boiteV2.pack_start(labelSelectionnerDonnees); 
    boiteV2.pack_start(boutonSelectionnerDonnees);
    boiteV2.pack_start(boutonLancerTest);  
    boiteV2.pack_start(boutonSauvegarder);
   


    boiteV1.pack_start(questionMenu);
    boiteV1.pack_start(zoneArchitecture);
    boiteV1.pack_end(boiteV2);

    //Mise en place de la fenetre
    fenetre.add(boiteV1); 
    fenetre.show_all();
	fenetre.set_title("Menu test");
	Gtk::Main::run(fenetre);

}



#endif
