#include "ArcInexistantException.hpp"
#include <iostream>

ArcInexistantException :: ArcInexistantException(){
}
		
void ArcInexistantException :: messageErreur(){
	std :: cout << "Erreur : L'arc n'existe pas.\n";
}
