#include <gtkmm.h>
#include <cairomm/context.h>
#include <math.h>

#include "Panneau.hpp"
#include "BoiteArchitecture.hpp"
#include "DialogueParamCouche.hpp"
#include "DialogueParamData.hpp"

#include "../deeplearn/archi/ReseauNeurones.hpp"
#include "../deeplearn/archi/Couche.hpp"

using namespace std;

BoiteArchitecture::BoiteArchitecture(Gtk::Window *parent) : input(new Couche("I")), output(new Couche("O")), parent(parent)
{
	add_events(Gdk::BUTTON_PRESS_MASK);
}

BoiteArchitecture::BoiteArchitecture(Gtk::Window *parent, ReseauNeurones *res) : rn(res), input(new Couche("I")), output(new Couche("O")), parent(parent)
{
	add_events(Gdk::BUTTON_PRESS_MASK);
	// add_events(Gdk::KEY_PRESS_MASK);
}

BoiteArchitecture::~BoiteArchitecture()
{
}

void BoiteArchitecture::setReseauNeurones(ReseauNeurones *res)
{
	rn = res;
}

bool BoiteArchitecture::isInputSelected()
{
	return selected_couche == input;
}

bool BoiteArchitecture::isOutputSelected()
{
	return selected_couche == output;
}

Couche *BoiteArchitecture::selectCouche(double x, double y)
{
	input->setDimOutput(rn->getDimInput());
	input->setPos(zoom * RAYON_COUCHE + 10, height / 2);
	output->setDimOutput(rn->getDimOutput());
	output->setPos(width - zoom * RAYON_COUCHE - 10, height / 2);

	if ((x > input->getX() - zoom * RAYON_COUCHE) &&
		(x < input->getX() + zoom * RAYON_COUCHE) &&
		(y > input->getY() - zoom * RAYON_COUCHE) &&
		(y < input->getY() + zoom * RAYON_COUCHE))
	{
		return input;
	}

	if ((x > output->getX() - zoom * RAYON_COUCHE) &&
		(x < output->getX() + zoom * RAYON_COUCHE) &&
		(y > output->getY() - zoom * RAYON_COUCHE) &&
		(y < output->getY() + zoom * RAYON_COUCHE))
	{
		return output;
	}

	for (std::pair<Couche *, std::vector<Couche *>> couche : rn->getListSucc())
	{
		Couche *c = couche.first;
		if ((x > c->getX() - zoom * RAYON_COUCHE) &&
			(x < c->getX() + zoom * RAYON_COUCHE) &&
			(y > c->getY() - zoom * RAYON_COUCHE) &&
			(y < c->getY() + zoom * RAYON_COUCHE))
		{
			return c;
		}
	}
	return NULL;
}

// Echap key pressed
bool BoiteArchitecture::on_key_press_event(GdkEventKey *event)
{
	cout << "#> Suppression noeud : " << endl;
	if (event->keyval == GDK_KEY_Escape)
	{
		if (selected_couche != NULL && selected_couche != input && selected_couche != output)
		{
			rn->supprimerNoeud(selected_couche);
		}
	}
	return true;
}

