#include "ParametresApprentissage.hpp" 



ParametresApprentissage::ParametresApprentissage()
{
	
}


int ParametresApprentissage::getNbEpoques()
{
	return nb_epoques;
}

double ParametresApprentissage::getTauxApprentissage()
{
	return taux_apprentissage;
}


void ParametresApprentissage::setNbEpoques(int ep)
{
	nb_epoques=ep;
}
 	
 	
void ParametresApprentissage::setTauxApprentissage(double ta)
{
	taux_apprentissage = ta;
}
 	
