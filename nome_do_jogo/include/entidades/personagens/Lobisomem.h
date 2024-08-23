#pragma once

#include "Inimigo.h"
#include <cmath>

#define TAM_X_LOBISOMEM 50
#define TAM_Y_LOBISOMEM 50
#define VIDAS_LOBISOMEM 20
#define VEL_MAX_LOBISOMEM 4.0f
#define FORCA_LOBISOMEM 7
#define DURACAO_ATAQUE_LOBISOMEM 1.0f
#define DURACAO_ESPERA_LOBISOMEM 2.0f
#define ALCANCE_LOBISOMEM 300.0f

namespace Entidades
{
    namespace Personagens
    {
        class Lobisomem : public Inimigo
        {
            private:
                const int nivelAtrapalhado;
                float tempoRapido;
                bool rapido;

            public:

                Lobisomem(sf::Color c, const float xx, const float yy);
                Lobisomem();
                ~Lobisomem();
                void salvar();
                void atacarCorpo(Personagem* pPersonagem);
                void habilidadeInimiga();
        };
    }
}