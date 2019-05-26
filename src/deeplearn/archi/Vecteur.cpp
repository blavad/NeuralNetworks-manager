#include "Vecteur.hpp"

Vecteur::Vecteur(int l) : Tenseur(std::vector<int>{l})
{
}
/* 
Vecteur Vecteur::operator=(const Vecteur copy)
{
    Tenseur::operator=(copy);
    return (*this);
} */

Vecteur &Vecteur::operator+(const Vecteur &m)
{
    Vecteur *res = new Vecteur(getLength());
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

Vecteur &Vecteur::operator-(const Vecteur &m)
{
    Vecteur *res = new Vecteur(getLength());
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

Tenseur &Vecteur::operator*(Tenseur &t)
{
    if ((t.getOrdre() > 1) || (getLength() != t.getDim(0)))
        throw DimensionsIncompatiblesException(getLength(), t.getDim(0));
    else
    {
        Vecteur *v = new Vecteur(1);
        for (int i = 0; i < getLength(); i++)
        {
            v->setValeur(v->getValeur(std::vector<int>{0}) + getValeur(std::vector<int>{i}) * t.getValeur(std::vector<int>{i}), std::vector<int>{0});
        }
        return (*v);
    }
}

int Vecteur::getLength() const
{
    return getDim(0);
}