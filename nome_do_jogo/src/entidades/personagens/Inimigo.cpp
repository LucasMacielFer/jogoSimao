#include "../../../include/entidades/personagens/Inimigo.h"

namespace Entidades
{
    namespace Personagens
    {
        const unsigned int Inimigo::idClasse(2);
        Jogador* Inimigo::jogador1Perseguido(NULL);
        Jogador* Inimigo::jogador2Perseguido(NULL);

        Inimigo::Inimigo(sf::Color c, const float tamXX, const float tamYY, const float xx, const float yy, const int vd, const float vel, const int f, const float duraEspera, const float duraAtaque):
        Personagem(idClasse, c ,tamXX, tamYY, xx, yy, vd, vel, f, duraEspera, duraAtaque),
        distancia_jogador1(0.0f),
        distancia_jogador2(0.0f),
        tempoVolta(0.0f)
        {
        }

        Inimigo::Inimigo():
        Personagem(),
        distancia_jogador1(0.0f),
        distancia_jogador2(0.0f),
        tempoVolta(0.0f)
        {
        }

        Inimigo::~Inimigo()
        {
            jogador1Perseguido = NULL;
            jogador2Perseguido = NULL;
        }

        void Inimigo::setJogador1(Jogador* pJogador)
        {
            jogador1Perseguido = pJogador;
        }

        void Inimigo::setJogador2(Jogador* pJogador)
        {
            jogador2Perseguido = pJogador;
        }

        sf::Vector2f Inimigo::getPosJogador1()
        {
            if(jogador1Perseguido)
            {
                return jogador1Perseguido->getPosicao();
            }
            else
            {
                std::cout << "Ponteiro Nulo" << std::endl;
                exit(1);
            }
        }

        sf::Vector2f Inimigo::getPosJogador2()
        {
            if(jogador2Perseguido)
            {
                return jogador2Perseguido->getPosicao();
            }
            else
            {
                std::cout << "Ponteiro Nulo" << std::endl;
                exit(1);
            }
        }

            void Inimigo::executar(float dt)
        {
            if(vivo)
            {
                tempoVolta += dt;
                aumentarTempoExecucao(dt);
                aplicaGravidade(dt);
                habilidadeInimiga();
                direcionar();
                mover();
                atacarDist(jogador1Perseguido);
            }
        }

        void Inimigo::colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao)
        {
            if(entAlternativa->getId()==3)
                regularColisao(entAlternativa, distancia_colisao);
            if(entAlternativa->getId()==1)
                atacarCorpo(dynamic_cast<Personagem*>(entAlternativa));
        }

        void Inimigo::direcionar()
        {
            movimentaX(sentidoMovX);
            if(tempoVolta >= TEMPO_VOLTA)
            {
                sentidoMovX = -sentidoMovX;
                tempoVolta = 0;
            }
        }

        void Inimigo::atacarCorpo(Personagem* pPersonagem)
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

        void Inimigo::atacarDist(Personagem* pPersonagem)
        {
            // Não é implementada na classe inimigo. As derivadas podem implementá-la!
        }

        void Inimigo::morrer()
        {
            vivo = false;
        }
    }
}