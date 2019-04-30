#include "NoeudDejaExistantException.hpp"
#include <iostream>

NoeudDejaExistantException :: NoeudDejaExistantException(){
}
		
void NoeudDejaExistantException :: messageErreur(){
	std :: cout << "Le noeud existe déjà.\n";
}
