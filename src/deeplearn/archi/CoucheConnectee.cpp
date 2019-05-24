#include "CoucheConnectee.hpp"
#include "Matrice.hpp"
#include "Vecteur.hpp"
#include <iostream>

using namespace std;

CoucheConnectee::CoucheConnectee(int nb_sorties, std::string no) : CoucheCombinaison(std::vector<int>{0}, std::vector<int>{nb_sorties}, no)
{
}

CoucheConnectee::CoucheConnectee(DimTenseur din, int nb_sorties, std::string no) : CoucheCombinaison(din, std::vector<int>{nb_sorties}, no)
{
}

Tenseur *CoucheConnectee::propagation(Tenseur *t)
{
	Couche::propagation(t);
	t->lineariser();
	return &params.operator*(*t);
}

Tenseur *CoucheConnectee::derivee(Tenseur *t)
{
	return t;
}

void CoucheConnectee::setDimInput(DimTenseur dimIn)
{
	Couche::setDimInput(std::vector<int>{dimIn.getTaille()});
}

std::string CoucheConnectee::type()
{
    return "CoucheConnectee";
}

void CoucheConnectee::upDateDimOutput()
{
	if (getDimInput().getTaille() == 0)
	{
		params.setDim(DimTenseur(std::vector<int>{}));
	}
	else
	{
		params.setDim(DimTenseur(std::vector<int>{getDimInput().getDim(0), getDimOutput().getDim(0)}));
	}
}