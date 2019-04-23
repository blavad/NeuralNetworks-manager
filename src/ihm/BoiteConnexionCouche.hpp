
#ifndef __BOITE_CONNEXION_COUCHE_HPP__
#define __BOITE_CONNEXION_COUCHE_HPP__

#include "../deeplearn/archi/Couche.hpp"
#include "Panneau.hpp"
#include "Boite.hpp"
 
 using namespace std;

/** 
 * \class BoiteConnexionCouche
 * \brief Gestion de l'interaction Homme/Machine liée à la liaison entre 2 couches
 * \author Samra
 * \version 1.0 
 * \date avril 2019
 *
 * Module permettant le choix des couches à relier et la mise en place de leur liaison
 * 
 */
class BoiteConnexionCouche : public Boite {

    private :
        /** \brief La couche de depart de la connexion */
        Couche couche_init;

        /** \brief La couche d'arrivée de la connexion */
        Couche couche_finale;

    public :

         /**
         * \fn BoiteConnexionCouche(Panneau parent)
         * \brief Constucteur prenant en paramètre un Panneau
         * \param parent un Panneau contenant déja un réseau de neurones
         */
        BoiteConnexionCouche(Panneau parent);

         /**
         * \fn setCoucheInitiale(Couche couche)
         * \brief Setteur permetant de changer la valeur de la Couche Initiale  
         * \param la nouvelle Couche initiale
         */
        void setCoucheInitiale(Couche couche);

         /**
         * \fn setCoucheFinale(Couche couche)
         * \brief Setteur permetant de changer la valeur de la Couche finale 
         * \param la nouvelle Couche finale
         */
        void setCoucheFinale(Couche couche);

         /**
         * \fn getCoucheInitiale()
         * \brief Getteur permetant d'obtenir la valeur de la Couche Initiale  
	 * \return la Couche c_init en attribut de la classe
         */
        Couche getCoucheInitiale();

         /**
         * \fn getCoucheFinale()
         * \brief getteur permetant d'obtenir la valeur de la Couche Finale 
	 * \return la Couche c_finale en attribut de la classe
         */
        Couche getCoucheFinale();

};

#endif
