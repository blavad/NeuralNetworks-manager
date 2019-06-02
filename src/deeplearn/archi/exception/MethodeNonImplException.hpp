#include <exception>
#include <string>

#ifndef __METHODE_NON_IMPL_EXCEPTION_HPP__
#define __METHODE_NON_IMPL_EXCEPTION_HPP__

/**
 * \class MethodeNonImplException
 * \brief Gestion de l'erreur MethodeNonImplException
 *
 * Erreur appelée lorsque la méthode appelée n'est pas implémentée
 *
 */
class MethodeNonImplException : public std::exception {
	private :
	    /** \brief Le message d'erreur */
		std::string m_error;

	public :
	    /**
         * \brief Constructeur de MethodeNonImplException
         * \param nom : string (le nom de la méthode non implémentée)
         */
		MethodeNonImplException(std::string nom) : m_error("Méthode '"+nom+"' non implémentée."){}

        /**
         * \fn const char * what()
         * \brief Renvoie le message d'erreur
         * \return const char *
         */
		const char * what() const throw() {return m_error.c_str();}
};

#endif
