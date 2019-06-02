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

Optimisateur Apprentissage::getOptimisateur()
{
    return opt;
}

Erreur *Apprentissage::getErreur()
{
    return err;
}

Donnees &Apprentissage::getDonnees()
{
    return donnees;
}

ParametresApprentissage Apprentissage::getParam()
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

void Apprentissage::setOptimisateur(Optimisateur optimisateur)
{
    opt = optimisateur;
}

void Apprentissage::setDonnees(Donnees d)
{
    donnees = d;
}

void Apprentissage::setParam(ParametresApprentissage paramApp)
{
    param = paramApp;
}

void Apprentissage::chargerDonnees(bool couleur)
{

    DIR *rep;
    std::vector<std::string> dossiersDonnees = donnees.getDossiersDonnees();
    for (unsigned int i = 0; i < dossiersDonnees.size(); i++)
    {
        std::string dossierEnCours = dossiersDonnees[i];
        rep = opendir(dossierEnCours.c_str());
        if (rep != NULL)
        {
            struct dirent *fichierLu;
            while ((fichierLu = readdir(rep)) != NULL)
            {
                std::string image = fichierLu->d_name;
                std::size_t found = image.find(".png");
                if (found != std::string::npos)
                {
                    std::string nomEntierImage{dossierEnCours + image};
                }
                found = image.find(".jpeg");
                if (found != std::string::npos)
                {
                    std::string nomEntierImage{dossierEnCours + image};
                }
                found = image.find(".jpg");
                if (found != std::string::npos)
                {
                    std::string nomEntierImage{dossierEnCours + image};
                    ;
                }
                Tenseur t;
                std::vector<int> dims;
                dims.push_back(dossiersDonnees.size());
                dims.push_back(1);
                t = Tenseur(dims);
                //donnees.ajouter(imageToTenseur(nomEntierImage,couleur), t);
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
            Tenseur e = err->eval(y, label);
            for (auto cf : rn->getCouchesFinales()){
                rn->retro(cf, &y, param.getTauxApprentissage());
            } 
        }
        donnees.melanger();
    }
}
