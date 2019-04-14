#include <Tenseur.hpp>
#include <DimTenseur.hpp>
#include <CoucheCombinaison.hpp>

#ifndef __COUCHE_CONNECTEE_HPP__
#define __COUCHE_CONNECTEE_HPP__

/** 
 * \class CoucheConnectée
 * \brief Création d'une couche connectée
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Classe permettant la création d'une couche de combinaison de "type" connectée : tous les neurones sont reliés d'une couche à une autre.
 * Cette classe hérite de la classe CoucheCombinaison.
 */

class CoucheConnectee
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
