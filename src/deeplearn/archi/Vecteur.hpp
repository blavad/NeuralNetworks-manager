#ifndef __VECTEUR_HPP__
#define __VECTEUR_HPP__

#include "Matrice.hpp"

/** 
 * \class Vecteur
 * \brief Module qui permet la manipulation de vecteurs
 * \author Adrien
 * \author David
 * \version 1.0 
 * \date avril 2019
 *
 * Classe qui crée un tenseur d'ordre 1 (= vecteur)
 *
 */

class Vecteur : public Matrice {
 
    public :


        /**
         * \brief Constructeur d'un vecteur de longueur l
         */
        Vecteur(int l);
        
};

#endif
