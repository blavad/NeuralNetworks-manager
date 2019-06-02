#include "Donnee.hpp" 
#include "../archi/Tenseur.hpp"
#include <iostream>

Donnee::Donnee()
{
}


Donnee::Donnee(Tenseur &ent, Tenseur &sor): entree(ent),sortie(sor)
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
