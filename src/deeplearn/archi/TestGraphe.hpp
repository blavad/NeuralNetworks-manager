#include <vector>
#include <cppunit/TestFixture.h>
#include "Graphe.hpp"

#ifndef TESTGRAPHE_HPP
#define TESTGRAPHE_HPP

/**
 * \class TestGraphe
 * \brief Test des méthodes de la classe Graphe.
 * \author Coralie
 * \version 1.0
 * \date avril 2019
 *
 */

using namespace CppUnit;

class TestGraphe : public CppUnit::TextFixture {

private :

	Graphe g1, g2;

public:

    // Initialiser les variables
    void setUp();

    // Supprime les variables
    void tearDown();

    // Vérifier que le nouveau noeud apparait dans la liste d'adjacence et d'antécédence
    void testAjouterNoeud();

    // Vérifier que le noeud de départ apparait dans la liste d'antécédence du noeud d'arrivée
    void testAjouterArc();

    // Vérifier que le noeud n'apparait plus dans la liste d'adjacence et d'antécédence
    void testSupprimerNoeud();

    // Vérifier que le noeud de départ d'apparaît plus dans la liste d'antécédence du noeud d'arrivée
    void testSupprimerArc();

    // Vérifier qu'elle renvoie vrai quand on lui donne un graphe avec cycle faux sinon
    void testContientCycle();

    // Vérifier qu'elle renvoie vrai quand on lui donne un graphe connexe faux sinon
    void testEstConnexe();


};


#endif // TESTGRAPHE_HPP
