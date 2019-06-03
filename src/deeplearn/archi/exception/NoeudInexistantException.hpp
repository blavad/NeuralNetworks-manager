#include <exception>
#include <string>

#ifndef __NOEUD_INEXISTANT_EXCEPTION_HPP__
#define __NOEUD_INEXISTANT_EXCEPTION_HPP__

/**
 * \class NoeudInexistantException
 * \brief Gestion de l'erreur NoeudInexistantException
 * \author Coralie
 * \version 2.0
 * \date juin 2019
 * Erreur appelee lorsqu'un noeud n'existe pas
 *
 */
class NoeudInexistantException {
	private :
	    /** \brief Le message d'erreur */
		std::string m_error;

	public :
	    /**
         * \brief Constructeur de NoeudInexistantException
         * \param error : Un message d'erreur
         */
		NoeudInexistantException(std::string error) : m_error(error){}

		/**
         * \fn const char * messageErreur()
         * \brief Renvoie le message d'erreur
         * \return const char *
         */
		const char * messageErreur() const {return m_error.c_str();}

};

#endif

