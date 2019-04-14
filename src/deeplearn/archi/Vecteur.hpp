#ifndef __VECTEUR_HPP__
#define __VECTEUR_HPP__

#include <Tenseur.hpp>

/** 
 * \class Vecteur
 * \brief Classe qui crée un vecteur
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Classe qui crée un tenseur d'ordre 1 (= vecteur)
 *
 */

class Vecteur : public Tenseur {
 
    public :
        /**
         * \brief Constructeur d'un vecteur de longueur l
         */
        Vecteur(int l);

};

#endif
