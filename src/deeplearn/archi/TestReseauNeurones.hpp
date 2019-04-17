#ifndef TESTRESEAUNEURONES_HPP__
#define TESTRESEAUNEURONES_HPP__

#include "cppunit/TestFixture.h"
#include "ReseauNeurones.hpp"


using namespace CppUnit;

class TestReseauNeurones : public CppUnit::TestFixture{

private :

	DimTenseur d1,d2;
	Couche ci1,ci2,cf1,cf2,c1,c2;
	ReseauNeurones res1,res2;

public:
	void setUp();
	void tearDown();

	void testGetCoucheInitiale();
	void testGetCoucheFinale();
	void testAjouterCoucheInitiale();
	void testAjouterCoucheFinale();
	void testSupprimerCoucheInitiale();
	void testSupprimerCoucheFinale();

	
};
#endif
