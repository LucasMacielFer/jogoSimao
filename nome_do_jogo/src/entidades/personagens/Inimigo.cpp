#include "../../../include/entidades/personagens/Inimigo.h"

namespace Entidades
{
    namespace Personagens
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