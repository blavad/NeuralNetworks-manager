#ifndef __PARAMETRESAPPRENTISSAGE_HPP__
#define __PARAMETRESAPPRENTISSAGE_HPP__


/** 
 * \class ParametresApprentissage 
 * \brief Gère les parametres d'apprentissage du réseau de neurones.
 * \author Adrien
 * \version 2.0 
 * \date juin 2019
 *
 * Module permettant le choix des paramètres de l'apprentissage.
 * Il permet également leur récupération.
 * 
 */
class ParametresApprentissage {

    private :
        /** \brief Nombre d'epoques de l'apprentissage */
        int nb_epoques;

        /** \brief Vitesse d'apprentissage du réseau */
        double taux_apprentissage;

        /** \brief Fréquence d'affichage du résultat de la propagation dans le réseau de neurones */
        int freq_affichage;

        /** \brief Fréquence de sauvegarde du réseau de neurones */
        int freq_sauvegarde;

    public :

        /**
         * \brief Constructeur des paramètres d'apprentissage
         */
        ParametresApprentissage();

        /**
         * \fn int getNbEpoques()
         * \brief Retourne le nombre d'epoques de l'apprentissage
         * \return Le nombre d'epoques
         */
        int getNbEpoques();

        /**
         * \fn double getTauxApprentissage()
         * \brief Retourne le taux d'apprentissage du reseau
         * \return Le taux d'apprentissage
         */
        double getTauxApprentissage();

        /**
         * \fn int getFreqAffichage()
         * \brief Retourne la fréquence à laquelle sera affiché le résultat de la propagation du réseau de neurones
         * \return fr La fréquence d'affichage
         */
        int getFreqAffichage();

        /**
         * \fn int getFreqSauvegarde()
         * \brief Retourne la fréquence à laquelle sera sauvegardé le réseau de neurones
         * \return fr La fréquence de sauvegarde
         */
        int getFreqSauvegarde();

        /**
         * \fn void setNbEpoques(int ep)
         * \brief Met a jour le nombre d'epoques de l'apprentissage
         * \param ep Le nombre d'epoques de l'apprentissage
         */
        void setNbEpoques(int ep);

        /**
         * \fn void setTauxApprentissage(double ta)
         * \brief Met a jour le taux d'apprentissage du reseau
         * \param ta Le taux d'apprentissage
         */
        void setTauxApprentissage(double ta);

        /**
         * \fn void setFreqAffichage(int fr)
         * \brief Met a jour le nombre d'itérations avant affichage
         * \param fr La fréquence d'affichage
         */
        void setFreqAffichage(int fr);

        /**
         * \fn void setFreqSauvegarde(int fr)
         * \brief Met a jour le nombre d'itérations avant de sauvegarder le réseau de neurones
         * \param fr La fréquence de sauvegarde
         */
        void setFreqSauvegarde(int fr);

};

#endif
