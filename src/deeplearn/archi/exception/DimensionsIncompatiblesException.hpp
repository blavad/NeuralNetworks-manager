#include <exception>
#include <string>

#ifndef __DIMENSIONS_INCOMPATIBLES_EXCEPTION_HPP__
#define __DIMENSIONS_INCOMPATIBLES_EXCEPTION_HPP__

class DimensionsIncompatiblesException : public std::exception {
	private :
		std::string m_error;
		
	public : 
		DimensionsIncompatiblesException() : m_error("Dimension tenseurs différentes."){}

		DimensionsIncompatiblesException(int d1, int d2) : m_error("Erreur dimension."){}
		
		const char * what() const throw() {return m_error.c_str();}
};

#endif
