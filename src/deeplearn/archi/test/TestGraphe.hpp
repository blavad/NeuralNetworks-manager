#ifndef TESTGRAPHE_HPP__
#define TESTGRAPHE_HPP__

#include <vector>
#include <string>
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include "../Graphe.hpp"

/**
 * \class TestGraphe
 * \brief Test des m�thodes de la classe Graphe.
 * \author Coralie
 * \version 1.0
 * \date avril 2019
 *
 */
class TestGraphe : public CppUnit::TestFixture {

	public :

		/** \brief V�rifier que le nouveau noeud apparait dans la liste d'adjacence et d'ant�c�dence */
		void testAjouterNoeud();

		/** \brief V�rifier que le noeud de d�part apparait dans la liste d'ant�c�dence du noeud d'arriv�e */
		void testAjouterArc();

		/** \brief V�rifier que le noeud n'apparait plus dans la liste d'adjacence et d'ant�c�dence */
		void testSupprimerNoeud();

		/** \brief V�rifier que le noeud de d�part d'appara�t plus dans la liste d'ant�c�dence du noeud d'arriv�e */
		void testSupprimerArc();

		/** \brief V�rifier qu'elle renvoie vrai quand on lui donne un graphe avec cycle faux sinon */
		void testContientCycle();

		/** \brief V�rifier qu'elle renvoie vrai quand on lui donne un graphe connexe faux sinon */
		void testEstConnexe();


};


#endif // TESTGRAPHE_HPP
