#include "ReseauNeurones.hpp"
#include "DimTenseur.hpp"
#include "exception/CycleException.hpp"
#include "Couche.hpp"
#include "CoucheCombinaison.hpp"
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

bool ReseauNeurones::tousArcsAntVisites(Couche *s)
{
	//verifie si tous les antecedents ont ete visites
	for (Couche *c : getListNoeudAnt(positionNoeud(s)))
	{
		if (std::find(visite.begin(), visite.end(), make_pair(c, s)) == visite.end())
		{
			return false;
		}
	}
	return true;
}

DimTenseur getSumDimOutput(vector<Couche *> c)
{
	DimTenseur sum;
	for (Couche *couche : c)
	{
		sum = sum + couche->getDimOutput();
	}
	return sum;
}

void ReseauNeurones::miseAJourDims()
{
	visite.clear();
	for (pair<Couche *, vector<Couche *>> c : getListSucc())
	{
		Couche *tmp = c.first;
		if (getListNoeudAnt(positionNoeud(tmp)).size() == 0)
		{
			if (isInitiale(tmp))
			{
				tmp->setDimInput(getDimInput());
			}
			else
			{
				tmp->setDimInput(DimTenseur());
			}
			tmp->upDateDimOutput();
			miseAJourDims(tmp);
		}
	}
	upDateDimOutput();
}

void ReseauNeurones::miseAJourDims(Couche *cIn, Couche *cOut)
{
	if (std::find(visite.begin(), visite.end(), make_pair(cIn, cOut)) == visite.end())
	{
		//on ajoute l'arc a la liste des arcs visites
		visite.push_back(make_pair(cIn, cOut));
		// si tous les antecedents ont ete visites
		if (tousArcsAntVisites(cOut))
		{
			// On somme toutes les dimensions de tenseur qui arrivent
			cOut->setDimInput(getSumDimOutput(getListNoeudAnt(positionNoeud(cOut))));
			cOut->upDateDimOutput();
			miseAJourDims(cOut);
		}
	}
}

void ReseauNeurones::miseAJourDims(Couche *c)
{
	for (Couche *cSucc : getListNoeudSucc(positionNoeud(c)))
	{
		miseAJourDims(c, cSucc);
	}
}

void ReseauNeurones::upDateDimOutput()
{
	setDimOutput(getSumDimOutput(couche_finale));
}

/* void ReseauNeurones ::miseAJourDims(Couche *cIn, Couche *cOut, bool signe)
{
	if ((signe) && (std::find(couche_finale.begin(), couche_finale.end(), cIn) == couche_finale.end()))
	{
		if (couche_finale.size() > 1)
		{
			int sum2 = 0;
			for (auto f : couche_finale)
			{
				sum2 = sum2 + f->getDimOutput().getTaille();
			}
			this->setDimOutput(vector<int>{sum2});
		}
		else
		{
			this->setDimOutput(couche_finale[0]->getDimOutput());
		}
	}
	else
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
		else
		{
			if (signe)
			{
				if (couche_finale.size() > 1)
				{
					int sum2 = 0;
					for (auto f : couche_finale)
					{
						sum2 = sum2 + f->getDimOutput().getTaille();
					}
					this->setDimOutput(vector<int>{sum2});
				}
				else
				{
					this->setDimOutput(couche_finale[0]->getDimOutput());
				}
			}
		}
	}
}
 */

std::string ReseauNeurones::type()
{
	return "ReseauNeurones";
}

Tenseur &ReseauNeurones::propagation(Tenseur &t)
{
	visite.clear();
	entree = t;
	for (Couche *c : couche_initiale)
	{
		cout << "#> Couche Init : " << c->getNom() <<endl;
		propagation(c,c->propagation(t));
		t = entree;
	} 
	Tenseur *sortie_rn = new Tenseur();
	for (Couche *c : couche_finale)
	{
		Tenseur ent(c->getEntree());
		Tenseur sortie_couche = c->propagation(ent);
		if (couche_finale.size() > 1){
			cout << "#> Couche Finale : " << c->getNom() << endl;	
			*sortie_rn = sortie_rn->concatener(sortie_couche);
		}
		else
			*sortie_rn = sortie_couche;
	}
	return *sortie_rn;
}

void ReseauNeurones::propagation(Couche *cIn, Couche *cOut, Tenseur &t)
{
	//on ajoute l'arc a la liste des arcs visites
	visite.push_back(make_pair(cIn, cOut));
	cout << "#> Visite " << cIn->getNom() << " -- " << cOut->getNom() << endl;
	// si tous les antecedents ont ete visites
	if (tousArcsAntVisites(cOut))
	{
		// On somme toutes les dimensions de tenseur qui arrivent
		cOut->setEntree(cOut->getEntree().concatener(t));
		Tenseur tmp = cOut->getEntree();
		cout << "#> Propage dans " << cOut->getNom() << endl;

		propagation(cOut, cOut->propagation(tmp));
	}
	else
	{
		cOut->setEntree(cOut->getEntree().concatener(t));
	}
}

