#ifndef __COUCHE_CONNECTEE_HPP__
#define __COUCHE_CONNECTEE_HPP__

#include <Tenseur.hpp>
#include <DimTenseur.hpp>
#include <CoucheCombinaison.hpp>

/** 
 * \class CoucheConnectée
 * \brief Création d'une couche connectee
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Classe permettant la création d'une couche de combinaison de "type" connectée : tous les neurones sont reliés d'une couche à une autre.
 * 
 */

class CoucheConnectee : public CoucheCombinaison
{

  public:
    /**
     * \brief Constructeur d'une couche connectée à partir du nombre de sorties
     */
    CoucheConnectee(int nb_out);

    /**
     * \fn Tenseur propagation(Tenseur t)
     * \brief Methode permettant la propagation d'une couche à une autre.
     * \param t le tenseur d'entree
	 * \return la sortie de la couche
     */
    Tenseur propagation(Tenseur t);
};

#endif
