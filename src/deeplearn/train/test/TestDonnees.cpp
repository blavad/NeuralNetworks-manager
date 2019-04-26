#include "TestDonnees.hpp"

using namespace CppUnit;

void TestDonnees::setUp()
{
	d1 = new Donnees();
	d2 = new Donnees();
	du = new Donnee();
}
void TestDonnees::tearDown()
{
	delete d1;
	delete d2;
}

void TestDonnees::testAjouterDonnees()
{
	int n = d1->getNbDonnees();
    std::vector<Donnee> donnees{Donnee(),Donnee(),Donnee()};

	d1 -> ajouterDonnees(donnees);
	CPPUNIT_ASSERT(d1->getNbDonnees() == donnees.size() + n);
}

void TestDonnees::testAjouterDonnee()
{
	int n = d1 -> getNbDonnees();
	d1 -> ajouterDonnee(*du);
	CPPUNIT_ASSERT(d1->getNbDonnees() == n + 1);
}

void TestDonnees::testMelanger(){
	CPPUNIT_ASSERT(true);
}
