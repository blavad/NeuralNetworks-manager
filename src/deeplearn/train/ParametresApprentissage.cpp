#include "ParametresApprentissage.hpp"

ParametresApprentissage::ParametresApprentissage()
{
}

int ParametresApprentissage::getNbEpoques()
{
	return nb_epoques;
}

double ParametresApprentissage::getTauxApprentissage()
{
	return taux_apprentissage;
}

int ParametresApprentissage::getFreqAffichage()
{
	return freq_affichage;
}

int ParametresApprentissage::getFreqSauvegarde()
{
	return freq_sauvegarde;
}

void ParametresApprentissage::setNbEpoques(int ep)
{
	nb_epoques = ep;
}

void ParametresApprentissage::setTauxApprentissage(double ta)
{
	taux_apprentissage = ta;
}

void ParametresApprentissage::setFreqAffichage(int fr)
{
	freq_affichage = fr;
}

void ParametresApprentissage::setFreqSauvegarde(int fr)
{
	freq_sauvegarde = fr;
}
