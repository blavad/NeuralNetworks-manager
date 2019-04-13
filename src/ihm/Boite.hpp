#include <gtkmm.h>

#ifndef __RESEAUNEURONES_HPP__
#define __RESEAUNEURONES_HPP__


/** 
 * \class Boite
 * \brief Gestion du type Boite
 * \author Samra
 * \version 1.0 
 * \date avril 2019
 *
 *
 * Cette classe hérite de getkmm::Frame
 */

class Boite {

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
