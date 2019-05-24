#include "DialogueParamCouche.hpp"
#include <string>

using namespace std;

DialogueParamCouche::DialogueParamCouche(std::string titre, Gtk::Window *parent, Couche *new_c) : Gtk::Dialog(titre, *parent), boiteV(get_vbox()), lab_nom("Nom de la couche"), couche(new_c), ajustement(Gtk::Adjustment::create(10, 1, 500, 1)), compteurNbOutput(ajustement)
{
    boiteV->pack_start(lab_nom);
    nom_couche.set_text(new_c->getNom());
    boiteV->pack_start(nom_couche);
    if (new_c->type() == "CoucheConnectee")
    {
        Gtk::Label *lab_nbS = new Gtk::Label("Nombre de sorties");
        ajustement->set_value(new_c->getDimOutput().getDim(0));
        compteurNbOutput.set_numeric();
        boiteV->pack_start(*lab_nbS);
        boiteV->pack_start(compteurNbOutput);
    }
    else if (new_c->type() == "CoucheConvolution")
    {
    }
    add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);

    show_all();
}

DimTenseur DialogueParamCouche::getDimOutput()
{
    DimTenseur dimO;
    if (couche->type() == "CoucheConnectee")
    {
        dimO = DimTenseur(vector<int>{std::stoi(compteurNbOutput.get_text())});
    }
    return dimO;
}

std::string DialogueParamCouche::getNomC()
{
    return nom_couche.get_text();
}

void DialogueParamCouche::updateParams()
{
    if (couche->type() == "CoucheConnectee")
    {
        couche->setDimOutput(getDimOutput());
    }
    couche->setNom(getNomC());
}