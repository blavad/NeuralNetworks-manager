#ifndef __TESTPRETRAITEMENT_HPP__
#define __TESTPRETRAITEMENT_HPP__

#include <string>
#include <vector>
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../deeplearn/train/Donnees.hpp"
#include "../deeplearn/archi/ReseauNeurones.hpp"
#include "../Pretraitement.hpp"

/**
 * \class TestPretraitement
 * \brief Test des méthodes de la classe Pretraitement.
 * \author Kevin
 * \version 2.0
 * \date juin 2019
 *
 */

using namespace CppUnit;

class TestPretraitement : public CppUnit::TestFixture
{

	CPPUNIT_TEST_SUITE(TestPretraitement);
	CPPUNIT_TEST(testChargerDonnees);
	CPPUNIT_TEST(testChargerRN);
	CPPUNIT_TEST(testNormaliser);
	CPPUNIT_TEST(testDenormaliser);
	CPPUNIT_TEST_SUITE_END();

  public:
	/** \brief Vérifier que les données se chargent bien */
	void testChargerDonnees();

	/** \brief Vérifier que le réseau de neurones se charge bien */
	void testChargerRN();

	/** \brief Vérifier que la normalisation et denormalisation d'un tenseur */
	void testNormaliser();

	/** \brief Vérifier que la normalisation et denormalisation d'un tenseur */
	void testDenormaliser();

	/** \brief Vérifier que le tenseur a bien été normalisé */
	void testNormaliser(Tenseur &t, double minNorm, double maxNorm, double minValeur, double maxValeur);

	/** \brief Vérifier que le tenseur a bien été dénormalisé */
	void testDenormaliser(Tenseur &t, double minNorm, double maxNorm, double minValeur, double maxValeur);
};

#endif
