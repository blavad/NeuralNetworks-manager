#include "DialogueParamData.hpp"

using namespace std;

DialogueParamData::DialogueParamData(std::string titre, Gtk::Window *parent, std::vector<string> doss) : Gtk::Dialog(titre, *parent), dossiers(doss), choisirFolder("Choisir Dossiers Données"), boiteV(get_vbox()), parent(parent), supp("Supprimer Dossier")
{

    Gtk::Label *lab_folder_data = new Gtk::Label("Ajouter Données");
    boiteV->pack_start(*lab_folder_data);

    listeDossiers = new Gtk::ComboBoxText();
    for (std::string doss : dossiers)
    {
        listeDossiers->append(doss);
    }

    listeDossiers->set_active(0);

    Gtk::Label *lab_l = new Gtk::Label("Longueur (en px)");
    Glib::RefPtr<Gtk::Adjustment> aj_longueur(Gtk::Adjustment::create(50, 8, 500, 1));
    Gtk::SpinButton *longueur = new Gtk::SpinButton(aj_longueur);
    longueur->signal_value_changed().connect(sigc::bind<Gtk::SpinButton *, int &>(sigc::mem_fun(*this, &DialogueParamData::setDimsPhoto), longueur, l));
    longueur->set_numeric();
    setDimsPhoto(longueur,l);

    // Taux apprentissage
    Gtk::Label *lab_h = new Gtk::Label("Hauteur (en px)");
    Glib::RefPtr<Gtk::Adjustment> aj_hauteur(Gtk::Adjustment::create(50, 8, 500, 1));
    Gtk::SpinButton *hauteur = new Gtk::SpinButton(aj_hauteur);
    hauteur->signal_value_changed().connect(sigc::bind<Gtk::SpinButton *, int &>(sigc::mem_fun(*this, &DialogueParamData::setDimsPhoto), hauteur, h));
    hauteur->set_numeric();
    setDimsPhoto(hauteur,h);

    boiteV->pack_start(*lab_l);
    boiteV->pack_start(*longueur);
    boiteV->pack_start(*lab_h);
    boiteV->pack_start(*hauteur);

    boiteV->pack_start(choisirFolder);
    boiteV->pack_start(*listeDossiers);
    boiteV->pack_start(supp);
    // Connexion des boutons

    choisirFolder.signal_clicked().connect(sigc::mem_fun(*this,
                                                         &DialogueParamData::ajoutDossier));

    supp.signal_clicked().connect(sigc::mem_fun(*this,
                                                &DialogueParamData::suppressionDossier));

    add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);

    show_all();
}

std::vector<std::string> DialogueParamData::getNomDossiers()
{
    return dossiers;
}

std::string DialogueParamData::getTypeDonnees()
{
    return type;
}

std::vector<int> DialogueParamData::getDimDonneesEntree()
{
    return vector<int>{l, h};
}

void DialogueParamData::setDimsPhoto(Gtk::SpinButton *sp_b, int &v)
{
    v = sp_b->get_value_as_int();
}

void DialogueParamData::suppressionDossier()
{
    std::string active = listeDossiers->get_active_text();
    for (int i = 0; i < dossiers.size(); i++)
    {
        if (dossiers[i] == active)
        {
            listeDossiers->remove_text(i);
            dossiers.erase(dossiers.begin() + i);
        }
    }
    listeDossiers->set_active(0);
}

void DialogueParamData::ajoutDossier()
{
    GtkWidget *dialog;
    GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER;
    gint res;

    dialog = gtk_file_chooser_dialog_new("Choisir Dossier Données",
                                         NULL,
                                         action,
                                         ("_Cancel"),
                                         GTK_RESPONSE_CANCEL,
                                         ("_Open"),
                                         GTK_RESPONSE_ACCEPT,
                                         NULL);

    res = gtk_dialog_run(GTK_DIALOG(dialog));
    if (res == GTK_RESPONSE_ACCEPT)
    {
        char *filename;
        GtkFileChooser *chooser = GTK_FILE_CHOOSER(dialog);
        filename = gtk_file_chooser_get_filename(chooser);
        listeDossiers->append(filename);
        dossiers.push_back(filename);
        listeDossiers->set_active(0);
        g_free(filename);
    }

    gtk_widget_destroy(dialog);
}