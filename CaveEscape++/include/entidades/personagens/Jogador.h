#pragma once

#include "Personagem.h"

#define TAM_X_JOGADOR 50
#define TAM_Y_JOGADOR 50
#define VIDAS_JOGADOR 50
#define VEL_MAX_JOGADOR 7
#define FORCA_JOGADOR 10
#define DURACAO_ATAQUE_JOGADOR 2.0f
#define DURACAO_ESPERA_JOGADOR 2.0f

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

                Jogador(const char* txt, const float xx, const float yy);
                Jogador();
                ~Jogador();
                const int getPontuacao() const;
                void operator++();
                void atacarCorpo(Personagens::Personagem* pPersonagem);
                void atacarDist(float PosJogador);
                void executar(float dt);
                void salvar();
                void colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao);
                void morrer();
        };
    }
}