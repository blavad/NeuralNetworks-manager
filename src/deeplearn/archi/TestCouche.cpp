#include <cppunit/TestFixture.h>
#include "TestCouche.hpp"

using namespace CppUnit;

class TestCouche : public CppUnit::TestFixture
{
	
public:
	void setUp()
{	
	d1 = new DimTenseur(2);
	c1 = new Couche (d1,d1);
	t1 = new Tenseur(2);
};
	void tearDown()
{
	delete d1;	
	delete c1;	
	delete t1;	
};

	void testPropagation()
{
	CPPUNIT_ASSERT (c1.propagation(t1).getDim()==c1.getDimOutput());
};
	void testDerivee()
{

};



};

