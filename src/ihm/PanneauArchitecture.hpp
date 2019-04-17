

#ifndef __PANNEAU_ARCHITECTURE_HPP__
#define __PANNEAU_ARCHITECTURE_HPP__


/** 
 * \class PanneauArchitecture 
 * \brief ???
 * \author ???
 * \version 1.0 
 * \date avril 2019
 * 
 * ??? Regroupe les differentes boites ( choix couche, rn,connexion ) dans un même Panneau
 * 
 */
class PanneauArchitecture {

    private :
        /** \brief Boite de choix des couches à travailler */
        BoiteChoixCouche choixCouche;

        /** \brief Boite de choix du Reseau de Neurone à travailler */
        BoiteChoixReseauNeurones choixRN;

        /** \brief Boite de choix du Reseau de Neurone à travailler */
        BoiteConnexionCouche choixConnexion;

    public :

        /**
         * \brief Constructeur du panneau vide.
         */
        Panneau();

        /**
         * \brief Méthode permettant la sauvegarde d'un Reseau de Neurones. 
         */
        void sauvegarderRN();


  	/**
         * \fn void sauvegarderRN(String nomFichier)
         * \brief Méthode permettant la sauvegarde d'un reseau de neurones sous un nom donnée
         * \param nomFichier le nom du fichier en sortie
         */
        void sauvegarderRN(String nomFichier);


    
};

#endif
