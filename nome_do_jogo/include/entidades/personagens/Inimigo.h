#pragma once

#include "Personagem.h"
#include "Jogador.h"

namespace Entidades
{
    namespace Personagens
    {
        class Inimigo : public Personagem
        {
            private:

            Jogador* jogadorPerseguido;

            protected:

            sf::Vector2f distancia_jogador;

            public:

                Inimigo(std::string txt="",const int vd = 10, const float vel = 10.0f, const int danos = 1, const float duraEspera = 0.0f, const float duraAtaque = 0.0f, const float tamXX=10.0f, const float tamYY=10.0f, const float xx=0.0f, const float yy=0.0f);
                ~Inimigo();
                void setJogador(Jogador* pJogador);
                virtual void salvar() = 0;
                virtual void executar() = 0;
        };
    }
}