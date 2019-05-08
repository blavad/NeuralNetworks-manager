#include "ReseauNeurones.hpp"
#include "Couche.hpp"
#include <vector>
#include "Vecteur.hpp"
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
	std::vector<Couche *> ant = getListNoeudAnt(positionNoeud(noeud_final));
	if (ant.empty())
	{
		noeud_final->setDimInput(noeud_init->getDimOutput());
	}
	else
	{
		int new_dim = noeud_init->getDimOutput().getTaille() + noeud_final->getDimInput().getTaille();
		noeud_final->setDimInput(DimTenseur(std::vector<int>{new_dim}));
	}
}

void ReseauNeurones::supprimerArc(Couche *noeud_init, Couche *noeud_final)
{
	Graphe<Couche *>::supprimerArc(noeud_init, noeud_final);
	std::vector<Couche *> ant = getListNoeudAnt(positionNoeud(noeud_final));
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
		noeud_final->setDimInput(DimTenseur(std::vector<int>{new_dim}));
	}
}

void ReseauNeurones::sauvegarderReseau(ReseauNeurones reseau)
{
}
