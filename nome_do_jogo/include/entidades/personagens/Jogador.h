#pragma once

#include "Personagem.h"

namespace Entidades
{
    namespace Personagens
    {
        class Jogador : public Personagem
        {
            private:
                static const unsigned int idClasse;
                int pontuacao;

            public: 

                Jogador(sf::Color c, const float tamXX, const float tamYY, const float xx, const float yy, const int vd, const float vel, const int f, const float duraEspera, const float duraAtaque);
                Jogador(sf::Color c, const float tamXX, const float tamYY, const float xx=0.0f, const float yy=0.0f);
                Jogador();
                ~Jogador();
                const int getPontuacao() const;
                void operator++();
                void atacarCorpo(Personagens::Personagem* pPersonagem);
                void atacarDist(Personagens::Personagem* pPersonagem);
                void executar(float dt);
                void salvar();
                void colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao);
        };
    }
}