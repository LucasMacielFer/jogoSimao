#include "../../../include/entidades/personagens/Mago.h"
#include "SFML/Graphics/Color.hpp"
#include "../../../include/estados/fases/Fase.h"

namespace Entidades
{   
    namespace Personagens
    {
        
        Mago::Mago(const char* txt, const float xx, const float yy):
        Inimigo(txt, TAM_X_MAGO, TAM_Y_MAGO, xx, yy, VIDAS_MAGO, VEL_MAX_MAGO, FORCA_MAGO, DURACAO_ESPERA_MAGO, DURACAO_ATAQUE_MAGO, tipoInimigo::Mag),
        bolaFogo(NULL), 
        esperaTeleporte(0.0f)
        {
        }
        

        Mago::Mago():
        Inimigo(), 
        bolaFogo(NULL), 
        esperaTeleporte(0.0f)
        {
        }

        Mago::~Mago()
        {
            if(bolaFogo)
                delete bolaFogo;
            bolaFogo = NULL;
        }

        
        Projetil* Mago::getBolaFogo() const
        {
            return bolaFogo;
        }

        void Mago::setBolaFogo(Projetil* bf)
        {
            bolaFogo = bf;
        }

        void Mago::danificar(Jogador* pJogador)
        {
            if(ataqueDisponivel() && pJogador)
            {
                atacando = true;
                pular();
                Personagem* pPersonagem = dynamic_cast <Personagem*>(pJogador);
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
                        atacando = true;
                    }
                }
                else 
                {   
                    if(existeP2())
                    {
                        this->setPosicao(getPosJogador2().x, getPosJogador2().y);
                        esperaTeleporte = 0;
                        atacando = true;
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
            if(!bolaFogo && ataqueDisponivel())
            {
                if(posJogador <= 0)
                {
                    faseAgregado->criarProjetil(static_cast<Inimigo*>(this), CAMINHO_FOGO, TAMANHO_FOGO_X, TAMANHO_FOGO_Y, this->getPosicao().x, this->getPosicao().y - 30,-1,-VELOCIDADE_FOGO);
                }
                else 
                {
                    faseAgregado->criarProjetil(static_cast<Inimigo*>(this), CAMINHO_FOGO, TAMANHO_FOGO_X, TAMANHO_FOGO_Y, this->getPosicao().x, this->getPosicao().y - 30 ,1,VELOCIDADE_FOGO);
                }

                atacando = true;
            }
        }

        void Mago::setFase(Estados::Fases::Fase* f)
        {
            faseAgregado = f;
        }

        void Mago::salvar()
        {
        }
    
    }
}