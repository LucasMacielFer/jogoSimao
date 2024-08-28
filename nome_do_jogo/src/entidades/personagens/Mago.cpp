#include "../../../include/entidades/personagens/Mago.h"
#include "SFML/Graphics/Color.hpp"

namespace Entidades
{   
    namespace Personagens
    {
        
        Mago::Mago(const char* txt, const float xx, const float yy):
        Inimigo(txt, TAM_X_MAGO, TAM_Y_MAGO, xx, yy, VIDAS_MAGO, VEL_MAX_MAGO, FORCA_MAGO, DURACAO_ESPERA_MAGO, DURACAO_ATAQUE_MAGO, 3),
        fogo(NULL), 
        esperaTeleporte(0.0f),
        bolaDeFogoTratada(false)
        {
        }
        

        Mago::Mago():
        Inimigo(), 
        fogo(NULL), 
        esperaTeleporte(0.0f),
        bolaDeFogoTratada(true)
        {
        }

        Mago::~Mago()
        {
            delete fogo;
            fogo = NULL;
        }

        
        Projetil* Mago::getFogo()
        {
            return fogo;
        }

        const bool Mago::getBFTratada() const
        {
            return bolaDeFogoTratada;
        }

        void Mago::setBFTratada(const bool bf)
        {
            bolaDeFogoTratada = bf;
        }

        void Mago::atacarCorpo(Personagem* pPersonagem)
        {
            if(ataqueDisponivel() && pPersonagem)
            {
                atacando = true;
                pular();
                pPersonagem->sofrerDano(forca);
            }
        }


        void Mago::habilidadeInimiga(float dt) 
        {  
            
            if(existeP1())
                distancia_jogador1 = getPosJogador1().x - getPosicao().x;
            else
                distancia_jogador1 = FLOAT_MAX;

            if(existeP2())
                distancia_jogador2 = getPosJogador2().x - getPosicao().x;
            else
                distancia_jogador2 = FLOAT_MAX;

            if(fogo && !(fogo->getAtivo()))
            {
                fogo = NULL;
            }

            if(esperaTeleporte < ESPERA_TELEPORTE_MAGO)
            {
                esperaTeleporte += dt;
            }
            else 
            {
                if(rand()%2 == 1)
                {
                    if(existeP1())
                    {
                        this->setPosicao(getPosJogador1().x, getPosJogador1().y);
                        esperaTeleporte = 0;
                    }
                }
                else 
                {   
                    if(existeP2())
                    {
                        this->setPosicao(getPosJogador2().x, getPosJogador2().y);
                        esperaTeleporte = 0;
                    }
                }

                if(existeP1())
                    distancia_jogador1 = getPosJogador1().x - getPosicao().x;
                else
                    distancia_jogador1 = FLOAT_MAX;

                if(existeP2())
                    distancia_jogador2 = getPosJogador2().x - getPosicao().x;
                else
                    distancia_jogador2 = FLOAT_MAX;
            }
           
            if(fabs(distancia_jogador1) < ALCANCE_MAGO || (fabs(distancia_jogador2) < ALCANCE_MAGO)) 
            { 
                setVelocidade(VEL_MAX_MAGO*2);
                
                if(fabs(distancia_jogador1) < fabs(distancia_jogador2))
                {
                    if(existeP1())
                        atacarDist(distancia_jogador1);
                }
                else 
                {
                    if(existeP2())
                        atacarDist(distancia_jogador2);
                }
            }
            else 
            {
                setVelocidade(VEL_MAX_MAGO);
            }
        }

        void Mago::atacarDist(float posJogador)
        {
            if(!fogo && ataqueDisponivel())
            {
                if(posJogador <= 0)
                {
                    fogo = new Projetil(static_cast<Inimigo*>(this), "assets/textures/plat1.png" , TAMANHO_FOGO_X, TAMANHO_FOGO_Y, this->getPosicao().x, this->getPosicao().y - 30,-1,-VELOCIDADE_FOGO);
                }
                else 
                {
                    fogo = new Projetil(static_cast<Inimigo*>(this),"assets/textures/plat1.png", TAMANHO_FOGO_X, TAMANHO_FOGO_Y, this->getPosicao().x, this->getPosicao().y - 30 ,1,VELOCIDADE_FOGO);
                }

                bolaDeFogoTratada = false;
                atacando = true;
            }
        }


       void Mago::salvar()
       {
       }
    
    }
}