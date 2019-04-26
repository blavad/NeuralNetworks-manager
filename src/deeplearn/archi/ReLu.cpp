#include "ReLU.hpp"

ReLU::ReLU(DimTenseur din, std::string no):CoucheActivation(din, no)
{
}


Tenseur ReLU::propagation(Tenseur t)
{
	return t;
}
