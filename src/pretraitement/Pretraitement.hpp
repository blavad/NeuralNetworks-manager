#ifndef __PRETRAITEMENT_HPP__
#define __PRETRAITEMENT_HPP__

#include "../deeplearn/train/Donnees.hpp"
#include "../deeplearn/archi/ReseauNeurones.hpp"
#include "../deeplearn/archi/Tenseur.hpp"
#include <string>

#include "Magick++.h"

/** 
 * \class Pretraitement
 * \brief Gère le pretraitement des donnees necessaires a l'apprentissage
 * \author Marion
 * \version 1.0 
 * \date avril 2019
 *
 * Module permettant le pretraitement des donnees necessaires avant l'apprentissage.
 * 
 */
class Pretraitement
{

public:
     Pretraitement();

     /**
         * \fn static Donnees chargerDonnees(string nomDossier)
         * \brief Charge les donnees du dossier
         * \param nomDossier le nom du dossier dans lequel se trouve les donnees a recuperer
         */
     Donnees chargerDonnees(std::string nomDossier);

     /**
         * \fn static ReseauNeurones chargerRN(string nomFichier)
         * \brief Charge le reseau de neurones contenu dans un fichier
         * \param nomFichier le nom du fichier dans lequel se trouve le reseau de neurones a recuperer
         */
     ReseauNeurones chargerRN(std::string nomFichier);

     /**
         * \fn static Tenseur imageToTenseur(string nomFichier)
         * \brief Transforme l'image d'entree en un tenseur
         * \param nomFichier le nom du fichier image a transformer en tenseur
         * \param longueur la longueur de l'image redimensionnée
         * \param largeur la largeur de l'image redimensionnée
         * \param couleur vrai si l'image est en couleur
         */
     Tenseur &imageToTenseur(std::string nomFichier, int longueur = 100, int largeur = 100, bool couleur = true);

     /**
         * \fn static Tenseur csvToTenseur(string nomFichier)
         * \brief Transforme un fichier csv en tenseur
         * \param nomFichier le nom du fichier csv a transformer en tenseur 
         */
     Tenseur csvToTenseur(std::string nomFichier);

     /**
         * \fn static void normaliser(Tenseur& t, double minNorm, double maxNorm, double minValeur, double maxValeur)
         * \brief Normalise le tenseur passe en entree en fonction des autres parametres
         * \param t le tenseur a normalise
         * \param minNorm la norme minimale
         * \param maxNorm la norme maximale
         * \param minValeur la valeur minimale
         * \param maxValeur la valeur maximale
         */
     void normaliser(Tenseur &t, double minNorm, double maxNorm, double minValeur, double maxValeur);

     /**
         * \fn static void denormaliser(Tenseur& t, double minNorm, double maxNorm, double minValeur, double maxValeur)
         * \brief Denormalise le tenseur passe en entree en fonction des autres parametres
         * \param t le tenseur a normalise
         * \param minNorm la norme minimale
         * \param maxNorm la norme maximale
         * \param minValeur la valeur minimale
         * \param maxValeur la valeur maximale
         */
     void denormaliser(Tenseur &t, double minNorm, double maxNorm, double minValeur, double maxValeur);
};

#endif
