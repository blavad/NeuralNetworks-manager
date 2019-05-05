#include "ErreurL1.hpp"
#include "../archi/Tenseur.hpp"

ErreurL1::ErreurL1(){}

Tenseur ErreurL1::eval(Tenseur sortieRN, Tenseur label){
  return (sortieRN - label);
}

Tenseur ErreurL1::derivee(Tenseur t){
  Tenseur m(t.getDim());
  m.initValeur(1.0);
  return m;
}