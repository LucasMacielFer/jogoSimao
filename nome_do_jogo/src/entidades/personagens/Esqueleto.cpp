#include "../../../include/entidades/personagens/Esqueleto.h"
#include "SFML/Graphics/Color.hpp"

namespace Entidades
{
    namespace Personagens
    {
        Esqueleto::Esqueleto(const char* txt, const float xx, const float yy):
        Inimigo(txt, TAM_X_ESQUELETO, TAM_Y_ESQUELETO, xx, yy, VIDAS_ESQUELETO, VEL_MAX_ESQUELETO, FORCA_ESQUELETO, DURACAO_ESPERA_ESQUELETO, DURACAO_ATAQUE_ESQUELETO, 2),
        flecha(NULL),
        flechaTratada(true)
        {
        }

        Esqueleto::Esqueleto():
        Inimigo(), 
        flecha(NULL),
        flechaTratada(true)
        {
        }

        Esqueleto::~Esqueleto()
        {
            if(flecha)
                delete flecha;
            flecha = NULL;
        }

        Projetil* Esqueleto::getFlecha()
        {
            return flecha;
        }

        const bool Esqueleto::getFTratada() const
        {
            return flechaTratada;
        }

        void Esqueleto::setFTratada(const bool f)
        {
            flechaTratada = f;
        }

        void Esqueleto::atacarCorpo(Personagem* pPersonagem)
        {
            if(ataqueDisponivel() && pPersonagem)
            {
                atacando = true;
                pPersonagem->sofrerDano(forca);
            }
        }

        void Esqueleto::habilidadeInimiga(float dt) 
        {  
            if(existeP1())
                distancia_jogador1 = getPosJogador1().x - getPosicao().x;
            else
                distancia_jogador1 = FLOAT_MAX;

            if(existeP2())
                distancia_jogador2 = getPosJogador2().x - getPosicao().x;
            else
                distancia_jogador2 = FLOAT_MAX;
            
            if(flecha && !(flecha->getAtivo()))
            {
                flecha = NULL;
            }
            
            if(fabs(distancia_jogador1) < ALCANCE_ESQUELETO || (fabs(distancia_jogador2) < ALCANCE_ESQUELETO)) 
            { 
                setVelocidade(0);
                
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
                setVelocidade(VEL_MAX_ESQUELETO);
            }
        }

        void Esqueleto::atacarDist(float posJogador)
        {
            if(!flecha && ataqueDisponivel())
            {
                if(posJogador <= 0)
                {
                    flecha = new Projetil(static_cast<Inimigo*>(this), CAMINHO_FLECHA, TAMANHO_FLECHA_X, TAMANHO_FLECHA_Y, this->getPosicao().x, this->getPosicao().y - 30,-1,-VELOCIDADE_FLECHA);
                }
                else 
                {
                    flecha = new Projetil(static_cast<Inimigo*>(this), CAMINHO_FLECHA, TAMANHO_FLECHA_X, TAMANHO_FLECHA_Y, this->getPosicao().x, this->getPosicao().y - 30 ,1,VELOCIDADE_FLECHA);
                }
                
                flechaTratada = false;
                atacando = true;
            }
        }

       void Esqueleto::salvar()
       {
       }
    }
}