#ifndef __GRAPHE_HPP__
#define __GRAPHE_HPP__

#include <vector>
#include <iostream>
#include "exception/NoeudInexistantException.hpp"
#include "exception/ArcDejaExistantException.hpp"
#include "exception/NoeudDejaExistantException.hpp"
#include "exception/ArcInexistantException.hpp"
#include <algorithm> // pour pouvoir utiliser find

/**
 * \class Graphe
 * \tparam Type Type de noeud du graphe.
 * \brief Gestion de graphes génériques.
 * \author David, Coralie
 * \version 1.0
 * \date avril 2019
 *
 * Module permettant l'utilisation d'un graphe orienté générique.
 * Les noeuds du graphe portent cette généricité et peuvent donc être de n'importe quel type de données.
 *
 */
template <class Type>
class Graphe {

    protected :
        /** \brief La liste dynamique d'adjacence. */
        std::vector<std::pair<Type, std::vector<Type>>> list_adj;

        /** \brief La liste dynamique d'antécédence. */
        std::vector<std::pair<Type, std::vector<Type>>> list_ant;

    public :

        /**
         * \brief Constructeur de graphe vide.
         */
        Graphe(){
		}

        /**
         * \brief Constructeur de graphe à partir de noeuds isolés.
         * \params noeuds Ensembles de noeuds initiaux
         */
        Graphe(std::vector<Type> noeuds){
			for (unsigned int i=0; i<noeuds.size(); i++){
			   try {
				   ajouterNoeud(noeuds[(int)i]);
			   }
			   catch (NoeudDejaExistantException &e){
				   std::cerr << "An array exception occurred (" << e.messageErreur() << ")\n";
			   }
			};
		}
        
        /**
         * \brief Récupère list_adj
         */
        std::vector<std::pair<Type, std::vector<Type>>> getListAdj(){
			return (list_adj);
		}
        
        /**
         * \brief Récupère list_ant
         */
        std::vector<std::pair<Type, std::vector<Type>>> getListAnt(){
			return (list_ant);
		}    
        
        /**
         * \brief Récupère la kième paire de list_adj
         */
        std::pair<Type, std::vector<Type>> getPairAdj(int k){
			return (list_adj[k]);
		}
        
        /**
         * \brief Récupère la kième paire de list_ant
         */
        std::pair<Type, std::vector<Type>> getPairAnt(int k){
			return (list_ant[k]);
		}
        
        /**
         * \brief Récupère le premier élément de la kième paire de list_adj
         */
        Type getNoeudAdj(int k){
			return (list_adj[k].first);
		}
        
        /**
         * \brief Récupère le premier élément de la kième paire de list_ant
         */
        Type getNoeudAnt(int k){
			return (list_ant[k].first);
		}
        
        /**
         * \brief Récupère le deuxième élément de la kième paire de list_adj
         */
        std::vector<Type> getListNoeudAdj(int k){
			return (list_adj[k].second);
		}
        
        /**
         * \brief Récupère le deuxième élément de la kième paire de list_ant
         */
        std::vector<Type> getListNoeudAnt(int k){
			return (list_ant[k].second);
		}

        /**
         * \fn void ajouterNoeud(Type noeud)
         * \brief Ajout d'un noeud.
         * \param noeud un noeud du graphe.
         */
        void ajouterNoeud(Type noeud) {
			unsigned int i=0;
			bool trouve = false;
			while (i<list_adj.size() && trouve == false){
				if (getNoeudAdj((int)i) == noeud){
					trouve = true;
				}
				i++;
			}
			if (trouve == true){
				throw NoeudDejaExistantException ("Le noeud existe déjà");
			}
			else {
				std::vector<Type> vect{};
				std::pair<Type, std::vector<Type>> p (noeud,vect);
				list_adj.push_back(p);
				list_ant.push_back(p);
			}
			
		}

