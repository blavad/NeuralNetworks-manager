#include "Matrice.hpp"

Matrice::Matrice() : Tenseur()
{
}

Matrice::Matrice(int l, int c) : Tenseur(std::vector<int>{l, c})
{
}

Matrice::Matrice(double *vl, int l, int c) : Tenseur(DimTenseur(std::vector<int>{l, c}))
{
    // setValeurs(vl);
}

Matrice &Matrice::operator=(const Matrice &copy)
{
    Tenseur::operator=(copy);
    return (*this);
}

Matrice &Matrice::operator+(const Matrice &m)
{
    Matrice *res = new Matrice(getNbLignes(), getNbColonnes());
    if (getDim() != m.getDim())
        throw DimensionsIncompatiblesException();
    else
    {
        int n = res->getTaille();
        for (int i = 0; i < n; i++)
        {
            res->setValeur(getValeur(i) + m.getValeur(i), i);
        }
    }
    return *res;
}

Matrice &Matrice::operator-(const Matrice &m)
{
    Matrice *res = new Matrice(getNbLignes(), getNbColonnes());
    if (getDim() != m.getDim())
        throw DimensionsIncompatiblesException();
    else
    {
        int n = res->getTaille();
        for (int i = 0; i < n; i++)
        {
            res->setValeur(getValeur(i) - m.getValeur(i), i);
        }
    }
    return *res;
}

Tenseur &Matrice::operator*(const Tenseur &t)
{
    if (t.getOrdre() > 2)
    {
        throw MethodeNonImplException("Multiplication avec tenseur ordre > 3");
    }
    else if (t.getOrdre() == 2)
    {
        if (getNbColonnes() != t.getDim(1))
            throw DimensionsIncompatiblesException(getNbColonnes(), t.getDim(1));
        else
        {
            Matrice *m = new Matrice(getNbLignes(), t.getDim(0));
            for (int i = 0; i < m->getNbLignes(); i++)
            {
                for (int j = 0; j < m->getNbColonnes(); j++)
                {
                    for (int k = 0; k < getNbColonnes(); k++)
                    {
                        m->setValeur(m->getValeur(std::vector<int>{i, j}) + getValeur(std::vector<int>{i, k}) * t.getValeur(std::vector<int>{k, j}), std::vector<int>{i, j});
                    }
                }
            }
            return (*m);
        }
    }
    else if (t.getOrdre() == 1)
    {
        Vecteur *v = new Vecteur(getNbLignes());
        for (int i = 0; i < getNbLignes(); i++)
        {
            for (int k = 0; k < getNbColonnes(); k++)
            {
                setValeur(v->getValeur(std::vector<int>{i}) + getValeur(std::vector<int>{i, k}) * t.getValeur(std::vector<int>{k}), std::vector<int>{k});
            }
        }
        return (*v);
    }
}

int Matrice::getNbLignes() const
{
    return getDim(1);
}
int Matrice::getNbColonnes() const
{
    return getDim(0);
}