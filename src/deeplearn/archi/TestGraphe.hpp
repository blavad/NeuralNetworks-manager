#ifndef TESTGRAPHE_HPP__
#define TESTGRAPHE_HPP__

#include <vector>
#include <string>
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include "Graphe.hpp"

/**
 * \class TestGraphe
 * \brief Test des méthodes de la classe Graphe.
 * \author Coralie
 * \version 1.0
 * \date avril 2019
 *
 */
class TestGraphe : public CppUnit::TestFixture {

	public :

		/** \brief Vérifier que le nouveau noeud apparait dans la liste d'adjacence et d'antécédence */
		void testAjouterNoeud();

		/** \brief Vérifier que le noeud de départ apparait dans la liste d'antécédence du noeud d'arrivée */
		void testAjouterArc();

		/** \brief Vérifier que le noeud n'apparait plus dans la liste d'adjacence et d'antécédence */
		void testSupprimerNoeud();

		/** \brief Vérifier que le noeud de départ d'apparaît plus dans la liste d'antécédence du noeud d'arrivée */
		void testSupprimerArc();

		/** \brief Vérifier qu'elle renvoie vrai quand on lui donne un graphe avec cycle faux sinon */
		void testContientCycle();

		/** \brief Vérifier qu'elle renvoie vrai quand on lui donne un graphe connexe faux sinon */
		void testEstConnexe();


};


#endif // TESTGRAPHE_HPP
