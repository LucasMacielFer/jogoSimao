#pragma once
#include <string>
#include <iostream>
#include "gerenciadores/Gerenciador_Grafico.h"

// Ente é a classe abstrata base para os entes do jogo
class Ente
{
private:
    // Ainda não há texturas
    //std::string textura;

protected:
    Gerenciadores::Gerenciador_Grafico* pGGrafico;
    int id;
    
public:
    Ente(const int i);
    virtual ~Ente();
    const int getId() const;
    //std::string getTextura() const;
    //void setTextura(std::string txt);
    virtual void desenhar(sf::RenderWindow& janela) = 0;
    virtual void executar(const float dt) = 0;
};