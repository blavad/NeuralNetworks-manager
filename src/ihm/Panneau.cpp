#include <gtkmm.h>
#include "Panneau.hpp"
#include "BoiteChoixMultiple.hpp"
#include "DialogueParamCouche.hpp"
#include "DialogueEntrainement.hpp"

Panneau::Panneau() : Gtk::Window(), boiteV1(false, 20), conteneur_secondaire(false, 10), boiteArchi(this)
{
	set_title("Gestion Reseau Neurones");
	set_border_width(10);
	resize(1200, 600);
	set_position(Gtk::WIN_POS_CENTER);

	// Création du visuel de l'architecture et initialisation des données par défault de l'apprentissage
	boiteArchi.setReseauNeurones(reseauNeurones);
	appr->setRN(reseauNeurones);
	appr->setErreur(new ErreurL1());

	// --------------------------------------------------------------------
	// Création et ajout des boites de choix multiples
	Gtk::VBox *multipleChoicheBox = new Gtk::VBox();

	// Création de la boite permettant l'ajout de couches
	void (Panneau::*f)(void);
	f = &Panneau::ajouterCouche;
	choixCouche = new BoiteChoixMultiple(this, f, "Ajouter Couche", vector<std::string>{"Couche Connectee", "Neurone", "TanH", "ReLU", "Sigmoid"});

	// Création de la boite permettant le changement de l'erreur
	void (Panneau::*g)(void);
	g = &Panneau::changerErreur;
	BoiteChoixMultiple *choixErr = new BoiteChoixMultiple(this, g, "Changer Erreur", vector<std::string>{"Erreur L1", "Erreur L2", "Erreur Entropie Croisée"});
	choixErreur = choixErr;

	multipleChoicheBox->pack_start(*choixCouche);
	multipleChoicheBox->pack_start(*choixErr);

	// ----------------------------------------------------------------------
	// Création boutons

	Gtk::VBox *buttonBox = new Gtk::VBox(false);
	Gtk::Button *open = new Gtk::Button("Ouvrir ...");
	open->signal_clicked().connect(sigc::mem_fun(*this, &Panneau::ouvrirRN));
	Gtk::Button *save = new Gtk::Button("Sauvegarder");
	save->signal_clicked().connect(sigc::mem_fun(*this, &Panneau::sauvegarderRN));
	Gtk::Button *save_as = new Gtk::Button("Sauvegarder sous ...");
	save_as->signal_clicked().connect(sigc::mem_fun(*this, &Panneau::sauvegarderRN));
	Gtk::Button *train = new Gtk::Button("Entraîner");
	train->signal_clicked().connect(sigc::mem_fun(*this, &Panneau::lancerEntrainement));

	buttonBox->pack_start(*open);
	buttonBox->pack_start(*save);
	buttonBox->pack_start(*save_as);
	buttonBox->pack_start(*train);

	// -----------------------------------------------------------------------
	// Création choix params entrainement

	Gtk::VBox *paramBox = new Gtk::VBox();
	// Nb Epoques
	Gtk::Label *lab_nb_epochs = new Gtk::Label("Nombre Epoques");
	Glib::RefPtr<Gtk::Adjustment> ajustement(Gtk::Adjustment::create(3, 1, 30, 1));
	Gtk::SpinButton *nb_epochs = new Gtk::SpinButton(ajustement);
	nb_epochs->signal_value_changed().connect(sigc::bind<Gtk::SpinButton *, std::string>(sigc::mem_fun(*this, &Panneau::updateParams), nb_epochs, "nb_epochs"));
	nb_epochs->set_numeric();
	updateParams(nb_epochs, "nb_epochs");

	// Fréquence Affichage
	Gtk::Label *lab_freq = new Gtk::Label("Fréquence Affichage");
	Glib::RefPtr<Gtk::Adjustment> ajustement_freq(Gtk::Adjustment::create(15, 3, 500, 1));
	Gtk::SpinButton *freq = new Gtk::SpinButton(ajustement_freq);
	freq->signal_value_changed().connect(sigc::bind<Gtk::SpinButton *, std::string>(sigc::mem_fun(*this, &Panneau::updateParams), freq, "freq_affichage"));
	freq->set_numeric();
	updateParams(freq, "freq_affichage");

	// Taux apprentissage
	Gtk::Label *lab_taux_appr = new Gtk::Label("Taux d'apprentissage (x0.01)");
	Glib::RefPtr<Gtk::Adjustment> ajustement_taux_appr(Gtk::Adjustment::create(20, 1, 100, 1));
	Gtk::SpinButton *taux_appr = new Gtk::SpinButton(ajustement_taux_appr);
	taux_appr->signal_value_changed().connect(sigc::bind<Gtk::SpinButton *, std::string>(sigc::mem_fun(*this, &Panneau::updateParams), taux_appr, "taux_apprentissage"));
	taux_appr->set_numeric();
	updateParams(taux_appr, "taux_apprentissage");

	paramBox->pack_start(*lab_nb_epochs);
	paramBox->pack_start(*nb_epochs);
	paramBox->pack_start(*lab_taux_appr);
	paramBox->pack_start(*taux_appr);
	paramBox->pack_start(*lab_freq);
	paramBox->pack_start(*freq);

	// -------------------------------------------------------------------
	// Autres
	Glib::RefPtr<Gtk::Adjustment> m_adjustment(Gtk::Adjustment::create(1.0, 0.3, 3.0, 0.1, 1.0, 1.0));
	Gtk::Scale *scale_barre = new Gtk::Scale(m_adjustment, Gtk::ORIENTATION_HORIZONTAL);
	scale_barre->set_digits(1);
	scale_barre->set_value_pos(Gtk::POS_TOP);
	scale_barre->set_draw_value();
	scale_barre->signal_value_changed().connect(sigc::bind<Gtk::Scale *>(sigc::mem_fun(*this, &Panneau::updateZoom), scale_barre));
	updateZoom(scale_barre);

	// -------------------------------------------------------------------
	// Ajout des éléments

	// Ajout des composants
	conteneur_secondaire.pack_start(*multipleChoicheBox);
	conteneur_secondaire.pack_start(*paramBox);
	conteneur_secondaire.pack_start(*buttonBox);

	// Ajout des composants au conteneur multiple
	boiteV1.pack_start(boiteArchi);
	boiteV1.pack_start(*scale_barre, Gtk::PACK_SHRINK);
	boiteV1.pack_end(conteneur_secondaire, Gtk::PACK_SHRINK);

	// Ajout à la fenetre
	add(boiteV1);
	show_all();
}

