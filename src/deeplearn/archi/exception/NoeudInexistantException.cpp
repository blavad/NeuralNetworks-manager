#include "NoeudInexistantException.hpp"
#include <iostream>

NoeudInexistantException :: NoeudInexistantException(){
}
		
void NoeudInexistantException :: messageErreur(){
	std :: cout << "Il manque au moins une des extrémités.\n";
}
