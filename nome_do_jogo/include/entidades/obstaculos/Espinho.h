#pragma once

#include "Obstaculo.h"

#define TAM_X_ESPINHO 50
#define TAM_Y_ESPINHO 50
#define RECARGA_DANO 0.5f

namespace Entidades
{
    namespace Obstaculos
    {
        class Espinho : public Obstaculo
        {
            private:
                const int dano;
                bool danificar;
                float tempoEspera;
            
            public:
                Espinho(sf::Color c, const int d, const float xx, const float yy);
                Espinho();
                ~Espinho();
                void obstacular(Personagens::Personagem* p);
                void salvar();
                void executar(float dt);
        };
    }
}