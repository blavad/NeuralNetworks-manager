#include "Sigmoid.hpp"

Sigmoid::Sigmoid(DimTenseur din,DimTenseur dout, std::string no):CoucheActivation(din,dout,no)
{
}


Tenseur Sigmoid::propagation(Tenseur t)
{
	return t;
}
