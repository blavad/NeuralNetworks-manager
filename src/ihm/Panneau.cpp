#include <gtkmm.h>
#include "Panneau.hpp"
#include "BoiteChoixMultiple.hpp"
#include "DialogueParamCouche.hpp"

Panneau::Panneau() : Gtk::Window(), boiteV1(false, 20),conteneur_secondaire(true,10), sauvegarder("Save"), boiteArchi(this)
{
	set_title("Gestion Reseau Neurones");
	set_border_width(10);
	resize(1200, 600);
	set_position(Gtk::WIN_POS_CENTER);

	// Création du visuel de l'architecture
	//appr->setRN(reseauNeurones);
	boiteArchi.setReseauNeurones(reseauNeurones);

	// Création de la boite permettant l'ajout de couches
	void (Panneau::*f)(void);
	f = &Panneau::ajouterCouche;
	choixCouche = new BoiteChoixMultiple(this, f, "Ajouter Couche", vector<std::string>{"Couche Connectee", "Neurone", "TanH", "ReLU", "Sigmoid"});

	conteneur_secondaire.pack_start(*choixCouche);
	conteneur_secondaire.pack_start(sauvegarder);

	// Ajout des composants au conteneur multiple
	boiteV1.pack_start(boiteArchi);
	boiteV1.pack_end(conteneur_secondaire,Gtk::PACK_SHRINK);

	// Ajout à la fenetre
	add(boiteV1);
	show_all();
}

void Panneau::ajouterCouche()
{
	string val = choixCouche->getValeurSectionnee();

	Couche *new_c;
	if (val == "Couche Connectee")
	{
		new_c = new CoucheConnectee(10);
	}
	else if (val == "Neurone")
	{
		new_c = new Neurone();
	}
	else if (val == "TanH")
	{
		new_c = new TanH();
	}
	else if (val == "ReLU")
	{
		new_c = new ReLU();
	}
	else if (val == "Sigmoid")
	{
		new_c = new Sigmoid();
	}
	DialogueParamCouche dialogue("Paramétrage " + val, this, new_c);

	int reponse = dialogue.run();

	if (reponse == Gtk::RESPONSE_OK)
	{
		new_c -> setNom(dialogue.getNomC());
		reseauNeurones->ajouterNoeud(new_c);
	}
	boiteArchi.queue_draw();
}

void Panneau::sauvegarderRN()
{
	cout << "Sauvegarde de " << reseauNeurones->getNom() << endl;
}

void Panneau::sauvegarderRN(string nomFichier)
{
	cout << "Sauvegarde de " << reseauNeurones->getNom() << " dans " << nomFichier << endl;
}

ReseauNeurones *Panneau::getReseauNeurones()
{
	return reseauNeurones;
}
