#include "Tenseur.hpp"
#include "DimTenseur.hpp"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <random>

using namespace std;

Tenseur::Tenseur()
{
}

Tenseur::Tenseur(std::vector<int> dims) : dimT(dims)
{
	init();
}

Tenseur::Tenseur(DimTenseur di) : dimT(di)
{
	init();
}

Tenseur::~Tenseur()
{
	free(valeur);
}

void Tenseur::init()
{
	int prod = getTaille();
	valeur = (double *)malloc(prod * sizeof(double));
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
		vector<int> indice(t.getDim().getOrdre(), 0);
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

Tenseur operator+(const Tenseur &, const Tenseur &){
	
}

Tenseur operator-(const Tenseur &, const Tenseur &){

}

Tenseur operator*(const Tenseur &, const Tenseur &){

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

Tenseur Tenseur::appliquerFonction(double (*f)(double), Tenseur x)
{
	Tenseur res(x.getDim());
	int n = x.getTaille();
	for (int i = 0; i < n; i++)
	{
		res.setValeur(f(x.getValeur(i)), i);
	}
	/* 
	vector<int> indice(dimT.getOrdre(), 0);
	res.setValeur(f(x.getValeur(indice)), indice);
	while (nextInd(indice))
	{
		res.setValeur(f(x.getValeur(indice)), indice);
	} */
	return res;
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

 void Tenseur::setValeur(double val, int indice){
	 valeur[indice]=val;
 }

double Tenseur::getValeur(int i){
	return valeur[i];
}
int Tenseur::getTaille()
{
	int prod = 1;
	for (int d : dimT.getDims())
	{
		prod = prod * d;
	}
	return prod;
}