#include <cppunit/TestFixture.h>
#include "TestTenseur.hpp"

using namespace CppUnit;

class TestReseauNeurones : public CppUnit::TestFixture
{
	
public:
	void setUp()
{
	d1 = new DimTenseur(2);
	d2 = new DimTenseur(3);
	ci1 = new Couche(d1,d2);
	ci2 = new Couche(d2,d1);
	cf1 = new Couche(d1,d2);
	cf2 = new Couche(d2,d1);
	c1 = new Couche(d1,d2);
	c2 = new Couche(d2,d1);
	res1 = new ReseauNeurones(new vector<Couche> {ci1},new vector<Couche> {cf1});
	res2 = new ReseauNeurones(new vector<Couche> {ci2},new vector<Couche> {cf2});

};


	void tearDown()
{	
	delete d1;	
	delete d2;
	delete ci1;
	delete ci2;
	delete cf1;
	delete cf2;
	delete c1;
	delete c2;
	delete res1;
	delete res2;
};



void testGetCoucheInitiale()
{
      
        CPPUNIT_ASSERT (res1.getCoucheInitiale() == vector<Couche> {ci1});
	CPPUNIT_ASSERT (!(res1.getCoucheInitiale() == c1));
	CPPUNIT_ASSERT (res2.getCoucheInitiale() == vector<Couche> {ci2});
	CPPUNIT_ASSERT (!(res2.getCoucheInitiale() == c2));

};



void testGetCoucheFinale()
{
      
        CPPUNIT_ASSERT (res1.getCoucheInitiale() == vector<Couche> {cf1});
	CPPUNIT_ASSERT (!(res1.getCoucheInitiale() == ci1));
	CPPUNIT_ASSERT (res2.getCoucheInitiale() == vector<Couche> {cf2});
	CPPUNIT_ASSERT (!(res2.getCoucheInitiale() == ci2));

};


	void testAjouterCoucheInitiale()
{
        res1.ajouterCoucheInitiale(c1);
	res2.ajouterCoucheInitiale(c2);

        CPPUNIT_ASSERT (res1.getCoucheInitiale() == vector<Couche> {ci1,c1});
	CPPUNIT_ASSERT (!(res1.getCoucheInitiale() == ci1));
	CPPUNIT_ASSERT (res2.getCoucheInitiale() == vector<Couche> {ci2,c2});
	CPPUNIT_ASSERT (!(res2.getCoucheInitiale() == ci2));

	

};


	void testAjouterCoucheFinale()
{

	res1.ajouterCoucheFinale(c1);
	res2.ajouterCoucheFinale(c2);

        CPPUNIT_ASSERT (res1.getCoucheInitiale() == vector<Couche> {cf1,c1});
	CPPUNIT_ASSERT (!(res1.getCoucheInitiale() == cf1));
	CPPUNIT_ASSERT (res2.getCoucheInitiale() == vector<Couche> {cf2,c2});
	CPPUNIT_ASSERT (!(res2.getCoucheInitiale() == cf2));


};


	void testSupprimerCoucheInitiale()
{

	res1.supprimerCoucheInitiale(ci1);
	res2.supprimerCoucheInitiale(ci2);

        CPPUNIT_ASSERT (res1.getCoucheInitiale() == vector<Couche> {});
	CPPUNIT_ASSERT (!(res1.getCoucheInitiale() == ci1));
	CPPUNIT_ASSERT (res2.getCoucheInitiale() == vector<Couche> {});
	CPPUNIT_ASSERT (!(res2.getCoucheInitiale() == ci2));

};


	void testSupprimerCoucheFinale()
{

	res1.supprimerCoucheFinale(ci1);
	res2.supprimerCoucheFinale(ci2);

        CPPUNIT_ASSERT (res1.getCoucheFinale() == vector<Couche> {});
	CPPUNIT_ASSERT (!(res1.getCoucheFinale() == cf1));
	CPPUNIT_ASSERT (res2.getCoucheFinale() == vector<Couche> {});
	CPPUNIT_ASSERT (!(res2.getCoucheFinale() == cf2));

};


};

