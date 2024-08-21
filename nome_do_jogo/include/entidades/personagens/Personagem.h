#pragma once

#include "../Entidade.h"

#define GRAVIDADE 30

namespace Entidades
{
    namespace Personagens
    {
        class Personagem : public Entidade
        {
        protected:
            int vidas;
            const float velocidade;
            float velocidadeX;
            float velocidadeY;
            int dano;
            bool atacando;
            bool puloDisponivel;
            const float duracaoEspera;
            const float duracaoAtaque;
            float tempoEsperando;
            float tempoAtacando;

        public:
            Personagem(std::string txt="",const int vd = 10, const float vel = 10.0f, const int danos = 1, const float duraEspera = 0.0f, const float duraAtaque = 0.0f, const float tamXX=10.0f, const float tamYY=10.0f, const float xx=0.0f, const float yy=0.0f);
            virtual ~Personagem();
            void mover();
            const int getVidas() const;
            void setVidas(const int v);
            virtual void sofrerDano(const int dano);
            virtual void atacar(Personagem* pPersonagem);
            void pular();
            const bool ataqueDisponivel() const;
            const bool emAtaque() const;
            void aumentarTempoExecucao(const float tempo);
            const int getDano() const;
            void regularColisao(Entidade* entAlternativa, sf::Vector2f distancia_colisao);
            void setSentidoMovX(const float s);
            void setSentidoMovY(const float s);
            void aplicaGravidade(float dt);

            // Devem ser virtuais puras
            virtual void executar(float dt) = 0;
            virtual void salvar() = 0;
            virtual void colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao) = 0;
        };
    }
}