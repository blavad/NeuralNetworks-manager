#include "DimTenseur.hpp"

DimTenseur::DimTenseur(std::vector<int> d)
{
	dim = d;
}

bool DimTenseur::operator==(DimTenseur t2)
{
	return (dim == t2.getDims());
}

int DimTenseur::getOrdre()
{
	return dim.size();
}

int DimTenseur::getDim(int i)
{
	return dim[i];
}

std::vector<int> DimTenseur::getDims()
{
	return dim;
}
