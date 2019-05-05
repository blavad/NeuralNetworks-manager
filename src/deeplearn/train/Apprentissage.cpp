#include "Apprentissage.hpp"

Apprentissage::Apprentissage(){}

Apprentissage::Apprentissage(ReseauNeurones reseauN, Erreur erreur){
    rn = reseauN;
    err = erreur;
}

ReseauNeurones Apprentissage::getRN(){
    return rn;
}

Optimisateur Apprentissage::getOptimisateur(){
    return opt;
}

Erreur Apprentissage::getErreur(){
    return err;
}

Donnees Apprentissage::getDonnees(){
    return donnees;
}

ParametresApprentissage Apprentissage::getParam(){
    return param;
}

void Apprentissage::setOptimisateur(Optimisateur optimisateur){
    opt=optimisateur;
}

void Apprentissage::setDonnees(Donnees d){
    donnees=d;
}

void Apprentissage::setParam(ParametresApprentissage paramApp){
     param=paramApp;
}

void Apprentissage::apprendre(){
    for (int i=0;i++;param.getNbEpoques){
        for (int j=0;j++;donnees.getNbDonnees){
            Tenseur* t;
            Tenseur x = donnees.getDonnee(j).getEntree();
            t = &x;
            Tenseur l = donnees.getDonnee(j).getSortie();
            Tenseur* y = rn.propagation(t);
            Tenseur e = err.eval(*y,l);
            opt.minimiser(err);
        }
        donnees.melanger();
    }
}