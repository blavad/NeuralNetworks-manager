#include <exception>
#include <string>

#ifndef __ARC_INEXISTANT_EXCEPTION_HPP__
#define __ARC_INEXISTANT_EXCEPTION_HPP__

class ArcInexistantException {
	private :
		std::string m_error;
	
	public : 
		ArcInexistantException(std::string error) : m_error(error){}
		
		const char * messageErreur() const {return m_error.c_str();}
	
};

#endif

