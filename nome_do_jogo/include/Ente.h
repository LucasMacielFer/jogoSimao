#pragma once
#include <string>
#include <iostream>
#include "gerenciadores/Gerenciador_Grafico.h"

// Ente é a classe abstrata base para os entes do jogo
class Ente
{
protected:
    Gerenciadores::Gerenciador_Grafico* pGGrafico;
    int id;
    sf::Texture* textura;
    
public:
    Ente(const int i);
    Ente(const int i, const char* txt);
    virtual ~Ente();
    const int getId() const;
    virtual void desenhar(sf::RenderWindow& janela) = 0;
    virtual void executar(const float dt) = 0;
};