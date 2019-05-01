#include "Donnees.hpp"
#include <vector>

using namespace std;


Donnees::Donnees()
{
	
}

Donnees::Donnees(std::vector<Donnee> vd)
{
	
}


std::vector<Donnee> Donnees::getDonnees()
{
	return donnees;
}


Donnee Donnees::getDonnee(int ind)
{
	return donnees.at(ind-1); // Je pense qu'il faut mettre -1 car si on veut la 9eme donnée, il faut prendre donnees(8).
}


int Donnees::getNbDonnees()
{
	return donnees.size();
}



void Donnees::ajouterDonnee(Donnee d)
{
	donnees.emplace_back(d); // Emplace_back et push_back font la même chose apparement mais emplace est plus efficace (voir infos sur "geeksforgeeks")
}


void Donnees::ajouterDonnees(Donnees d)
{
	donnees.insert(donnees.end(),d.getDonnees.begin(),d.getDonnees.end());
}

	
int Donnees::nombreAleatoire(int i)
{
    srand((int)time(0));
    int nombreAleatoire = (rand() % i);
      
    return nombreAleatoire;
}

void Donnees::melanger()
{
	random_shuffle(donnees.begin(),donnees.end(),nombreAleatoire); // On est obligé de mettre nombreAleatoire sinon on a toujours le même mélange. 
																   // J'ai pas réussi à comprendre pourquoi on est obligé d'utiliser la méthode nombreAleatoire 
																   // mais c'est la seule façon que j'ai trouvé pour que ça marche (j'ai testé sur des entiers)
																   // Je me demande également si on va mélanger plusieurs fois ou qu'une seule fois ? Si on mélange 
																   // qu'une seule fois, on pourra dégager l'histoire du nb aléatoire.
}


