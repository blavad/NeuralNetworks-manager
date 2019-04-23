#include "Vecteur.hpp"

Vecteur::Vecteur(void* vl, int l):Tenseur(vl,DimTenseur(1,std::vector<int>{l}))
{
}