#include "TestCouche.hpp"



	void TestCouche::testPropagation()
{
	DimTenseur d1;
	Couche c1(d1,d1,"test");
	Tenseur t1(2);
	// IL FAUT SURCHARGER L'OPERATEUR = POUR DIMTENSEUR AVANT DE POUVOIR ENLEVER LES COMMENTAIRES
	//CPPUNIT_ASSERT_EQUAL(c1.propagation(t1).getDim(),c1.getDimOutput());
}


	void TestCouche::testDerivee()
{
	DimTenseur d1;
	Couche c1(d1,d1,"test");
	Tenseur t1(2);
	//CPPUNIT_ASSERT_EQUAL (c1.derivee(t1).getDim(),c1.getDimOutput());
}





