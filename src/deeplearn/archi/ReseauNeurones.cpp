#include "ReseauNeurones.hpp"
#include "Couche.hpp"
#include <vector>
#include "Tenseur.hpp"

using namespace std;

ReseauNeurones::ReseauNeurones() : Graphe<Couche *>(), Couche()
{
}

ReseauNeurones::ReseauNeurones(std::vector<Couche *> couches) : Graphe<Couche *>(couches), Couche()
{
}

Tenseur *ReseauNeurones::propagation(Tenseur *t)
{
	for (auto c = couche_initiale.begin(); c != couche_initiale.end(); c++)
	{
		visite.push_back(*c);
		propagationS(*c, (*c)->propagation(t));
	}
	Tenseur *res = new Tenseur();
	for (auto c = couche_finale.begin(); c != couche_finale.end(); c++)
	{
		int i = 0;
		while (l[i].first != *c)
			i++;
		cout << "Prop dans " << l[i].first->getNom() << endl;

		*res = res->concatener(*(l[i].first->propagation(l[i].second)));
	}

	return res;
}

void ReseauNeurones::propagationS(Couche *c, Tenseur *t)
{
	//std::vector<Couche*>::iterator s;

	for (auto s = getListNoeudSucc(positionNoeud(c)).begin(); s != getListNoeudSucc(positionNoeud(c)).end(); ++s)
	{
		if (std::find(visite.begin(), visite.end(), *s) == visite.end())
		{
			//std::vector<Couche*>::iterator a;
			bool test = true;
			//verifie si tous les antecedents ont ete visites
			for (auto a = getListNoeudAnt(positionNoeud(*s)).begin(); a != getListNoeudAnt(positionNoeud(*s)).end(); ++a)
			{
				if (std::find(visite.begin(), visite.end(), *a) == visite.end())
				{
					test = false;
					break;
				}
			}
			// si tous les antecedents ont ete visites
			if (test)
			{
				visite.push_back(*s);
				// si le noeud n'est pas une couche finale
				if (std::find(couche_finale.begin(), couche_finale.end(), *s) == couche_finale.end())
				{
					int i = 0;
					while (l[i].first != *s)
						i++;
					// si le noeud est deja en attente dans la liste
					if (l.begin() + i != l.end())
					{
						t->lineariser();
						*t = t->concatener(*(l[i].second));
						cout << "Prop dans " << (*s)->getNom() << endl;

						propagationS(*s, (*s)->propagation(t));
						l.erase(l.begin() + i);
					}
					// le noeud n'est pas dans la liste
					else
					{
						cout << "Prop dans " << (*s)->getNom() << endl;
						propagationS(*s, (*s)->propagation(t));
					}
				}
				else
				{
					int i = 0;
					while (l[i].first != *s)
						i++;
					if (i == l.size())
					{
						t->lineariser();
						l.push_back(make_pair(*s, t));
					}
					else
					{
						t->lineariser();
						*(l[i].second) = l[i].second->concatener(*t);
					}
				}
			}
		}
		else
		{
			t->lineariser();
			l.push_back(make_pair(*s, t));
		}
	}
}

Tenseur *ReseauNeurones::derivee(Tenseur *t)
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
