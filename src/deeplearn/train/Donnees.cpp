#include "Donnees.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

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
	return donnees.at(ind); // Je pense qu'il faut mettre -1 car si on veut la 9eme donnée, il faut prendre donnees(8).
}

std::vector<std::string> Donnees::getDossiersDonnees() { return dossiers_donnees; }

void Donnees::setDossiersDonnees(std::vector<std::string> d)
{
	dossiers_donnees = d;
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
	donnees.insert(donnees.end(), d.getDonnees().begin(), d.getDonnees().end());
}

DimTenseur Donnees::getDimDonneesSortie()
{
	return dimSortie;
}
 
DimTenseur Donnees::getDimDonneesEntree()
{
	return dimEntree;
}

void Donnees::setDimDonneesSortie(DimTenseur d)
{
	dimSortie = d;
}

void Donnees::setDimDonneesEntree(DimTenseur d)
{
	dimEntree = d;
}

int nombreAleatoire(int i)
{
	srand((int)time(0));
	int nombreAleatoire = (rand() % i);
	return nombreAleatoire;
}

void Donnees::melanger()
{
	random_shuffle(donnees.begin(), donnees.end(), nombreAleatoire); // On est obligé de mettre nombreAleatoire sinon on a toujours le même mélange.
																	 // J'ai pas réussi à comprendre pourquoi on est obligé d'utiliser la méthode nombreAleatoire
																	 // mais c'est la seule façon que j'ai trouvé pour que ça marche (j'ai testé sur des entiers)
																	 // Je me demande également si on va mélanger plusieurs fois ou qu'une seule fois ? Si on mélange
																	 // qu'une seule fois, on pourra dégager l'histoire du nb aléatoire.
}
