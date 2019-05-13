#include <gtkmm.h>
#include "Panneau.hpp"
#include "../deeplearn/archi/TanH.hpp"
#include "BoiteChoixMultiple.hpp"

Panneau::Panneau() : Gtk::Window(), boiteV1(true)
{
	set_title("Gestion Reseau Neurones");
	set_border_width(10);
	resize(1200, 600);
	set_position(Gtk::WIN_POS_CENTER);

	boiteArchi.setReseauNeurones(reseauNeurones);

	void (Panneau::*f)(void);
	f = &Panneau::ajouterCouche;
	choixCouche = new BoiteChoixMultiple(this, f, "Choisir Couche", vector<std::string>{"FC", "CONV", "NEURONE", "TanH", "ReLU", "Sigmoid"});
	// choixCouche.setFonctionAppel(f);

	boiteV1.pack_start(boiteArchi);
	boiteV1.pack_end(*choixCouche);

	//Mise en place de la fenetre
	add(boiteV1);
	show_all();
}

void Panneau::ajouterCouche()
{
	cout << "Ajout " << choixCouche->getValeurSectionnee() <<endl;
	if (choixCouche->getValeurSectionnee() == "TanH")
	{
		reseauNeurones->ajouterNoeud(new TanH());
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
