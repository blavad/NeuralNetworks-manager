#include "TestCouche.hpp"
#include <vector>

void TestCouche::testPropagation()
{
	std::vector<int> din{4, 2}, dout{5};
	DimTenseur dimIn(din), dimOut(dout);
	Couche c1(din, dout, "test");
	Tenseur t1(dout);

	CPPUNIT_ASSERT_EQUAL(c1.propagation(t1).getDim(), c1.getDimOutput());
}

void TestCouche::testDerivee()
{
	std::vector<int> din{4, 2}, dout{5};
	DimTenseur dimIn(din), dimOut(dout);
	Couche c1(dimIn, dimOut, "test");
	Tenseur t1(dout);
	CPPUNIT_ASSERT_EQUAL(c1.derivee(t1).getDim(), c1.getDimOutput());
}
