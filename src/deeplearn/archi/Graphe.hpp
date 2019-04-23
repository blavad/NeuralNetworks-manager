#ifndef __GRAPHE_HPP__
#define __GRAPHE_HPP__

#include <vector>
#include <iostream>

/**
 * \class Graphe
 * \tparam Type Type de noeud du graphe.
 * \brief Gestion du type Graphe.
 * \author David, Coralie
 * \version 1.0
 * \date avril 2019
 *
 * Module permettant l'utilisation d'un graphe orienté générique.
 * Les noeuds du graphe portent cette généricité et peuvent donc être de n'importe quel type de données.
 *
 */
template <class Type>
class Graphe {

    private :
        /** \brief La liste dynamique d'adjacence. */
        std::vector<std::pair<Type, std::vector<Type>>> list_adj;

        /** \brief La liste dynamique d'antécédence. */
        std::vector<std::pair<Type, std::vector<Type>>> list_ant;

    public :

        /**
         * \brief Constructeur de graphe vide.
         */
        Graphe();

        /**
         * \brief Constructeur de graphe à partir de noeuds isolés.
         */
        Graphe(Type* noeuds);
        
        /**
         * \brief Récupère list_adj
         */
        std::vector<std::pair<Type, std::vector<Type>>> getListAdj();
        
        /**
         * \brief Récupère list_ant
         */
        std::vector<std::pair<Type, std::vector<Type>>> getListAnt();     
        
        /**
         * \brief Récupère la kième paire de list_adj
         */
        std::pair<Type, std::vector<Type>> getPairAdj(int k);
        
        /**
         * \brief Récupère la kième paire de list_ant
         */
        std::pair<Type, std::vector<Type>> getPairAnt(int k);
        
        /**
         * \brief Récupère le premier élément de la kième paire de list_adj
         */
        Type getNoeudAdj(int k);
        
        /**
         * \brief Récupère le premier élément de la kième paire de list_ant
         */
        Type getNoeudAnt(int k);
        
        /**
         * \brief Récupère le deuxième élément de la kième paire de list_adj
         */
        std::vector<Type> getListNoeudAdj(int k);
        
        /**
         * \brief Récupère le deuxième élément de la kième paire de list_ant
         */
        std::vector<Type> getListNoeudAnt(int k);

        /**
         * \fn void ajouterNoeud(Type noeud)
         * \brief Ajout d'un noeud.
         * \param noeud un noeud du graphe.
         */
        void ajouterNoeud(Type noeud);

         /**
         * \fn void ajouterArc(Type noeud_init,Type noeud_final)
         * \brief Ajout d'un arc.
         * \param noeud_init le noeud de départ de l'arc.
         * \param noeud_final le noeud d'arrivé de l'arc.
         */
        void ajouterArc(Type noeud_init,Type noeud_final);

        /**
         * \fn void supprimerNoeud(Type noeud)
         * \brief Suppression d'un noeud.
         * \param noeud un noeud du graphe.
         */
        void supprimerNoeud(Type noeud);

        /**
         * \fn void supprimerArc(Type noeud_init,Type noeud_final)
         * \brief Suppression d'un arc.
         * \param noeud_init le noeud de départ de l'arc.
         * \param noeud_final le noeud d'arrivé de l'arc.
         */
        void supprimerArc(Type noeud_init,Type noeud_final);

        /**
         * \fn bool contientCycle()
         * \brief Teste si le graphe contient un cycle.
         * \return un booléen.
         */
        bool contientCycle();

        /**
         * \fn bool estConnexe()
         * \brief Teste si le graphe est connexe.
         * \return un booléen.
         */
        bool estConnexe();
};


#endif

