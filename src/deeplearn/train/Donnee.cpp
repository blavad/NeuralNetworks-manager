#include "Donnee.hpp" 
#include "../archi/Tenseur.hpp"


Donnee::Donnee()
{
	
}


Donnee::Donnee(Tenseur entree, Tenseur sortie)
{
	
}


Tenseur Donnee::getEntree()
{
	return entree;
}

Tenseur Donnee::getSortie()
{
	return sortie;
}


void Donnee::setEntree(Tenseur e)
{
	entree = e;
}
 	
 	
 	void Donnee::setSortie(Tenseur s)
{
	sortie = s;
}
 	
