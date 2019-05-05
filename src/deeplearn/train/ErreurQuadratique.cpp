#include "ErreurQuadratique.hpp"

ErreurQuadratique::ErreurQuadratique(){}

Tenseur ErreurQuadratique::eval(Tenseur sortieRN, Tenseur label){
  return (label - sortieRN)*(label - sortieRN);
}

Tenseur ErreurQuadratique::derivee(Tenseur t){
  return t+t; //2*t
}