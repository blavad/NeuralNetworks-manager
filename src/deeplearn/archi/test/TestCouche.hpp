#ifndef TESTARCHI_HPP__
#define TESTARCHI_HPP__

#include <string>
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../Tenseur.hpp"
#include "../DimTenseur.hpp"
#include "../Couche.hpp"

/**
 * \class TestCouche
 * \brief Test des méthodes de la classe Couche.
 * \author Adrien
 * \version 2.0
 * \date juin 2019
 *
 */
class TestCouche : public CppUnit::TestFixture
{

	CPPUNIT_TEST_SUITE(TestCouche);
	CPPUNIT_TEST(testPropagation);
	CPPUNIT_TEST(testDerivee);
	CPPUNIT_TEST_SUITE_END();

  public:
	/** \brief Vérifier que la propagation d'une couche à une autre se déroule normalement */
	void testPropagation();

	/** \brief Vérifier que la dérivation d'une couche s'effectue correctement */
	void testDerivee();
};
#endif
