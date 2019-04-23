#ifndef __TESTPRETRAITEMENT_HPP__
#define __TESTPRETRAITEMENT_HPP__

#include <string>
#include <vector>
#include <cppunit/TestFixture.h>
#include "../deeplearn/train/Donnees.hpp"
#include "../deeplearn/archi/ReseauNeurones.hpp"
#include "Pretraitement.hpp"
#include <cppunit/TestAssert.h>

/**
 * \class TestPretraitement
 * \brief Test des méthodes de la classe Pretraitement.
 * \author Marion
 * \version 1.0
 * \date avril 2019
 *
 */

using namespace CppUnit;

class TestPretraitement : public CppUnit::TestFixture {
	
	public :
	
	/** \brief Vérifier que les données se chargent bien */
	void testChargerDonnees();
	
	/** \brief Vérifier que le réseau de neurones se charge bien */
	void testChargerRN();
	
	/** \brief Vérifier que le tenseur a bien été normalisé */
	void testNormaliser(Tenseur& t, double minNorm, double maxNorm, double minValeur, double maxValeur);
	
	/** \brief Vérifier que le tenseur a bien été dénormalisé */
	void testDenormaliser(Tenseur& t, double minNorm, double maxNorm, double minValeur, double maxValeur);
	
};


#endif
