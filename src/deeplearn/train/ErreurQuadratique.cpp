#include "ErreurQuadratique.hpp"

ErreurQuadratique::ErreurQuadratique(){}

Tenseur ErreurQuadratique::eval(Tenseur sortieRN, Tenseur label){
  return (sortieRN-label)*(sortieRN-label);
}

Tenseur ErreurQuadratique::derivee(Tenseur sortieRN, Tenseur label){
  return (sortieRN-label)+(sortieRN-label);
}