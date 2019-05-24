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

        /** \brief fréquence d'affichage du résultat de la propagation dans le réseau de neurones */
        int freq_affichage;

        /** \brief fréquence de sauvegarde du réseau de neurones */
        int freq_sauvegarde;

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
         * \return le taux d'apprentissage         * 
         */
        double getTauxApprentissage();

        /**
         * \fn int getFreqAffichage()
         * \brief Retourne la fréquence à laquelle sera afficher le résultat de la propagation du réseau de neurones
         * \return fr la fréquence d'affichage
         */
        int getFreqAffichage();

        /**
         * \fn int getFreqSauvegarde()
         * \brief Retourne la fréquence à laquelle sera sauvegarder le réseau de neurones
         * \return fr la fréquence de sauvegarde
         */
        int getFreqSauvegarde();

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

        /**
         * \fn void setFreqAffichage(int fr)
         * \brief Met a jour le nombre d'itérations avant affichage
         * \param fr la fréquence d'affichage
         */
        void setFreqAffichage(int fr);

        /**
         * \fn void setFreqSauvegarde(int fr)
         * \brief Met a jour le nombre d'itérations avant de sauvegarder le réseau de neurones
         * \param fr la fréquence de sauvegarde
         */
        void setFreqSauvegarde(int fr);

};

#endif