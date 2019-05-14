#include "DialogueParamCouche.hpp"
#include <string>

using namespace std;

DialogueParamCouche::DialogueParamCouche(std::string titre, Gtk::Window *parent, Couche *new_c) : Gtk::Dialog(titre, *parent), boiteV(get_vbox()), lab_nom("Nom de la couche"), couche(new_c), ajustement(Gtk::Adjustment::create(10, 1, 500, 1)), compteurNbOutput(ajustement)
{
    boiteV->pack_start(lab_nom);
    nom_couche.set_text(new_c->getNom());
    boiteV->pack_start(nom_couche);
    Gtk::Label lab_nbS("Nombre de sorties");
    if (new_c->type() == "CoucheConnectee")
    {
        compteurNbOutput.set_numeric();
        boiteV->pack_start(lab_nbS);
        boiteV->pack_start(compteurNbOutput);
        compteurNbOutput.signal_value_changed().connect(sigc::mem_fun(*this, &DialogueParamCouche::updateDim));
    }
    else if (new_c->type() == "CoucheConvolution")
    {
    }
    add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);

    show_all();
}

void DialogueParamCouche::updateDim()
{
    string str = compteurNbOutput.get_text();
    couche->setDimOutput(vector<int>{std::stoi(str)});
}

std::string DialogueParamCouche::getNomC()
{
    return nom_couche.get_text();
}