// Mouse button press event
bool BoiteArchitecture::on_button_press_event(GdkEventButton *event)
{
	try
	{

		if (event->type == GDK_2BUTTON_PRESS)
		{
			// Cas du double clic droit = suppression du noeud et de ses arcs
			if (event->button == 3)
			{
				selected_couche = selectCouche(event->x, event->y);
				if (selected_couche != NULL && !isOutputSelected() && !isInputSelected())
				{
					if (rn->isInitiale(selected_couche))
						rn->supprimerCoucheInitiale(selected_couche);
					if (rn->isFinale(selected_couche))
						rn->supprimerCoucheFinale(selected_couche);
					rn->supprimerNoeud(selected_couche);
					selected_couche = NULL;
				}
			}
			// Cas du double clic gauche = Paramétrage de la couche
			else if (event->button == 1)
			{
				selected_couche = selectCouche(event->x, event->y);
				if (selected_couche != NULL)
				{
					if (isInputSelected())
					{
						DialogueParamData dialogue("Paramétrage des données", parent, ((Panneau *)parent)->getApprentissage()->getDonnees().getDossiersDonnees());
						int reponse = dialogue.run();
						if (reponse == Gtk::RESPONSE_OK)
						{
							Donnees &d = ((Panneau *)parent)->getApprentissage()->getDonnees();
							d.setDossiersDonnees(dialogue.getNomDossiers());
							d.setDimDonneesEntree(DimTenseur(dialogue.getDimDonneesEntree()));
							rn->setDimInput(DimTenseur(dialogue.getDimDonneesEntree()));
							d.setDimDonneesSortie(DimTenseur(vector<int>{dialogue.getNomDossiers().size()}));
							cout << "#> Dossiers de données mis à jour.\n";
							rn->miseAJourDims();
						}
					}
					else if (isOutputSelected())
					{
					}
					else
					{
						DialogueParamCouche dialogue("Paramétrage " + selected_couche->getNom(), parent, selected_couche);
						int reponse = dialogue.run();
						if (reponse == Gtk::RESPONSE_OK)
						{
							dialogue.updateParams();
							rn->miseAJourDims();
							rn->upDateDimOutput();
						}
					}
				}
			}
		}

		// Cas clic gauche = Selection de la couche
		else if ((event->type == GDK_BUTTON_PRESS))
		{
			if (event->button == 1)
			{
				selected_couche = selectCouche(event->x, event->y);
			}

			// Cas clic droit = ajout de liaisons
			if (event->button == 3)
			{
				Couche *c_final = selectCouche(event->x, event->y);
				if (selected_couche != NULL)
				{
					if (c_final != NULL && !isOutputSelected() && c_final != selected_couche)
					{
						if (isInputSelected() && !rn->isInitiale(c_final))
						{
							rn->ajouterCoucheInitiale(c_final);
						}
						else if ((c_final == output) && !rn->isFinale(selected_couche))
						{
							rn->ajouterCoucheFinale(selected_couche);
						}
						else
						{
							rn->ajouterArc(selected_couche, c_final);
						}
					}
					else
					{
						selected_couche->setPos(event->x, event->y);
					}
				}
			}
		}
	}
	catch (BoucleException &eb)
	{
		cerr << "!> Impossible de créer l'arc. Boucle créée.\n";
	}
	catch (ArcDejaExistantException &ea)
	{
		cerr << "!> Impossible de créer l'arc. Arc déjà existant.\n";
	}
	catch (NoeudInexistantException &en)
	{
		cerr << "!> Impossible de créer l'arc. Noeud inexistant.\n";
	}
	catch (CycleException &ec)
	{
		cerr << "!> Impossible de créer l'arc. Création d'un cycle.\n";
	}
	queue_draw();
	return true;
}

bool BoiteArchitecture::on_draw(const Cairo::RefPtr<Cairo::Context> &cr)
{
	Gtk::Allocation allocation = get_allocation();
	width = allocation.get_width();
	height = allocation.get_height();

	cr->set_line_width(EPAISSEUR_TRAIT);

	draw_arcs(cr);
	draw_noeuds(cr);

	return true;
}

