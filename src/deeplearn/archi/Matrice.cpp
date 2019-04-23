#include "Matrice.hpp"

Matrice::Matrice(void* vl, int l, int c):Tenseur(vl,DimTenseur(2,std::vector<int>{l,c}))
{
}