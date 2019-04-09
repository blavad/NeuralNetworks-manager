#ifndef __PRETRAITEMENT_HPP__
#define __PRETRAITEMENT_HPP__

#include "Donnees.hpp"
#include "ReseauNeurones.hpp"


/** 
 * \class Pretraitement
 * \brief Gère le pretraitement des donnees necessaires a l'apprentissage
 * \author Marion
 * \version 1.0 
 * \date avril 2019
 *
 * Module permettant le pretraitement des donnees necessaires avant l'apprentissage.
 * 
 * 
 */
class Pretraitement {

    public :

        /**
         * \fn static Donnees chargerDonnees(string nomDossier)
         * \brief Charge les donnees du dossier
         * \param nomDossier le nom du dossier dans lequel se trouve les donnees a recuperer
         */
        static Donnees chargerDonnees(string nomDossier);

        /**
         * \fn static ReseauNeurones chargerRN(string nomFichier)
         * \brief Charge le reseau de neurones contenu dans un fichier
         * \param nomFichier le nom du fichier dans lequel se trouve le reseau de neurones a recuperer
         */
        static ReseauNeurones chargerRN(string nomFichier);

        /**
         * \fn static Tenseur imageToTenseur(string nomFichier)
         * \brief Transforme l'image d'entree en un tenseur
         * \param nomFichier le nom du fichier image a transformer en tenseur
         */
        static Tenseur imageToTenseur(string nomFichier);

        /**
         * \fn static Tenseur csvToTenseur(string nomFichier)
         * \brief Transforme un fichier csv en tenseur
         * \param nomFichier le nom du fichier csv a transformer en tenseur 
         */
        static Tenseur csvToTenseur(string nomFichier);

        /**
         * \fn static void normaliser(Tenseur& t, double minNorm, double maxNorm, double minValeur, double maxValeur)
         * \brief Normalise le tenseur passe en entree en fonction des autres parametres
         * \param t le tenseur a normalise
         * \param minNorm la norme minimale
         * \param maxNorm la norme maximale
         * \param minValeur la valeur minimale
         * \param maxValeur la valeur maximale
         */
        static void normaliser(Tenseur& t, double minNorm, double maxNorm, double minValeur, double maxValeur);

        /**
         * \fn static void denormaliser(Tenseur& t, double minNorm, double maxNorm, double minValeur, double maxValeur)
         * \brief Denormalise le tenseur passe en entree en fonction des autres parametres
         * \param t le tenseur a normalise
         * \param minNorm la norme minimale
         * \param maxNorm la norme maximale
         * \param minValeur la valeur minimale
         * \param maxValeur la valeur maximale
         */
        static void denormaliser(Tenseur& t, double minNorm, double maxNorm, double minValeur, double maxValeur);

};

#endif