void BoiteArchitecture::draw_arcs(const Cairo::RefPtr<Cairo::Context> &cr)
{

	int ep_arrow = 10;

	for (Couche *c : rn->getCouchesInitiales())
	{
		cr->move_to(input->getX(), input->getY());
		double x_arrow, y_arrow, sign_x, sign_y, dx, dy;
		dx = c->getX() - input->getX();
		dy = c->getY() - input->getY();
		double alpha = (atan(dy / dx) < 1000) ? atan(dy / dx) : 1000;
		sign_x = (dx > 0) ? -cos(alpha) : cos(alpha);
		sign_y = (dx > 0) ? -sin(alpha) : sin(alpha);
		x_arrow = c->getX() + sign_x * zoom * RAYON_COUCHE;
		y_arrow = c->getY() + sign_y * zoom * RAYON_COUCHE;
		cr->line_to(x_arrow, y_arrow);
		cr->move_to(x_arrow, y_arrow);
		draw_circle(cr, x_arrow, y_arrow, ep_arrow * zoom, 0., 0., 0.);
	}

	for (Couche *c : rn->getCouchesFinales())
	{
		cr->move_to(c->getX(), c->getY());
		double x_arrow, y_arrow, sign_x, sign_y, dx, dy;
		dx = output->getX() - c->getX();
		dy = output->getY() - c->getY();
		double alpha = (atan(dy / dx) < 1000) ? atan(dy / dx) : 1000;
		sign_x = (dx > 0) ? -cos(alpha) : cos(alpha);
		sign_y = (dx > 0) ? -sin(alpha) : sin(alpha);
		x_arrow = output->getX() + sign_x * zoom * RAYON_COUCHE;
		y_arrow = output->getY() + sign_y * zoom * RAYON_COUCHE;
		cr->line_to(x_arrow, y_arrow);
		cr->move_to(x_arrow, y_arrow);
		draw_circle(cr, x_arrow, y_arrow, ep_arrow * zoom, 0., 0., 0.);
		;
	}

	for (std::pair<Couche *, std::vector<Couche *>> couche : rn->getListSucc())
	{
		Couche *init = couche.first;

		for (Couche *s : couche.second)
		{
			cr->move_to(init->getX(), init->getY());
			double x_arrow, y_arrow, sign_x, sign_y, dx, dy;
			dx = s->getX() - init->getX();
			dy = s->getY() - init->getY();
			double alpha = (atan(dy / dx) < 1000) ? atan(dy / dx) : 1000;
			sign_x = (dx > 0) ? -cos(alpha) : cos(alpha);
			sign_y = (dx > 0) ? -sin(alpha) : sin(alpha);
			x_arrow = s->getX() + sign_x * zoom * RAYON_COUCHE;
			y_arrow = s->getY() + sign_y * zoom * RAYON_COUCHE;
			cr->line_to(x_arrow, y_arrow);
			cr->move_to(x_arrow, y_arrow);
			draw_circle(cr, x_arrow, y_arrow, ep_arrow * zoom, 0., 0., 0.);
		}
	}
}

