#include "TanH.hpp"

TanH::TanH(DimTenseur din, std::string no):CoucheActivation(din,no)
{
}

double calcul(double x)
{
	return tanh(x);
}

Tenseur TanH::propagation(Tenseur t)
{
	double (*f)(double);
	f = calcul;
	return t.appliquerFonction(f,t);
}

double calcul_derive(double x)
{
	return (1 - tanh(x)*tanh(x));
}

Tenseur TanH::derivee(Tenseur t)
{
	double (*df)(double);
	df = calcul_derive;
	return t.appliquerFonction(df,t);
}