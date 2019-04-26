#include "Matrice.hpp"

Matrice::Matrice(int l, int c) : Tenseur(std::vector<int>{l, c})
{
}

Matrice::Matrice(double *vl, int l, int c) : Tenseur(DimTenseur(std::vector<int>{l, c}))
{
    setValeurs(vl);
}