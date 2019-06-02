#include <exception>
#include <string>

#ifndef __NOEUD_DEJA_EXISTANT_EXCEPTION_HPP__
#define __NOEUD_DEJA_EXISTANT_EXCEPTION_HPP__

/**
 * \class NoeudDejaExistantException
 * \brief Gestion de l'erreur NoeudDejaExistantException
 *
 * Erreur appelée lorsqu'un noeud existe déjà
 *
 */
class NoeudDejaExistantException : public std::exception {
	private :
	    /** \brief Le message d'erreur */
		std::string m_error;

	public :
	    /**
         * \brief Constructeur de NoeudDejaExistantException
         * \param error : Un message d'erreur
         */
		NoeudDejaExistantException(std::string error) : m_error(error){}

        /**
         * \fn const char * messageErreur()
         * \brief Renvoie le message d'erreur
         * \return const char *
         */
		const char * messageErreur() const {return m_error.c_str();}
};

#endif
