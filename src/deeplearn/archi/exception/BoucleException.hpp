#include <exception>
#include <string>

#ifndef __BOUCLE_EXCEPTION_HPP__
#define __BOUCLE_EXCEPTION_HPP__

/**
 * \class BoucleException
 * \brief Gestion de l'erreur BoucleException
 * \author Coralie
 * \version 2.0
 * \date juin 2019
 * 
 * Erreur appelee lorsqu'on veut creer un arc d'un noeud sur lui-meme
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

