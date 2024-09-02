#include "../include/Ente.h"
    
Ente::Ente(const idEntes i):
id(i)
{
    pGGrafico = Gerenciadores::GerenciadorGrafico::getInstancia();
}

Ente::Ente(const idEntes i, const char* txt):
id(i)
{
    pGGrafico = Gerenciadores::GerenciadorGrafico::getInstancia();
    textura = pGGrafico->carregarTextura(txt);
}

Ente::~Ente()
{
    id = idEntes::Indefinido;
    pGGrafico = NULL; 
}

void Ente::setTextura(const char* txt)
{
    textura = pGGrafico->carregarTextura(txt);
}

const idEntes Ente::getId() const
{
    return id;
}