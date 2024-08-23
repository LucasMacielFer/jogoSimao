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
            int forca;
            bool atacando;
            bool puloDisponivel;
            const float duracaoEspera;
            const float duracaoAtaque;
            float tempoEsperando;
            float tempoAtacando;
            bool vivo;

        public:
            Personagem(const int i, sf::Color c, const float tamXX, const float tamYY, const float xx, const float yy, const int vd, const float vel, const int f, const float duraEspera, const float duraAtaque);
            Personagem();
            virtual ~Personagem();
            const int getVidas() const;
            void setVidas(const int v);
            const bool getPulo() const;
            void setPulo(const bool p);
            const bool ataqueDisponivel() const;
            const bool emAtaque() const;
            void aumentarTempoExecucao(const float tempo);
            const int getForca() const;
            void regularColisao(Entidade* entAlternativa, sf::Vector2f distancia_colisao);
            void pular();
            void sofrerDano(const int dano);
            virtual void atacarCorpo(Personagem* pPersonagem) = 0; 
            virtual void atacarDist(Personagem* pPersonagem) = 0;
            virtual void executar(float dt) = 0;
            virtual void salvar() = 0;
            virtual void colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao) = 0;
            virtual void morrer() = 0;
        };
    }
}