#include "ReseauNeurones.hpp"
#include "DimTenseur.hpp"
#include "exception/CycleException.hpp"
#include "Couche.hpp"
#include <vector>
#include "Vecteur.hpp"
#include "Tenseur.hpp"

using namespace std;

ReseauNeurones::ReseauNeurones(const std::string no) : Graphe<Couche *>(), Couche(no)
{
}

ReseauNeurones::ReseauNeurones(std::vector<Couche *> couches, const std::string no) : Graphe<Couche *>(couches), Couche(no)
{
}

void ReseauNeurones ::miseAJourDims(Couche *cIn, Couche *cOut, bool signe)
{
	DimTenseur sum;

	for (auto a : getListNoeudAnt(positionNoeud(cOut)))
	{
		if (a != cIn)
		{
			sum = sum + a->getDimOutput();
		}
	}
	if (signe)
	{
		sum = sum + cIn->getDimOutput();
	}

	cOut->setDimInput(sum);
	cOut->upDateDimOutput();

	// si cO n'est pas une couche finale
	if (std::find(couche_finale.begin(), couche_finale.end(), cOut) == couche_finale.end())
	{

		for (auto s : getListNoeudSucc(positionNoeud(cOut)))
		{
			if (signe)
				miseAJourDims(cOut, s, signe);
			else
				miseAJourDims(cOut, s, !signe);
		}
	}
}

Tenseur *ReseauNeurones::propagation(Tenseur *t)
{
	if (contientCycle())
	{
		throw CycleException("Le graphe contient un cycle.");
	}
	else
	{
		for (auto c : couche_initiale)
		{
			//visite.push_back(c);
			cout << "Prop dans " << c->getNom() << " " << t->getTaille() << endl;
			propagationS(c, c->propagation(t));
		}
		Tenseur *res = new Tenseur();
		for (auto c : couche_finale)
		{
			int i = 0;
			while ((i < l.size()) && (l[i].first != c))
				i++;
			// Rajouter erreur si couche finale pas dans l
			Tenseur *ttemp = l[i].first->propagation(l[i].second);
			cout << "Propprop dans " << l[i].first->getNom() << " " << ttemp->getTaille() << endl;
			if (couche_finale.size() > 1)
				*res = res->concatener(*ttemp);
			else
				*res = *ttemp;
		}

		return res;
	}
}

void ReseauNeurones::propagationS(Couche *c, Tenseur *sortie)
{
	for (auto s : getListNoeudSucc(positionNoeud(c)))
	{
		Tenseur *t = new Tenseur();
		*t = *sortie;
		// si l'arc n'a pas deja ete visite
		if (std::find(visite.begin(), visite.end(), make_pair(c, s)) == visite.end())
		{
			//on ajoute l'arc a la liste des arcs visites
			visite.push_back(make_pair(c, s));
			//std::vector<Couche*>::iterator a;
			bool test = true;
			//verifie si tous les antecedents ont ete visites
			for (auto a : getListNoeudAnt(positionNoeud(s)))
			{
				if (std::find(visite.begin(), visite.end(), make_pair(a, s)) == visite.end())
				{
					test = false;
					cout << "FAUX" << endl;
					break;
				}
				cout << "Tous les antécédents visités ? " << test << endl;
			}
			// si tous les antecedents ont ete visites
			if (test)
			{
				//visite.push_back(s);
				// si le noeud n'est pas une couche finale
				if (std::find(couche_finale.begin(), couche_finale.end(), s) == couche_finale.end())
				{
					cout << "Pas couche finale et passe " << endl;

					int i = 0;
					while ((i < l.size()) && (l[i].first != s))
						i++;
					// si le noeud est deja en attente dans la liste
					if (l.begin() + i != l.end())
					{
						//on concatene et on propoage
						t->lineariser();
						*t = t->concatener(*(l[i].second));
						cout << "Prop dans " << s->getNom() << " " << t->getTaille() << endl;

						propagationS(s, s->propagation(t));
						// on supprime de la liste
						l.erase(l.begin() + i);
					}
					// le noeud n'est pas dans la liste
					else
					{
						//on propage car tous les arcs antecedents ont ete visites
						cout << "Propag dans " << s->getNom() << " " << t->getTaille() << endl;
						propagationS(s, s->propagation(t));
					}
				}
				// si le noeud est une couche finale
				else
				{
					// on cherche le noeud dans la liste
					int i = 0;
					while ((i < l.size()) && (l[i].first != s))
						i++;
					// si le noeud n'est pas dans la liste on le rajoute
					if (i == l.size())
					{
						//t->lineariser();
						l.push_back(make_pair(s, t));
					}
					// sinon on linearise et concatene dans la liste
					else
					{
						//display(*t);
						t->lineariser();
						l[i].second->lineariser();
						*(l[i].second) = l[i].second->concatener(*t);
					}
				}
			}
			// si des arcs antecedents n'ont pas ete visite
			else
			{
				// on cherche le noeud dans la liste
				int i = 0;
				while ((i < l.size()) && (l[i].first != s))
					i++;
				// si le noeud n'est pas dans la liste on le rajoute
				if (i == l.size())
				{
					//display(*t);
					t->lineariser();
					// display(*t);
					l.push_back(make_pair(s, t));
				}
				// sinon on linearise et concatene dans la liste
				else
				{
					//display(*t);
					t->lineariser();
					l[i].second->lineariser();
					*(l[i].second) = l[i].second->concatener(*t);
				}
			}
		}
	}
}

Tenseur *ReseauNeurones::derivee(Tenseur *t)
{
	return t;
}

void ReseauNeurones::ajouterCoucheInitiale(Couche *c)
{
	// Graphe<Couche *>::ajouterNoeud(c);
	couche_initiale.push_back(c);
}

void ReseauNeurones::ajouterCoucheFinale(Couche *c)
{
	// Graphe<Couche *>::ajouterNoeud(c);
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
	miseAJourDims(noeud_init, noeud_final, true);
	/* std::vector<Couche *> ant = getListNoeudAnt(positionNoeud(noeud_final));
	if (ant.empty())
	{
		noeud_final->setDimInput(noeud_init->getDimOutput());
	}
	else
	{
		int new_dim = noeud_init->getDimOutput().getTaille() + noeud_final->getDimInput().getTaille();
		noeud_final->setDimInput(DimTenseur(std::vector<int>{new_dim}));
	} */
}

void ReseauNeurones::supprimerArc(Couche *noeud_init, Couche *noeud_final)
{
	miseAJourDims(noeud_init, noeud_final, false);

	Graphe<Couche *>::supprimerArc(noeud_init, noeud_final);

	/* std::vector<Couche *> ant = getListNoeudAnt(positionNoeud(noeud_final));
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
	} */
}

void ReseauNeurones::sauvegarderReseau(ReseauNeurones reseau)
{
}

std::vector<Couche *> ReseauNeurones::getCouchesInitiales()
{
	return couche_initiale;
}

std::vector<Couche *> ReseauNeurones::getCouchesFinales()
{
	return couche_finale;
}

void ReseauNeurones::display()
{
	for (int i = 0; i < getListAdj().size(); i++)
	{
		cout << "Couche : " << getListAdj()[i].first->getNom() << " dim entree : " << getListAdj()[i].first->getDimInput().getTaille() << " dim sortie : " << getListAdj()[i].first->getDimOutput().getTaille() << endl;
	}
}
