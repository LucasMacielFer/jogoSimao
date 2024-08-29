#include "../../../include/entidades/personagens/Esqueleto.h"
#include "../../../include/fases/Fase.h"

namespace Entidades
{
    namespace Personagens
    {
        Esqueleto::Esqueleto(const char* txt, const float xx, const float yy):
        Inimigo(txt, TAM_X_ESQUELETO, TAM_Y_ESQUELETO, xx, yy, VIDAS_ESQUELETO, VEL_MAX_ESQUELETO, FORCA_ESQUELETO, DURACAO_ESPERA_ESQUELETO, DURACAO_ATAQUE_ESQUELETO, 2),
        flecha(NULL),
        faseAgregado(NULL)
        {
        }

        Esqueleto::Esqueleto():
        Inimigo(), 
        flecha(NULL),
        faseAgregado(NULL)
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

        void Esqueleto::setFlecha(Projetil* p)
        {
            flecha = p;
        }

        void Esqueleto::setFase(Fases::Fase* f)
        {
            faseAgregado = f;
        }


        void Esqueleto::danificar(Jogador* pJogador)
        {
            if(ataqueDisponivel() && pJogador)
            {
                atacando = true;
                Personagem* pPersonagem = dynamic_cast <Personagem*>(pJogador);
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
                    faseAgregado->criarProjetil(static_cast<Inimigo*>(this), CAMINHO_FLECHA, TAMANHO_FLECHA_X, TAMANHO_FLECHA_Y, x, y - 30, -1, -VELOCIDADE_FLECHA);
                }
                else 
                {
                    faseAgregado->criarProjetil(static_cast<Inimigo*>(this), CAMINHO_FLECHA, TAMANHO_FLECHA_X, TAMANHO_FLECHA_Y, x, y - 30, 1, VELOCIDADE_FLECHA);
                }
                atacando = true;
            }
        }

       void Esqueleto::salvar()
       {
       }
    }
}