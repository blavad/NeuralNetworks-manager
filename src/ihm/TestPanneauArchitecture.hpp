

#ifndef __TEST_PANNEAU_ARCHITECTURE_HPP__
#define __TEST_PANNEAU_ARCHITECTURE_HPP__


#include <cppunit/TestFixture.h>
#include "PanneauArchitecture.hpp"

using namespace CppUnit;
using namespace std;

class TestPanneauArchitecture : public TestFixture{
	
	private :
		
		
	public :
		void setUp();
		void tearDown();
		
		void testAjouterCouche();
		void testAjouterLiaison();
		void testAjouterRN();
		void testSupprimerCouche();
		void testSupprimerLiaison();
		void testSelectCouche();
		void testSelectLiaison();
		void testGetCoucheSelectionnee();
		void testGetLiaison();
		

	};
#endif
