#include <vector>

#ifndef __DIMTENSEUR_HPP__
#define __DIMTENSEUR_HPP__


/** 
 * \class DimTenseur
 * \brief Classe liée à la dimension d'un tenseur.
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Classe qui va gérer la dimension d'un tenseur
 * 
 */

class MaxPooling {
 

    private :
        /** \brief Entier correspondant à l'ordre du tenseur  */
        int ordre;

        /** \brief La liste des dimensions du tenseur */
        vector<int> dim;

    public :

        /**
         * \brief Constructeur avec d'obtenir la dimension souhaitée.
         */
        DimTenseur(int dim,...);

};

#endif
