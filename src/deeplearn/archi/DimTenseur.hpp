#ifndef __DIM_TENSEUR_HPP__
#define __DIM_TENSEUR_HPP__

#include <vector>
#include <string>
#include <ostream>

/** 
 * \class DimTenseur
 * \brief Classe qui gere la dimension d'un tenseur.
 * \author Adrien
 * \author David
 * \version 1.0 
 * \date avril 2019
 *
 * Classe stockant les dimensions d'un tenseur.
 * La dimension d'un tenseur est représentée comme une suite de dimensions dans chaque direction.
 * 
 */

class DimTenseur
{

protected:
   /** \brief la liste des dimensions du tenseur */
   std::vector<int> dim;

public:
   /**
     * \brief Constructeur par défault.
     */
   DimTenseur();

   /**
     * \brief Constructeur standard.
     * \param di la liste des dimensions
     */
   DimTenseur(std::vector<int> di);

   /**
     *  \fn bool operator=(const DimTenseur &dimT)
     *  \brief Affectation de dimensions tensorielles  
     *  \param dimT la dimension tensorielle à affecter
     *  \return booleen
     */
   DimTenseur &operator=(const DimTenseur &dimT);
   DimTenseur &operator=(std::vector<int> &dimT);

   /**
     *  \fn bool operator==(const DimTenseur dimT)
     *  \brief Compare des dimensions tensorielles  
     *  \param dimT la dimension tensorielle à comparer
     *  \return booleen
     */
   bool operator==(const DimTenseur &dimT) const;

   /**
   *  \fn bool operator!=(const DimTenseur dimT)
   *  \brief Compare des dimensions tensorielles
   *  \param dimT la dimension tensorielle à comparer
   *  \return booleen
   */
   bool operator!=(const DimTenseur &dimT) const;

   DimTenseur operator+(const DimTenseur dt);

   friend std::ostream &operator<<(std::ostream &os, DimTenseur &t);

   /**
     * \fn int getOrdre()
     * \brief Méthode pour obtenir l'ordre du tenseur
     * \return l'ordre du tenseur
     */
   int getOrdre() const;

   /**
     * \fn int getDim(int)
     * \brief Méthode pour obtenir la i ème dimension d'un tenseur
     * \param i la dimension souhaitée
     * \return la i ème dimension du tenseur
     */
   int getDim(int) const;

   /**
     * \fn std::vector<int> getDims()
     * \brief Méthode pour obtenir les dimensions d'un tenseur
     * \return le vecteur de dimensions
     */
   std::vector<int> getDims() const;

   /**
   * \fn int getTaille()
   * \brief Récupère le nombre de valeurs présentent dans le tenseur
   */
   int getTaille() const;

   /**
   * \fn std::string toString()
   * \brief Récupère les dimensions sous forme de string
   */
   std::string toString();
};

#endif
