#include <exception>
#include <string>

#ifndef __CYCLE_EXCEPTION_HPP__
#define __CYCLE_EXCEPTION_HPP__

/**
 * \class CycleException
 * \brief Gestion de l'erreur CycleException
 * \author Coralie
 * \version 2.0
 * \date juin 2019
 * Erreur appelee lorsqu'on trouve un cycle dans le graphe
 *
 */
class CycleException {
	private :
	    /** \brief Le message d'erreur */
		std::string m_error;

	public :
	    /**
         * \brief Constructeur de CycleException
         * \param error : Un message d'erreur
         */
		CycleException(std::string error) : m_error(error){}

		/**
         * \fn const char * messageErreur()
         * \brief Renvoie le message d'erreur
         * \return const char *
         */
		const char * messageErreur() const {return m_error.c_str();}

};

#endif

