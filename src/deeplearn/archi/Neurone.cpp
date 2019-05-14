#include "Neurone.hpp"

Neurone::Neurone(std::string no):CoucheConnectee(1,no)
{
}


std::string Neurone::type()
{
    return "Neurone";
}