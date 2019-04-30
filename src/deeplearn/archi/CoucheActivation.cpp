#include "CoucheActivation.hpp"

CoucheActivation::CoucheActivation(DimTenseur din,std::string no):Couche(din,din,no)
{
}

CoucheActivation::CoucheActivation(std::string no):Couche(std::vector<int>{},std::vector<int>{},no)
{
}
