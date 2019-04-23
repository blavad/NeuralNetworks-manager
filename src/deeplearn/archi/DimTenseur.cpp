#include "DimTenseur.hpp"



DimTenseur::DimTenseur()
{
}



DimTenseur::DimTenseur(int ord, std::vector<int> di)
{
	ordre = ord;
	dim = di;
}



int DimTenseur::getOrdre()
{
	return ordre;
}



std::vector<int> DimTenseur::getDim()
{
	return dim;
}