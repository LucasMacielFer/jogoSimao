#pragma once

#include "Personagem.h"

namespace Entidades
{
    namespace Personagens
    {
        class Jogador : public Personagem
        {
            private:
                int pontuacao;

            public:

                Jogador(std::string txt="",const int vd = 10, const float vel = 10.0f, const int danos = 1, const float duraEspera = 0.0f, const float duraAtaque = 0.0f, const float tamXX=100.0f, const float tamYY=100.0f, const float xx=0.0f, const float yy=0.0f);
                ~Jogador();

                const int getPontuacao() const;
                void operator++();
                void executar();
                void salvar();
                void colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao);
                void pular();
        };
    }
}