#include "ArcDejaExistantException.hpp"
#include <iostream>

ArcDejaExistantException :: ArcDejaExistantException(){
}
		
void ArcDejaExistantException :: messageErreur(){
	std::cout << "L'arc existe déjà.\n";
}
