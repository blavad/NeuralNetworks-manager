#include "CoucheCombinaison.hpp"

CoucheCombinaison::CoucheCombinaison(DimTenseur din, DimTenseur dout, std::string no):Couche(din,dout,no)
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