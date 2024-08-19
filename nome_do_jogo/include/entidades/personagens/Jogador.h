#pragma once

#include "Personagem.h"

namespace Entidades
{
    namespace Personagens
    {
        class Jogador : public Personagem
        {
            private:
                int pontuacao;

            public:

                Jogador();
                ~Jogador();

                void executar();
                void salvar();
                //void colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao);
            
        };
    }
}