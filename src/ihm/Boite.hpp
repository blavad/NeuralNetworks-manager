#ifndef __BOITE_HPP__
#define __BOITE_HPP__

#include <gtkmm.h>
#include <gtkmm/frame.h>
#include <string>
 
 using namespace std;

/** 
 * \class Boite
 * \brief Composant graphique abstrait qui contient des composants propres propres au type de boite.
 * \author Samra
 * \version 1.0 
 * \date avril 2019
 *
 *
 * Cette classe hérite de gtkmm::Frame. Elle contient un nom des des composants graphiques dépendants du type de boite.
 */

class Boite : public Frame {

    private :
        /** 
	     * \brief Le nom de la boite 
         */
        string nom;


    public :

        /**
         * \brief Constructeur d'une boite avec un nom 
         */
        Boite(string nom);

};
#endif
