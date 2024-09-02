#pragma once

#include "Personagem.h"

#define TAM_X_JOGADOR 50
#define TAM_Y_JOGADOR 50
#define VIDAS_JOGADOR 50
#define VEL_MAX_JOGADOR 7
#define FORCA_JOGADOR 10
#define DURACAO_ATAQUE_JOGADOR 0.2f
#define DURACAO_ESPERA_JOGADOR 2.0f

namespace Observadores
{
    class ObservadorJogador;
}

namespace Entidades
{
    namespace Personagens
    {
        class Inimigo;

        class Jogador : public Personagem
        {
            private:
                int numeroJog;
                int pontuacao;
                const char* texturaAtaque;
                const char* texturaPadrao;
                Observadores::ObservadorJogador* pObs;

            public: 
                Jogador(const int numJog, const char* txt, const char* txt2, const float xx, const float yy);
                Jogador();
                ~Jogador();
                const int getPontuacao() const;
                void operator=(const unsigned int pontos);
                void aumentarTempoExecucao(const float tempo);
                void atacar();
                void danificar(Inimigo* pInim);
                void executar(float dt);
                void salvar(const char* caminhoSalvamento);
                void colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao);
                void morrer();
                void setAtivo(const bool at);
        };
    }
}