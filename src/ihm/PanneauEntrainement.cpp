#ifndef __PANNEAU_ENTRAINEMENT_CPP__
#define __PANNEAU_ENTRAINEMENT_CPP__

#include "PanneauEntrainement.hpp"
#include <gtkmm.h>

PanneauEntrainement::PanneauEntrainement(){

}


void PanneauEntrainement::afficherContenu(int argc, char* argv[]){

	//Initialisation de la fenetre
	Gtk::Main app(argc, argv);
	Gtk::Window fenetre;
	fenetre.set_border_width(10);
	fenetre.resize(500, 300);
	fenetre.set_position(Gtk::WIN_POS_CENTER);

	//Premiere boite verticale
	Gtk::VBox boiteV1(true);
	Gtk::Label questionMenu("Que voulez vous faire ?");
	Gtk::Label zoneArchitecture("\"VISUALISATION DU RESEAU\"");
	
	//Deuxieme boite verticale
	Gtk::VButtonBox boiteV2(Gtk::BUTTONBOX_START,5);
	Gtk::Label labelOuvrirArchitecture("Ouvrir architecture");
	Gtk::Button boutonOuvrirArchitecture("...");
    boutonOuvrirArchitecture.set_can_focus(false);
    Gtk::Label labelChoisirFonctionCout("Choisir fonction de coût");
    Gtk::ComboBoxText listeChoixFonctionCout;
    listeChoixFonctionCout.append("Erreur quadratique");
    listeChoixFonctionCout.append("Erreur L1");
    listeChoixFonctionCout.append("Erreur enthropie croisée");
    listeChoixFonctionCout.set_active_text("Erreur quadratique");
    Gtk::Label labelChoisirMethodeOptimisation("Ajouter une méthode d'optimisation");
    Gtk::ComboBoxText listeChoixMethodeOptimisation;
    /*listeChoixMethodeOptimisation.append("");
    listeChoixMethodeOptimisation.append("");
    listeChoixMethodeOptimisation.append("");
    listeChoixMethodeOptimisation.set_active_text("");*/
    Gtk::Label labelSelectionnerDonnees("Selectionner données");
    Gtk::Button boutonSelectionnerDonnees("...");
    boutonSelectionnerDonnees.set_can_focus(false);
    Gtk::Label labelParametresApprentissage("Modifier paramètres d'apprentissage");
    Gtk::Button boutonParametresApprentissage("Modifier");
    boutonParametresApprentissage.set_can_focus(false);
    Gtk::Button boutonSauvegarder("Sauvegarder");
    boutonSauvegarder.set_can_focus(false);
    Gtk::Button boutonEntrainer("Entraîner");
    boutonEntrainer.set_can_focus(false);
    Gtk::Button boutonTester("Tester");
    boutonTester.set_can_focus(false);

    //Fusion des containers
    boiteV2.pack_start(labelOuvrirArchitecture); 
    boiteV2.pack_start(boutonOuvrirArchitecture); 
    boiteV2.pack_start(labelChoisirFonctionCout);
    boiteV2.pack_start(listeChoixFonctionCout);    
    boiteV2.pack_start(labelChoisirMethodeOptimisation);
    boiteV2.pack_start(listeChoixMethodeOptimisation);
    boiteV2.pack_start(labelSelectionnerDonnees);
    boiteV2.pack_start(boutonSelectionnerDonnees);   
    boiteV2.pack_start(labelParametresApprentissage);
    boiteV2.pack_start(boutonParametresApprentissage);
    boiteV2.pack_start(boutonSauvegarder);
    boiteV2.pack_start(boutonEntrainer);
    boiteV2.pack_start(boutonTester);  


    boiteV1.pack_start(questionMenu);
    boiteV1.pack_start(zoneArchitecture);
    boiteV1.pack_end(boiteV2);

    //Mise en place de la fenetre
    fenetre.add(boiteV1); 
    fenetre.show_all();
	fenetre.set_title("Menu entraînement");
	Gtk::Main::run(fenetre);

}



#endif
