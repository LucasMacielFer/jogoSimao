#include "../../../include/entidades/personagens/Jogador.h"

namespace Entidades
{
    namespace Personagens
    {
        Jogador::Jogador(): Personagem(), pontuacao(0)
        {

        }
        Jogador::~Jogador()
        {
            pontuacao = -1;
        }

        void Jogador::executar()
        {

        }
        void Jogador::salvar()
        {

        }

        void Jogador::colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao)
        {
            if(entAlternativa)
            {
                if( entAlternativa->getId() == 1    /*"Inimigo"*/ )
                {
                    Personagem* paux = static_cast<Personagem*>(entAlternativa);
                    if(paux && emAtaque())
                    {
                        paux->sofrerDano(dano);
                    }
                }
                else if(entAlternativa->getId() == 2  /*"Obstaculo"*/)
                {
                    Personagem* paux = static_cast<Personagem*>(entAlternativa);
                    paux->regularColisao(entAlternativa, distancia_colisao);
                }
            }
        }
    }
}