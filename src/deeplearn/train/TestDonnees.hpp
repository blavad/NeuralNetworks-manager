#include <vector>
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include "Donnees.hpp"
#include "Donnee.hpp"


#ifndef TESTDONNEES_HPP
#define TESTDONNEES_HPP

/**
 * \class TestDonnees
 * \brief Test des méthodes de la classe Donnees.
 * \author Adrien
 * \version 1.0
 * \date avril 2019
 *
 */

using namespace CppUnit;

class TestDonnees : public CppUnit::TestFixture {

private :

	Donnees d1;
	std::vector<Donnee> d2;

public:

    /** \brief Vérifier que les données s'ajoutent bien */
    void testAjouterDonnees();

   /** \brief Vérifier que la donnee s'ajoute bien */
    void testAjouterDonnee();

    /** \brief Vérifier que les données se mélangent bien */
    void testMelanger();


};


#endif // TESTDONNEES_HPP
