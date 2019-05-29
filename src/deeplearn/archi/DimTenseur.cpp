#include "DimTenseur.hpp"
#include <string>

DimTenseur::DimTenseur() : dim(std::vector<int>{})
{
}

DimTenseur::DimTenseur(std::initializer_list<int> dims)
{
	for (int d : dims)
	{
		dim.push_back(d);
	};
}

DimTenseur::DimTenseur(std::vector<int> d)
{
	dim = d;
}

DimTenseur::DimTenseur(const DimTenseur &d) : DimTenseur(d.getDims()) {}

DimTenseur &DimTenseur::operator=(const DimTenseur &dimT)
{
	dim = dimT.getDims();
	return *this;
}

DimTenseur &DimTenseur::operator=(std::vector<int> &dimT)
{
	dim = dimT;
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

DimTenseur DimTenseur::operator+(const DimTenseur dt)
{
	if (dim.size() == 0)
		return dt;
	else
	{
		if (dt.getDims().size() == 0)
			return dim;
		else
		{
			DimTenseur res(std::vector<int>{getTaille() + dt.getTaille()});
			return res;
		}
	}
}

std::ostream &operator<<(std::ostream &os, const DimTenseur &d)
{
	std::string str;
	if (d.getDims().size() == 0)
	{
		os << 0;
	}
	else
	{
		for (int i = 0; i < d.getOrdre() - 1; i++)
		{
			os << d.getDim(i) << "x";
		}
		os << d.getDim(d.getOrdre() - 1);
	}
	return os;
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
	if ((getDims().size() == 0) || ((getDims().size() == 1) && (getDim(0) == 0)))
	{
		return 0;
	}
	int prod = 1;
	for (int d : getDims())
	{
		prod = prod * d;
	}
	return prod;
}

std::string DimTenseur::toString()
{
	std::string str;
	if (getDims().size() == 0)
	{
		return "0";
	}
	else
	{
		for (int i = 0; i < getOrdre() - 1; i++)
		{
			str += std::to_string(getDim(i)) + "x";
		}
		str += std::to_string(getDim(getOrdre() - 1));
		return str;
	}
}
