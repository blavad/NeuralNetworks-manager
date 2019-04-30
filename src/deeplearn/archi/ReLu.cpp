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


