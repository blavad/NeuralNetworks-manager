#include "CoucheConnectee.hpp"
#include "Matrice.hpp"
#include "Vecteur.hpp"

CoucheConnectee::CoucheConnectee(int nb_sorties, std::string no = "Fully Connected") : CoucheCombinaison(std::vector<int>{0}, std::vector<int>{nb_sorties},no)
{
}

CoucheConnectee::CoucheConnectee(DimTenseur din, int nb_sorties, std::string no) : CoucheCombinaison(din, std::vector<int>{nb_sorties}, no)
{
}

Tenseur* CoucheConnectee::propagation(Tenseur* t)
{
	Tenseur res = params.operator*(*t);
	return &res;
}

Tenseur* CoucheConnectee::derivee(Tenseur* t)
{
	return t;
}