#include "../../../include/entidades/obstaculos/Plataforma.h"

namespace Entidades
{
    namespace Obstaculos
    {
        Plataforma::Plataforma(const float xx, const float yy, const bool ehChao):
        Obstaculo("", TAM_PLAT_X, TAM_PLAT_Y, xx, yy, false),
        chao(ehChao)
        {
        }

        Plataforma::Plataforma(const char* c, const float xx, const float yy, const bool ehChao):
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

        void Plataforma::regularColisao(Entidade* entAlternativa, sf::Vector2f distancia_colisao)
        {
            if(distancia_colisao.x > distancia_colisao.y)
            {
                if(x < entAlternativa->getPosicao().x)
                {
                    if(velocidadeX > 0) {velocidadeX = 0;}
                    if(entAlternativa->getId() == 1 || entAlternativa->getId() == 2)
                    {
                        dynamic_cast<Personagens::Personagem*>(entAlternativa)->setPulo(false);
                    }
                }
                else
                {
                    if(velocidadeX < 0) {velocidadeX = 0;}
                    if(entAlternativa->getId() == 1 || entAlternativa->getId() == 2)
                    {
                        dynamic_cast<Personagens::Personagem*>(entAlternativa)->setPulo(false);
                    }
                }
            }
            else 
            {
                if(y < entAlternativa->getPosicao().y)
                {
                    if(velocidadeY > 0) {velocidadeY = 0;}
                    if(entAlternativa->getId() == 1 || entAlternativa->getId() == 2)
                    {
                        dynamic_cast<Personagens::Personagem*>(entAlternativa)->setPulo(false);
                    }
                }
                else 
                {
                    if(velocidadeY < 0) {velocidadeY = 0;}
                }
            }
        }

        void Plataforma::obstacular(Personagens::Personagem* p)
        {
            p->setVelocidade(p->getVelMax());
            if(chao)
                p->setPulo(true);
        }
    }
}