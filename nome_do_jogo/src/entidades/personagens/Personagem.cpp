#include "../../../include/entidades/personagens/Personagem.h"

namespace Entidades
{
    namespace Personagens
    {
        Personagem::Personagem(const int vd, const int vel, const int tamXX, const int tamYY, const int xx, const int yy):
        Entidade(tamXX, tamYY, xx, yy),
        vidas(vd),
        velocidade(vel)
        {
        }

        Personagem::~Personagem()
        {
            vidas = -1;
        }

        void Personagem::mover(int dir)
        {
            switch(dir)
            {
                case -1:
                    x -= velocidade;
                    break;
                case 1:
                    x += velocidade;
                    break;
                case -2:
                    y += velocidade;
                    break;
                case 2:
                    y -= velocidade;
                    break;
                default:
                    break;
            }

            atualizaEntidade();
        }

        const int Personagem::getVidas() const
        {
            return vidas;
        }

        void Personagem::setVidas(const int v)
        {
            vidas = v;
        }

        void Personagem::operator++()
        {
            vidas++;
        }

        void Personagem::operator--()
        {
            vidas--;
        }

        // Devem ser virtuais PURAS
        void Personagem::executar()
        {
        }

        void Personagem::salvar()
        {
        }
    }
}