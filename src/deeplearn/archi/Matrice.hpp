#include <Tenseur.hpp>

#ifndef __MATRICE_HPP__
#define __MATRICE_HPP__


/** 
 * \class Matrice
 * \brief Classe qui crée une matrice
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Classe qui crée un tenseur de dimension 2 (= matrice)
 * Classe qui hérite de Tenseur.
 *
 */

class Matrice {
 
    public :

        /**
         * \brief Constructeur d'une matrice de taille lxc
         */
        Matrice(int l,int c);

};

#endif
