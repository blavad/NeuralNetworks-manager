#ifndef __PANNEAU_CPP__
#define __PANNEAU_CPP__

#include "Panneau.hpp"
#include "PanneauMenuPrincipal.hpp"
#include "PanneauArchitecture.hpp"
#include "PanneauEntrainement.hpp"
#include "PanneauTest.hpp"
#include <gtkmm.h>

Panneau::Panneau(){

}

main(int argc, char* argv[]) {
	
	PanneauMenuPrincipal pp;
	pp.afficherContenu(argc,argv);

	PanneauArchitecture pa;
	pa.afficherContenu(argc,argv);

	PanneauEntrainement pe;
	pe.afficherContenu(argc,argv);

	PanneauTest pt;
	pt.afficherContenu(argc,argv);

}
#endif
