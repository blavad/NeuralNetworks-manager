#include <exception>
#include <string>

#ifndef __NOEUD_INEXISTANT_EXCEPTION_HPP__
#define __NOEUD_INEXISTANT_EXCEPTION_HPP__

class NoeudInexistantException {
	private :
		std::string m_error;
	
	public : 
		NoeudInexistantException(std::string error) : m_error(error){}
		
		const char * messageErreur() const {return m_error.c_str();}
	
};

#endif

