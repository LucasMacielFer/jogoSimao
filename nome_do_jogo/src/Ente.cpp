#include "../include/Ente.h"
    
Ente::Ente(const int i):
id(i)
{
}

Ente::~Ente()
{
    id = -1;
    pGGrafico = NULL; 
}

const int Ente::getId() const
{
    return id;
}

/*
Temporariamente não há textura

std::string Ente::getTextura() const
{
    return c;
}

void Ente::setTextura(std::string txt)
{
    textura = txt;
}
*/