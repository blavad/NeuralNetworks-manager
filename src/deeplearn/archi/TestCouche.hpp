#ifndef TESTARCHI_HPP__
#define TESTARCHI_HPP__

#include "cppunit/TestFixture.h"
#include "Tenseur.hpp"
#include "DimTenseur.hpp"


using namespace CppUnit;

class TestCouche : public CppUnit::TextFixture {
{
private :

	Couche c1,c2;
	Tenseur t1;
	DimTenseur d1,d2

public:
	void setUp();
	void tearDown();

	void testGetDimInput();
	void testGetDimOutput();
	void testSetDimInput();
	void testSetDimOutput();
	void testPropagation();
	void testDerivee();
	
};
#endif
