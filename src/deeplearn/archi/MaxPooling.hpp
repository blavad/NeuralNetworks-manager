#ifndef __MAX_POOLING_HPP__
#define __MAX_POOLING_HPP__

#include "Couche.hpp"

/**
 * \class MaxPooling
 * \brief Classe gérant une couche de MaxPooling.
 * \author David
 * \version 2.0
 * \date juin 2019
 *
 * Classe qui va effectuer l'opération de redimensionnement des images par la technique du MaxPooling.
 *
 */
class MaxPooling : public Couche {

    private :
     /** \brief Nombre de pixels dimension 1*/
    int pool_x;

    /** \brief Nombre de pixels dimension 2*/
    int pool_y;

    public :
        /**
         * \brief Constructeur afin d'obtenir une image de taille pool_x par pool_y.
         * \param din : DimTenseur
         * \param no : string
         * \param pl_x : int
         * \param pl_y : int
         */
        MaxPooling(DimTenseur din, std::string no, int pl_x, int pl_y);

       /**
         * \brief Constructeur afin d'obtenir une image de taille pool par pool.
         * \param din : DimTenseur
         * \param no : string
         * \param pl : int
         */
        MaxPooling(DimTenseur din, std::string no, int pl);

	/**
         * \fn Tenseur propagation(Tenseur t)
         * \brief Méthode permettant la propagation d'une couche à une autre.
         * \param t le tenseur
         * \return Le tenseur à l'étape d'après
         */
        Tenseur propagation(Tenseur t);


         /**
         * \fn void setPoolX(int pl_x)
         * \brief Méthode pour fixer le nombre de pixels en dimension x
         * \param pl_x : le nombre de pixels en x
         */
        void setPoolX(int pl_x );

        /**
         * \fn void setPoolY(int pl_y)
         * \brief Méthode pour fixer le nombre de pixels en dimension y
         * \param pl_y : le nombre de pixels en y
         */
        void setPoolY(int pl_y);

        /**
         * \fn int getPoolX()
         * \brief Méthode pour obtenir le nombre de pixels fixé pour les images en dimension x
         * \return Le nombre de pixels en dimension x
         */
        int getPoolX() const;

        /**
         * \fn int getPoolY()
         * \brief Méthode pour obtenir le nombre de pixels fixé pour les images en dimension y
         * \return Le nombre de pixels en dimension y
         */
        int getPoolY() const;

};

#endif
