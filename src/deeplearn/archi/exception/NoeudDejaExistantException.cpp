#include "NoeudDejaExistantException.hpp"
#include <iostream>

NoeudDejaExistantException :: NoeudDejaExistantException(){
}
		
void NoeudDejaExistantException :: messageErreur(){
	std :: cout << "Erreur : Le noeud existe déjà.\n";
}
