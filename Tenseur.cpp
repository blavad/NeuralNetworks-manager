#include "Tenseur.hpp"



Tenseur::Tenseur(void* val, DimTenseur di)
{
	valeur = val;
	dim = di;
}

 
void Tenseur::initValeurGaussienne()
{
}

  
      
void Tenseur::initValeurNulle()
{
}


        
void Tenseur::initValeurUnif()
{
}



void Tenseur::setValeur(void* vl)
{
	valeur = vl;
}

       

void Tenseur::setDim(DimTenseur di)
{
	dim = di;
}



void* Tenseur::getValeur()
{
	return valeur;
}



DimTenseur Tenseur::getDim()
{
	return dim;
}