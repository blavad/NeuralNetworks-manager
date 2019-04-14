#ifndef __COUCHE_COMBINAISON_HPP__
#define __COUCHE_COMBINAISON_HPP__

#include <Couche.hpp>
#include <Tenseur.hpp>
#include <DimTenseur.hpp>

/** 
 * \class CoucheCombinaison
 * \brief Gestion d'une couche de combinaison
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Classe permettant la création d'une couche de combinaison c'est-à-dire comportant les parametres du reseau
 * 
 */

class CoucheCombinaison : public Couche
{

  private:
    /** \brief Le tenseur "décrivant" la couche */
    Tenseur params;

  public:
    /**
     * \fn Tenseur getParams()
     * \brief getter des parametres de la couche.
     * \return les parametres de la couche
     */
    Tenseur getParams();
};

#endif
