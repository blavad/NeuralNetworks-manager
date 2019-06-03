#include <exception>
#include <string>

#ifndef __ARC_DEJA_EXISTANT_EXCEPTION_HPP__
#define __ARC_DEJA_EXISTANT_EXCEPTION_HPP__

/**
 * \class ArcDejaExistantException
 * \brief Gestion de l'erreur ArcDejaExistantException
 * \author Kevin
 * \version 2.0
 * \date juin 2019
 * Erreur appelee lorsqu'un arc existe deja
 *
 */
class ArcDejaExistantException {
	private :
	    /** \brief Le message d'erreur */
		std::string m_error;

	public :
	    /**
         * \brief Constructeur de ArcDejaExistantException
         * \param error : Un message d'erreur
         */
		ArcDejaExistantException(std::string error) : m_error(error){}

        /**
         * \fn const char * messageErreur()
         * \brief Renvoie le message d'erreur
         * \return const char *
         */
		const char * messageErreur() const {return m_error.c_str();}

};

#endif
