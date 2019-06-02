#include "TanH.hpp"
#include <iostream>

TanH::TanH(std::string no) : CoucheActivation(no)
{
}

TanH::TanH(DimTenseur din, std::string no) : CoucheActivation(din, no)
{
}

double calcul_tanh(double x)
{
	return tanh(x);
}

double calcul_derive_tanh(double x)
{
	return (1 - tanh(x) * tanh(x));
}

Tenseur &TanH::propagation(Tenseur &t)
{
	Couche::propagation(t);
	Tenseur* res = new Tenseur();
	*res = t;
	double (*f)	(double);
	f=calcul_tanh;
	res->appliquerFonction(f);
	return *res;
}

Tenseur& TanH::derivee(Tenseur &t)
{
	Tenseur* res = new Tenseur();
	*res = t;
	double (*df)(double);
	df = calcul_derive_tanh;
	res->appliquerFonction(df);
	return *res;
}