#ifndef __ERREUR_HPP__
#define __ERREUR_HPP__

#include "../archi/Tenseur.hpp"

/** 
 * \class Erreur
 * \brief Gère le calcul de l'erreur commise lors d'un apprentissage.
 * \author Marion
 * \version 1.0 
 * \date avril 2019
 *
 * Module permettant le traitement de l'erreur commise lors d'un apprentissage.
 * Il permet également la récupération des données liées aux erreurs.
 * 
 * 
 */
class Erreur
{

public:
    Erreur();

    /**
     * \fn virtual Tenseur eval(Tenseur sortieRN, Tenseur prediction)
     * \brief Methode virtuelle Pour evaluer l'erreur effectuée entre la sortie et la prédiction
     * \param sortieRN Le tenseur de sortie du reseau de neurones
     * \param label La sortie souhaitée du reseau de neurones
     */
    virtual Tenseur eval(Tenseur sortieRN, Tenseur label);

    /**
     * \fn virtual void derivee(Tenseur t)
     * \brief Méthode virtuelle pour avoir la derivée d'un tenseur donnée en entree
     * \param t Le tenseur pour lequel on veut la derivée
     */
    virtual Tenseur derivee(Tenseur t);
};

#endif
