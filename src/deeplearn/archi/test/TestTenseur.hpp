#ifndef TESTTENSEUR_HPP__
#define TESTTENSEUR_HPP__

#include <vector>
#include <string>

#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/Test.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../Tenseur.hpp"

using namespace CppUnit;

/**
 * \class TestTenseur
 * \brief Test les méthodes de la classe Tenseur.
 * \author David
 * \version 1.0
 * \date avril 2019
 *
 */
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

        /** \brief Vérifier l'égalité entre deux Tenseurs */
	void testEgalite();

        /** \brief Vérifier l'addition entre deux Tenseurs */
	void testAddition();

        /** \brief Vérifier la multiplication entre deux Tenseurs */
	void testMultiplication();

        /** \brief Vérifier que l'indice absolu est le bon */
	void testGetIndAbs();

	/** \brief Vérifier que l'initiaisation du vecteur est correcte */
	void testSetValeurFromVector();

        /** \brief Vérifier que le prochain indice est correcte */
	void testNextIndice();

        /** \brief Vérifier que le prochain indice est correcte avec une contrainte d'ordre */
	void testNextIndice(int ordre);
};
#endif
