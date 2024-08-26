#include "../../../include/entidades/personagens/Lobisomem.h"

namespace Entidades
{
    namespace Personagens
    {
        Lobisomem::Lobisomem(const char* txt, const float xx, const float yy):
        Inimigo(txt, TAM_X_LOBISOMEM, TAM_Y_LOBISOMEM, xx, yy, VIDAS_LOBISOMEM, VEL_MAX_LOBISOMEM, FORCA_LOBISOMEM, DURACAO_ESPERA_LOBISOMEM, DURACAO_ATAQUE_LOBISOMEM),
        nivelAtrapalhado(rand()%20), rapido(false)
        {
        }

        Lobisomem::Lobisomem():
        Inimigo(),
        nivelAtrapalhado(0), rapido(false)
        {
        }

        Lobisomem::~Lobisomem()
        {
        }

        void Lobisomem::atacarCorpo(Personagem* pPersonagem)
        {
            if(ataqueDisponivel() && pPersonagem)
            {
                atacando = true;
                pular();
                if(rand()%100 > nivelAtrapalhado)
                {
                    pPersonagem->sofrerDano(forca);
                }
            }
        }


        void Lobisomem::habilidadeInimiga(float dt) 
        {  
            
            distancia_jogador1 = getPosJogador1().x - getPosicao().x;
            distancia_jogador2 = getPosJogador2().x - getPosicao().x;
            
            if(fabs(distancia_jogador1) < ALCANCE_LOBISOMEM || (fabs(distancia_jogador2) < ALCANCE_LOBISOMEM)) 
             { 
                rapido = true;
                setVelocidade( VEL_MAX_LOBISOMEM*2);
             }
            else 
            {
                rapido = false;
                setVelocidade(VEL_MAX_LOBISOMEM);
            }

        }


       void Lobisomem::salvar()
       {
       }
    }

}