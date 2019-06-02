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

Tenseur& Sigmoid::propagation(Tenseur& t)
{
	Couche::propagation(t);
	Tenseur* res = new Tenseur();
	*res = t;
	double (*f)	(double);
	f=calcul_sigmoid;
	res->appliquerFonction(f);
	return *res;
}

Tenseur& Sigmoid::derivee(Tenseur& t)
{
	Tenseur* res = new Tenseur();
	*res = t;
	double (*df)(double);
	df = calcul_derive_sigmoid;
	res->appliquerFonction(df);
	return *res;
}

