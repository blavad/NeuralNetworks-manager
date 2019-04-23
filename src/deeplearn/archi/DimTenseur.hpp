#ifndef __DIM_TENSEUR_HPP__
#define __DIM_TENSEUR_HPP__

#include <vector>

/** 
 * \class DimTenseur
 * \brief Classe stockant les dimensions d'un tenseur.
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Classe qui gere la dimension d'un tenseur
 * 
 */


class DimTenseur 
{
 

    private :
        /** \brief Entier correspondant à l'ordre du tenseur  */
        int ordre;

        /** \brief La liste des dimensions du tenseur */
        std::vector<int> dim;




    public :


        /**
         * \brief Constructeur standard.
         */
        DimTenseur();



        /**
         * \brief Constructeur avec d'obtenir la dimension souhaitée.
         */
        DimTenseur(int ord, std::vector<int> di);



         /**
         * \fn int getOrdre()
         * \brief Méthode pour obtenir l'ordre du tenseur
         * \return l'ordre du tenseur
         */
        int getOrdre();



         /**
         * \fn DimTenseur getDim()
         * \brief Méthode pour obtenir la liste des dimensions du tenseur
         * \return la liste des dimensions du tenseur
         */
        std::vector<int> getDim();



};

#endif
