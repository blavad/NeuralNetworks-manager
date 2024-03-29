#include "Couche.hpp"
#include <iostream>

Couche::Couche(const std::string no) : nom(no), coords(std::make_pair(50, 50))
{
}

Couche::Couche(DimTenseur din, DimTenseur dout, const std::string no) : dim_in(din), dim_out(dout), nom(no), coords(std::make_pair(50, 50))
{
}

Tenseur &Couche::propagation(Tenseur &t)
{
}

Tenseur& Couche::derivee(Tenseur &t)
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

void Couche::setTmp(Tenseur t)
{
	tmp = t;
}

Tenseur& Couche::getTmp()
{
	return tmp;
}

Tenseur Couche::getEntree() const
{
	return entree;
}

void Couche::setEntree(Tenseur t)
{
	entree = t;
}

std::ostream &operator<<(std::ostream &os, const Couche &c)
{
	std::string str;
	os << "nom de la couche : "<<c.getNom()<<"\n";
	os << "Dim tenseur en entree : "<<c.getDimInput()<<"\n";
	os << "Dim tenseur en sortie : "<<c.getDimOutput()<<"\n";

	return os;
}
