#include <exception>
#include <string>

#ifndef __NOEUD_DEJA_EXISTANT_EXCEPTION_HPP__
#define __NOEUD_DEJA_EXISTANT_EXCEPTION_HPP__

class NoeudDejaExistantException : public std::exception {
	private :
		std::string m_error;
		
	public : 
		NoeudDejaExistantException(std::string error) : m_error(error){}
		
		const char * messageErreur() const {return m_error.c_str();}
};

#endif
