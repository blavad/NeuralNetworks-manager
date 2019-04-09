#ifndef __ERREUR_HPP__
#define __ERREUR_HPP__

#include "Tenseur.hpp"


/** 
 * \class Erreur
 * \brief Gère le calcul de l'erreur commise lors d'un apprentissage.
 * \author Marion
 * \version 1.0 
 * \date avril 2019
 *
 * Module permettant le traitement de l'erreur commise lors d'un apprentissage.
 * Il permet également la récupération des données liées aux erreurs.
 * 
 * 
 */
class Erreur {

    public :

        /**
         * \fn virtual Tenseur eval(Tenseur sortieRN, Tenseur prediction)
         * \brief Methode virtuelle pour evaluer l'erreur effectuee entre la sortie et la prediction.
         * \param sortieRN le tenseur de sortie du reseau de neurones.
         * \param prediction la sortie attendue du reseau de neurones.
         */
        virtual eval(Tenseur sortieRN, Tenseur prediction);

        /**
         * \fn virtual void derivee(Tenseur t)
         * \brief Méthode virtuelle pour avoir la derivee d'un tenseur donnee en entree
         * \param t le tenseur pour lequel on veut la derivee
         */
        virtual derivee(Tenseur t);



};

#endif