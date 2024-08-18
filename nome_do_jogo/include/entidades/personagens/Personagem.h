#pragma once

#include "../Entidade.h"

namespace Entidades
{
    namespace Personagens
    {
        class Personagem : public Entidade
        {
        protected:
            int vidas;
            float velocidade;
            int dano;
            bool atacando;
            const float duracaoEspera;
            const float duracaoAtaque;
            float tempoEsperando;
            float tempoAtacando;

        public:
            Personagem(const int vd = 10, const float vel = 10.0f, const int danos = 1, const float duraEspera = 0.0f, const float duraAtaque = 0.0f, const float tamXX=10.0f, const float tamYY=10.0f, const float xx=0.0f, const float yy=0.0f);
            virtual ~Personagem();
            void mover(int dir);
            const int getVidas() const;
            void setVidas(const int v);
            virtual void sofrerDano(const int dano);
            virtual void atacar();
            const bool ataqueDisponivel() const;
            const bool emAtaque() const;
            void aumentarDuracaoAtaque(const float tempo);
            const int getDano() const;
            //void regularColisao(Entidade* entAltenativa, sf::Vector2f distancia_colisao);
            void operator++();
            void operator--();

            // Devem ser virtuais puras
            virtual void executar();
            virtual void salvar();
            virtual void colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao);
        };
    }
}