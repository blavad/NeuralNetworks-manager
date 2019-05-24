#ifndef __APPRENTISSAGE_HPP__
#define __APPRENTISSAGE_HPP__

#include "../archi/ReseauNeurones.hpp"
#include "Optimisateur.hpp"
#include "Erreur.hpp"
#include "Donnees.hpp"
#include "Donnee.hpp"
#include "ParametresApprentissage.hpp"
#include "ErreurL1.hpp"

/** 
 * \class Apprentissage 
 * \brief Gère l'apprentissage automatique des paramètres du réseau de neurones.
 * \author Marion
 * \version 1.0 
 * \date avril 2019
 *
 * Module permettant le lancement de l'apprentissage.
 * Il permet également la récupération des données et paramètres d'apprentissage.
 * 
 * 
 */
class Apprentissage
{

private:
    /** \brief le reseau de neurones qui va apprendre */
    ReseauNeurones *rn;

    /** \brief l'optimisateur choisi */
    Optimisateur opt;

    /** \brief  l'erreur commise a la fin de l'apprentissage */
    Erreur *err;

    /** \brief les donnees utilisees pour l'apprentissage */
    Donnees donnees;

    /** \brief les parametres d'apprentissages qui definissent la facon d'apprendre */
    ParametresApprentissage param;

public:
    /**
     * \brief Constructeur d'une session d'apprentissage vide.
     */
    Apprentissage();

    Apprentissage(ReseauNeurones *reseauN);
    /**
     * \brief Contructeur d'une session d'apprentissage avec un reseau de neurones et une erreur donnes.
     */
    Apprentissage(ReseauNeurones *reseauN, Erreur *erreur);
    /**
     * \fn void apprendre()
     * \brief Lance l'apprentissage.
     */
    void apprendre();
    /**
     * \fn ReseauNeurones getRN()
     * \brief Recupere le reseau de neurones
     * \return le reseau de neurones.'         * 
     */
    ReseauNeurones *getRN();
    /**
     * \fn Optimisateur getOptimisateur()
     * \brief Recupere l'optimisateur.
     * \return l'optimisateur.'
     */
    Optimisateur getOptimisateur();
    /**
     * \fn Erreur getErreur()
     * \brief Recupere l'erreur
     * \return l'erreur.       * 
     */
    Erreur *getErreur();
    /**
     * \fn Donnes getDonnees()
     * \brief Recupere les donnees d'apprentissage.
     * \return les données d'apprentissage.
     */
    Donnees& getDonnees();
    /**
     * \fn ParametresApprentissage getParam()
     * \brief Recupere les parametres d'apprentissage du reseau.
     * \return les parametres d'apprentissage actuels.
     */
    ParametresApprentissage getParam();
    /**
     * \fn void setRN(ReseauNeurones *rn)
     * \brief Met à jour le reseau
     * \param rn un pointeur sur le reseau
     */
    void setRN(ReseauNeurones *res);
    /**
     * \fn void setErreur(Erreur *err)
     * \brief Met à jour l'erreur
     * \param err un pointeur sur l'erreur
     */
    void setErreur(Erreur *err);
    /**
     * \fn void setOptimisateur(Optimisateur optimisateur)
     * \brief Met a jour l'optimisateur.
     * \param optimisateur l'optimisateur de l'apprentissage.
     */
    void setOptimisateur(Optimisateur optimisateur);
    /**
     * \fn void setDonnees(Donnees d)
     * \brief Met a jour les donnees de l'apprentissage.
     * \param d les donnees de l'apprentissage.
     */
    void setDonnees(Donnees d);
    /**
     * \fn void setParam(ParametresApprentissage paramApp)
     * \brief Met a jour les parametres d'apprentissage du reseau de neurones.
     * \param paramApp les parametres d'apprentissage.
     */
    void setParam(ParametresApprentissage paramApp);
};

#endif
