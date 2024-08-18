#include "../../../include/entidades/personagens/Personagem.h"

namespace Entidades
{
    namespace Personagens
    {
        Personagem::Personagem(const int vd, const float vel, const int danos, const float duraEspera, const float duraAtaque, const float tamXX, const float tamYY, const float xx, const float yy):
        Entidade(tamXX, tamYY, xx, yy),
        vidas(vd),
        velocidade(vel),
        dano(danos),
        atacando(false),
        duracaoEspera(duraEspera),
        duracaoAtaque(duraAtaque),
        tempoEsperando(0.0f),
        tempoAtacando(0.0f)
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

        void Personagem::sofrerDano(const int dano)
        {
            vidas -= dano;

            if(vidas <= 0)
            {
                //Precisa se desativar o jogador;
            }
        }
        void Personagem::atacar()
        {
            //Coloca o personagem no status de atacar se for possível.
            if(ataqueDisponivel())
            {
                atacando = true;
            }

        }
        const bool Personagem::ataqueDisponivel() const
        {
            //Responde se ele pode atacar, comparando o tempo da finalização do ultimo ataque com o tempo mínimo necessário de espera para realizar outro ataque.
            if(tempoEsperando > duracaoEspera)
            {
                return true;
            }
            else 
            {
                return false;    
            }
        }
        const bool Personagem::emAtaque() const
        {
            return atacando;
        }
        void Personagem::aumentarDuracaoAtaque(const float tempo)
        {
            if(emAtaque())
            {
                //Vai acontecendo enquanto o tempo definido de ataque não conclui.
                tempoEsperando = 0;
                tempoAtacando += tempo;

                //Caso a duração do ataque chegue no limite ele diz que o ataque chegou ao fim.
                if(tempoAtacando > duracaoAtaque)
                {
                    atacando = false;
                }
            }
            else 
            {
                //Vai considerando o tempo desde a finalização do último ataque.
                tempoEsperando += tempo;
                tempoAtacando = 0;
            }
        }

        /*void Personagem::regularColisao(Entidade* EntAlternativa, sf::Vector2f distancia_colisao)
        {

        }*/

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

        void Personagem::colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao)
        {
        }
    }
}