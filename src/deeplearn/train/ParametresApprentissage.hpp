#ifndef __PARAMETRESAPPRENTISSAGE_HPP__
#define __PARAMETRESAPPRENTISSAGE_HPP__


/** 
 * \class ParametresApprentissage 
 * \brief Gère les parametres d'apprentissage du réseau de neurones.
 * \author Marion
 * \version 1.0 
 * \date avril 2019
 *
 * Module permettant le choix des parametres de l'apprentissage.
 * Il permet également leur récupération.
 * 
 */
class ParametresApprentissage {

    private :
        /** \brief nombre d'epoques de l'apprentissage */
        int nb_epoques;

        /** \brief vitesse d'apprentissage du reseau */
        double taux_apprentissage;

    public :

        /**
         * \brief Constructeur des parametres d'apprentissage
         */
        ParametresApprentissage();

        /**
         * \fn int getNbEpoques()
         * \brief Retourne le nombre d'epoques de l'apprentissage.
         * \return le nombre d'epoques
         */
        int getNbEpoques();

        /**
         * \fn double getTauxApprentissage()
         * \brief Retourne le taux d'apprentissage du reseau
         * \return le tauc d'apprentissage         * 
         */
        double getTauxApprentissage();

        /**
         * \fn void setNbEpoques(int ep)
         * \brief Met a jour le nombre d'epoques de l'apprentissage
         * \param ep le nombre d'epoques de l'apprentissage
         */
        void setNbEpoques(int ep);

        /**
         * \fn void setTauxApprentissage(double ta)
         * \brief Met a jour le taux d'apprentissage du reseau
         * \param ta le taux d'apprentissage
         */
        void setTauxApprentissage(double ta);


};

#endif