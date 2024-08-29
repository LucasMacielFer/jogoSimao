#include "../../../include/entidades/obstaculos/Espinho.h"

namespace Entidades
{
    namespace Obstaculos
    {
        Espinho::Espinho(const char* txt, const int d, const float xx, const float yy):
        Obstaculo(txt, TAM_X_ESPINHO, TAM_Y_ESPINHO, xx, yy, true),
        dano(d),
        danificar(true),
        tempoEspera(0.0f)
        {
        }

        Espinho::Espinho():
        Obstaculo(),
        dano(0),
        danificar(false),
        tempoEspera(0.0f)
        {
        }

        Espinho::~Espinho()
        {
            danificar = false;
        }

        void Espinho::obstacular(Personagens::Personagem* p)
        {
            if(p->getId() == idEntes::Jogador) // Jogador
            {
                if(danificar)
                {
                    p->sofrerDano(dano);
                }
                p->setPulo(true);
            }
            else    // Inimigo
            {
                if(danificar)
                {
                    p->sofrerDano((int)dano/2);
                }
                p->pular();
            }
        }

        void Espinho::salvar()
        {

        }

        void Espinho::executar(float dt)
        {
            tempoEspera += dt;
            if(tempoEspera >= RECARGA_DANO)
            {
                danificar = true;
                tempoEspera = 0;
            }
            else
                danificar = false;
        }
    }
}