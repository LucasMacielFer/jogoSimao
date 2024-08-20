#include "../../../include/entidades/obstaculos/Obstaculo.h"

namespace Entidades
{
    namespace Obstaculos
    {
        Obstaculo::Obstaculo(bool dano, std::string txt, const float tamXX, const float tamYY, const float xx, const float yy):
        Entidade(txt, tamXX, tamYY, xx, yy),
        danoso(dano)
        {
        }

        Obstaculo::~Obstaculo()
        {
            danoso = false;
        }
    }
}