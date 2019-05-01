#include <exception>
#include <string>

#ifndef __ARC_DEJA_EXISTANT_EXCEPTION_HPP__
#define __ARC_DEJA_EXISTANT_EXCEPTION_HPP__

class ArcDejaExistantException {
	private :
		std::string m_error;
	
	public : 
		ArcDejaExistantException(std::string error) : m_error(error){}
		
		const char * messageErreur() const {return m_error.c_str();}
	
};

#endif
