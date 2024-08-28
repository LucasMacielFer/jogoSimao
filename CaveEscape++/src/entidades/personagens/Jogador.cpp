#include "../../../include/entidades/personagens/Jogador.h"

namespace Entidades
{
    namespace Personagens
    {
        const unsigned int Jogador::idClasse(1);

        Jogador::Jogador(const char* txt, const float xx, const float yy):
        Personagem(idClasse, txt ,TAM_X_JOGADOR, TAM_Y_JOGADOR, xx, yy, VIDAS_JOGADOR, VEL_MAX_JOGADOR, FORCA_JOGADOR, DURACAO_ESPERA_JOGADOR, DURACAO_ATAQUE_JOGADOR), 
        pontuacao(0)
        {
        }

        Jogador::Jogador():
        Personagem(),
        pontuacao(-1)
        {
        }

        Jogador::~Jogador()
        {
            pontuacao = -1;
        }

        const int Jogador:: getPontuacao() const
        {
            return pontuacao;
        }

        void Jogador:: operator++()
        {
            pontuacao++;
        }

        void Jogador::atacarCorpo(Personagens::Personagem* pPersonagem)
        {
            if(ataqueDisponivel())
            {
                if(!atacando)
                {
                    pPersonagem->sofrerDano(forca);
                }
                atacando = true;
            }
        }

        void Jogador::atacarDist(float posJogador)
        {
            // Implementar caso o jogador venha a atacar em distancia também
        }

        void Jogador::executar(float dt)
        {
            if(vivo)
            {
                aumentarTempoExecucao(dt);
                aplicaGravidade(dt);
                mover();
            }
        }

        void Jogador::salvar()
        {

        }

        void Jogador::colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao)
        {
            if(entAlternativa)
            {
                //if( entAlternativa->getId() == 1    /*"Inimigo"*/ )
                //{
                //    Personagem* paux = static_cast<Personagem*>(entAlternativa);
                //    if(paux && emAtaque())
                //    {
                //        Personagem* pJogador = static_cast <Personagem*> (this);    
                //        if(pJogador)
                //        {
                //             pJogador->atacar(paux);
                //        }
                //    
                //    }
                //}
                //else if(entAlternativa->getId() == 2  /*"Obstaculo"*/)
                //{
                    regularColisao(entAlternativa, distancia_colisao);
                    puloDisponivel = true;
                //}
            }
        }

        void Jogador::morrer()
        {
            vivo = false;
        }
    }
}