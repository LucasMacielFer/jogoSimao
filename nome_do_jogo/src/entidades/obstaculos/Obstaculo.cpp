#include "../../../include/entidades/obstaculos/Obstaculo.h"

namespace Entidades
{
    namespace Obstaculos
    {
        const unsigned int Obstaculo::idClasse(3);

        Obstaculo::Obstaculo(sf::Color c, const float tamXX, const float tamYY, const float xx, const float yy, const bool dano):
        Entidade(idClasse, c, tamXX, tamYY, xx, yy),
        danoso(dano)
        {
        }

        Obstaculo::Obstaculo():
        Entidade(),
        danoso(false)
        {
        }

        Obstaculo::~Obstaculo()
        {
            danoso = false;
        }
    }
} 