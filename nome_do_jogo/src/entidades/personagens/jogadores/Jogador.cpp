#include "../../../include/entidades/personagens/jogadores/Jogador.h"

namespace Entidades
{
    namespace Personagens
    {
        namespace Jogadores
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

                /*void Jogador::colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao)
                {
                    if(entAlternativa)
                    {
                        if( entAlternativa->getId() == "Inimigo" )
                        {
                            entAlternativa->sofrerDano(dano);
                        }
                        else if(entAlternativa->getId() == "Obstaculo")
                        {
                            regularColisao(entAlternativa, distancia_colisao);
                        }
                    }
                }*/
                
        }

    }

}