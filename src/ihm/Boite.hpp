#ifndef __BOITE_HPP__
#define __BOITE_HPP__

#include <gtkmm.h>
#include <gtkmm/frame.h>
#include <string>
 
 using namespace std;

/** 
 * \class Boite
 * \brief Gestion du type Boite
 * \author Samra
 * \version 1.0 
 * \date avril 2019
 *
 *
 * Cette classe hérite de gtkmm::Frame
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
