#include "../include/Ente.h"

int Ente::cont(0);
    
Ente::Ente():
id(++cont)
{
}

Ente::~Ente()
{
    id = -1;
    pGGrafico = NULL;
}