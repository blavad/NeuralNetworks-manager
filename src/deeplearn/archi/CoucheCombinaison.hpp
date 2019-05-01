#ifndef __COUCHE_COMBINAISON_HPP__
#define __COUCHE_COMBINAISON_HPP__

#include "Couche.hpp"
/** 
 * \class CoucheCombinaison
 * \brief Classe abstraite définissant les couches de combinaisons.
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Classe permettant la création d'une couche de combinaison c'est-à-dire comportant les paramètres du reseau
 * 
 */

class CoucheCombinaison : public Couche
{

  protected:
    /** \brief Le tenseur "décrivant" la couche */
    Tenseur params;

  public:

    /**
     * \brief Constructeur d'une couche à partir de la taille des tenseurs d'entrée/sortie
     * \param no nom de la couche  
     * 
    */
    CoucheCombinaison(std::string no="Combinaison");

    /**
     * \brief Constructeur d'une couche à partir de la taille des tenseurs d'entrée/sortie
     * \param din dimension des entrées de la couche 
     * \param dout dimension des sorties de la couche 
     * \param no nom de la couche  
     * 
    */
    CoucheCombinaison(DimTenseur din, DimTenseur dout, std::string no="Combinaison");


    /**
     * \fn void setParams()
     * \brief setter les parametres de la couche.
     */
    void setParams(Tenseur nouvParams);


    /**
     * \fn Tenseur getParams()
     * \brief getter des parametres de la couche.
     * \return les parametres de la couche
     */
    Tenseur getParams();

    /**
     * \fn void update(Tenseur t)
     * \brief Met à jour les paramètres
     * \param t les parametres mis a jour
     */
    void update(Tenseur t);

};

#endif
