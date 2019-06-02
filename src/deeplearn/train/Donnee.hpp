#ifndef __DONNEE_HPP__
#define __DONNEE_HPP__

#include "../archi/Tenseur.hpp"

/** 
 * \class Donnee
 * \brief Gère une des données nécessaires à l'apprentissage.
 * \author Marion
 * \version 1.0 
 * \date avril 2019
 *
 * Module permettant le stockage en mémoire vive d'une donnee necessaire a l'apprentissage.
 * La donnee est vu comme un couple Entree/Sortie.
 * 
 */
class Donnee {

    private :
        /** \brief L'entree */
        Tenseur entree;

        /** \brief La sortie */
        Tenseur sortie;

    public :

        /**
         * \brief Constructeur standard
         */
        Donnee();

        /**
         * \brief Constructeur de Donnee avec l'entrée et la sortie 
         */
        Donnee(Tenseur& entree, Tenseur& sortie);

        /**
         * \fn Tenseur getEntree()
         * \brief Retourne l'entree de la donnee
         * \return L'entree.         
         */
        Tenseur getEntree();

        /**
         * \fn Tenseur getSortie()
         * \brief Retourne la sortie de la donnee
         * \return La sortie.  
         */
        Tenseur getSortie();

        /**
         * \fn void setEntree(Tenseur e)
         * \brief Met a jour l'entree de la donnee
         * \param e Le tenseur d'entree
         */
        void setEntree(Tenseur e);

        /**
         * \fn void setSortie(Tenseur s)
         * \brief Met a jour la sortie de la donnee
         * \param s Le tenseur de sortie
         */
        void setSortie(Tenseur s);

	
};

#endif
