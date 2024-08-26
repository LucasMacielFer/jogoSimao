#include "../include/Ente.h"
    
Ente::Ente(const int i):
id(i)
{
    pGGrafico = Gerenciadores::Gerenciador_Grafico::getInstancia();
}

Ente::Ente(const int i, const char* txt):
id(i)
{
    pGGrafico = Gerenciadores::Gerenciador_Grafico::getInstancia();
    textura = pGGrafico->carregarTextura(txt);
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