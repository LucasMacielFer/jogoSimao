#pragma once
#include <string>
#include <iostream>
#include "gerenciadores/GerenciadorGrafico.h"

enum idEntes
{
    Indefinido = -1,
    Jogador = 1,
    Inimigo,
    Obstaculo,
    Projetil,
    Fase,
    MenuId,
    Salvamento,
    Botao,
};

// Ente é a classe abstrata base para os entes do jogo
class Ente
{
    protected:
        Gerenciadores::GerenciadorGrafico* pGGrafico;
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