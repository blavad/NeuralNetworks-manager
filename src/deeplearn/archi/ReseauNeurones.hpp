#include <vector>
#include <Graphe.hpp>
#include <Couche.hpp>
#include <Tenseur.hpp>

#ifndef __RESEAUNEURONES_HPP__
#define __RESEAUNEURONES_HPP__


/** 
 * \class ReseauNeurones
 * \brief Classe liée à la création du réseau de neurones.
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Cette classe permet de créer un réseau de neurones : on peut ajouter/supprimer des couches/noeuds/arcs. 
 * Cette classe hérite de Graphe et de Couche.
 */

class ReseauNeurones {

    private :
        /** \brief La liste correspondant à la première couche du réseau */
        vector<Couche> couche_initiale;

        /** \brief La liste correspondant à la dernière couche du réseau */
        vector<Couche> couche_finale;

	/** \brief Le nom du réseau*/
	string nom;

    public :

        /**
         * \brief Constructeur du réseau vide.
         */
        ReseauNeurones();

        /**
         * \brief Constructeur du réseau à partir de couches déjà crées. 
         */
        Graphe(Couche);

  	/**
         * \fn Tenseur propagation(Tenseur t)
         * \brief Méthode permettant la propagation du réseau d'une étape à une autre.
         * \param t le tenseur
	 * \return Le tenseur à l'étape d'après
         */
        Tenseur propagation(Tenseur t);

         /**
         * \fn void ajouterCoucheInitiale(Couche c)
         * \brief Ajout de la couche initiale.
         * \param c une couche déjà créée.

         */
       void ajouterCoucheInitiale(Couche c)

        /**
         * \fn void ajouterCoucheFinale(Couche c)
         * \brief Ajout de la couche finale.
         * \param c une couche déjà créée.

         */
       void ajouterCoucheFinale(Couche c)

        /**
         * \fn void supprimerCoucheInitiale(Couche c)
         * \brief Suppression de la couche initiale.
         * \param c une couche présente dans le réseau.

         */
       void supprimerCoucheInitiale(Couche c)

        /**
         * \fn void supprimerCoucheFinale(Couche c)
         * \brief Suppression de la couche finale.
         * \param c une couche présente dans le réseau.

         */
       void supprimerCoucheFinale(Couche c)

};
#endif
