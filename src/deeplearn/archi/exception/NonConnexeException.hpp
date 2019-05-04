#include <exception>
#include <string>

#ifndef __NON_CONNEXE_EXCEPTION_HPP__
#define __NON_CONNEXE_EXCEPTION_HPP__

class NonConnexeException {
	private :
		std::string m_error;
	
	public : 
		NonConnexeException(std::string error) : m_error(error){}
		
		const char * messageErreur() const {return m_error.c_str();}
	
};

#endif

