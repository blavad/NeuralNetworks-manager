#include "Pretraitement.hpp"
#include <string>

static Donnees chargerDonnees(std::string nomDossier)
{
}

static ReseauNeurones chargerRN(std::string nomFichier)
{
}

static Tenseur imageToTenseur(std::string nomFichier)
{
}

static Tenseur csvToTenseur(std::string nomFichier) {}

static void normaliser(Tenseur &t, double minNorm, double maxNorm, double minValeur, double maxValeur) {}

static void denormaliser(Tenseur &t, double minNorm, double maxNorm, double minValeur, double maxValeur) {}
