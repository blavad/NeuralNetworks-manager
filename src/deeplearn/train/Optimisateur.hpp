#ifndef __OPTIMISATEUR_HPP__
#define __OPTIMISATEUR_HPP__

#include "ReseauNeurones.hpp"
#include "Erreur.hpp"


/** 
 * \class Optimisateur
 * \brief Gère l'optimisation d'un apprentissage.
 * \author Marion
 * \version 1.0 
 * \date avril 2019
 *
 * Module permettant le traitement de l'optimisation de l'erreur lors d'un apprentissage.
 * 
 * 
 */
class Optimisateur {

    private :
        /** \brief le reseau de neurones de l'optimisateur */
        ReseauNeurones rn;

    public :

        /**
         * \brief Constructeur d'un otpimisateur a partir d'un reseau de neurones
         */
        Optimisateur(ReseauNeurones reseauN);

        /**
         * \fn void minimiser(Erreur err)
         * \brief Minimise une erreur donnee
         */
        void minimiser(Erreur err);

};

#endif