#include "TanH.hpp"

TanH::TanH(DimTenseur din, std::string no):CoucheActivation(din,no)
{
}

Tenseur TanH::propagation(Tenseur t)
{
	return t;
}