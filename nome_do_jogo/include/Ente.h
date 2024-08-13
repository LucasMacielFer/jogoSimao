#pragma once
#include "gerenciadores/Gerenciador_Grafico.h"

// Ente é a classe abstrata base para os entes do jogo
class Ente
{
private:
    static int cont;

protected:
    Gerenciadores::Gerenciador_Grafico* pGGrafico;
    int id;
    
public:
    Ente();
    virtual ~Ente();
    virtual void desenhar(sf::RenderWindow& janela) = 0;
    virtual void executar() = 0;
};