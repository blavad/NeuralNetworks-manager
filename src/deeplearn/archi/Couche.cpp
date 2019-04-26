#include "Couche.hpp"


Couche::Couche(DimTenseur din, DimTenseur dout, std::string no=NULL):dim_in(din),dim_out(dout), nom(no)
{	
}


  	
Tenseur Couche::propagation(Tenseur t)
{
}


         
Tenseur Couche::derivee(Tenseur t)
{
}


 	
void Couche::setDimInput(DimTenseur dimIn)
{
	dim_in = dimIn;
}


 	
void Couche::setDimOutput(DimTenseur dimOut)
{
	dim_out = dimOut;
}
 	

 	
DimTenseur Couche::getDimInput() const 
{
	return dim_in;
}


 	
DimTenseur Couche::getDimOutput() const 
{
	return dim_out;
}


	
std::string Couche::getNom() const
{
	return nom;
}


	
bool Couche::afficher()
{
	return true;
}

