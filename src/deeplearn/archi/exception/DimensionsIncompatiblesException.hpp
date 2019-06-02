#include <exception>
#include <string>

#ifndef __DIMENSIONS_INCOMPATIBLES_EXCEPTION_HPP__
#define __DIMENSIONS_INCOMPATIBLES_EXCEPTION_HPP__

/**
 * \class DimensionsIncompatiblesException
 * \brief Gestion de l'erreur DimensionsIncompatiblesException
 *
 * Erreur appelée lorsque les dimensions des tenseurs sont incompatibles
 *
 */
class DimensionsIncompatiblesException : public std::exception {
	private :
	    /** \brief Le message d'erreur */
		std::string m_error;

	public :
	    /**
         * \brief Constructeur vide de DimensionsIncompatiblesException
         */
		DimensionsIncompatiblesException() : m_error("Dimension tenseurs différentes."){}

        /**
         * \brief Constructeur de DimensionsIncompatiblesException avec paramètres
         * \param d1 : int
         * \param d2 : int
         */
		DimensionsIncompatiblesException(int d1, int d2) : m_error("Erreur dimension."){}

		/**
         * \fn const char * what()
         * \brief Renvoie le message d'erreur
         * \return const char *
         */
		const char * what() const throw() {return m_error.c_str();}
};

#endif
