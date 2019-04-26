#include "Sigmoid.hpp"

Sigmoid::Sigmoid(DimTenseur din, std::string no):CoucheActivation(din,no)
{
}


Tenseur Sigmoid::propagation(Tenseur t)
{
	return t;
}
