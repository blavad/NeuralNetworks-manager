#include "ArcDejaExistantException.hpp"
#include <iostream>

ArcDejaExistantException :: ArcDejaExistantException(){
}
		
void ArcDejaExistantException :: messageErreur(){
	std::cout << "Erreur : L'arc existe déjà.\n";
}
