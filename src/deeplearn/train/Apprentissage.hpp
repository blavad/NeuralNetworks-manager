#ifndef __APPRENTISSAGE_HPP__
#define __APPRENTISSAGE_HPP__

#include "../archi/ReseauNeurones.hpp"
#include "Erreur.hpp"
#include "Donnees.hpp"
#include "Donnee.hpp"
#include "ParametresApprentissage.hpp"
#include "ErreurL1.hpp"
#include "../../pretraitement/Pretraitement.hpp"

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
 */
class Apprentissage
{

private:
    /** \brief Le reseau de neurones qui va apprendre */
    ReseauNeurones *rn;

    /** \brief  L'erreur commise a la fin de l'apprentissage */
    Erreur *err;

    /** \brief Les données utilisées pour l'apprentissage */
    Donnees donnees;

    /** \brief Les paramètres d'apprentissages qui definissent la facon d'apprendre */
    ParametresApprentissage param;

    /** \brief Un booléen pour savoir si l'apprentissage est en cours */
    bool enCours;

public:
    /**
     * \brief Constructeur d'une session d'apprentissage vide
     */
    Apprentissage();

    /**
     * \brief Constructeur d'une session d'apprentissage avec un réseau de neurones
     */
    Apprentissage(ReseauNeurones *reseauN);

    /**
     * \brief Contructeur d'une session d'apprentissage avec un reseau de neurones et une erreur donnée
     */
    Apprentissage(ReseauNeurones *reseauN, Erreur *erreur);

    /**
     * \fn void apprendre()
     * \brief Lance l'apprentissage
     */
    void apprendre();

    /**
     * \fn void chargerDonnees()
     * \brief Charge les donnees
     * \param couleur Booleen pour savoir si on est en couleur ou en noir et blanc
     */
    void chargerDonnees(bool couleur = true);

    /**
     * \fn void stop()
     * \brief Arrete l'apprentissage si celui ci est en cours
     */
    void stop();

    /**
     * \fn ReseauNeurones getRN()
     * \brief Récupére le reseau de neurones
     * \return Le réseau de neurones
     */
    ReseauNeurones *getRN();

    /**
     * \fn Erreur getErreur()
     * \brief Récupére l'erreur
     * \return L'erreur
     */
    Erreur *getErreur();

    /**
     * \fn Donnees getDonnees()
     * \brief Récupère les données d'apprentissage
     * \return Les données d'apprentissage
     */
    Donnees &getDonnees();

    /**
     * \fn ParamètresApprentissage getParam()
     * \brief Récupère les paramètres d'apprentissage du reseau
     * \return Les paramètres d'apprentissage actuels
     */
    ParametresApprentissage getParam();

    /**
     * \fn void setRN(ReseauNeurones *rn)
     * \brief Met à jour le reseau
     * \param rn Un pointeur sur le reseau
     */
    void setRN(ReseauNeurones *res);

    /**
     * \fn void setErreur(Erreur *err)
     * \brief Met à jour l'erreur
     * \param err Un pointeur sur l'erreur
     */
    void setErreur(Erreur *err);

    /**
     * \fn void setDonnees(Donnees d)
     * \brief Met a jour les données de l'apprentissage
     * \param d Les données de l'apprentissage
     */
    void setDonnees(Donnees d);

    /**
     * \fn void setParam(ParametresApprentissage paramApp)
     * \brief Met a jour les paramètres d'apprentissage du réseau de neurones
     * \param paramApp Les paramètres d'apprentissage
     */
    void setParam(ParametresApprentissage paramApp);
};

#endif
