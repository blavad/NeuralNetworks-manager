#include "DialogueEntrainement.hpp"

using namespace std;

DialogueEntrainement::DialogueEntrainement(std::string titre, Gtk::Window *parent,int m_d, int m_e) : Gtk::Dialog(titre, *parent), boiteV(get_vbox()),
                                                                                     nb_donnees(0), nb_epochs(0),max_epochs(m_e),max_donnees(m_d),
                                                                                     lab_count_epochs("- Epoque : ?/?"),
                                                                                     lab_count_donnees("- Donnée : ?/?")
{ 
    boiteV->pack_start(lab_count_epochs);
    boiteV->pack_start(lab_count_donnees);

    add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    show_all();
}

void DialogueEntrainement::nextData()
{
    if (nb_donnees == max_donnees)
    {
        nb_donnees = 1;
        nb_epochs++;
    }
    else
    {
        nb_donnees++;
    }
    lab_count_donnees.set_text("- Donnée : " + to_string(nb_donnees) + "/" + to_string(max_donnees));
    lab_count_epochs.set_text("- Epoque : " + to_string(nb_epochs) + "/" + to_string(max_epochs));
}