#include "ReseauNeurones.hpp"
#include "Couche.hpp"
#include <vector>
#include "Tenseur.hpp"


using namespace std;


ReseauNeurones::ReseauNeurones()
{
	
}


ReseauNeurones::ReseauNeurones(std::vector<Couche*> couches)
{
	
}


Tenseur ReseauNeurones::propagation(Tenseur t)
{
	return t;
}


void ReseauNeurones::ajouterCoucheInitiale(Couche *c)
{
	
	ajouterNoeud(c);
	couche_initiale.push_back(c);
	
}

void ReseauNeurones::ajouterCoucheFinale(Couche *c)
{
	
	ajouterNoeud(c);
	couche_finale.push_back(c);
	
	
}

void ReseauNeurones::supprimerCoucheInitiale(Couche *c)
{
	
	supprimerNoeud(c);
	couche_initiale.erase(c);
	
	
}
void ReseauNeurones::supprimerCoucheFinale(Couche *c)
{
	
	supprimerNoeud(c);
	couche_finale.erase(c);
	
}

void ReseauNeurones::ajouterArc(Couche *noeud_init, Couche *noeud_final)
{
	
	ajouterArc(noeud_init, noeud_final);
	
	
}


void ReseauNeurones::supprimerArc(Couche *noeud_init, Couche *noeud_final)
{
	
	supprimerArc(noeud_init, noeud_final);
	
	
	
}


void ReseauNeurones::sauvegarderReseau(Reseau reseau)
{
	
	
}

















