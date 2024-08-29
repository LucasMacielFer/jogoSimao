#pragma once
#include <string>
#include <iostream>
#include "gerenciadores/Gerenciador_Grafico.h"

enum idEntes
{
    Indefinido = -1,
    Jogador = 1,
    Inimigo,
    Obstaculo,
    Projetil,
    Fase,
    Menu
};

// Ente é a classe abstrata base para os entes do jogo
class Ente
{
    protected:
        Gerenciadores::Gerenciador_Grafico* pGGrafico;
        idEntes id;
        sf::Texture* textura;
        
    public:
        Ente(const idEntes i);
        Ente(const idEntes i, const char* txt);
        virtual ~Ente();
        const idEntes getId() const;
        void setTextura(const char* txt);
        virtual void desenhar(sf::RenderWindow& janela) = 0;
        virtual void executar(const float dt) = 0;
};