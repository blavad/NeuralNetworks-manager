#include "CoucheCombinaison.hpp"

CoucheCombinaison::CoucheCombinaison(std::string no):Couche(no)
{	
}


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

void CoucheCombinaison::update(Tenseur t, double alpha){
	Tenseur talpha(t.getDim());
	talpha.initValeurConstant(alpha);
	setParams(params + talpha*t); //multiplication terme a terme
}