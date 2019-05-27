#include "ReLU.hpp"
#include <iostream>

ReLU::ReLU(const std::string no):CoucheActivation(no)
{
}

ReLU::ReLU(DimTenseur din, const std::string no):CoucheActivation(din, no)
{
}

double calcul_relu(double x)
{
	return std::max(0.0,x);
}

double calcul_derive_relu(double x)
{
	if (x<=0.0) return 0.0;
	else return 1.0;
}

Tenseur& ReLU::propagation(Tenseur& t)
{
	Couche::propagation(t);
	Tenseur* res = new Tenseur();
	*res = t;
	double (*f)	(double);
	f=calcul_relu;
	res->appliquerFonction(f);
	return *res;
}

Tenseur* ReLU::derivee(Tenseur* t)
{
	double (*df)(double);
	df = calcul_derive_relu;
	return t->appliquerFonction(df);
}