void Panneau::updateParams(Gtk::SpinButton *param, std::string type)
{
	cout << "#> Changement Params " << type << " to : " << param->get_value() << endl;
	if (type == "taux_apprentissage")
	{
		appr->getParam().setTauxApprentissage(0.01 * param->get_value());
	}
	if (type == "nb_epochs")
	{
		appr->getParam().setNbEpoques(param->get_value());
	}
	if (type == "freq_affichage")
	{
		appr->getParam().setFreqAffichage(param->get_value());
	}
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
		cout << "#> Ajout " << val << " : " << dialogue.getNomC() << endl;
		new_c->setNom(dialogue.getNomC());
		reseauNeurones->ajouterNoeud(new_c);
	}
	boiteArchi.queue_draw();
}

void Panneau::changerErreur()
{
	string val = choixErreur->getValeurSectionnee();
	cout << "#> Changement Erreur : " << val << endl;
	Erreur *new_err;
	if (val == "Erreur L1")
	{
		new_err = new ErreurL1();
	}
	else if (val == "Erreur L2")
	{
		new_err = new ErreurQuadratique();
	}
	else if (val == "Erreur Entropie Croisee")
	{
		new_err = new ErreurEntropieCroisee();
	}
	appr->setErreur(new_err);
	boiteArchi.queue_draw();
}

void Panneau::ouvrirRN()
{
	cout << "#> Ouvrir ... " << endl;
}

void Panneau::sauvegarderRN()
{
	cout << "#> Sauvegarde de " << reseauNeurones->getNom() << endl;
}

void Panneau::lancerEntrainement()
{
	cout << "#> Lancement Entrainement" << endl;
	appr->chargerDonnees();

	DialogueEntrainement dialogue("Entrainement " + reseauNeurones->getNom(), this,appr->getDonnees().getDonnees().size(),appr->getParam().getNbEpoques());
	dialogue.nextData();
	int rep = dialogue.run();
	//appr->apprendre();
}

void Panneau::updateZoom(Gtk::Scale *zoom)
{
	boiteArchi.setZoom(zoom->get_value());
	boiteArchi.queue_draw();
}

Apprentissage *Panneau::getApprentissage()
{
	return appr;
}
