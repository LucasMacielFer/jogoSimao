#include "../../../include/entidades/personagens/Personagem.h"

namespace Entidades
{
    namespace Personagens
    {
        Personagem::Personagem(idEntes i, const char* txt, const float tamXX, const float tamYY, const float xx, const float yy, const int vd, const float vel, const int f, const float duraEspera, const float duraAtaque):
        Entidade(i, txt, tamXX, tamYY, xx, yy, vel),
        vidas(vd),
        forca(f),
        atacando(false),
        puloDisponivel(false),
        duracaoEspera(duraEspera),
        duracaoAtaque(duraAtaque),
        tempoEsperando(0.0f),
        tempoAtacando(0.0f),
        vivo(true)
        {
        }

        Personagem::Personagem():
        Entidade(),
        vidas(0.0f),
        forca(0),
        atacando(false),
        puloDisponivel(false),
        duracaoEspera(0.0f),
        duracaoAtaque(0.0f),
        tempoEsperando(0.0f),
        tempoAtacando(0.0f),
        vivo(false)
        {
        }

        Personagem::~Personagem()
        {
            vidas = -1;
        }

        const int Personagem::getVidas() const
        {
            return vidas;
        }

        void Personagem::setVidas(const int v)
        {
            vidas = v;
        }
        
        const bool Personagem::getPulo() const
        {
            return puloDisponivel;
        }

        void Personagem::setPulo(const bool p)
        {
            puloDisponivel = p;
        }   

        void Personagem::sofrerDano(const int dano)
        {
            vidas -= dano;
            if(vidas <= 0)
            {
                morrer();
            }
        }

        const bool Personagem::getVivo() const
        {
            return vivo;
        }

        void Personagem::executar(float dt)
        {

        }

        void Personagem::pular()
        {
            if(puloDisponivel)
            {
                velocidadeY = -10;
                puloDisponivel = false;
            }
        }

        const int Personagem::getForca() const
        {
            return forca;
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

        void Personagem::setAtaque(const bool status_ataque)
        {
            atacando = status_ataque;
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
            if(distancia_colisao.x > distancia_colisao.y)
            {
                if(x < entAlternativa->getPosicao().x)
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
                if(y < entAlternativa->getPosicao().y)
                {
                    y += distancia_colisao.y;
                    if(velocidadeY > 0) {velocidadeY = 0;}
                }
                else 
                {
                    y -= distancia_colisao.y;
                    if(velocidadeY < 0) {velocidadeY = 0;}
                }
            }
        }

        void Personagem::salvar(const char* caminhoSalvamento)
        {
            Entidade::salvar(caminhoSalvamento);
            salvamento += std::to_string(vidas);
            salvamento += " ";
            salvamento += std::to_string(forca);
            salvamento += " ";
            salvamento += std::to_string(atacando);
            salvamento += " ";
            salvamento += std::to_string(puloDisponivel);
            salvamento += " ";
            salvamento += std::to_string(duracaoEspera);
            salvamento += " ";
            salvamento += std::to_string(duracaoAtaque);
            salvamento += " ";
            salvamento += std::to_string(tempoEsperando);
            salvamento += " ";
            salvamento += std::to_string(tempoAtacando);
            salvamento += " ";
            salvamento += std::to_string(vivo);
        }
    }
}