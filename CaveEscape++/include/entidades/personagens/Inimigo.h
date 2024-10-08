#pragma once

#include "Personagem.h"
#include "Jogador.h"

#define TEMPO_VOLTA 1
#define FLOAT_MAX 1000000.0f

namespace Entidades
{
    namespace Personagens
    {
        enum tipoInimigo
        {
            Indef = 0,
            Lobis = 1,
            Esque,
            Mag
        };

        class Inimigo : public Personagem
        {
            private:
                static Jogador* jogador1Perseguido;
                static Jogador* jogador2Perseguido;
                float tempoVolta;
                const tipoInimigo tipoInim;

            protected:
                float distancia_jogador1;
                float distancia_jogador2;

            public:
                Inimigo(const char* txt, const float tamXX, const float tamYY, const float xx, const float yy, const int vd, const float vel, const int f, const float duraEspera, const float duraAtaque, const tipoInimigo tipo);
                Inimigo();
                ~Inimigo();
                static void setJogador1(Jogador* pJogador);
                static void setJogador2(Jogador* pJogador);
                sf::Vector2f getPosJogador1();
                sf::Vector2f getPosJogador2();
                static const bool existeP1();
                static const bool existeP2();
                const tipoInimigo getTipo() const;
                void executar(float dt);
                void colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao);
                void morrer();
                virtual void direcionar();
                virtual void salvar(const char* caminhoSalvamento);
                virtual void danificar(Jogador* pJogador) = 0;
                virtual void habilidadeInimiga(float dt) = 0;
        };

    }
}

/*
TEMPLATE METHOD:

direcionar:
Fácil: Anda de um lado ao outro eternamente
Difícil: Anda de um lado ao outro. Quando encontra, persegue o jogador
Chefão: Persegue o jogador desde o momento que spawna

atacarCorpo:
Fácil: 10% de chance de errar o ataque e dar 0.5x o dano
Difícil: Ataca sempre
Chefão: 20% de chance de aumentar o dano em 1.5x

atacarDist:
Fácil: Não ataca em distância
Difícil: Ataca em distância
Chefão: Não sabemos ainda

-> Efetivação Template Method
executar: Chamará em ordem:
direcionar();
mover();
atacarDist();

-> Efetivação Template Method
colidir: Chamará em ordem:
regularColisao();
atacarCorpo();

*/