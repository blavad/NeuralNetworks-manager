#ifndef TESTARCHI_HPP__
#define TESTARCHI_HPP__

#include <string>
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include "Tenseur.hpp"
#include "DimTenseur.hpp"
#include "Couche.hpp"

/**
 * \class TestCouche
 * \brief Test des méthodes de la classe Couche.
 * \author Adrien
 * \version 1.0
 * \date avril 2019
 *
 */
class TestCouche : public CppUnit::TestFixture {

public :
	/** \brief Vérifier que la propagation d'une couche à une autre se déroule normalement */
	void testPropagation();
	/** \brief Vérifier que la dérivation d'une couche s'effectue correctement */
	void testDerivee();
	
};
#endif
