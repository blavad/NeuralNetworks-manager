#ifndef __MATRICE_HPP__
#define __MATRICE_HPP__

#include "Tenseur.hpp"

/** 
 * \class Matrice
 * \brief Classe qui crée une matrice
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Classe qui crée un tenseur d'ordre 2 (= matrice).
 *
 */

class Matrice : public Tenseur {
 
    public :
        /**
         * \brief Constructeur d'une matrice de taille lxc
         */
        Matrice(void* valeur, int l, int c);

};

#endif
