#include "NoeudInexistantException.hpp"
#include <iostream>

NoeudInexistantException :: NoeudInexistantException(){
}
		
void NoeudInexistantException :: messageErreur(){
	std :: cout << "Erreur : Il manque un noeud.\n";
}

