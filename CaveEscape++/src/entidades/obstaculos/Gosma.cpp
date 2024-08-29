#include "../../../include/entidades/obstaculos/Gosma.h"

namespace Entidades
{
    namespace Obstaculos
    {
        Gosma::Gosma(const char* txt, const float d, const float xx, const float yy):
        Obstaculo(txt, TAM_X_GOSMA, TAM_Y_GOSMA, xx, yy, false),
        decrementoVelocidade(d)
        {
        }

        Gosma::Gosma():
        Obstaculo(),
        decrementoVelocidade(1)
        {
        }

        Gosma::~Gosma()
        {
        }

        void Gosma::obstacular(Personagens::Personagem* p)
        {
            if(p->getId() == idEntes::Jogador) // Jogador
            {
                p->setVelocidade(p->getVelMax()*decrementoVelocidade);
                p->setPulo(false);
            }
            else    // Inimigo
            {
                p->setVelocidade(p->getVelMax()*decrementoVelocidade);
            }
        }

        void Gosma::salvar()
        {
        }

        void Gosma::executar(float dt)
        {
        }
    }
}