         /**
         * \fn void ajouterArc(Type noeud_init,Type noeud_final)
         * \brief Ajout d'un arc.
         * \param noeud_init le noeud de départ de l'arc.
         * \param noeud_final le noeud d'arrivé de l'arc.
         */
        void ajouterArc(Type noeud_init,Type noeud_final){
			bool trouveNI = false;
			bool trouveNF = false;
			unsigned int i=0;
					
			while (i<list_adj.size() && (trouveNF == false || trouveNI == false)){
				if (getNoeudAdj(i)==noeud_init){
					std::vector<Type> v1 = getListNoeudAdj(i);
					if (std::find(v1.begin(), v1.end(), noeud_final) != v1.end()){
						throw ArcDejaExistantException("L'arc entre ces 2 noeuds existe déjà");
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
				throw NoeudInexistantException("Au moins un des noeuds n'existe pas");
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

        /**
         * \fn void supprimerNoeud(Type noeud)
         * \brief Suppression d'un noeud.
         * \param noeud un noeud du graphe.
         */
        void supprimerNoeud(Type noeud){
			unsigned int i = 0;
			unsigned int j = 0;
			bool trouveG = false;
			bool trouveP = false;
		
			while (i<list_adj.size()){
				if (getNoeudAdj(i)==noeud){
					getListAdj().erase(getListAdj().begin + i);
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
			if (trouveG == false){
				throw NoeudInexistantException("Le noeud n'existe pas");
				std::exit(-1);
			}
			else {
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

        /**
         * \fn void supprimerArc(Type noeud_init,Type noeud_final)
         * \brief Suppression d'un arc.
         * \param noeud_init le noeud de départ de l'arc.
         * \param noeud_final le noeud d'arrivé de l'arc.
         */
        void supprimerArc(Type noeud_init,Type noeud_final){
			unsigned int i = 0;
			unsigned int j = 0;
			bool trouveF = false;
			bool trouveI = false;
			
			while (i<list_ant.size() && trouveF == false){
				if (getNoeudAnt(i)==noeud_final){
					trouveF = true;
					while (j<getListNoeudAnt(i).size() && trouveI == false){
						if (getListNoeudAnt(i)[j] == noeud_init){
							getListNoeudAnt(i).erase(j);
							trouveI = true;
						}
						j++;
					}
				};
				i++;
			};
			if (trouveF == false || trouveI == false){
				throw ArcInexistantException("L'arc n'existe pas");
			}
			else {
				i = 0;
				trouveF = false;
				trouveI = false;
				while (i<list_adj.size() && (trouveF == false || trouveI == false)){
					if (getNoeudAdj(i)==noeud_init){
						trouveI = true;
						j = 0;
						bool stop1 = false;
						while (j<getListNoeudAdj(i).size() && stop1 == false){
							if (getListNoeudAdj(i)[j] == noeud_final){
								getListNoeudAdj(i).erase(j);
								stop1 = true;
							}
							j++;
						};
					};
					
					if (getNoeudAdj(i)==noeud_final){
						trouveF = true;
						j = 0;
						bool stop2 = false;
						while (j<getListNoeudAdj(i).size() && stop2 == false){
							if (getListNoeudAdj(i)[j] == noeud_init){
								getListNoeudAdj(i).erase(j);
								stop2 = true;
							}
							j++;
						};
					}
				};
			}; 
		}

        /**
         * \fn bool contientCycle()
         * \brief Teste si le graphe contient un cycle.
         * \return un booléen.
         */
        bool contientCycle(){
			bool cycle = false;
			return (cycle);
		}

        /**
         * \fn bool estConnexe()
         * \brief Teste si le graphe est connexe.
         * \return un booléen.
         */
        bool estConnexe(){
			bool connexe = true;
			unsigned int i = 0;
			while (i<list_adj.size() && connexe == true){
				if (getListNoeudAdj(i).size()==0){
					connexe = false;
				};
				i++;
			};
			return(connexe);
		}
};

#endif
