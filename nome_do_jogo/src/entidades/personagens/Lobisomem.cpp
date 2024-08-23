#include "../../../include/entidades/personagens/Lobisomem.h"

namespace Entidades
{
    namespace Personagens
    {
        Lobisomem::Lobisomem(sf::Color c, const float xx, const float yy):
        Inimigo(c, TAM_X_LOBISOMEM, TAM_Y_LOBISOMEM, xx, yy, VIDAS_LOBISOMEM, VEL_MAX_LOBISOMEM, FORCA_LOBISOMEM, DURACAO_ESPERA_LOBISOMEM, DURACAO_ATAQUE_LOBISOMEM),
        nivelAtrapalhado(rand()%20)
        {
        }

        Lobisomem::Lobisomem():
        Inimigo(),
        nivelAtrapalhado(0)
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


        /*void Lobisomem::executar(float dt) //Estrutura levemente adaptada do código do monitor Matheus Burda. https://github.com/MatheusBurda/Desert.git. Acesso em: 21/08/2024. 
        { 
            Personagem::aumentarTempoExecucao(dt); 
            distancia_jogador = getPosJogador().x - getPosicao().x; 

            if(fabs(distancia_jogador) < ALCANCE_INIMIGO_FACIL) 
             { 
                if(distancia_jogador >= 0) 
                { 
                    if(velocidadeX < 0) 
                    { 
                        velocidadeX ++; 
                    } 
                    else 
                    { 
                        velocidadeX = 0.0f; 
                    } 
                } 
                else 
                { 
                    if(velocidadeX > 0) 
                    { 
                        velocidadeX--; 
                    } 
                    else 
                    { 
                        velocidadeX = 0.0f; 
                    } 
                } 
            }
             if (fabs(distancia_jogador) < ALCANCE_ATAQUE_INIMIGO && Personagem::ataqueDisponivel()) 
             { 
                Personagem* paux = static_cast<Personagem*> (jogadorPerseguido); 
                Personagem::atacar(paux); 
             } 
             
             aplicaGravidade(dt);
             mover(); }
             */

        /*
        void Lobisomem::colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao)
        {
            if(entAlternativa)
                {
                    //if( entAlternativa->getId() == 0    //"Jogador" )
                    //{
                    //    Personagem* paux = static_cast<Personagem*>(entAlternativa);
                    //    if(paux && emAtaque())
                    //    {
                    //        Personagem* pAtacado = static_cast <Personagem*> (this);
                    //        paux->atacar(pAtacado);
                    //    }
                    //}
                    //else if(entAlternativa->getId() == 2  //"Obstaculo")
                    //{
                        regularColisao(entAlternativa, distancia_colisao);
                    //}
                }
        }
        */

       void Lobisomem::salvar()
       {
       }
    }

}