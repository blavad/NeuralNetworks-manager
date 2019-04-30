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

