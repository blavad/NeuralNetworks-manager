#include "TanH.hpp"

TanH::TanH(std::string no):CoucheActivation(no)
{
}

TanH::TanH(DimTenseur din, std::string no):CoucheActivation(din,no)
{
}

double calcul_tanh(double x)
{
	return tanh(x);
}

double calcul_derive_tanh(double x)
{
	return (1 - tanh(x)*tanh(x));
}

Tenseur* TanH::propagation(Tenseur* t)
{
	double (*f)	(double);
	f=calcul_tanh;
	return t->appliquerFonction(f);
}

Tenseur* TanH::derivee(Tenseur* t)
{
	double (*df)(double);
	df = calcul_derive_tanh;
	return t->appliquerFonction(df);
}