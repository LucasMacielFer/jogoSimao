#include "../../../include/entidades/obstaculos/Plataforma.h"

namespace Entidades
{
    namespace Obstaculos
    {
        Plataforma::Plataforma(const float tamXX, const float tamYY, const float xx, const float yy):
        Obstaculo(sf::Color::Green, tamXX, tamYY, xx, yy, false)
        {
        }

        Plataforma::Plataforma(sf::Color c, const float tamXX, const float tamYY, const float xx, const float yy):
        Obstaculo(c, tamXX, tamYY, xx, yy, false)
        {
        }

        Plataforma::Plataforma():
        Obstaculo()
        {
        }

        Plataforma::~Plataforma()
        {
        }

        void Plataforma::salvar()
        {
        }

        void Plataforma::executar(float dt)
        {
        }

        void Plataforma::obstacular(Personagens::Personagem* p)
        {
            p->setVelocidade(p->getVelMax());
            p->setPulo(true);
        }
    }
}