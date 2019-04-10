#include <DimTenseur.hpp>

#ifndef __TENSEUR_HPP__
#define __TENSEUR_HPP__


/** 
 * \class ReseauNeurones
 * \brief Classe liée à la création d'un tenseur
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Cette classe permet de créer un tenseur de la taille souhaitée.
 * On peut initialiser un tenseur de trois façons différentes (uniforme,nulle,gaussienne).
 */

class ReseauNeurones {

    private :
        /** \brief  */
        void* valeur;

        /** \brief Dimension du tenseur */
        DimTenseur dim;


    public :

        /**
         * \brief Constructeur d'un tenseur dont la taille est fixée grâce à des entiers. 
         */
        Tenseur(int dim,..);
 
        /**
         * \brief Constructeur d'un tenseur dont la taille est fixée grâce à un objet DimTenseur. 
         */
        Tenseur(DimTenseur dim);


         /**
         * \fn void initValeurGaussienne()
         * \brief Initialisation du tenseur selon une loi gaussienne

         */
       void initValeurGaussienne()

        /**
         * \fn void initValeurNulle()
         * \brief Initialisation du tenseur avec des valeurs nulles

         */
       void initValeurNulle()

        /**
         * \fn void initValeurUnif()
         * \brief Initialisation du tenseur selon une loi uniforme

         */
       void initValeurUnif()

};
       
#endif
