#include "../../../include/entidades/personagens/inimigos/Inimigo.h"

namespace Entidades
{
    namespace Personagens
    {
        namespace Inimigos
        {
            Inimigo::Inimigo(): Personagem()
            {

            }

            Inimigo::~Inimigo()
            {
                poder_ataque = -1;
            }
        }

    }

}