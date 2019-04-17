#ifndef TESTTENSEUR_HPP__
#define TESTTENSEUR_HPP__

#include "cppunit/TestFixture.h"
#include "Tenseur.hpp"


using namespace CppUnit;

class TestTenseur : public CppUnit::TextFixture {
{
private :

	Tenseur t1,t2;

public:
	void setUp();
	void tearDown();

	void testGetValeur();
	void testInitValeurGaussienne();
	void testInitValeurUnif(int valeur);
	void testInitValeurNulle();

	
};
#endif
