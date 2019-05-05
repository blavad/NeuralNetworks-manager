#include "ErreurEntropieCroisee.hpp"
#include <vector>

ErreurEntropieCroisee::ErreurEntropieCroisee(){}

Tenseur ErreurEntropieCroisee::eval(Tenseur sortieRN, Tenseur label){
    Tenseur m(sortieRN.getDim());
    std::vector<int> indice(m.getDim().getOrdre(),0);
    m.setValeur(-label.getValeur(indice)*log(sortieRN.getValeur(indice))-(1-label.getValeur(indice))*log(1-sortieRN.getValeur(indice)),indice);
    while(sortieRN.nextInd(indice)){
        m.setValeur(-label.getValeur(indice)*log(sortieRN.getValeur(indice))-(1-label.getValeur(indice))*log(1-sortieRN.getValeur(indice)),indice);
    }
    return m;
}

Tenseur ErreurEntropieCroisee::derivee(Tenseur sortieRN, Tenseur label){
    Tenseur m(sortieRN.getDim());
    std::vector<int> indice(m.getDim().getOrdre(),0);
    m.setValeur(-(label.getValeur(indice)/sortieRN.getValeur(indice))-((1-label.getValeur(indice))/(1-sortieRN.getValeur(indice))),indice);
    while(sortieRN.nextInd(indice)){
        m.setValeur(-(label.getValeur(indice)/sortieRN.getValeur(indice))-((1-label.getValeur(indice))/(1-sortieRN.getValeur(indice))),indice);
    }
    return m;
}