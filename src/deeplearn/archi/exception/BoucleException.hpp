#include <exception>
#include <string>

#ifndef __BOUCLE_EXCEPTION_HPP__
#define __BOUCLE_EXCEPTION_HPP__

/**
 * \class BoucleException
 * \brief Gestion de l'erreur BoucleException
 *
 * Erreur appel�e lorsqu'on veut cr�er un arc d'un noeud sur lui-m�me
 *
 */
class BoucleException {
	private :
	    /** \brief Le message d'erreur */
		std::string m_error;

	public :
	    /**
         * \brief Constructeur de BoucleException
         * \param error : Un message d'erreur
         */
		BoucleException(std::string error) : m_error(error){}

		/**
         * \fn const char * messageErreur()
         * \brief Renvoie le message d'erreur
         * \return const char *
         */
		const char * messageErreur() const {return m_error.c_str();}

};

#endif

