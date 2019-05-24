#include "CoucheActivation.hpp"
#include <iostream>

CoucheActivation::CoucheActivation( const std::string no):Couche(no)
{
}

CoucheActivation::CoucheActivation(DimTenseur din, const std::string no):Couche(din,din,no)
{
}

std::string CoucheActivation::type()
{
    return "CoucheActivation";
}

void CoucheActivation::upDateDimOutput(){
    setDimOutput(getDimInput());
}
