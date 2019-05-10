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

DimTenseur DimTenseur::operator+(const DimTenseur dt){
	if(dim.size()==0) return dt;
	else {
		if(dt.getDims().size()==0) return dim;
		else{
			DimTenseur res(std::vector<int> {getTaille() + dt.getTaille()});
			return res;
		}
	}
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

int DimTenseur::getTaille() const
{
	int prod = 1;
	for (int d : getDims())
	{
		prod = prod * d;
	}
	return prod;
}