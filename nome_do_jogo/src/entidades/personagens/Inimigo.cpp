#include "../../../include/entidades/personagens/Inimigo.h"

namespace Entidades
{
    namespace Personagens
    {
        const unsigned int Inimigo::idClasse(2);

        Inimigo::Inimigo(sf::Color c, const float tamXX, const float tamYY, const float xx, const float yy, const int vd, const float vel, const int f, const float duraEspera, const float duraAtaque):
        Personagem(idClasse, c ,tamXX, tamYY, xx, yy, vd, vel, f, duraEspera, duraAtaque),
        jogadorPerseguido(NULL),
        distancia_jogador(0.0f),
        tempoVolta(0.0f)
        {
        }

        Inimigo::Inimigo():
        Personagem(),
        jogadorPerseguido(NULL),
        distancia_jogador(0.0f),
        tempoVolta(0.0f)
        {
        }

        Inimigo::~Inimigo()
        {
            jogadorPerseguido = NULL;
        }

        void Inimigo::setJogador(Jogador* pJogador)
        {
            jogadorPerseguido = pJogador;
        }

        sf::Vector2f Inimigo::getPosJogador()
        {
            if(jogadorPerseguido)
            {
                return jogadorPerseguido->getPosicao();
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
                atacarDist(jogadorPerseguido);
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