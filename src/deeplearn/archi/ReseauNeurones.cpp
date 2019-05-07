#include "ReseauNeurones.hpp"
#include "Couche.hpp"
#include <vector>
#include "Vecteur.hpp"
#include "Tenseur.hpp"
#include "DimTenseur.hpp"

using namespace std;

ReseauNeurones::ReseauNeurones()
{
}

ReseauNeurones::ReseauNeurones(std::vector<Couche *> couches)
{
}

Tenseur *ReseauNeurones::propagation(Tenseur *t)
{
	return t;
}

Tenseur *ReseauNeurones::derivee(Tenseur *t)
{
	return t;
}

void ReseauNeurones::ajouterCoucheInitiale(Couche *c)
{
	Graphe<Couche *>::ajouterNoeud(c);
	couche_initiale.push_back(c);
}

void ReseauNeurones::ajouterCoucheFinale(Couche *c)
{
	Graphe<Couche *>::ajouterNoeud(c);
	couche_finale.push_back(c);
}

void ReseauNeurones::supprimerCoucheInitiale(Couche *c)
{

	Graphe<Couche *>::supprimerNoeud(c);

	for (auto tmp = couche_initiale.begin(); tmp != couche_initiale.end(); ++tmp)
	{
		if (*tmp == c)
		{
			couche_initiale.erase(tmp);
			break;
		}
	}
}
void ReseauNeurones::supprimerCoucheFinale(Couche *c)
{

	Graphe<Couche *>::supprimerNoeud(c);
	for (auto tmp = couche_finale.begin(); tmp != couche_initiale.end(); ++tmp)
	{
		if (*tmp == c)
		{
			couche_finale.erase(tmp);
			break;
		}
	}
}

void ReseauNeurones::ajouterArc(Couche *noeud_init, Couche *noeud_final)
{
	Graphe<Couche *>::ajouterArc(noeud_init, noeud_final);
	vector<Couche *> ant = getListNoeudAnt(positionNoeud(noeud_final));
	if (ant.empty())
	{
		noeud_final->setDimInput(noeud_init->getDimOutput());
	}
	else
	{
		int new_dim = noeud_init->getDimOutput().getTaille() + noeud_final->getDimInput().getTaille();
		noeud_final->setDimInput(DimTenseur(vector<int>{new_dim}));
	}
}

void ReseauNeurones::supprimerArc(Couche *noeud_init, Couche *noeud_final)
{
	Graphe<Couche *>::supprimerArc(noeud_init, noeud_final);
	vector<Couche *> ant = getListNoeudAnt(positionNoeud(noeud_final));
	if (ant.empty())
	{
		throw exception();
	}
	else if (ant.size() == 1)
	{
		noeud_final->setDimInput(DimTenseur());
	}
	else if (ant.size() == 2)
	{
		noeud_final->setDimInput(noeud_init->getDimOutput());
	}
	else
	{
		int new_dim = noeud_init->getDimOutput().getTaille() + noeud_final->getDimInput().getTaille();
		noeud_final->setDimInput(DimTenseur(vector<int>{new_dim}));
	}
}

void ReseauNeurones::sauvegarderReseau(ReseauNeurones reseau)
{
}
