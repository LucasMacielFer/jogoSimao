#include "../../../include/entidades/obstaculos/Plataforma.h"

namespace Entidades
{
    namespace Obstaculos
    {
        Plataforma::Plataforma(const float xx, const float yy, const bool ehChao):
        Obstaculo(sf::Color::Green, TAM_PLAT_X, TAM_PLAT_Y, xx, yy, false),
        chao(ehChao)
        {
        }

        Plataforma::Plataforma(sf::Color c, const float xx, const float yy, const bool ehChao):
        Obstaculo(c, TAM_PLAT_X, TAM_PLAT_Y, xx, yy, false),
        chao(ehChao)
        {
        }

        Plataforma::Plataforma():
        Obstaculo(),
        chao(false)
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