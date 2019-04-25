#include "TestPretraitement.hpp"

	void TestPretraitement::testChargerDonnees(){
		Donnees d;
		std::string nomDossier = "nomDossierExistant";
		CPPUNIT_ASSERT_NO_THROW(d = Pretraitement::chargerDonnees(nomDossier));
		
		nomDossier = "nomDossierNonExistant";
		// ajouter l'exception avant d'enlever le commentaire
		//CPPUNIT_ASSERT_THROW(d = Pretraitement::chargerDonnees(nomDossier),FichierInexistantException);	
	}
	
	void TestPretraitement::testChargerRN(){
		ReseauNeurones rn;
		std::string nomFichier = "nomFichierExistant";
		CPPUNIT_ASSERT_NO_THROW(rn = Pretraitement::chargerRN(nomFichier));
		
		nomFichier = "nomFichierNonExistant";
		// ajouter l'exception avant d'enlever le commentaire
		//CPPUNIT_ASSERT_THROW(rn = Pretraitement::chargerRN(nomFichier),FichierInexistantException);
	}
	
	void testNormaliser(Tenseur& t, double minNorm, double maxNorm, double minValeur, double maxValeur){
		int taille = t.getDim().getOrdre();
		std::vector<int> ind(taille,0);
		bool pasfin = true;
		bool ok = true;
		while (pasfin && ok){
			if ((t.getValeur(ind)>maxNorm) || (t.getValeur(ind)<minNorm)) ok = false;
			ind = nextIndice(ind);
			if (ind[0]==-1) pasfin=false;
		}
		CPPUNIT_ASSERT(ok);
	}
	
	void testDenormaliser(Tenseur& t, double minNorm, double maxNorm, double minValeur, double maxValeur){
		int taille = t.getDim().getOrdre();
		std::vector<int> ind(taille,0);
		bool pasfin = true;
		bool ok = false;
		while (pasfin && !(ok)){
			if (t.getValeur(ind)>maxNorm) ok = true;
			ind = nextIndice(ind);
			if (ind[0]==-1) pasfin=false;
		}
		CPPUNIT_ASSERT(ok);
	}

 
