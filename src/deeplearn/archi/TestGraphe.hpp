#include <vector>
#include <cppunit/TestFixture.h>
#include "Graphe.hpp"

#ifndef TESTGRAPHE_HPP
#define TESTGRAPHE_HPP

/**
 * \class TestGraphe
 * \brief Test des m�thodes de la classe Graphe.
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

    // V�rifier que le nouveau noeud apparait dans la liste d'adjacence et d'ant�c�dence
    void testAjouterNoeud();

    // V�rifier que le noeud de d�part apparait dans la liste d'ant�c�dence du noeud d'arriv�e
    void testAjouterArc();

    // V�rifier que le noeud n'apparait plus dans la liste d'adjacence et d'ant�c�dence
    void testSupprimerNoeud();

    // V�rifier que le noeud de d�part d'appara�t plus dans la liste d'ant�c�dence du noeud d'arriv�e
    void testSupprimerArc();

    // V�rifier qu'elle renvoie vrai quand on lui donne un graphe avec cycle faux sinon
    void testContientCycle();

    // V�rifier qu'elle renvoie vrai quand on lui donne un graphe connexe faux sinon
    void testEstConnexe();


};


#endif // TESTGRAPHE_HPP
