#include "TestDonnees.hpp"

using namespace CppUnit;

class TestDonnees : public CppUnit::TestFixture{

    void setUp(){
	d1 = new Donnees();
	std::vector<Donnee> d2
    };

    void tearDown(){
      	delete d1;
      	delete d2;
    };

    void testAjouterDonnees(){
        d1.ajouterDonnees(d2);
        CPPUNIT_ASSERT ((d1.getNbDonnees() == d2.getNbDonnees()) && (d1.getDonnees() == d2.getDonnees());
    };

    void testMelanger(){
	d1.ajouterDonnees(d2);
	d1.melanger();
        CPPUNIT_ASSERT (d1.getDonnees() != d2);
    };


};
