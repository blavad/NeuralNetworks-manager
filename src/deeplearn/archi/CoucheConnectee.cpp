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
	t->lineariser();
	Tenseur res = params.operator*(*t);
	return &res;
}

Tenseur* CoucheConnectee::derivee(Tenseur* t)
{
	return t;
}

void CoucheConnectee::upDateDimOutput(){
	params.setDim(DimTenseur(std::vector<int>{getDimInput().getDim(0),getDimOutput().getDim(0)}));
}