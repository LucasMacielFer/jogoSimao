#include "../../../include/entidades/personagens/Lobisomem.h"
#include "entidades/personagens/Inimigo.h"

namespace Entidades
{
    namespace Personagens
    {
        Lobisomem::Lobisomem(const char* txt, const float xx, const float yy):
        Inimigo(txt, TAM_X_LOBISOMEM, TAM_Y_LOBISOMEM, xx, yy, VIDAS_LOBISOMEM, VEL_MAX_LOBISOMEM, FORCA_LOBISOMEM, DURACAO_ESPERA_LOBISOMEM, DURACAO_ATAQUE_LOBISOMEM, tipoInimigo::Lobis),
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

        void Lobisomem::danificar(Jogador* pJogador)
        {
            if(ataqueDisponivel() && pJogador)
            {
                atacando = true;
                if(rand()%100 > nivelAtrapalhado)
                {
                    pular();
                    Personagem* pPersonagem = dynamic_cast <Personagem*>(pJogador);
                    pPersonagem->sofrerDano(forca);
                }
            }
        }

        void Lobisomem::habilidadeInimiga(float dt) 
        {  
            if(existeP1())
                distancia_jogador1 = getPosJogador1().x - getPosicao().x;
            else
                distancia_jogador1 = FLOAT_MAX;

            if(existeP2())
                distancia_jogador2 = getPosJogador2().x - getPosicao().x;
            else
                distancia_jogador2 = FLOAT_MAX;
            
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


        void Lobisomem::salvar(const char* caminhoSalvamento)
        {
            Inimigo::salvar(caminhoSalvamento);
            salvamento += " ";
            salvamento += std::to_string(nivelAtrapalhado);
            salvamento += " ";
            salvamento += std::to_string(tempoRapido);
            salvamento += " ";
            salvamento += std::to_string(rapido);

            std::ofstream gravador(caminhoSalvamento, std::ios::app);
            if(!gravador)
            {
                std::cout<<"Erro ao salvar lobisomem"<<std::endl;
            }
            else
            {
                gravador << salvamento << std::endl;
            }
            gravador.close();
        }
    }

}