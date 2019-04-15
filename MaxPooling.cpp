#include "MaxPooling.hpp"


   
MaxPooling::MaxPooling(DimTenseur din, DimTenseur dout, std::string no, int pl_x, int pl_y):Couche(din,dout,no), pool_x(pl_x), pool_y(pl_y) 
{
}



MaxPooling::MaxPooling(DimTenseur din, DimTenseur dout, std::string no, int pl):Couche(din,dout,no), pool_x(pl), pool_y(pl) 
{
}
	

	
Tenseur MaxPooling::propagation(Tenseur t)
{
	return t;
}



void MaxPooling::setPoolX(int pl_x )
{
	pool_x = pl_x;
}



void MaxPooling::setPoolY(int pl_y)
{
	pool_y = pl_y;
}



int MaxPooling::getPoolX() const
{
	return pool_x;
}



int MaxPooling::getPoolY() const 
{
	return pool_y;
}