void ReseauNeurones::propagation(Couche *c, Tenseur &t)
{
	if (!isFinale(c))
	{
		for (Couche *cSucc : getListNoeudSucc(positionNoeud(c)))
		{
			propagation(c, cSucc, t);
		}
	}
}

/* 
Tenseur *ReseauNeurones::propagation(Tenseur *tens)
{
	visite.clear();
	Tenseur *t = new Tenseur();

	if (estConnexe())
	{
		throw NonConnexeException("Le graphe n'est pas connexe");
	}
	else
	{
		for (auto c : couche_initiale)
		{
			//visite.push_back(c);
			*t = *tens;
			cout << "Prop dans " << c->getNom() << " " << t->getDim().toString() << " et " << t->getTaille() << endl;
			cout << t->getValeur(0) << endl;
			t = c->propagation(t);
			propagationS(c, t);
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
	Tenseur *t = new Tenseur();
	for (auto s : getListNoeudSucc(positionNoeud(c)))
	{
		cout << " Noeud suiv " << s->getNom() << endl;
		*t = *sortie;
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
				break;
			}
		}
		cout << " Valeur test : " << test << endl;
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
					t->concatener(*(l[i].second));
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
} */
/* 
void ReseauNeurones::retro(std::vector<Couche *> liste_Couches, Couche *f, Tenseur *t, double alpha)
{
	Tenseur *t2;
	int pos = 0;
	int pos2 = 0;
	for (auto d : liste_Couches)
	{
		pos2 = pos + d->getDimOutput().getTaille();
		*t2 = t->copie(pos, pos2);
		pos = pos2;
		visite.push_back(make_pair(d, f));
		retro(d, t2, alpha);
	}
}

void ReseauNeurones::retro(Couche *d, Tenseur *t, double alpha)
{
	if (d->type() == "Combinaison")
	{
		d->setTmp(d->getTmp().concatener(*t));
		bool test = true;
		for (auto s : getListNoeudSucc(positionNoeud(d)))
			if (std::find(visite.begin(), visite.end(), make_pair(d, s)) == visite.end())
			{
				test = false;
				break;
			}
		if (test)
		{
			((CoucheCombinaison *)d)->update(d->getTmp() * *(d->derivee(&d->getEntree())), alpha); //pblm de multiplication, ecrire multiplication terme a terme
			retro(getListNoeudAnt(positionNoeud(d)), d, &d->getTmp(), alpha);
		}
	}
	else
	{
		d->setTmp(d->getTmp() + *t);
		bool test = true;
		for (auto s : getListNoeudSucc(positionNoeud(d)))
			if (std::find(visite.begin(), visite.end(), make_pair(d, s)) == visite.end())
			{
				test = false;
				break;
			}
		if (test)
		{
			retro(getListNoeudAnt(positionNoeud(d)), d, d->derivee(&(d->getEntree() * d->getTmp())), alpha); //stocker l'entree
		}
	}
}
 */
Tenseur *ReseauNeurones::derivee(Tenseur *t)
{
	return t;
}

void ReseauNeurones::ajouterCoucheInitiale(Couche *c)
{
	couche_initiale.push_back(c);
	miseAJourDims();
}

void ReseauNeurones::ajouterCoucheFinale(Couche *c)
{
	couche_finale.push_back(c);
	upDateDimOutput();
}

void ReseauNeurones::supprimerNoeud(Couche *noeud)
{
	Graphe<Couche *>::supprimerNoeud(noeud);
	miseAJourDims();
}

void ReseauNeurones::supprimerCoucheInitiale(Couche *c)
{
	for (int i = 0; i < couche_initiale.size(); i++)
	{
		if (couche_initiale[i] == c)
		{
			couche_initiale.erase(couche_initiale.begin() + i);
			break;
		}
	}
}

void ReseauNeurones::supprimerCoucheFinale(Couche *c)
{
	for (int i = 0; i < couche_finale.size(); i++)
	{
		if (couche_finale[i] == c)
		{
			couche_finale.erase(couche_finale.begin() + i);
			break;
		}
	}
}

void ReseauNeurones::ajouterArc(Couche *noeud_init, Couche *noeud_final)
{
	Graphe<Couche *>::ajouterArc(noeud_init, noeud_final);
	miseAJourDims();
}

void ReseauNeurones::supprimerArc(Couche *noeud_init, Couche *noeud_final)
{
	Graphe<Couche *>::supprimerArc(noeud_init, noeud_final);
	miseAJourDims();
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

bool ReseauNeurones::isFinale(Couche *c)
{
	for (Couche *c_fin : getCouchesFinales())
	{
		if (c == c_fin)
		{
			return true;
		}
	}
	return false;
}

bool ReseauNeurones::isInitiale(Couche *c)
{
	for (Couche *c_init : getCouchesInitiales())
	{
		if (c == c_init)
		{
			return true;
		}
	}
	return false;
}

void ReseauNeurones::display()
{
	for (int i = 0; i < getListAdj().size(); i++)
	{
		cout << "Couche : " << getListAdj()[i].first->getNom() << " dim entree : " << getListAdj()[i].first->getDimInput().toString() << " dim sortie : " << getListAdj()[i].first->getDimOutput().toString() << endl;
	}
}
