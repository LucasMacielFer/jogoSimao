#include "../../../include/entidades/personagens/Inimigo.h"

namespace Entidades
{
    namespace Personagens
    {
        Jogador* Inimigo::jogador1Perseguido(NULL);
        Jogador* Inimigo::jogador2Perseguido(NULL);

        Inimigo::Inimigo(const char* txt, const float tamXX, const float tamYY, const float xx, const float yy, const int vd, const float vel, const int f, const float duraEspera, const float duraAtaque, const tipoInimigo tipo):
        Personagem(idEntes::Inimigo, txt ,tamXX, tamYY, xx, yy, vd, vel, f, duraEspera, duraAtaque),
        distancia_jogador1(0.0f),
        distancia_jogador2(0.0f),
        tempoVolta(0.0f),
        tipoInim(tipo)
        {
        }

        Inimigo::Inimigo():
        Personagem(),
        distancia_jogador1(0.0f),
        distancia_jogador2(0.0f),
        tempoVolta(0.0f),
        tipoInim(tipoInimigo::Indef)
        {
        }

        Inimigo::~Inimigo()
        {
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

        const bool Inimigo::existeP1()
        {
            if(jogador1Perseguido)
                return true;
            else
                return false;
        }

        const bool Inimigo::existeP2()
        {
            if(jogador2Perseguido)
                return true;
            else
                return false;
        }
        
        const tipoInimigo Inimigo::getTipo() const
        {
            return tipoInim;
        }

        void Inimigo::executar(float dt)
        {
            if(vivo)
            {
                tempoVolta += dt;
                aumentarTempoExecucao(dt);
                aplicaGravidade(dt);
                habilidadeInimiga(dt);
                direcionar();
                mover();
            }
        }

        void Inimigo::colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao)
        {
            if(entAlternativa->getId() == idEntes::Obstaculo)
                regularColisao(entAlternativa, distancia_colisao);
            if(entAlternativa->getId()== idEntes::Jogador)
            {
                danificar(dynamic_cast<Jogador*>(entAlternativa));
            }
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

        void Inimigo::morrer()
        {
            vivo = false;
        }

        void Inimigo::salvar(const char* caminhoSalvamento)
        {
            Personagem::salvar(caminhoSalvamento);
            salvamento += " ";
            salvamento += std::to_string(tempoVolta);
            salvamento += " ";
            salvamento += std::to_string(tipoInim);
        }
    }
}