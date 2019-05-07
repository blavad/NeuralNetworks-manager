#include <exception>
#include <string>

#ifndef __METHODE_NON_IMPL_EXCEPTION_HPP__
#define __METHODE_NON_IMPL_EXCEPTION_HPP__

class MethodeNonImplException : public std::exception {
	private :
		std::string m_error;
		
	public : 
		MethodeNonImplException(std::string nom) : m_error("Méthode '"+nom+"' non implémentée."){}
		
		const char * what() const throw() {return m_error.c_str();}
};

#endif
