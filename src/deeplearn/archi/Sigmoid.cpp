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

double calcul_derive(double x)
{
	return calcul(x)*(1-calcul(x));
}

Tenseur Sigmoid::derivee(Tenseur t)
{
	double (*df)(double);
	df = calcul_derive;
	return t.appliquerFonction(df,t);
}

