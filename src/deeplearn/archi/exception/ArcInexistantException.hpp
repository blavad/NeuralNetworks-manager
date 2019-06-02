#include <exception>
#include <string>

#ifndef __ARC_INEXISTANT_EXCEPTION_HPP__
#define __ARC_INEXISTANT_EXCEPTION_HPP__

/**
 * \class ArcInexistantException
 * \brief Gestion de l'erreur ArcInexistantException
 *
 * Erreur appel�e lorsqu'un arc n'existe pas
 *
 */

class ArcInexistantException {
	private :
	    /** \brief Le message d'erreur */
		std::string m_error;

	public :
	    /**
         * \brief Constructeur de ArcInexistantException
         * \param error : Un message d'erreur
         */
		ArcInexistantException(std::string error) : m_error(error){}

		/**
         * \fn const char * messageErreur()
         * \brief Renvoie le message d'erreur
         * \return const char *
         */
		const char * messageErreur() const {return m_error.c_str();}

};

#endif

