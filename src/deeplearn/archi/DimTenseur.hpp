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

  protected:
    /** \brief La liste des dimensions du tenseur */
    std::vector<int> dim;

  public:
    /**
     * \brief Constructeur standard.
     */
    DimTenseur(std::vector<int> di);

    /**
     *  \fn bool operator==(const DimTenseur t2)
     *  \param t2 le tenseur à comparer
     *  \return booleen
     */
    bool operator==(const DimTenseur t2);

    /**
     * \fn int getOrdre()
     * \brief Méthode pour obtenir l'ordre du tenseur
     * \return l'ordre du tenseur
     */
    int getOrdre();

    /**
     * \fn int getDim(int)
     * \brief Méthode pour obtenir la i ème dimension d'un tenseur
     * \return la i ème dimension du tenseur
     */
    int getDim(int);

    /**
     * \fn std::vector<int> getDims()
     * \brief Méthode pour obtenir les dimensions d'un tenseur
     * \return le vecteur de dimensions
     */
    std::vector<int> getDims();
};

#endif
