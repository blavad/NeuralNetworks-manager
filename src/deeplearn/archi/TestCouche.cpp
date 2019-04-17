#include <cppunit/TestFixture.h>
#include "TestCouche.hpp"

using namespace CppUnit;

class TestCouche : public CppUnit::TestFixture
{
	
public:
	void setUp()
{	
	d1 = new DimTenseur(2);
	d2 = new DimTenseur(3);
	d3 = new DimTenseur(4);
	d4 = new DimTenseur(5);
	c1 = new Couche (d1,d1);
	t1 = new Tenseur(2);
};


	void tearDown()
{
	delete d1;	
	delete c1;	
	delete t1;	
};


	void testGetDimInput()
{

	CPPUNIT_ASSERT (c1.getDimInput()==d1);
	CPPUNIT_ASSERT (!c1.getDimInput()==d2);
	CPPUNIT_ASSERT (c2.getDimInput()==d1);
	CPPUNIT_ASSERT (!c1.getDimInput()==d2);

};


	void testGetDimOutput()
{

	CPPUNIT_ASSERT (c1.getDimOutput()==d1);
	CPPUNIT_ASSERT (!c1.getDimOutput()==d2);
	CPPUNIT_ASSERT (c2.getDimOutput()==d2);
	CPPUNIT_ASSERT (!c2.getDimOutpout()==d1);

};


	void testSetDimInput()
{

	c1.setDimInput(d3);
	c2.setDimInput(d4);
	

	CPPUNIT_ASSERT (c1.getDimInput()==d3);
	CPPUNIT_ASSERT (!c1.getDimInput()==d2);
	CPPUNIT_ASSERT (c2.getDimInput()==d4);
	CPPUNIT_ASSERT (!c2.getDimInput()==d1);

};


	void testSetDimOutput()
{

	c1.setDimOutput(d3);
	c2.setDimOutput(d4);
	

	CPPUNIT_ASSERT (c1.getDimOutput()==d3);
	CPPUNIT_ASSERT (!c1.getDimOutput()==d2);
	CPPUNIT_ASSERT (c2.getDimOutput()==d4);
	CPPUNIT_ASSERT (!c2.getDimOutput()==d1);

};


	void testPropagation()
{
	CPPUNIT_ASSERT (c1.propagation(t1).getDim()==c1.getDimOutput());
};


	void testDerivee()
{
	CPPUNIT_ASSERT (c1.derivee(t1).getDim()==c1.getDimOutput());
	CPPUNIT_ASSERT (c2.derivee(t1).getDim()==c2.getDimOutput());
};



};

