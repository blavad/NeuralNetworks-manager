#include "TestDonnees.hpp"

using namespace CppUnit;

void TestDonnees::setUp()
{
	d1 = new Donnees();
	d2 = new Donnees();
}
void TestDonnees::tearDown()
{
	delete d1;
	delete d2;
}

void TestDonnees::testAjouterDonnees()
{
	int n = d1->getNbDonnees();
	d1 -> ajouterDonnees(d2);
	CPPUNIT_ASSERT(d1.Donnees::getNbDonnees() == d2.size() + n);
};

void TestDonnees::testAjouterDonnee()
{
	d1.ajouterDonnee(d);
	int n = d1.Donnees::getNbDonnees();
	CPPUNIT_ASSERT(d1.Donnees::getNbDonnees() == n + 1);
};
