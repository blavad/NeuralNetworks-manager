#ifndef __DONNEE_HPP__
#define __DONNEE_HPP__

#include "Tenseur.hpp"

/** 
 * \class Donnee
 * \brief Gère une des donnees necessaires a l'apprentissage.
 * \author Marion
 * \version 1.0 
 * \date avril 2019
 *
 * Module permettant le traitement d'une donnee necessaire a l'apprentissage.
 * Il permet également sa récupération.
 * 
 * 
 */
class Donnee {

    private :
        /** \brief l'entree */
        Tenseur entree;

        /** \brief la sortie */
        Tenseur sortie;

    public :

        /**
         * \brief Constructeur de Donnee avec une entree et une sortie
         */
        Donnee(Tenseur entree, Tenseur sortie);

        /**
         * \fn Tenseur getEntree()
         * \brief Retourne l'entree de la donnee
         */
        Tenseur getEntree();

        /**
         * \fn Tenseur getSortie()
         * \brief Retourne la sortie de la donnee
         */
        Tenseur getSortie();

        /**
         * \fn void setEntree(Tenseur e)
         * \brief Met a jour l'entree de la donnee
         * \param e le tenseur d'entree
         */
        void setEntree(Tenseur e);

        /**
         * \fn void setSortie(Tenseur s)
         * \brief Met a jour la sortie de la donnee
         * \param s le tenseur de sortie
         */
        void setSortie(Tenseur s);

};

#endif