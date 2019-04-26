#include "Vecteur.hpp"


Vecteur::Vecteur(int l):Tenseur(std::vector<int>{l})
{
    
}

Vecteur::Vecteur(double* vl, int l):Tenseur(DimTenseur(std::vector<int>{l}))
{
    setValeurs(vl);
}