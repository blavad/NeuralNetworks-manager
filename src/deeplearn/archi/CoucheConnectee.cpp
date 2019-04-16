#include "CoucheConnectee.hpp"

CoucheConnectee::CoucheConnectee(DimTenseur din, DimTenseur dout, std::string no, Tenseur par):CoucheCombinaison(din,dout,no,par)
{	
}


Tenseur CoucheConnectee::propagation(Tenseur t)
{
	return t;
}