#include <exception>
#include <string>

#ifndef __NON_CONNEXE_EXCEPTION_HPP__
#define __NON_CONNEXE_EXCEPTION_HPP__

/**
 * \class NonConnexeException
 * \brief Gestion de l'erreur NonConnexeException
 *
 * Erreur appelée lorsqu'un graphe n'est pas connexe
 *
 */
class NonConnexeException {
	private :
	    /** \brief Le message d'erreur */
		std::string m_error;

	public :
	    /**
         * \brief Constructeur de NonConnexeException
         * \param error : Un message d'erreur
         */
		NonConnexeException(std::string error) : m_error(error){}

		/**
         * \fn const char * messageErreur()
         * \brief Renvoie le message d'erreur
         * \return const char *
         */
		const char * messageErreur() const {return m_error.c_str();}

};

#endif

