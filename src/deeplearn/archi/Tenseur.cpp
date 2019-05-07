#include "Tenseur.hpp"
#include "DimTenseur.hpp"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <random>
#include "exception/MethodeNonImplException.hpp"

using namespace std;

Tenseur::Tenseur()
{
}

Tenseur::Tenseur(std::vector<int> dims) : dimT(dims)
{
	allocate();
}

Tenseur::Tenseur(DimTenseur di) : dimT(di)
{
	allocate();
}

Tenseur::~Tenseur()
{
	free(valeur);
}

void Tenseur::allocate()
{
	int prod = getTaille();
	if (valeur == NULL)
	{
		valeur = (double *)malloc(prod * sizeof(double));
	}
	else
	{
		valeur = (double *)realloc(valeur, prod * sizeof(double));
	}
}

Tenseur &Tenseur::operator=(const Tenseur &copy)
{
	int n = copy.getTaille();
	setDim(copy.getDim());
	allocate();
	for (int i = 0; i < n; i++)
	{
		setValeur(copy.valeur[i], i);
	}
	return *this;
}

bool Tenseur::operator==(const Tenseur &t)
{
	bool res;
	if (getDim() != t.getDim())
	{
		return false;
	}
	else
	{
		vector<int> indice(t.getOrdre(), 0);
		res = getValeur(indice) == t.getValeur(indice);
		while (res && nextInd(indice))
		{
			res = getValeur(indice) == t.getValeur(indice);
		}
		return res;
	}
}

bool Tenseur::operator!=(const Tenseur &t)
{
	return !(operator==(t));
}

Tenseur &Tenseur::operator+(const Tenseur &tt)
{
	Tenseur *res = new Tenseur(getDim());
	if (getDim() != tt.getDim())
		throw DimensionsIncompatiblesException();
	else
	{
		int n = res->getTaille();
		for (int i = 0; i < n; i++)
		{
			res->setValeur(getValeur(i) + tt.getValeur(i), i);
		}
	}
	return *res;
}

Tenseur &Tenseur::operator-(const Tenseur &tt)
{
	Tenseur *res = new Tenseur(getDim());
	if (getDim() != tt.getDim())
		throw DimensionsIncompatiblesException();
	else
	{
		int n = res->getTaille();
		for (int i = 0; i < n; i++)
		{
			res->setValeur(getValeur(i) - tt.getValeur(i), i);
		}
	}
	return *res;
}

Tenseur &Tenseur::operator*(const Tenseur &)
{
	cout << "Erreur !!! " << endl;
}

bool Tenseur::nextInd(std::vector<int> &ind) const
{
	int n = ind.size();
	for (int i = 0; i < n; i++)
	{
		if (ind[n - i - 1] + 1 >= getDim(i))
		{
			ind[n - i - 1] = 0;
		}
		else
		{
			ind[n - i - 1] += 1;
			return true;
		}
	}
	return false;
}

Tenseur *Tenseur::appliquerFonction(double (*f)(double))
{
	int n = getTaille();
	for (int i = 0; i < n; i++)
	{
		setValeur(f(getValeur(i)), i);
	}
	return this;
}

void Tenseur::initValeurGaussienne()
{
	default_random_engine generator;
	normal_distribution<double> distribution(0.0, 1.0);
	vector<int> ind(getOrdre(), 0);
	double val = distribution(generator);
	setValeur(val, ind);
	while (nextInd(ind))
	{
		double val = distribution(generator);
		setValeur(val, ind);
	}
}

void Tenseur::initValeurConstant(double v)
{
	vector<int> indice(getOrdre(), 0);
	setValeur(v, indice);
	while (nextInd(indice))
	{
		setValeur(v, indice);
	}
}

void Tenseur::initValeurNulle()
{
	initValeurConstant(0.);
}

void Tenseur::initValeurUnif()
{
	vector<int> indice(dimT.getOrdre(), 0);
	srand(time(0));
	double val = (double)rand() / (double)RAND_MAX;
	setValeur(val, indice);
	while (nextInd(indice))
	{
		double val = (double)rand() / (double)RAND_MAX;
		setValeur(val, indice);
	}
}

double Tenseur::getValeur(std::vector<int> indices) const
{
	int ind = getInd(indices);
	return valeur[ind];
}

void Tenseur::setValeur(double val, std::vector<int> indices) const
{
	int ind = getInd(indices);
	valeur[ind] = val;
}

DimTenseur Tenseur::getDim() const
{
	return dimT;
}

int Tenseur::getDim(int i) const
{
	return getDim().getDim(i);
}

int Tenseur::getOrdre() const
{
	return getDim().getOrdre();
}

void Tenseur::setDim(DimTenseur di)
{
	dimT = di;
}

int Tenseur::getInd(std::vector<int> indices) const
{
	int n = indices.size() - 1;
	int ind = indices[n];
	for (int k = n - 1; k >= 0; k--)
	{
		int prod = 1;
		for (int i = n; i > k; i--)
		{
			prod *= dimT.getDim(i);
		}
		ind += (indices[k]) * prod;
	}
	return ind;
}

void Tenseur::setValeur(double val, int indice)
{
	valeur[indice] = val;
}

double Tenseur::getValeur(int i) const
{
	return valeur[i];
}
int Tenseur::getTaille() const
{
	int prod = 1;
	for (int d : dimT.getDims())
	{
		prod = prod * d;
	}
	return prod;
}