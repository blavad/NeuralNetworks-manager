#include "Couche.cpp"
#include "DimTenseur.cpp"
#include "Tenseur.cpp"
#include "Vecteur.cpp"
#include "Matrice.cpp"
#include "MaxPooling.cpp"
#include "CoucheActivation.cpp"
#include "ReLu.cpp"
#include "Sigmoid.cpp"
#include "TanH.cpp"
#include "CoucheCombinaison.cpp"
#include "CoucheConnectee.cpp"
#include "Neurone.cpp"
#include "CoucheConvolutive.cpp"
#include <iostream>
#include <vector>
#include <string>

int main()
{	
	/*Initialisation d'un vector d'entiers pour creer des objets DimTenseur*/
	std::vector<int> vec1{2,3,7}; //!!ecrire -std=c++11 au moment de la compilation!!
	std::vector<int> vec2{5,8,3,9,7};
	std::vector<int> vec3{8,4,6,4};

	/*Constructiond'un objet DimTenseur*/
	DimTenseur d1(3,vec1);
	DimTenseur d2(5,vec2);
	DimTenseur d3(4,vec3);


	/*Vérification de l'accès à l'ordre d'un DimTenseur*/
	std::cout << "Ordre d'un DimTenseur:\n\n"; 
	std::cout << d2.getOrdre() << "\n\n";


	/*Vérification de l'accès au nombre de valeurs par dimension d'un DimTenseur*/
	std::cout << "Dimensions d'un DimTenseur:\n\n";
	for (int i : d2.getDim() )
		std::cout << i << "\n";
	std::cout << "\n";


	/*Construction d'un objet Couche*/
	Couche coucheA(d1,d2,"CoucheA");
	Couche coucheB(d2,d3,"CoucheB");


	/*Vérification de l'accès au nom d'une Couche*/
	std::cout << "Nom d'une couche:\n\n";
	std::cout << coucheA.getNom() << "\n"; 
	std::cout << coucheB.getNom() << "\n\n";


	/*Vérification de l'accès à l'ordre d'un DimTenseur*/
	std::cout << "Ordre d'un DimTenseur via Couche:\n\n"; 
	std::cout << coucheA.getDimInput().getOrdre() << "\n";
	std::cout << coucheA.getDimOutput().getOrdre() << "\n";
	std::cout << coucheB.getDimInput().getOrdre() << "\n";
	std::cout << coucheB.getDimOutput().getOrdre() << "\n\n";	


	/*Constructiond'un objet MaxPooling*/
	MaxPooling maxPxy(d1,d2,"MaxPool1",200,300);
	MaxPooling maxP(d2,d3,"MaxPool1",300);	

	
	/*Vérification de l'accès aux pool d'un MaxPooling*/
	std::cout << "Pool des Maxpooling\n\n";
	std::cout << maxPxy.getPoolX() << "\n";
	std::cout << maxPxy.getPoolY() << "\n";
	std::cout << maxP.getPoolX() << "\n";
	std::cout << maxP.getPoolY() << "\n\n";

	/*Création de couches d'activation diverses*/
	CoucheActivation c(d1,d2,"CoucheActivation");
	ReLU r(d1,d2,"ReLU");
	Sigmoid s(d1,d2,"Sigmoid");
	TanH t(d1,d2,"TangenteH");


	/*Vérification de l'accès au nom d'une Couche*/
	std::cout << "Nom d'une couche:\n\n";
	std::cout << r.getNom() << "\n";
	std::cout << c.getNom() << "\n"; 
	std::cout << s.getNom() << "\n"; 
	std::cout << t.getNom() << "\n\n";

	/*Création de tenseurs divers*/
	int* ptr = nullptr;
	int truc = 2;
	ptr = &truc;


	Tenseur ts(ptr,d1);
	Vecteur ve(ptr,7);
	Matrice mat(ptr,8,10);


	/*Vérification de l'accès à l'ordre d'un DimTenseur*/
	std::cout << "Ordre d'un DimTenseur via Couche Tenseur:\n\n"; 
	std::cout << ts.getDim().getOrdre() << "\n";
	std::cout << ve.getDim().getOrdre() << "\n\n";



	/* Vérification de l'accès aux vector de dimension des tenseurs*/
	std::cout << "Vectors de dimension des tenseurs :\n\n"; 
	for (int i : ve.getDim().getDim())
		std::cout << i << "\n";


	for (int i : mat.getDim().getDim())
		std::cout << i << "\n";	
	
	

	/*Création couche combinaison*/
	CoucheCombinaison ccb(d1,d2,"CoucheCombinaison",mat);
	CoucheConnectee ccn(d1,d2,"CoucheConnectee",mat);
	Neurone neu(d1,d2,"Neurone",mat);
	CoucheConvolutive ccv(d1,d2,"CoucheConnectee",mat,200,300,5);


	return 0;
}