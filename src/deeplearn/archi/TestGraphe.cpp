#include "TestGraphe.hpp"
#include "Graphe.hpp"
#include <algorithm> // pour pouvoir utiliser find

void TestGraphe :: testAjouterNoeud(){
	Graphe<int> g1;
	g1.ajouterNoeud(3);
	CPPUNIT_ASSERT (g1.getNoeudAdj(0) == 3 && g1.getNoeudAnt(0) == 3);
}

void TestGraphe :: testAjouterArc(){
	Graphe<int> g1;
	g1.ajouterNoeud(3);
	g1.ajouterNoeud(2);
	g1.ajouterArc(2,3);
	CPPUNIT_ASSERT (g1.getListNoeudAdj(0)[0] == 2 && g1.getListNoeudAdj(1)[0] == 3 && g1.getListNoeudAnt(0)[0] == 2);
}

void TestGraphe :: testSupprimerNoeud(){
	int n[3] = {2,3,4}; 
	Graphe<int> g1 (n);
	g1.ajouterArc(2,3);
	g1.ajouterArc(3,4);
	g1.ajouterArc(4,2);
	g1.supprimerNoeud(2);
	
	// Vérification que le noeud 2 n'est plus dans le premier élément de list_adj
	bool noeudPresent = false;
	unsigned int i=0;
	while (i<g1.getListAdj().size() && noeudPresent == false) {
		if (g1.getNoeudAdj(i) == 2){
			noeudPresent = true;
		}
		i++;
	}
	CPPUNIT_ASSERT (!noeudPresent);
	// Vérification que le noeud 2 n'est plus dans le premier élément de list_ant
	noeudPresent = false;
	i=0;
	while (i<g1.getListAnt().size() && noeudPresent == false) {
		if (g1.getNoeudAnt(i) == 2){
			noeudPresent = true;
		}
		i++;
	}
	CPPUNIT_ASSERT (!noeudPresent);
	
	// Vérification que le noeud 2 n'est plus dans les listes de noeuds de list_adj
	noeudPresent = false;
	i=0;
	std::vector<int> v1;
	while (i<g1.getListAdj().size() && noeudPresent == false) {
		v1 = g1.getListNoeudAdj(i);
		if (std::find(v1.begin(), v1.end(), 2) != v1.end()){
			noeudPresent = true;
		}
		i++;
	}
	CPPUNIT_ASSERT (!noeudPresent);
	// Vérification que le noeud 2 n'est plus dans les listes de noeuds de list_ant
	noeudPresent = false;
	i=0;
	while (i<g1.getListAnt().size() && noeudPresent == false) {
		v1 = g1.getListNoeudAnt(i);
		if (std::find(v1.begin(), v1.end(), 2) != v1.end()){
			noeudPresent = true;
		}
		i++;
	}
	CPPUNIT_ASSERT (!noeudPresent);
}

void TestGraphe :: testSupprimerArc(){
	int n[3] = {2,3,4}; 
	Graphe<int> g1 (n);
	g1.ajouterArc(2,3);
	g1.ajouterArc(2,4);
	g1.supprimerArc(2,3);
	
	// Vérification que le noeud 2 n'est plus un antécédent de 3
	bool noeudPresent = false;
	unsigned int i=0;
	std::vector<int> v1;
	while (i<g1.getListAnt().size() && noeudPresent == false) {
		if (g1.getNoeudAnt(i) == 3){
			v1 = g1.getListNoeudAnt(i);
			if (std::find(v1.begin(), v1.end(), 2) != v1.end()){
				noeudPresent = true;
			}
		}
		i++;
	}
	CPPUNIT_ASSERT (!noeudPresent);
	
	// Vérification que le noeud 2 n'est plus un adjacent de 3
	noeudPresent = false;
	i=0;
	while (i<g1.getListAdj().size() && noeudPresent == false) {
		if (g1.getNoeudAdj(i) == 3){
			v1 = g1.getListNoeudAdj(i);
			if (std::find(v1.begin(), v1.end(), 2) != v1.end()){
				noeudPresent = true;
			}
		}
		i++;
	}
	CPPUNIT_ASSERT (!noeudPresent);  
	
	// Vérification que le noeud 3 n'est plus un adjacent de 2
	noeudPresent = false;
	i=0;
	while (i<g1.getListAdj().size() && noeudPresent == false) {
		if (g1.getNoeudAdj(i) == 2){
			v1 = g1.getListNoeudAdj(i);
			if (std::find(v1.begin(), v1.end(), 3) != v1.end()){
				noeudPresent = true;
			}
		}
		i++;
	}
	CPPUNIT_ASSERT (!noeudPresent);
}

void TestGraphe :: testContientCycle(){
	int n[3] = {2,3,4}; 
	Graphe<int> g1 (n);
	g1.ajouterArc(2,3);
	g1.ajouterArc(3,4);
	g1.ajouterArc(4,2);
	Graphe<int> g2 (n);
	g2.ajouterArc(2,3);
	g2.ajouterArc(3,4);
	CPPUNIT_ASSERT (g1.contientCycle());
	CPPUNIT_ASSERT (!g2.contientCycle());
}

void TestGraphe :: testEstConnexe(){
	int n[3] = {2,3,4}; 
	Graphe<int> g1 (n);
	g1.ajouterArc(2,3);
	g1.ajouterArc(3,4);
	Graphe<int> g2 (n);
	g2.ajouterArc(2,3);
	CPPUNIT_ASSERT (g1.estConnexe());
	CPPUNIT_ASSERT (!g2.estConnexe());
}

