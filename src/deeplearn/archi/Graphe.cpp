#include "Graphe.hpp"
#include "NoeudInexistantException.hpp"
#include "ArcDejaExistantException.hpp"
#include "NoeudDejaExistantException.hpp"
#include <algorithm> // pour pouvoir utiliser find

template <class Type> Graphe <Type> :: Graphe(){
}

template <class Type> Graphe <Type> :: Graphe(Type* noeuds){
    for (int i=0; i<noeuds.size(); i++){
       ajouterNoeud(noeuds[i]);
    };
}

template <class Type> std::vector<std::pair<Type, std::vector<Type> > > Graphe <Type> :: getListAdj(){
    return (list_adj);
}

template <class Type> std::vector<std::pair<Type, std::vector<Type> >  > Graphe <Type> :: getListAnt(){
    return (list_ant);
}

template <class Type> std::pair<Type, std::vector<Type> > Graphe <Type> :: getPairAdj(int k){
    return (list_adj.get(k));
}

template <class Type> std::pair<Type, std::vector<Type> > Graphe <Type> :: getPairAnt(int k){
    return (list_ant.get(k));
}

template <class Type> Type Graphe <Type> :: getNoeudAdj(int k){
    return (list_adj.get(k).first);
}

template <class Type> Type Graphe <Type> :: getNoeudAnt(int k){
    return (list_ant.get(k).first);
}

template <class Type> std::vector<Type> Graphe <Type> :: getListNoeudAdj(int k){
    return (list_adj.get(k).second);
}

template <class Type> std::vector<Type> Graphe <Type> :: getListNoeudAnt(int k){
    return (list_ant.get(k).second);
}

template <class Type> void Graphe <Type> :: ajouterNoeud(Type noeud){
	int i=0;
	bool trouve = false;
	try {
		while (i<list_adj.size() && trouve == false){
			if (getNoeudAdj(i) == noeud){
				trouve = true;
			}
			i++;
		}
		if (trouve == true){
			throw NoeudDejaExistantException();
		}
		else {
			list_adj.first.push_back(noeud);
			list_ant.first.push_back(noeud);
		}
	}
	catch (NoeudDejaExistantException e){
		e.messageErreur();
	}
}


template <class Type> void Graphe <Type> :: ajouterArc(Type noeud_init,Type noeud_final){
    bool trouveNI = false;
    bool trouveNF = false;
    int i=0;
    try {		
		while (i<list_adj.size() && (trouveNF == false || trouveNI == false)){
			if (getNoeudAdj(i)==noeud_init){
				std::vector<Type> v1 = getListNoeudAdj(i);
				if (std::find(v1.begin(), v1.end(), noeud_final) != v1.end()){
					throw ArcDejaExistantException();
					std::exit(-1);
				}
				else {		
					getListNoeudAdj(i).push_back(noeud_final);
					trouveNI = true;
				}
			};
			if (getNoeudAdj(i)==noeud_final){
				getListNoeudAdj(i).push_back(noeud_init);
				trouveNF = true;
			};
			i++;
		};
		if (trouveNI==false || trouveNF==false) {
			throw NoeudInexistantException();
		}
		else {
			trouveNF = false;
			i = 0;
			while (i<list_ant.size() && trouveNF == false){
				if (getNoeudAnt(i)==noeud_final){
					getListNoeudAnt(i).push_back(noeud_init);
					trouveNF = true;
				};
				i++;
			};
		};
	}
	catch (NoeudInexistantException e1) {
		e1.messageErreur();
	}
	catch (ArcDejaExistantException e2) {
		e2.messageErreur();
	}  
}

template <class Type> void Graphe <Type> :: supprimerNoeud(Type noeud){
    int i = 0;
    int j = 0;
    bool trouveG = false;
    bool trouveP = false;
    while (i<list_adj.size()){
        if (getNoeudAdj(i)==noeud){
            getListAdj().erase(i);
            trouveG = true;
        };
        while (j<getListNoeudAdj(i).size() && trouveP == false){
            if (getListNoeudAdj(i)[j]==noeud){
                getListNoeudAdj(i).erase(j);
                trouveG = true;
                trouveP = true;
            };
            j++;
        };
        j = 0;
        trouveP = false;
        i++;
    };
    if (trouveG == true){
        i = 0;
        j = 0;
        trouveP = false;
        while (i<list_ant.size()){
            if (getNoeudAnt(i)==noeud){
                getListAnt().erase(i);
            };
            while (j<getListNoeudAnt(i).size() && trouveP == false){
                if (getListNoeudAnt(i)[j]==noeud){
                    getListNoeudAnt(i).erase(j);
                    trouveP = true;
                };
                j++;
            };
            j = 0;
            trouveP = false;
            i++;
        };
    };
}

template <class Type> void Graphe <Type> :: supprimerArc(Type noeud_init,Type noeud_final){
}

template <class Type> bool Graphe <Type> :: contientCycle(){
    bool cycle = false;
    return (cycle);
}

template <class Type> bool Graphe <Type> :: estConnexe(){
    bool connexe = true;
    int i = 0;
    while (i<list_adj.size() && connexe == true){
        if (getListNoeudAdj(i).size()==0){
            connexe = false;
        };
        i++;
    };
    return(connexe);
}

