/* Documentation tag for Doxygen
 */

/*! \mainpage PLEGAT Documentation
 *
 * \section intro_sec Introduction
 *
 * This is the Plegat documentation.
 *
 * \section install_sec Installation
 *
 * \subsection tools_subsec Tools required&#58;
 * - Java Runtime Environment &#40;JRE&#41; 1.4.2 or later &#40;<small><a href="http&#58;//java.sun.com/">Java Web Site etc etc...
 *
 * \subsection running Running the program
 * In a command window, etc etc...
 *
 * \section copyright Copyright and License
 * This license applies to etc etc...
 *
 * <BR><BR>
 *
 */
#include "Tenseur.hpp"
#include "DimTenseur.hpp"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

using namespace std;

int main(){
	
	Tenseur tenseur(std::vector(2,2));
std::ofstream ofile(filename);
boost::archive::text_oarchive oTextArchive(ofile);
oTextArchive << t;


    return 0;
}
