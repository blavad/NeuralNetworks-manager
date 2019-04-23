#include "TestDonnees.hpp"
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
using namespace CppUnit;

	Donnees d1;
	std::vector<Donnee> d2;
	Donnees d3;
	Donnee d;

    void TestDonnees::testAjouterDonnees(){
	int n=d1.Donnees::getNbDonnees();
        d1.ajouterDonnees(d2);
	CPPUNIT_ASSERT(d1.Donnees::getNbDonnees()==d2.size()+n);
    };

    void TestDonnees::testAjouterDonnee(){
        d1.ajouterDonnee(d);
	int n=d1.Donnees::getNbDonnees();
	CPPUNIT_ASSERT(d1.Donnees::getNbDonnees()==n+1);
    };

