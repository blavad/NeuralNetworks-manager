#include "DimTenseur.hpp"

DimTenseur::DimTenseur() : dim(std::vector<int>{})
{
}

DimTenseur::DimTenseur(std::vector<int> d)
{
	dim = d;
}

DimTenseur &DimTenseur::operator=(const DimTenseur &dimT)
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
	return dim[dim.size() - i - 1];
}

std::vector<int> DimTenseur::getDims() const
{
	return dim;
}

int DimTenseur::getTaille() const
{
	int prod = 1;
	for (int d : getDims())
	{
		prod = prod * d;
	}
	return prod;
}