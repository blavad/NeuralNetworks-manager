#include "../deeplearn/archi/ReseauNeurones.hpp"
#include <gtkmm.h>
#include "BoiteArchitecture.hpp"
#include "Boite.hpp"
#include <cairomm/context.h>
#include <cmath>

using namespace std;

BoiteArchitecture::BoiteArchitecture()
{	
	coords.push_back(make_pair(100, 100));
	coords.push_back(make_pair(50, 50));
	coords.push_back(make_pair(80, 120));
	coords.push_back(make_pair(150, 120));
}

BoiteArchitecture::BoiteArchitecture(ReseauNeurones *res) : rn(res)
{
}

BoiteArchitecture::~BoiteArchitecture()
{
}

void setReseauNeurones(ReseauNeurones *res){
	rn = res;
}

bool BoiteArchitecture::on_draw(const Cairo::RefPtr<Cairo::Context> &cr)
{
	// This is where we draw on the window
	Gtk::Allocation allocation = get_allocation();
	const int width = allocation.get_width();
	const int height = allocation.get_height();
	const int lesser = MIN(width, height);

	// coordinates for the center of the window
	int xc, yc;
	xc = width / 2;
	yc = height / 2;

	cout << xc << "  " << yc << endl;

	cr->set_line_width(EPAISSEUR_TRAIT);

	for (int i = 0; i < coords.size(); i++)
	{
		cr->save();
		cr->arc(coords[i].first, coords[i].second, zoom * RAYON_COUCHE, 0.0, 2.0 * M_PI);
		cr->set_source_rgba(0.0, 0.6, 0.6, 0.6);
		cr->fill_preserve();
		cr->restore();
		cr->stroke();
	}

	return true;
}
