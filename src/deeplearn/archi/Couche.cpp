#include "Couche.hpp"

Couche::Couche(const std::string no) : nom(no)
{
}

Couche::Couche(DimTenseur din, DimTenseur dout, const std::string no) : dim_in(din), dim_out(dout), nom(no)
{
}

Tenseur* Couche::propagation(Tenseur* t){

}

Tenseur* Couche::derivee(Tenseur* t){

}

bool Couche::afficher(){
	return true;
}

void Couche::setDimInput(DimTenseur dimIn)
{
	dim_in = dimIn;
}

void Couche::setDimOutput(DimTenseur dimOut)
{
	dim_out = dimOut;
}

void Couche::setNom(std::string n){
	nom = n;
}

DimTenseur Couche::getDimInput() const
{
	return dim_in;
}

DimTenseur Couche::getDimOutput() const
{
	return dim_out;
}

std::string Couche::getNom() const
{
	return nom;
}
