#include "CoucheConvolutive.hpp"

CoucheConvolutive::CoucheConvolutive(DimTenseur din,
									 int l_fil,
									 int h_fil,
									 int nb_fil,
									 std::string no,
									 int pas = 1,
									 int pad = 0) : CoucheCombinaison(din,
																	  DimTenseur(std::vector<int>{}), no),l_filtre(l_fil), h_filtre(h_fil),nb_filtres(nb_fil),padding(pad),pas(pas)
{
}

Tenseur CoucheConvolutive::propagation(Tenseur t)
{
	return t;
}