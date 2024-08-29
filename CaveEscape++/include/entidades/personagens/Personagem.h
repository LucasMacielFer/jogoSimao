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
            Personagem(idEntes i, const char* txt, const float tamXX, const float tamYY, const float xx, const float yy, const int vd, const float vel, const int f, const float duraEspera, const float duraAtaque);
            Personagem();
            virtual ~Personagem();
            const int getVidas() const;
            void setVidas(const int v);
            const bool getPulo() const;
            void setPulo(const bool p);
            const bool ataqueDisponivel() const;
            const bool emAtaque() const;
            void setAtaque(const bool status_ataque);
            // Virtual pois, na classe jogador, existe uma textura diferente para o ataque
            virtual void aumentarTempoExecucao(const float tempo);
            const int getForca() const;
            void regularColisao(Entidade* entAlternativa, sf::Vector2f distancia_colisao);
            void pular();
            void sofrerDano(const int dano);
            const bool getVivo() const;
            virtual void executar(float dt);
            virtual void salvar() = 0;
            virtual void colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao) = 0;
            virtual void morrer() = 0;
        };
    }
}