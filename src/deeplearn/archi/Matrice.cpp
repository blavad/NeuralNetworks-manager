#include "Matrice.hpp"

Matrice::Matrice(int l, int c) : Tenseur(std::vector<int>{l, c})
{
}

Matrice::Matrice(double *vl, int l, int c) : Tenseur(vl, DimTenseur(std::vector<int>{l, c}))
{
}