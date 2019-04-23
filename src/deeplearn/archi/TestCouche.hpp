#ifndef TESTARCHI_HPP__
#define TESTARCHI_HPP__

#include "cppunit/TestFixture.h"
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


using namespace CppUnit;

class TestCouche : public CppUnit::TestFixture {

private :

	Couche c1,c2;
	Tenseur t1;
	DimTenseur d1,d2;

public :
	/** \brief Initialiser les variables  */
	void setUp();
	/** \brief Supprimer les variables  */
	void tearDown();
	/** \brief Vérifier que la propagation d'une couche à une autre se déroule normalement */
	void testGetDimInput();
	void testGetDimOutput();
	void testSetDimInput();
	void testSetDimOutput();
	void testPropagation();
	/** \brief Vérifier que la dérivation d'une couche s'effectue correctement */
	void testDerivee();
	
};
#endif
