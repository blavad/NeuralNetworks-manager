#include <DimTenseur.hpp>
#include <Tenseur.hpp>

#ifndef __COUCHE_HPP__
#define __COUCHE_HPP__


/** 
 * \class Couche
 * \brief Classe liée à la couche.
 * \author Adrien
 * \version 1.0 
 * \date avril 2019
 *
 * Cette classe permet de fixer les tailles (entrée/sortie) de la couche.
 * Une couche peut êter dérivée et propagée.
 */

class Couche {

    private :
        /** \brief La dimension du tenseur à l'entrée de la couche */
        DimTenseur dim_in;

        /** \brief La dimension du tenseur à la sortie de la couche */
        DimTenseur dim_out;

    public :

        /**
         * \brief Constructeur d'une couche à partir de la taille des tenseurs d'entrée/sortie
         */
        Couche(DimTenseur di, DimTenseur do);

  	/**
         * \fn virtual Tenseur propagation(Tenseur t)
         * \brief Méthode virtuelle permettant la propagation d'une couche à une autre.
         * \param t le tenseur
	 * \return Le tenseur à l'étape d'après
         */
        virtual Tenseur propagation(Tenseur t);

         /**
         * \fn virtual void derivee(Tenseur t)
         * \brief Méthode virtuelle pour avoir la derivee de la couche
         * \param t le tenseur pour lequel on veut la derivee
         */
        virtual Tenseur derivee(Tenseur t);

 	/**
         * \fn void setDimInput(DimTenseur dimIn)
         * \brief Méthode pour fixer la taille du tenseur à l'entrée de la couche
         * \param dimIn La dimension du tenseur d'entrée
         */
        void setDimInput(DimTenseur dimIn);

 	/**
         * \fn void setDimOutput(DimTenseur dimOut)
         * \brief Méthode pour fixer la taille du tenseur à la sortie de la couche
         * \param dimIn La dimension du tenseur de sortie
         */
        void setDimOutput(DimTenseur dimOut);
 	
 	/**
         * \fn DimTenseur getDimInput()
         * \brief Méthode pour obtenir la taille du tenseur à l'entrée de la couche
         * \return La taille du tenseur d'entrée
         */
        DimTenseur getDimInput();

 	/**
         * \fn DimTenseur getDimOutput()
         * \brief Méthode pour obtenir la taille du tenseur à la sortie de la couche
         * \return La taille du tenseur de sortie
         */
        DimTenseur getDimOutput();

	/**
         * \fn string getNom()
         * \brief Méthode pour obtenir le nom de la couche
         * \return Le nom de la couche
         */
        string getNom();

	/**
         * \fn virtual bool afficher()
         * \brief Méthode pour savoir si la couche est affichée ou non
         * \return booléen
         */
        virtual bool afficher();

};
#endif