void BoiteArchitecture::draw_noeuds(const Cairo::RefPtr<Cairo::Context> &cr)
{
	if (isInputSelected())
	{
		draw_circle(cr, zoom * RAYON_COUCHE + 10, height / 2, zoom * RAYON_COUCHE, 0.1, 0.5, 0.1);
	}
	else
	{
		draw_circle(cr, zoom * RAYON_COUCHE + 10, height / 2, zoom * RAYON_COUCHE, 0.1, 0.8, 0.1);
	}
	draw_text(cr, "Input ", zoom * RAYON_COUCHE + 10, height / 2 - zoom * RAYON_COUCHE * 0.4, 12);
	draw_text(cr, rn->getDimInput().toString(), zoom * RAYON_COUCHE + 10, height / 2 + zoom * RAYON_COUCHE * 0.2, 10);

	for (std::pair<Couche *, std::vector<Couche *>> couche : rn->getListSucc())
	{
		int xCouche = couche.first->getX(), yCouche = couche.first->getY();
		cr->move_to(xCouche + zoom * RAYON_COUCHE, yCouche);
		double c1 = 0.6, c2 = 0.5;

		if (couche.first == selected_couche)
		{
			if (couche.first->type() == "CoucheActivation")
			{
				draw_circle(cr, xCouche, yCouche, zoom * RAYON_COUCHE, c1 + 0.2, c2 + 0.2, 0.);
			}
			else
			{
				draw_circle(cr, xCouche, yCouche, zoom * RAYON_COUCHE, 0., c1, c2);
			}
		}
		else
		{
			if (couche.first->type() == "CoucheActivation")
			{
				draw_circle(cr, xCouche, yCouche, zoom * RAYON_COUCHE, c1 + 0.4, c2 + 0.4, 0.);
			}
			else
			{
				draw_circle(cr, xCouche, yCouche, zoom * RAYON_COUCHE, 0., c1 + 0.3, c2 + 0.3);
			}
		}
		cr->set_source_rgba(0.0, 0., 0., 1.);
		draw_text_couche(cr, couche.first, xCouche, yCouche, zoom * RAYON_COUCHE);
	}

	cr->move_to(width - 10, height / 2);

	if (isOutputSelected())
	{
		draw_circle(cr, width - zoom * RAYON_COUCHE - 10, height / 2, zoom * RAYON_COUCHE, 0.6, 0.1, 0.1);
	}
	else
	{
		draw_circle(cr, width - zoom * RAYON_COUCHE - 10, height / 2, zoom * RAYON_COUCHE, 0.9, 0.1, 0.1);
	}
	cr->set_source_rgba(0.0, 0., 0., 1.);
	draw_text(cr, "Output ", width - zoom * RAYON_COUCHE - 10, height / 2 - zoom * RAYON_COUCHE * 0.4, 12);
	draw_text(cr, rn->getDimOutput().toString(), width - zoom * RAYON_COUCHE - 10, height / 2 + zoom * RAYON_COUCHE * 0.2, 10);
}

void BoiteArchitecture::draw_circle(const Cairo::RefPtr<Cairo::Context> &cr, int x, int y, int rayon, double r, double v, double b)
{
	cr->save();
	cr->arc(x, y, rayon, 0.0, 2.0 * M_PI);
	cr->set_source_rgba(r, v, b, 1.);
	cr->fill_preserve();
	cr->restore();
	cr->stroke();
}

void BoiteArchitecture::draw_text(const Cairo::RefPtr<Cairo::Context> &cr, std::string str, int x, int y, int size)
{
	cr->move_to(x, y);

	Pango::FontDescription font("sans bold " + std::to_string(((int)(size * zoom))));
	auto text = create_pango_layout(str);
	text->set_font_description(font);

	int text_w;
	int text_h;

	text->get_pixel_size(text_w, text_h);
	cr->move_to(x - text_w * 0.5, y);
	text->show_in_cairo_context(cr);
}

void BoiteArchitecture::draw_text_couche(const Cairo::RefPtr<Cairo::Context> &cr, Couche *couche, int x, int y, int rayon)
{
	cr->move_to(x, y);
	int taille = (zoom >= 0.7) ? ((int)(8 * zoom)) : ((int)(8 * 0.7));
	Pango::FontDescription font("sans bold " + std::to_string(taille));
	auto nomC = create_pango_layout(couche->getNom());
	nomC->set_font_description(font);

	int text_w;
	int text_h;

	nomC->get_pixel_size(text_w, text_h);
	cr->move_to(x - text_w * 0.5, y - rayon * 0.6);
	nomC->show_in_cairo_context(cr);

	auto dimIn = create_pango_layout("I " + couche->getDimInput().toString());
	dimIn->set_font_description(font);

	dimIn->get_pixel_size(text_w, text_h);
	cr->move_to(x - text_w * 0.5, y);
	dimIn->show_in_cairo_context(cr);

	auto dimOut = create_pango_layout("O " + couche->getDimOutput().toString());
	dimOut->set_font_description(font);

	dimOut->get_pixel_size(text_w, text_h);
	cr->move_to(x - text_w * 0.5, y + rayon * 0.5);
	dimOut->show_in_cairo_context(cr);
}

void BoiteArchitecture::setZoom(double z)
{
	zoom = z;
}