#include "Matrice.hpp"

Matrice::Matrice(int l, int c) : Tenseur(std::vector<int>{l, c})
{
}

Matrice::Matrice(double *vl, int l, int c) : Tenseur(DimTenseur(std::vector<int>{l, c}))
{
    setValeurs(vl);
}

Tenseur Matrice::operator*(const Tenseur &t)
{
    if (getDim().getDim(1) != t.getDim().getDim(0)) throw DimensionsIncompatiblesException();
    else
    {
        for(int i=0; i++ ; i<getDim().getDim(0)){
            for(int j=0; j++ ; j<t.getDim().getDim(1)){
                for(int k=0; k++ ; k<getDim().getDim(1)){
                    setValeur(getValeur(std::vector<int>{i,j})+ getValeur(std::vector<int>{i,k}) * t.getValeur(std::vector<int>{k,j}),std::vector<int>{i,j});
                }
            }
        }
    }
    
}