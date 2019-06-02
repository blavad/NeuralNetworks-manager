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

void Donnees::ajouterDonnee(Donnee &d)
{
	donnees.emplace_back(d);
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
	random_shuffle(donnees.begin(), donnees.end(), nombreAleatoire);								  
}
