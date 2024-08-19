#include "../include/Ente.h"

int Ente::cont(0);
    
Ente::Ente(std::string txt):
id(++cont),
textura(txt)
{
    std::cout<<"Entidade sem textura"<<std::endl;
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

std::string Ente::getTextura() const
{
    return textura;
}

void Ente::setTextura(std::string txt)
{
    textura = txt;
}