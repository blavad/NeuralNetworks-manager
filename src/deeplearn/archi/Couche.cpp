#include "Couche.hpp"

Couche::Couche(const std::string no) : nom(no), coords(std::make_pair(50, 50))
{
}

Couche::Couche(DimTenseur din, DimTenseur dout, const std::string no) : dim_in(din), dim_out(dout), nom(no), coords(std::make_pair(50, 50))
{
}

Tenseur *Couche::propagation(Tenseur *t)
{
}

Tenseur *Couche::derivee(Tenseur *t)
{
}

void Couche::upDateDimOutput()
{
}

std::string Couche::type()
{
}

void Couche::setDimInput(DimTenseur dimIn)
{
	dim_in = dimIn;
}

void Couche::setDimOutput(DimTenseur dimOut)
{
	dim_out = dimOut;
}

void Couche::setNom(std::string n)
{
	nom = n;
}

void Couche::setPos(double x, double y)
{
	coords.first = x;
	coords.second = y;
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

double Couche::getX() const
{
	return coords.first;
}

double Couche::getY() const
{
	return coords.second;
}
