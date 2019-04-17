#include "TestGraphe.hpp"

using namespace CppUnit;

class TestGraphe : public CppUnit::TestFixture{

    void setUp(){
	g1 = new Graphe();
	g2 = new Graphe();
    };

    void tearDown(){
      	delete g1;
        delete g2;
    };

    void testAjouterNoeud(){
        g1.ajouterNoeud(3);
        CPPUNIT_ASSERT (g1.list_adj[0].first == 3 && g1.list_ant[0].first == 3);
    };

    void testAjouterArc(){
        g1.ajouterNoeud(3);
        g1.ajouterNoeud(2);
        g1.ajouterArc(2,3);
        CPPUNIT_ASSERT (g1.list_adj[0].second[0] == 2 && g1.list_adj[1].second[0] == 3 && g1.list_ant[0].second[0] == 2);
    };

    void testSupprimerNoeud(){
        g1.ajouterNoeud({2,3,4});
        g1.ajouterArc(2,3);
        g1.ajouterArc(4,2);
        g1.supprimerNoeud(2);
        CPPUNIT_ASSERT (std::find(g1.list_adj.begin(), g1.list_adj.end(), 2) != g1.list_adj.end() && std::find(g1.list_ant.begin(), g1.list_ant.end(), 2) != g1.list_ant.end());
    };


    void testSupprimerArc(){
        g1.ajouterNoeud({2,3,4});
        g1.ajouterArc(2,3);
        g1.ajouterArc(2,4);
        g1.supprimerArc(2,3);
        CPPUNIT_ASSERT (std::find(g1.list_adj[0].second.begin(), g1.list_adj[0].second.end(), 3) != g1.list_adj[0].second.end() && std::find(g1.list_adj[1].second.begin(), g1.list_adj[1].second.end(), 2) != g1.list_adj[1].second.end() && std::find(g1.list_ant[1].second.begin(), g1.list_ant[1].second.end(), 2) != g1.list_ant[1].second.end());
    };

    void testContientCycle(){
        g1.ajouterNoeud({2,3,4});
        g1.ajouterArc(2,3);
        g1.ajouterArc(3,4);
        g1.ajouterArc(4,2);
        g2.ajouterNoeud({2,3,4});
        g2.ajouterArc(2,3);
        g2.ajouterArc(3,4);
        CPPUNIT_ASSERT (g1.contientCycle());
        CPPUNIT_ASSERT (!g2.contientCycle());
    };

    void testEstConnexe(){
        g1.ajouterNoeud({2,3,4});
        g1.ajouterArc(2,3);
        g1.ajouterArc(3,4);
        g2.ajouterNoeud({2,3,4});
        g2.ajouterArc(2,3);
        CPPUNIT_ASSERT (g1.estConnexe());
        CPPUNIT_ASSERT (!g2.estConnexe());
    };
};
