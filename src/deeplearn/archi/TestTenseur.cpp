#include <cppunit/TestFixture.h>
#include "TestTenseur.hpp"

using namespace CppUnit;

class TestTenseur : public CppUnit::TestFixture
{
	
public:
	void setUp()
{
	t1 = new Tenseur(2);
	t2 = new Tenseur(3):

};


	void tearDown()
{
	delete t1;	
	delete t2;
};



	void testGetValeur()
{

	CPPUNIT_ASSERT (t1.getValeur()==2);
	CPPUNIT_ASSERT (!(t1.getValeur()==3));
	CPPUNIT_ASSERT (t2.getValeur()==3);
	CPPUNIT_ASSERT (!(t1.getValeur()==4));

};


	void testInitValeurGaussienne()
{

	t1.IniValeurGaussienne();
	t2.InitValeurGaussienne();	

	CPPUNIT_ASSERT (!(t1.getValeur()==t2.getValeur()));

};


	void testInitValeurUnif(int valeur)
{

	t1.InitValeurUnif(5);
	t2.InitValeurUnif(8);

	CPPUNIT_ASSERT (t1.getValeur()==5);
	CPPUNIT_ASSERT (!(t1.getValeur()==8));
	CPPUNIT_ASSERT (t2.getValeur()==8);
	CPPUNIT_ASSERT (!(t2.getValeur()==6));

};


	void testInitValeurNulle()
{

	t1.InitValeurNulle();
	t2.InitValeurNulle();
	

	CPPUNIT_ASSERT (t1.getValeur()==0);
	CPPUNIT_ASSERT (!(t1.getValeur()==5));
	CPPUNIT_ASSERT (t2.getValeur()==0);
	CPPUNIT_ASSERT (!(t2.getValeur()==6));

};


};

