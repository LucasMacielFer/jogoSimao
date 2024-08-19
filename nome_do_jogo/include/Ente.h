#pragma once
#include <string>
#include <iostream>
#include "gerenciadores/Gerenciador_Grafico.h"

// Ente é a classe abstrata base para os entes do jogo
class Ente
{
private:
    static int cont;
    std::string textura;
 
protected:
    Gerenciadores::Gerenciador_Grafico* pGGrafico;
    int id;
    
public:
    Ente(std::string txt="");
    virtual ~Ente();
    const int getId() const;
    std::string getTextura() const;
    void setTextura(std::string txt);
    virtual void desenhar(sf::RenderWindow& janela) = 0;
    virtual void executar() = 0;
};