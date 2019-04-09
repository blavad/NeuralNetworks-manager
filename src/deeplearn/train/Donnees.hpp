#ifndef __DONNEES_HPP__
#define __DONNEES_HPP__

#include <vector>
#include "Donnee.hpp"


/** 
 * \class Donnees
 * \brief Gère les donnees necessaire a l'apprentissage.
 * \author Marion
 * \version 1.0 
 * \date avril 2019
 *
 * Module permettant le traitement des donnees necessaire a l'apprentissage.
 * Il permet également leur récupération.
 * 
 * 
 */
class Donnees {

    private :
        /** \brief le vecteur des donnees */
        vector<Donnee> donnees;

    public :

        /**
         * \brief Constructeur des donnees d'apprentissage
         */
        Donnees();

        /**
         * \brief Constructeur des donnees d'apprentissage a partir d'un vecteur de donnees unitaires
         */
        Donnees(vector<Donnee> vd);

        /**
         * \fn void ajouterDonnees(Donnees d)
         * \brief Ajoute un ensemble de donnees
         * \param d l'ensemble des donnees
         */
        void ajouterDonnees(Donnees d);

        /**
         * \fn void ajouterDonnee(Donnee d)
         * \brief Ajoute une donnee a l'ensemble des donnees
         * \param d la donnee a ajouter
         */
        void ajouterDonnee(Donnee d);

        /**
         * \fn void melanger()
         * \brief Melange les donnees.
         */
        void melanger();

        /**
         * \fn Donnee getDonnee(int num)
         * \brief Retourne la donnee numero num parmis l'ensemble des donnees
         * \param num le numero de la donnee
         */
        Donnee getDonnee(int num);

        /**
         * \fn vector<Donnees> getDonnees()
         * \brief Retourne l'ensemble des donnees
         */
        vector<Donnees> getDonnees();

        /**
         * \fn int getNbDonnees()
         * \brief Retourne le nombre de donnees
         */
        int getNbDonnees();

};

#endif
