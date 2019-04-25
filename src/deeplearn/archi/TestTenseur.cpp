#include "Tenseur.hpp"
#include "TestTenseur.hpp"
#include <vector>

using namespace CppUnit;

void TestTenseur::setUp()
{
	std::vector<int> d1{16};
	std::vector<int> d2{18, 20};
	std::vector<int> d3{3, 10, 10};
	t1 = new Tenseur(d1);
	t2 = new Tenseur(d2);
	t3 = new Tenseur(d3);
}
void TestTenseur::tearDown()
{
	delete t1;
	delete t2;
	delete t3;
}

void TestTenseur::testEgalite()
{
	std::vector<int> d1{3, 10, 10}, d2{2, 10, 10};
	Tenseur t1(d1), t2(d2), t3(d1);

	t1.initValeurNulle();
	t2.initValeurNulle();	
	t3.initValeurNulle();

	CPPUNIT_ASSERT(t1==t3);
	CPPUNIT_ASSERT(t1!=t2);
}


void testAddition()
{
}

void testMultiplication()
{
}

void TestTenseur::testGetIndAbs()
{
	std::vector<int> pos{12};
	CPPUNIT_ASSERT(t1->getInd(pos) == 12);

	pos = {2, 4};

	CPPUNIT_ASSERT(t2->getInd(pos) == 44);

	pos = {2, 1, 0};
	CPPUNIT_ASSERT(t3->getInd(pos) == 210);
}

void TestTenseur::testSetValeurFromVector()
{
	std::vector<int> pos{12};
	t1->setValeur(3., pos);
	CPPUNIT_ASSERT(t1->getValeur(pos) == 3.);

	pos = {2, 4};
	t2->setValeur(3., pos);
	CPPUNIT_ASSERT(t2->getValeur(pos) == 3.);

	pos = {0, 8, 1};
	t3->setValeur(3., pos);
	CPPUNIT_ASSERT(t3->getValeur(pos) == 3.);
}

void TestTenseur::testNextIndice()
{
	testNextIndice(1);
	testNextIndice(2);
	testNextIndice(3);
	testNextIndice(4);
	testNextIndice(5);
	testNextIndice(6);
	testNextIndice(7);
	testNextIndice(8);
	testNextIndice(9);
	testNextIndice(10);

	std::vector<int> indAvant{10};
	std::vector<int> indApres{11};
	t1->nextInd(indAvant);
	CPPUNIT_ASSERT(indAvant == indApres);

	indAvant = {15, 19};
	indApres = {16, 0};
	t2->nextInd(indAvant);
	CPPUNIT_ASSERT(indAvant == indApres);

	indAvant = {15, 19};
	indApres = {16, 0};
	t2->nextInd(indAvant);
	CPPUNIT_ASSERT(indAvant == indApres);
}

void TestTenseur::testNextIndice(int ordre)
{
	std::vector<int> ind1F(ordre, 3);
	std::vector<int> ind1T(ordre, 0);

	std::vector<int> dimT(ordre, 4);

	Tenseur *t = new Tenseur(dimT);

	CPPUNIT_ASSERT(!t->nextInd(ind1F));

	CPPUNIT_ASSERT(t->nextInd(ind1T));
}
