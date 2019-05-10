#include "CoucheActivation.hpp"

CoucheActivation::CoucheActivation( const std::string no):Couche(no)
{
}

CoucheActivation::CoucheActivation(DimTenseur din, const std::string no):Couche(din,din,no)
{
}

void CoucheActivation::upDateDimOutput(){
    setDimOutput(getDimInput());
}
