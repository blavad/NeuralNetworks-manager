#include "Tenseur.hpp"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <random>

using namespace std;

Tenseur::Tenseur(std::vector<int> dims) : dimT(dims)
{
	int prod = 1;
	for (int d : dims)
	{
		prod = prod * d;
	}
	valeur = (double *)malloc(prod * sizeof(double));
}

Tenseur::Tenseur(double *val, DimTenseur di) : dimT(di)
{
	valeur = val;
}

Tenseur::~Tenseur()
{
	free(valeur);
}

Tenseur Tenseur::operator[](const int)
{
}

bool Tenseur::nextInd(std::vector<int> &ind)
{
	int n = ind.size() - 1;
	for (int i = n; i >= 0; i--)
	{
		if (ind[i] + 1 >= dimT.getDim(i))
		{
			ind[i] = 0;
		}
		else
		{
			ind[i] += 1;
			return true;
		}
	}
	return false;
}

void Tenseur::initValeurGaussienne()
{
	default_random_engine generator;
	normal_distribution<double> distribution(0.0, 1.0);
	vector<int> ind(dimT.getOrdre(), 0);
	double val = distribution(generator);
	setValeur(val, ind);
	while (nextInd(ind))
	{
		double val = distribution(generator);
		setValeur(val, ind);
	}
}

void Tenseur::initValeurNulle()
{
	vector<int> indice(dimT.getOrdre(), 0);
	setValeur(0., indice);
	while (nextInd(indice))
	{
		setValeur(0., indice);
	}
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

double Tenseur::getValeur(std::vector<int> indices)
{
	int ind = getInd(indices);
	return valeur[ind];
}

void Tenseur::setValeur(double val, std::vector<int> indices)
{
	int ind = getInd(indices);
	valeur[ind] = val;
}

DimTenseur Tenseur::getDim()
{
	return dimT;
}

void Tenseur::setDim(DimTenseur di)
{
	dimT = di;
}

int Tenseur::getInd(std::vector<int> indices)
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