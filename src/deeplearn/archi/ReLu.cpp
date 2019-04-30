#include "ReLU.hpp"

ReLU::ReLU(DimTenseur din, std::string no):CoucheActivation(din, no)
{
}

double calcul(double x)
{
	return std::max(0.0,x);
}

Tenseur ReLU::propagation(Tenseur t)
{
	double (*f)	(double);
	f=calcul;
	return t.appliquerFonction(f, t);
}

double calcul_derive(double x)
{
	if (x<=0.0) return 0.0;
	else return 1.0;
}

Tenseur ReLU::derivee(Tenseur t)
{
	double (*df)(double);
	df = calcul_derive;
	return t.appliquerFonction(df,t);
}
