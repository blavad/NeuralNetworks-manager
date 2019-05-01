#include "ReseauNeurones.hpp"
#include "Couche.hpp"
#include <vector>
#include "Tenseur.hpp"


using namespace std;


ReseauNeurones::ReseauNeurones()
{
}


ReseauNeurones::ReseauNeurones(std::vector<Couche> couches)
{
}


Tenseur* ReseauNeurones::propagation(Tenseur* t)
{
	return t;
}

Tenseur* ReseauNeurones::derivee(Tenseur* t)
{
	return t;
}


void ReseauNeurones::ajouterCoucheInitiale(Couche c)
{
	
}

void ReseauNeurones::ajouterCoucheFinale(Couche c)
{
	
}

void ReseauNeurones::supprimerCoucheInitiale(Couche c)
{
	
}

void ReseauNeurones::supprimerCoucheInitiale(Couche c)
{
	
}

void ReseauNeurones::ajouterArc(Couche noeud_init, Couche noeud_final)
{
	
}


void ReseauNeurones::supprimerArc(Couche noeud_init, Couche noeud_final)
{
	
}




















