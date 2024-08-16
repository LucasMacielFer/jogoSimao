#include "../../../include/entidades/personagens/jogadores/Jogador.h"

namespace Entidades
{
    namespace Personagens
    {
        namespace Jogadores
        {

                Jogador::Jogador(): Personagem(), pontuacao(0)
                {

                }
                Jogador::~Jogador()
                {
                    pontuacao = -1;
                }

                void Jogador::executar()
                {

                }
                void Jogador::salvar()
                {

                }
                
        }

    }

}