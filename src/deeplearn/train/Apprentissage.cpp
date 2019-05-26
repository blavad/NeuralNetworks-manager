#include "Apprentissage.hpp"

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

Donnees& Apprentissage::getDonnees()
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

void Apprentissage::apprendre()
{
    for (int i = 0; i < param.getNbEpoques(); i++)
    {
        for (int j = 0; j < donnees.getNbDonnees(); j++)
        {
            Tenseur x = donnees.getDonnee(j).getEntree();
            Tenseur l = donnees.getDonnee(j).getSortie();
            Tenseur *t;
            t = &x;
            Tenseur y = rn->propagation(*t);
            Tenseur e = err->eval(y, l);
            opt.minimiser(*err);
        }
        donnees.melanger();
    }
}