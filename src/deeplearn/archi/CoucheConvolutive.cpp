#include "CoucheConvolutive.hpp"

CoucheConvolutive::CoucheConvolutive(DimTenseur din,
									 int l_fil,
									 int h_fil,
									 int nb_fil,
									 std::string no,
									 int pas,
									 int pad) : CoucheCombinaison(din,DimTenseur(std::vector<int>{}), no),l_filtre(l_fil), h_filtre(h_fil),nb_filtres(nb_fil),padding(pad),pas(pas)
{
}

Tenseur& CoucheConvolutive::propagation(Tenseur& t)
{
	Couche::propagation(t);
	Tenseur res;
	return res;
}

std::string CoucheConvolutive::type()
{
    return "CoucheConvolutive";
}