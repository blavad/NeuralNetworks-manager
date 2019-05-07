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


Tenseur* ReseauNeurones::propagation(Tenseur* t)
{
	return t;
}

void ReseauNeurones::propagationS(Couche *c, Tenseur *t)
{
	//std::vector<Couche*>::iterator s;
	
	for( auto s = getListNoeudSucc(positionNoeud(c)).begin(); s!=getListNoeudSucc(positionNoeud(c)).end(); ++s){
        if (std::find(visite.begin(), visite.end(), *s) == visite.end()){
			//std::vector<Couche*>::iterator a;
			bool test = true;
			for (auto a = getListNoeudAnt(positionNoeud(*s)).begin(); a!=getListNoeudAnt(positionNoeud(*s)).end(); ++a) {
				if (std::find(visite.begin(), visite.end(), *a) == visite.end()) {
					test = false;
					break;
				}
			}
			if (test){
				visite.push_back(*s);
				if (std::find(couche_finale.begin(), couche_finale.end(), *s) == couche_finale.end()) {
					int i = 0;
					while (l[i].first != *s) i++;
				
				}
			}
		}
    }
}

Tenseur* ReseauNeurones::derivee(Tenseur* t)
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
	//couche_initiale.erase(c);
	
	
}
void ReseauNeurones::supprimerCoucheFinale(Couche *c)
{
	
	supprimerNoeud(c);
	//couche_finale.erase(c);
	
}

void ReseauNeurones::ajouterArc(Couche *noeud_init, Couche *noeud_final)
{
	
	ajouterArc(noeud_init, noeud_final);
	
	
}


void ReseauNeurones::supprimerArc(Couche *noeud_init, Couche *noeud_final)
{
	
	supprimerArc(noeud_init, noeud_final);
	
	
	
}


void ReseauNeurones::sauvegarderReseau(ReseauNeurones reseau)
{
	
	
}

















