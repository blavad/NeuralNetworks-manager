#ifndef __GRAPHE_HPP__
#define __GRAPHE_HPP__

#include <vector>
#include <iostream>
#include "exception/NoeudInexistantException.hpp"
#include "exception/ArcDejaExistantException.hpp"
#include "exception/NoeudDejaExistantException.hpp"
#include "exception/ArcInexistantException.hpp"
#include "exception/BoucleException.hpp"
#include "exception/NonConnexeException.hpp"
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

    public :
        /** \brief La liste dynamique d'adjacence. */
        std::vector<std::pair<Type, std::vector<Type>>> list_adj;

        /** \brief La liste dynamique d'antécédence. */
        std::vector<std::pair<Type, std::vector<Type>>> list_ant;
        
        /** \brief La liste dynamique de successeurs */
        std::vector<std::pair<Type, std::vector<Type>>> list_succ;

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
				   std::cerr << "Une exception a été soulevée : " << e.messageErreur() << "\n";
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
         * \brief Récupère list_succ
         */
        std::vector<std::pair<Type, std::vector<Type>>> getListSucc(){
			return (list_succ);
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
         * \brief Récupère la kième paire de list_succ
         */
        std::pair<Type, std::vector<Type>> getPairSucc(int k){
			return (list_succ[k]);
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
         * \brief Récupère le premier élément de la kième paire de list_succ
         */
        Type getNoeudSucc(int k){
			return (list_succ[k].first);
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
         * \brief Récupère le deuxième élément de la kième paire de list_succ
         */
        std::vector<Type> getListNoeudSucc(int k){
			return (list_succ[k].second);
		}
		
		/**
		 * \fn bool presenceGrapheNoeud (Type noeud)
		 * \brief Renvoie vrai si le noeud appartient au graphe
		 * faux sinon
		 * \param noeud un noeud du graphe.
		 */
		bool presenceGrapheNoeud (Type noeud){
			bool present = false;
			unsigned int i = 0; 
			while (i<list_adj.size() && present == false){
				if (getNoeudAdj(i) == noeud){
					present = true;
				};
				i++;
			};
			return(present);
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
				list_succ.push_back(p);
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
			
			if (noeud_init == noeud_final){
				throw BoucleException("Boucle d'un noeud sur lui-même");
			}
			else{
				if (presenceGrapheNoeud(noeud_init) && presenceGrapheNoeud(noeud_final)){
					while (i<list_adj.size() && (trouveNF == false || trouveNI == false)){
						if (getNoeudAdj(i)==noeud_init){
							std::vector<Type> v1 = getListNoeudAdj(i);
							if (std::find(v1.begin(), v1.end(), noeud_final) != v1.end()){
								throw ArcDejaExistantException("L'arc entre ces 2 noeuds existe déjà");
								std::exit(-1);
							}
							else {
								list_adj[i].second.push_back(noeud_final);
								list_succ[i].second.push_back(noeud_final);
								trouveNI = true;
							}
						}
						if (getNoeudAdj(i)==noeud_final){
							list_adj[i].second.push_back(noeud_init);
							trouveNF = true;
						}
						i++;
					}
					
					trouveNF = false;
					i = 0;
					while (i<list_ant.size() && trouveNF == false){
						if (getNoeudAnt(i)==noeud_final){
							list_ant[i].second.push_back(noeud_init);
							trouveNF = true;
						}
						i++;
					}
					
				}
				else{
					throw NoeudInexistantException("Au moins un des noeuds n'existe pas");
				}
			}
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
					list_adj.erase(list_adj.begin()+(int)i);
					trouveG = true;
				};
				while (j<getListNoeudAdj(i).size() && trouveP == false){
					if (getListNoeudAdj(i)[j]==noeud){
						list_adj[i].second.erase(list_adj[i].second.begin()+(int)j);
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
						list_ant.erase(list_ant.begin() + (int)i);
						list_succ.erase(list_succ.begin() + (int)i);
					};
					while (j<getListNoeudAnt(i).size() && trouveP == false){
						if (getListNoeudAnt(i)[j]==noeud){
							list_ant[i].second.erase(list_ant[i].second.begin()+(int)j);
							trouveP = true;
						};
						j++;
					};
					j = 0;
					trouveP = false;
					while (j<getListNoeudSucc(i).size() && trouveP == false){
						if (getListNoeudSucc(i)[j]==noeud){
							list_succ[i].second.erase(list_succ[i].second.begin()+(int)j);
							trouveP = true;
						};
						j++;
					}
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

			while (i<list_ant.size() && !trouveF){
				if (getNoeudAnt(i)==noeud_final){
					trouveF = true;
					while (j<getListNoeudAnt(i).size() && !trouveI){
						if (getListNoeudAnt(i)[j] == noeud_init){
							list_ant[i].second.erase(list_ant[i].second.begin()+j);
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
								list_adj[i].second.erase(list_adj[i].second.begin()+ (int)j);
								stop1 = true;
							}
							j++;
						};
						j = 0;
						stop1 = false;
						while (j<getListNoeudSucc(i).size() && stop1 == false){
							if (getListNoeudSucc(i)[j] == noeud_final){
								list_succ[i].second.erase(list_succ[i].second.begin()+ (int)j);
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
								list_adj[i].second.erase(list_adj[i].second.begin()+(int)j);
								stop2 = true;
							}
							j++;
						};
					};
					i++;
				};
			};
		}
		
		/**
		 * \fn int positionNoeud (Type noeud)
		 * \brief Retourne la position du noeud dans la list_adj
		 * \return un entier
		 */ 
		 
		 int positionNoeud (Type noeud){
			 unsigned int i = 0;
			 while (i<list_adj.size() && getNoeudAdj(i)!=noeud){
				 i++;
			 };		 
			 if (i==list_adj.size()){
				 throw NoeudInexistantException("Le noeud n'existe pas");
			 }
			 else {
				 return (i);
			 }
		 }

        /**
         * \fn bool contientCycle()
         * \brief Teste si le graphe contient un cycle.
         * \return un booléen.
         */
        bool contientCycle(){
			if (estConnexe()==false){
				throw NonConnexeException("Le graphe n'est pas connexe.");
			}
			else {
				bool cycle = false;
				unsigned int k;
				unsigned int l;
				unsigned int i = 0;
				int pos = 0;
				std::vector<Type> v1 = {};
				int tIntv1;
				std::vector<Type> vNoeudsNonCycle = {};
				
				// Initialisation vecteur cycle
				while (getListNoeudAnt(i).size()==0 && i<getListAnt().size()){
					i++;
				};
				v1.push_back(getNoeudAnt(i));
				for (k=0; k<getListNoeudAnt(i).size();k++){
					v1.push_back(getListNoeudAnt(i)[k]);
				}
				l=1;
				tIntv1 = v1.size();
				while (cycle == false && vNoeudsNonCycle.size()<getListAnt().size()){
					pos = positionNoeud(v1[l]);
					for (k=0; k<getListNoeudAnt(pos).size();k++){
						bool presentV1 = std::find(v1.begin(), v1.end(), getListNoeudAnt(pos)[k]) != v1.end();
						bool presentVNoeudsNonCycle = std::find(vNoeudsNonCycle.begin(), vNoeudsNonCycle.end(), getListNoeudAnt(pos)[k]) != vNoeudsNonCycle.end();
						if (!(presentV1)){
							if (!(presentVNoeudsNonCycle)){
								v1.push_back(getListNoeudAnt(pos)[k]);
							};
						}
						else {
							if (l >= tIntv1){
								cycle = true;
							}
						};
					};
					l++;
					// Si ts les noeuds n'ont pas été parcourus
					if (l == v1.size()){
						for (k=0; k<v1.size(); k++){
							bool presentVNoeudsNonCycle = std::find(vNoeudsNonCycle.begin(), vNoeudsNonCycle.end(), v1[k]) != vNoeudsNonCycle.end();
							if (!presentVNoeudsNonCycle){
								vNoeudsNonCycle.push_back(v1[k]);
							};
						};
						v1.clear();
						bool present = (std::find(vNoeudsNonCycle.begin(), vNoeudsNonCycle.end(), getNoeudAnt(i)) != vNoeudsNonCycle.end());
						while ((present == true || getListNoeudAnt(i).size()==0) && i<getListAnt().size()){
							i++;
							if (i<list_ant.size()){
								present = (std::find(vNoeudsNonCycle.begin(), vNoeudsNonCycle.end(), getNoeudAnt(i)) != vNoeudsNonCycle.end());
							};
						};
						if (i<list_ant.size()){
							v1.push_back(getNoeudAnt(i));
							for (k=0; k<getListNoeudAnt(i).size();k++){
								v1.push_back(getListNoeudAnt(i)[k]);
							}
							l=1;
							tIntv1 = v1.size();
						};
					}
				};			
				return (cycle);
			};
		}

        /**
         * \fn bool estConnexe()
         * \brief Teste si le graphe est connexe.
         * \return un booléen.
         */
        bool estConnexe(){
			bool connexe = false;
			unsigned int k;
			std::vector<Type> v1 = {};
			
			if (getListNoeudAdj(0).size()!=0) {
				v1.push_back(getNoeudAdj(0));
				for (k=0; k<getListNoeudAdj(0).size();k++){
					v1.push_back(getListNoeudAdj(0)[k]);
				}
				unsigned int i = 1;
				while (i<v1.size() && connexe == false){
					if (v1.size() == list_adj.size()){
						connexe = true;
					}
					else {
						for (k=0; k<getListNoeudAdj(i).size();k++){
							if (!(std::find(v1.begin(), v1.end(), getListNoeudAdj(i)[k]) != v1.end())){
								v1.push_back(getListNoeudAdj(i)[k]);
							}
						}
					}
					i++;
				};
			}
			return(connexe);
		}

};

#endif
