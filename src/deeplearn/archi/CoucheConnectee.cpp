#include "CoucheConnectee.hpp"

CoucheConnectee::CoucheConnectee(DimTenseur din, int nb_sorties, std::string no):CoucheCombinaison(din,DimTenseur(std::vector<int>{nb_sorties}),no)
{	
}


Tenseur CoucheConnectee::propagation(Tenseur t)
{
	return t;
}