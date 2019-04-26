#include "TestPretraitement.hpp"

void TestPretraitement::testChargerDonnees()
{
	Donnees d;
	std::string nomDossier = "nomDossierExistant";
	CPPUNIT_ASSERT_NO_THROW(d = Pretraitement::chargerDonnees(nomDossier));

	nomDossier = "nomDossierNonExistant";
	// ajouter l'exception avant d'enlever le commentaire
	//CPPUNIT_ASSERT_THROW(d = Pretraitement::chargerDonnees(nomDossier),FichierInexistantException);
}

void testNormaliser()
{
	std::vector<int> d{6, 3, 12};
	Tenseur t(d);

	t.initValeurUnif();
	testNormaliser(t, -1., 1., 0., 1.);
}

void testDenormaliser()
{
	std::vector<int> d{6, 3, 12};
	Tenseur t(d);

	t.initValeurUnif();
	testDenormaliser(t, 0., 1., 0., 255.);
	testDenormaliser(t, 0., 1., -1., 1.);
	testDenormaliser(t, 0., 1., -10., 0.);
}

void TestPretraitement::testChargerRN()
{
	ReseauNeurones rn;
	std::string nomFichier = "nomFichierExistant";
	CPPUNIT_ASSERT_NO_THROW(rn = Pretraitement::chargerRN(nomFichier));

	nomFichier = "nomFichierNonExistant";
	// ajouter l'exception avant d'enlever le commentaire
	//CPPUNIT_ASSERT_THROW(rn = Pretraitement::chargerRN(nomFichier),FichierInexistantException);
}

void testNormaliser(Tenseur &t, double minNorm, double maxNorm, double minValeur, double maxValeur)
{
	Pretraitement::normaliser(t, minNorm, maxNorm, minValeur, maxValeur);

	int taille = t.getDim().getOrdre();
	std::vector<int> ind(taille, 0);

	double val = t.getValeur(ind);
	bool ok = (val > minNorm) && (val < maxNorm);
	while (t.nextInd(ind) && ok)
	{
		val = t.getValeur(ind);
		ok = (val > minNorm) && (val < maxNorm);
	}

	CPPUNIT_ASSERT(ok);
}

void testDenormaliser(Tenseur &t, double minNorm, double maxNorm, double minValeur, double maxValeur)
{
	Pretraitement::denormaliser(t, minNorm, maxNorm, minValeur, maxValeur);
	int taille = t.getDim().getOrdre();
	std::vector<int> ind(taille, 0);

	double val = t.getValeur(ind);
	bool ok = (val > minNorm) && (val < maxNorm);
	while (t.nextInd(ind) && ok)
	{
		val = t.getValeur(ind);
		ok = (val > minValeur) && (val < maxValeur);
	}

	CPPUNIT_ASSERT(ok);
}
