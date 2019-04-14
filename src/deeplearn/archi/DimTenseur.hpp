#include <vector>

#ifndef __DIM_TENSEUR_HPP__
#define __DIM_TENSEUR_HPP__

/** 
 * \class DimTenseur
 * \brief Classe stockant les dimensions d'un tenseur.
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Classe qui gère la dimension d'un tenseur
 * 
 */

class DimTenseur
{
  private:
    /** \brief entier correspondant à l'ordre du tenseur  */
    int ordre;

    /** \brief La liste des dimensions du tenseur */
    std::vector<int> dim;

  public:
    /**
     * \brief Constructeur avec d'obtenir la dimension souhaitée.
     */
    DimTenseur(int dim, ...);
};

#endif
