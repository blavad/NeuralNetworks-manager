#include <exception>
#include <string>

#ifndef __BOUCLE_EXCEPTION_HPP__
#define __BOUCLE_EXCEPTION_HPP__

class BoucleException {
	private :
		std::string m_error;
	
	public : 
		BoucleException(std::string error) : m_error(error){}
		
		const char * messageErreur() const {return m_error.c_str();}
	
};

#endif

