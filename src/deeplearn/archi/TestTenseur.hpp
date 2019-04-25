#ifndef TESTTENSEUR_HPP__
#define TESTTENSEUR_HPP__

#include <vector>
#include <string>

#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/Test.h>
#include <cppunit/extensions/HelperMacros.h>

#include "Tenseur.hpp"

using namespace CppUnit;

class TestTenseur : public CppUnit::TestFixture
{

	CPPUNIT_TEST_SUITE(TestTenseur);
	CPPUNIT_TEST(testNextIndice);
	CPPUNIT_TEST(testGetIndAbs);
	CPPUNIT_TEST(testSetValeurFromVector);
	CPPUNIT_TEST(testEgalite);
	CPPUNIT_TEST_SUITE_END();

  protected:
	Tenseur *t1, *t2, *t3;

  public:
	void setUp();
	void tearDown();

	void testEgalite();
	void testAddition();
	void testMultiplication();

	void testGetIndAbs();
	void testSetValeurFromVector();

	void testNextIndice();
	void testNextIndice(int ordre);
};
#endif
