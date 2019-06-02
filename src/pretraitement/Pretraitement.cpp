#include "Pretraitement.hpp"
#include <stdio.h>
#include <vector>

using namespace Magick;

Pretraitement::Pretraitement()
{
}

Donnees Pretraitement::chargerDonnees(std::string nomDossier)
{
}

ReseauNeurones Pretraitement::chargerRN(std::string nomFichier)
{
}

Tenseur *Pretraitement::imageToTenseur(std::string nomFichier, int longueur, int hauteur, bool couleur)
{
	try
	{

		Image img(nomFichier);
		// img.resize(to_string(longueur) + "x" + to_string(hauteur));
		img.crop(Geometry(longueur, hauteur, 0, 0));
		if (!couleur)
		{
			img.type(GrayscaleType);
		}

		Tenseur *t;
		if (couleur)
			t = new Tenseur({longueur, hauteur, 3});
		else
			t = new Tenseur({longueur, hauteur});
		for (int l = 0; l < longueur; l++)
		{
			for (int h = 0; h < hauteur; h++)
			{
				if (couleur)
				{
					ColorRGB *pix = new ColorRGB();
					*pix = img.pixelColor(l, h);
					t->setValeur(pix->red(), {l, h, 0});
					t->setValeur(pix->green(), {l, h, 1});
					t->setValeur(pix->blue(), {l, h, 2});
				}
				else
				{
					ColorGray *pix = new ColorGray();
					pix = new ColorGray();
					*pix = img.pixelColor(l, h);
					t->setValeur(pix->shade(), {l, h});
				}
			}
		}
		return t;
	}
	catch (...)
	{
		cerr << "Exception"<< endl;
		return NULL;
	}
}

Tenseur Pretraitement::csvToTenseur(std::string nomFichier)
{
}

void Pretraitement::normaliser(Tenseur &t, double minNorm, double maxNorm, double minValeur, double maxValeur) {}
void Pretraitement::denormaliser(Tenseur &t, double minNorm, double maxNorm, double minValeur, double maxValeur) {}
