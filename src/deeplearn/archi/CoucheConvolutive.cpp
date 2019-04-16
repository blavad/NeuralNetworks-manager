#include "CoucheConvolutive.hpp"

CoucheConvolutive::CoucheConvolutive(DimTenseur din, DimTenseur dout, std::string no, Tenseur par, int l_fil, int h_fil, int nb_fil):CoucheCombinaison(din,dout,no,par),l_filtre(l_fil),h_filtre(h_fil),nb_filtres(nb_fil)
{
}



Tenseur CoucheConvolutive::propagation(Tenseur t)
{
	return t;
}