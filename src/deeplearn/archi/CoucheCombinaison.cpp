#include "CoucheCombinaison.hpp"

CoucheCombinaison::CoucheCombinaison(DimTenseur din, DimTenseur dout, std::string no, Tenseur par):Couche(din,dout,no), params(par)
{	
}



void CoucheCombinaison::setParams(Tenseur nouvParams)
{
	params = nouvParams;
}



Tenseur CoucheCombinaison::getParams()
{
	return params;
}