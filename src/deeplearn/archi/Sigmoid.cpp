#include "Sigmoid.hpp"

Sigmoid::Sigmoid(DimTenseur din, std::string no):CoucheActivation(din,no)
{
}

double calcul(double x)
{
	return 1.0/(1.0+exp(-x));
}

Tenseur Sigmoid::propagation(Tenseur t)
{
	double (*f)(double);
	f = calcul;
	return t.appliquerFonction(f,t);
}


