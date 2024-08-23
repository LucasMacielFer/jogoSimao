#include "../../../include/entidades/personagens/Lobisomem.h"

namespace Entidades
{
    namespace Personagens
    {
        Lobisomem::Lobisomem(sf::Color c, const float xx, const float yy):
        Inimigo(c, TAM_X_LOBISOMEM, TAM_Y_LOBISOMEM, xx, yy, VIDAS_LOBISOMEM, VEL_MAX_LOBISOMEM, FORCA_LOBISOMEM, DURACAO_ESPERA_LOBISOMEM, DURACAO_ATAQUE_LOBISOMEM),
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


        void Lobisomem::habilidadeInimiga() 
        {  
          /*  distancia_jogador = getPosJogador().x - getPosicao().x; 

            if(fabs(distancia_jogador) < ALCANCE_LOBISOMEM) 
            { 
                rapido = true;
            }
            else 
            {
                rapido = false;
            }

            if(rapido)
            {
                setVelocidade( VEL_MAX_LOBISOMEM*2);
            }
            else 
            {
                setVelocidade(VEL_MAX_LOBISOMEM);
            }*/
        }


       void Lobisomem::salvar()
       {
       }
    }

}