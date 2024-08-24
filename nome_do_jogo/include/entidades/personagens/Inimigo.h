#pragma once

#include "Personagem.h"
#include "Jogador.h"

#define TEMPO_VOLTA 1

namespace Entidades
{
    namespace Personagens
    {
        class Inimigo : public Personagem
        {
            private:
                static const unsigned int idClasse;
                float tempoVolta;
                static Jogador* jogador1Perseguido;
                static Jogador* jogador2Perseguido;

            protected:
                float distancia_jogador1;
                float distancia_jogador2;

            public:
                Inimigo(sf::Color c, const float tamXX, const float tamYY, const float xx, const float yy, const int vd, const float vel, const int f, const float duraEspera, const float duraAtaque);
                Inimigo();
                ~Inimigo();
                void setJogador1(Jogador* pJogador);
                void setJogador2(Jogador* pJogador);
                sf::Vector2f getPosJogador1();
                sf::Vector2f getPosJogador2();
                void executar(float dt);
                void colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao);
                void morrer();
                virtual void direcionar();
                virtual void atacarCorpo(Personagem* pPersonagem);
                virtual void atacarDist(Personagem* pPersonagem);
                virtual void habilidadeInimiga() = 0;
                virtual void salvar() = 0;
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