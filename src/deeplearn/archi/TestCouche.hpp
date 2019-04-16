#ifndef TESTARCHI_HPP__
#define TESTARCHI_HPP__

#include "cppunit/TestFixture.h"
#include "Tenseur.hpp"
#include "DimTenseur.hpp"
#include "Graphe.hpp"


using namespace CppUnit;

class TestCouche : public CppUnit::TextFixture {
{
private :

	Couche c1,c2;
	Tenseur t1;
	DimTenseur d1,d2
	Graphe g1;
public:
	void setUp();
	void tearDown();

	void testPropagation();
	void testDerivee();
	
};
#endif
