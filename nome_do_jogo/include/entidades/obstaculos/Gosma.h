#pragma once

#include "Obstaculo.h"
#include "../personagens/Personagem.h"

#define TAM_X_GOSMA 64
#define TAM_Y_GOSMA 32

namespace Entidades
{
    namespace Obstaculos
    {
        class Gosma : public Obstaculo
        {
            private:
                const float decrementoVelocidade;

            public:
                Gosma(sf::Color c, const float d, const float xx, const float yy);
                Gosma();
                ~Gosma();
                void obstacular(Personagens::Personagem* p);
                void salvar();
                void executar(float dt);
        };
    }
}