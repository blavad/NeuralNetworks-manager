#include "TanH.hpp"

TanH::TanH(DimTenseur din,DimTenseur dout, std::string no):CoucheActivation(din,dout,no)
{
}

Tenseur TanH::propagation(Tenseur t)
{
	return t;
}