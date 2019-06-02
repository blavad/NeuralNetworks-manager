#include "Apprentissage.hpp"
#include <dirent.h>

Apprentissage::Apprentissage() {}

Apprentissage::Apprentissage(ReseauNeurones *reseauN) : rn(reseauN)
{
}

Apprentissage::Apprentissage(ReseauNeurones *reseauN, Erreur *erreur) : rn(reseauN), err(erreur)
{
}

ReseauNeurones *Apprentissage::getRN()
{
    return rn;
}

Erreur *Apprentissage::getErreur()
{
    return err;
}

Donnees &Apprentissage::getDonnees()
{
    return donnees;
}

ParametresApprentissage &Apprentissage::getParam()
{
    return param;
}

void Apprentissage::setRN(ReseauNeurones *res)
{
    rn = res;
}

void Apprentissage::setErreur(Erreur *erreur)
{
    err = erreur;
}

void Apprentissage::setDonnees(Donnees d)
{
    donnees = d;
}

void Apprentissage::setParam(ParametresApprentissage paramApp)
{
    param = paramApp;
}

void Apprentissage::stop()
{
    enCours = false;
}

void Apprentissage::chargerDonnees(bool couleur)
{
    couleur = false;
    DIR *rep;
    Pretraitement pr;
    Tenseur *timg;

    std::vector<std::string> dossiersDonnees = donnees.getDossiersDonnees();
    for (unsigned int i = 0; i < dossiersDonnees.size(); i++)
    {
        std::string dossierEnCours = dossiersDonnees[i];
        rep = opendir(dossierEnCours.c_str());
        if (rep != NULL)
        {
            try
            {

                struct dirent *fichierLu;
                while ((fichierLu = readdir(rep)) != NULL)
                {
                    std::string image = fichierLu->d_name;
                    std::string nomEntierImage;
                    std::size_t found = image.find(".png");
                    if (found != std::string::npos)
                    {
                        nomEntierImage = dossierEnCours + "/" + image;
                    }
                    found = image.find(".jpeg");
                    if (found != std::string::npos)
                    {
                        nomEntierImage = dossierEnCours + "/" + image;
                    }
                    found = image.find(".jpg");
                    if (found != std::string::npos)
                    {
                        nomEntierImage = dossierEnCours + "/" + image;
                    }
                    if (nomEntierImage != "")
                    {

                        Tenseur *t = new Tenseur({dossiersDonnees.size()});
                        t->initValeurNulle();
                        t->setValeur(1., i);

                        int c = (couleur) ? 3 : 1;
                        //cout << "Ajout donnée : " << nomEntierImage << " - " << donnees.getDimDonneesEntree().getDim(0) << "x" << donnees.getDimDonneesEntree().getDim(1) << "x" << c << endl;
                        timg = pr.imageToTenseur(nomEntierImage, donnees.getDimDonneesEntree().getDim(0), donnees.getDimDonneesEntree().getDim(1), couleur);
                        if (timg != NULL)
                        {
                            Donnee *d = new Donnee(*timg, *t);
                            donnees.ajouterDonnee(*d);
                        }
                    }
                }
            }
            catch (...)
            {
                cerr << "!> Erreur d'ouverture" << endl;
            }
            closedir(rep);
        }
    }
}

void Apprentissage::apprendre()
{
    enCours = true;
    int epochs = 0;
    while (enCours && epochs < param.getNbEpoques())
    {
        epochs++;
        for (int j = 0; j < donnees.getNbDonnees(); j++)
        {
            Tenseur x = donnees.getDonnee(j).getEntree();
            Tenseur label = donnees.getDonnee(j).getSortie();
            Tenseur y = rn->propagation(x);
            if (j % getParam().getFreqAffichage() == 0)
            {
                cout << y << endl;
            }
            if (j % getParam().getFreqSauvegarde() == 0)
            {
                cout << "Save " << endl;
            }
            //Tenseur e = err->eval(y, label);
            //rn->retro(rn->getCouchesFinales(), ca, y, param.getTauxApprentissage());
        }
        donnees.melanger();
    }
}
