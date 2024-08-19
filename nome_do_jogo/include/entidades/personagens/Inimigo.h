#pragma once

#include "Personagem.h"

namespace Entidades
{
    namespace Personagens
    {
        class Inimigo : public Personagem
        {
            private:

            int poder_ataque;

            public:

                Inimigo();
                ~Inimigo();  
        };
    }
}