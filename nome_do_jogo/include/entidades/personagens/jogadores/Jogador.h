#pragma once

#include "../Personagem.h"

namespace Entidades
{
    namespace Personagens
    {
        namespace Jogadores
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
                
            };
        }

    }

}