#include <stdio.h>
#include "opencv2/opencv.hpp"
#include <string.h>
#include <vector>
#include "Tenseur.hpp"

using namespace cv;
using namespace std;

void imageToTenseur(char* nomFichier, int longueur=400, int largeur=400, bool couleur=false){
	Mat image;
	if (couleur) {
		image = imread(nomFichier, IMREAD_GRAYSCALE);
		resize(image,image,cv::Size(longueur,largeur),0,0); // Redimensionnement de l'image, modifier longueur et largeur pour modifier la taille souhaitée.
    }
    else {
		image = imread(nomFichier);
		resize(image,image,cv::Size(longueur,largeur),0,0);
	}
    //cout << image << endl;
	
	//Tenseur tenseur;
	std::vector<int> dims;
	dims.push_back(longueur);
	dims.push_back(largeur);
	dims.push_back(3);
	//tenseur = Tenseur(dims);

    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);
    waitKey(0);
	
	}

int main( int argc, char** argv )
{
	

	 
    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }
    char* nomFichier = argv[1];
    imageToTenseur(nomFichier);
    
    return 0 ;
}
