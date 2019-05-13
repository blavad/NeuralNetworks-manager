#include "BoiteChoixMultiple.hpp"
#include "Panneau.hpp"
#include <string>

using namespace std;

BoiteChoixMultiple::BoiteChoixMultiple(Panneau *parent, void (Panneau::*f)(void), string nom, vector<string> choix) : validerSelection("Valider"), Gtk::Frame(), parent(parent), f(f)
{
    set_label(nom);
    set_shadow_type(Gtk::SHADOW_ETCHED_OUT);

    for (string opt : choix)
    {
        listeChoix.append(opt);
    }

    // Mise en place de la valeure par défault
    listeChoix.set_active(0);

    cout << listeChoix.get_active_text() << endl;

    validerSelection.signal_clicked().connect(sigc::mem_fun(*parent, f));
    agencement.pack_start(listeChoix);
    agencement.pack_end(validerSelection);
    add(agencement);
}

string BoiteChoixMultiple::getValeurSectionnee()
{
    return listeChoix.get_active_text();
}
