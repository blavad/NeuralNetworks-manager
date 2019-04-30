#include "Graphe.hpp"
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
    list_adj.first.push_back(noeud);
    list_ant.first.push_back(noeud);
}

// /!\ Vérif arc existe pas déjà !!!!!!!!!
template <class Type> void Graphe <Type> :: ajouterArc(Type noeud_init,Type noeud_final){
    bool trouveNI = false;
    bool trouveNF = false;
    int i=0;
    while (i<list_adj.size() && (trouveNF == false || trouveNI == false)){
        if (getNoeudAdj(i)==noeud_init){
            getListNoeudAdj(i).push_back(noeud_final);
            trouveNI = true;
        };
        if (getNoeudAdj(i)==noeud_final){
            getListNoeudAdj(i).push_back(noeud_init);
            trouveNF = true;
        };
        i++;
    };
    if (trouveNI==false) {
        ajouterNoeud(noeud_init);
        getListNoeudAdj.second.push_back(noeud_final);
    };
    if (trouveNF==false) {
        ajouterNoeud(noeud_final);
        getListNoeudAdj.second.push_back(noeud_init);
    };
    trouveNF = false;
    i = 0;
    while (i<list_ant.size() && trouveNF == false){
        if (getNoeudAnt(i)==noeud_final){
            getListNoeudAnt(i).push_back(noeud_init);
            trouveNF = true;
        };
        i++;
    };
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

