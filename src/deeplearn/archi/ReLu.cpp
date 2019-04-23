#include "ReLU.hpp"

ReLU::ReLU(DimTenseur din,DimTenseur dout, std::string no):CoucheActivation(din,dout,no)
{
}


Tenseur ReLU::propagation(Tenseur t)
{
	return t;
}
