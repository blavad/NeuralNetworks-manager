#include "Sigmoid.hpp"

Sigmoid::Sigmoid(std::string no):CoucheActivation(no)
{
}

Sigmoid::Sigmoid(DimTenseur din, std::string no):CoucheActivation(din,no)
{
}

double calcul_sigmoid(double x)
{
	return 1.0/(1.0+exp(-x));
}

double calcul_derive_sigmoid(double x)
{
	return calcul_sigmoid(x)*(1-calcul_sigmoid(x));
}

Tenseur* Sigmoid::propagation(Tenseur* t)
{
	double (*f)	(double);
	f=calcul_sigmoid;
	return t->appliquerFonction(f);
}

Tenseur* Sigmoid::derivee(Tenseur* t)
{
	double (*df)(double);
	df = calcul_derive_sigmoid;
	return t->appliquerFonction(df);
}

