#include "Pretraitement.hpp"
#include <stdio.h>
#include "opencv2/opencv.hpp"
#include <vector>

using namespace cv;


static Donnees chargerDonnees(std::string nomDossier)
{
}

static ReseauNeurones chargerRN(std::string nomFichier)
{
}

static Tenseur imageToTenseur(char* nomFichier, int longueur=400, int largeur=400,bool couleur = true)
{
	Tenseur t;
	std::vector<int> dims;
	dims.push_back(longueur);
	dims.push_back(largeur);
	dims.push_back(3);
	t = Tenseur(dims);
	
	Mat image;
	// On redimensionne l'image et on la met en noir et blanc
	if (couleur) {
		image = imread(nomFichier, IMREAD_GRAYSCALE); // lecture image + mise en noir et blanc
		resize(image,image,cv::Size(longueur,largeur),0,0); // Redimensionnement de l'image, modifier longueur et largeur pour modifier la taille souhaitée.
    }
    else {
		image = imread(nomFichier);
		resize(image,image,cv::Size(longueur,largeur),0,0);
	}
	
   // cout << image << endl; // Affiche les valeurs des pixels. 3 valeurs par pixel.
   
   
    /*   Si on veut afficher l'image. Il faut créer un fichier CMakeLists.txt (comme celui que j'ai ajouté) puis compiler de la manière suivante :
     * 1 ) cmake .
     * 2 ) make
     * 3 )./DisplayImage Photo.jpg
     * 
     *  
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);
    waitKey(0);
    
    * */
    
    
    return t ;
	
	
}

static Tenseur csvToTenseur(std::string nomFichier) {
	
	}

static void normaliser(Tenseur &t, double minNorm, double maxNorm, double minValeur, double maxValeur) {}

static void denormaliser(Tenseur &t, double minNorm, double maxNorm, double minValeur, double maxValeur) {}
