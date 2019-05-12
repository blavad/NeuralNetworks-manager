#include <exception>
#include <string>

#ifndef __CYCLE_EXCEPTION_HPP__
#define __CYCLE_EXCEPTION_HPP__

class CycleException {
	private :
		std::string m_error;
	
	public : 
		CycleException(std::string error) : m_error(error){}
		
		const char * messageErreur() const {return m_error.c_str();}
	
};

#endif

