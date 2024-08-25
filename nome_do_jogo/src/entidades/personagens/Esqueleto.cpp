#include "../../../include/entidades/personagens/Esqueleto.h"

namespace Entidades
{
    namespace Personagens
    {
        Esqueleto::Esqueleto(sf::Color c, const float xx, const float yy):
        Inimigo(c, TAM_X_ESQUELETO, TAM_Y_ESQUELETO, xx, yy, VIDAS_ESQUELETO, VEL_MAX_ESQUELETO, FORCA_ESQUELETO, DURACAO_ESPERA_ESQUELETO, DURACAO_ATAQUE_ESQUELETO),
        flecha(NULL)
        {
        }

        Esqueleto::Esqueleto():
        Inimigo(), flecha(NULL)
        {
        }

        Esqueleto::~Esqueleto()
        {
            //delete flecha;
        }

        void Esqueleto::atacarCorpo(Personagem* pPersonagem)
        {
            if(ataqueDisponivel() && pPersonagem)
            {
                atacando = true;
                pPersonagem->sofrerDano(forca);
            }
        }


        void Esqueleto::habilidadeInimiga() 
        {  
            
            distancia_jogador1 = getPosJogador1().x - getPosicao().x;
            distancia_jogador2 = getPosJogador2().x - getPosicao().x;

            /*if(flecha && !(flecha->getAtivo()))
            {
                delete flecha;
                flecha = NULL;
            }*/

            /*if(flecha) 
            {
                flecha->executar();
            }*/
            
            if(fabs(distancia_jogador1) < ALCANCE_ESQUELETO || (fabs(distancia_jogador2) < ALCANCE_ESQUELETO)) 
             { 
                setVelocidade(0);
                
                if(fabs(distancia_jogador1) < fabs(distancia_jogador2))
                {
                    atacarDist(distancia_jogador1);
                }
                else 
                {
                    atacarDist(distancia_jogador2);
                }
             }
            else 
            {
                setVelocidade(VEL_MAX_ESQUELETO);
            }

        }

        void Esqueleto::atacarDist(float posJogador)
        {
            if(!flecha)
            {
                if(posJogador <= 0)
                {
                    //flecha = new Projetil( this, c, TAMANHO_FLECHA_X, TAMANHO_FLECHA_Y, this->getPosicao().x, this->getPosicao().y,sentMovX,VELOCIDADE_FLECHA);
                }
                else 
                {
                    //flecha = new Projetil( this, c, TAMANHO_FLECHA_X, TAMANHO_FLECHA_Y, this->getPosicao().x, this->getPosicao().y,sentMovX,VELOCIDADE_FLECHA);
                }

            }

        }


       void Esqueleto::salvar()
       {
       }
    }

}