#ifndef __PANNEAU_ARCHITECTURE_CPP__
#define __PANNEAU_ARCHITECTURE_CPP__

#include "PanneauArchitecture.hpp"
#include <gtkmm.h>

PanneauArchitecture::PanneauArchitecture(){

}


void PanneauArchitecture::afficherContenu(int argc, char* argv[]){

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
    Gtk::Label labelAjoutCoucheCombinaison("Ajouter une couche de combinaison");
    Gtk::ComboBoxText listeChoixCoucheCombinaison;
    listeChoixCoucheCombinaison.append("Couche connectée");
    listeChoixCoucheCombinaison.append("Couche convolutive");
    listeChoixCoucheCombinaison.append("Neurone");
    listeChoixCoucheCombinaison.set_active_text("Couche connectée");
    Gtk::Button boutonAjoutCoucheCombinaison("Ajouter");
    boutonAjoutCoucheCombinaison.set_can_focus(false);
    Gtk::Label labelAjoutCoucheActivation("Ajouter une couche d'activation");
    Gtk::ComboBoxText listeChoixCoucheActivation;
    listeChoixCoucheActivation.append("ReLU");
    listeChoixCoucheActivation.append("Sigmoid");
    listeChoixCoucheActivation.append("TanH");
    listeChoixCoucheActivation.set_active_text("ReLU");
    Gtk::Button boutonAjoutCoucheActivation("Ajouter");
    boutonAjoutCoucheActivation.set_can_focus(false);
    Gtk::Button boutonSauvegarder("Sauvegarder");
    boutonSauvegarder.set_can_focus(false);
    Gtk::Button boutonEntrainer("Entraîner");
    boutonEntrainer.set_can_focus(false);


    //Fusion des containers
    boiteV2.pack_start(labelAjoutReseauNeurones); 
    boiteV2.pack_start(boutonAjoutReseauNeurones); 
    boiteV2.pack_start(labelAjoutCoucheCombinaison);
    boiteV2.pack_start(listeChoixCoucheCombinaison);
    boiteV2.pack_start(boutonAjoutCoucheCombinaison);    
    boiteV2.pack_start(labelAjoutCoucheActivation);
    boiteV2.pack_start(listeChoixCoucheActivation); 
    boiteV2.pack_start(boutonAjoutCoucheActivation);  
    boiteV2.pack_start(boutonSauvegarder);
    boiteV2.pack_start(boutonEntrainer); 


    boiteV1.pack_start(questionMenu);
    boiteV1.pack_start(zoneArchitecture);
    boiteV1.pack_end(boiteV2);

    //Mise en place de la fenetre
    fenetre.add(boiteV1); 
    fenetre.show_all();
	fenetre.set_title("Menu architecture");
	Gtk::Main::run(fenetre);

}



#endif
