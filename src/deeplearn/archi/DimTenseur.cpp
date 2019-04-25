#include "DimTenseur.hpp"

DimTenseur::DimTenseur(std::vector<int> d)
{
	dim = d;
}

DimTenseur& DimTenseur::operator=(const DimTenseur &dimT) 
{
	dim = dimT.getDims();
	return *this;
}

bool DimTenseur::operator==(const DimTenseur &dimT) const
{
	return (dim == dimT.getDims());
}

bool DimTenseur::operator!=(const DimTenseur &dimT) const
{
	return (dim != dimT.getDims());
}

int DimTenseur::getOrdre() const
{
	return dim.size();
}

int DimTenseur::getDim(int i) const
{
	return dim[i];
}

std::vector<int> DimTenseur::getDims() const
{
	return dim;
}
