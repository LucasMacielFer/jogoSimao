#include "../../../include/entidades/personagens/Inimigo.h"

namespace Entidades
{
    namespace Personagens
    {
        Inimigo::Inimigo(std::string txt,const int vd, const float vel, const int danos, const float duraEspera, const float duraAtaque, const float tamXX, const float tamYY, const float xx, const float yy): Personagem(txt, vd, vel, danos, duraEspera, duraAtaque, tamXX, tamYY, xx, yy),
        jogadorPerseguido(NULL),
        distancia_jogador(0.0f, 0.0f)
        {

        }

        Inimigo::~Inimigo()
        {
            jogadorPerseguido = NULL;
        }

        void Inimigo:: setJogador(Jogador* pJogador)
        {
            jogadorPerseguido = pJogador;
        }

        sf::Vector2f Inimigo:: getPosJogador()
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

    }

}