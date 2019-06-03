#ifndef __DONNEES_HPP__
#define __DONNEES_HPP__

#include <vector>
#include "Donnee.hpp"
#include "../archi/DimTenseur.hpp"

/** 
 * \class Donnees
 * \brief Gère les donnees necessaire a l'apprentissage.
 * \author Adrien
 * \version 2.0 
 * \date juin 2019
 *
 * Module permettant le stockage en memoire vive des données nécessaires à l'apprentissage.
 * 
 */
class Donnees
{

private:
    /** \brief Le vecteur des donnees */
    std::vector<Donnee> donnees;

    /** \brief Type de données (image, CSV, etc) */
    std::string type;

    /** \brief Noms des dossiers où se situent les données */
    std::vector<std::string> dossiers_donnees;

    /** \brief Dimensions des données d'entrée et de sortie */
    DimTenseur dimEntree, dimSortie;

public:
    /**
     * \brief Constructeur des donnees d'apprentissage
     */
    Donnees();

    /**
     * \brief Constructeur des donnees d'apprentissage a partir d'un vecteur de donnees unitaires
     */
    Donnees(std::vector<Donnee> vd);

    /**
     * \fn void ajouterDonnees(Donnees d)
     * \brief Ajoute un ensemble de données
     * \param d L'ensemble des données
     */
    void ajouterDonnees(Donnees d);

    /**
     * \fn void ajouterDonnee(Donnee d)
     * \brief Ajoute une donnée à l'ensemble des données
     * \param d La donnée à ajouter
     */
    void ajouterDonnee(Donnee &d);

    /**
     * \fn void melanger()
     * \brief Mélange les données.
     */
    void melanger();

    /**
     * \fn Donnee getDonnee(int num)
     * \brief Retourne la donnée numero num parmi l'ensemble des donnees
     * \param num Le numero de la donnée
     * \return La donnée en position "num"
     */
    Donnee getDonnee(int num);

    /**
     * \fn std::vector<Donnees> getDonnees()
     * \brief Retourne l'ensemble des données
     * \return le vecteur des données
     */
    std::vector<Donnee> getDonnees();

    /**
     * \fn int getNbDonnees()
     * \brief Retourne le nombre de donnees
     * \return Le nombre de donnees
     */
    int getNbDonnees();

    /**
     * \fn std::string getType()
     * \brief Retourne le type de donnees
     * \return Le type de donnees
     */
    std::string getType();

     /**
     * \fn void setType(std::string t)
     * \brief Modifie le type de données
     * \param Une chaîne
     */
    void setType(std::string t);

     /**
     * \fn std::vector<std::string> getDossierDonnees()
     * \brief Retourne le dossier de données
     * \return Le dossier de données
     */
    std::vector<std::string> getDossiersDonnees();

     /**
     * \fn void setDossierDonnees(std::vector<std::string> d)
     * \brief Modifie le type de données
     * \param d Un vector de chaînes
     */
    void setDossiersDonnees(std::vector<std::string> d);

     /**
     * \fn DimTenseur getDimDonneesEntree()
     * \brief Retourne la dimension d'entrée des données
     * \return La dimension d'entrée des données
     */
    DimTenseur getDimDonneesEntree();
    
     /**
     * \fn void setDimDonneesEntree(DimTenseur d))
     * \brief Modifie la dimension d'entrée des données
     * \param d Une dimension
     */
    void setDimDonneesEntree(DimTenseur d);

    /**
     * \fn DimTenseur getDimDonneesSortie()
     * \brief Retourne la dimension de sortie des données
     * \return La dimension de sortie des données
     */
    DimTenseur getDimDonneesSortie();

     /**
     * \fn void setDimDonneesSortie(DimTenseur d)
     * \brief Modifie la dimension de sortie des données
     * \param d Une dimension
     */
    void setDimDonneesSortie(DimTenseur d);

};

#endif
