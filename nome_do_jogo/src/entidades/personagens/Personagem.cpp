#include "../../../include/entidades/personagens/Personagem.h"

namespace Entidades
{
    namespace Personagens
    {
        Personagem::Personagem(std::string txt, const int vd, const float vel, const int danos, const float duraEspera, const float duraAtaque, const float tamXX, const float tamYY, const float xx, const float yy):
        Entidade(txt, tamXX, tamYY, xx, yy),
        vidas(vd),
        velocidade(vel),
        velocidadeX(0),
        velocidadeY(0),
        dano(danos),
        atacando(false),
        puloDisponivel(false),
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

        void Personagem::mover()
        {
            x += velocidadeX;
            y += velocidadeY;
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
        void Personagem::atacar(Personagem* pPersonagem)
        {
            //Coloca o personagem no status de atacar se for possível.
            if(ataqueDisponivel())
            {
                if(!atacando)
                {
                    pPersonagem->sofrerDano(dano);
                }
                atacando = true;
            }
        }

        void Personagem::pular()
        {
            if(puloDisponivel)
            {
                velocidadeY = -10;
                puloDisponivel = false;
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
        void Personagem::aumentarTempoExecucao(const float tempo)
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

        // Método adaptado do monitor Matheus Burda. https://github.com/MatheusBurda/Desert.git Acesso em: 19/08/2024.
        void Personagem::regularColisao(Entidade* entAlternativa, sf::Vector2f distancia_colisao)
        {
            Personagem* paux = static_cast<Personagem*> (entAlternativa);
            
            if(distancia_colisao.x > distancia_colisao.y)
            {
                if(x < paux->x)
                {
                    x += distancia_colisao.x;
                    if(velocidadeX > 0) {velocidadeX = 0;}
                }
                else
                {
                    x -= distancia_colisao.x;
                    if(velocidadeX < 0) {velocidadeX = 0;}
                }
            }
            else 
            {
                if(y < paux->y)
                {
                    y += distancia_colisao.y;
                    if(velocidadeY > 0) {velocidadeY = 0;}
                    if(!puloDisponivel) {puloDisponivel = true;}
                }
                else 
                {
                    y -= distancia_colisao.y;
                    if(velocidadeY < 0) {velocidadeY = 0;}
                }
            }
        }

        void Personagem::setSentidoMovX(const float s)
        {
            if(s <= 1 && s >= -1) {velocidadeX = s*velocidade;}
        }

        void Personagem::setSentidoMovY(const float s)
        {
            if(s <= 1 && s >= -1) {velocidadeX = s*velocidade;}
        }

        // Implementação da gravidade baseada no jogo Desert++, do monitor Matheus Burda
        // Disponível em: https://github.com/MatheusBurda/Desert/tree/4d1ec28610a4675cfa3defc2a1aac12f28ffad2b
        void Personagem::aplicaGravidade(float dt)
        {
            velocidadeY += GRAVIDADE*dt;
        }
    }
}