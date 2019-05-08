#ifndef __BOITE_HPP__
#define __BOITE_HPP__

#include <gtkmm.h>
#include <gtkmm/frame.h>
#include <string>
 

/** 
 * \class Boite
 * \brief Composant graphique abstrait qui contient des composants propres propres au type de boite.
 * \author Samra
 * \version 1.0 
 * \date avril 2019
 *
 *
 * Cette classe hérite de gtkmm::Frame.
 */

class Boite : public Gtk::Frame {

    public :

        /**
         * \brief Constructeur d'une boite avec un nom 
         */
        Boite(std::string nom);
	//Boite();


};

#endif
