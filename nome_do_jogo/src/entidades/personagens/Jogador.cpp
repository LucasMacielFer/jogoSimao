#include "../../../include/entidades/personagens/Jogador.h"

namespace Entidades
{
    namespace Personagens
    {
        Jogador::Jogador(std::string txt,const int vd, const float vel, const int danos, const float duraEspera, const float duraAtaque, const float tamXX, const float tamYY, const float xx, const float yy): Personagem(txt, vd, vel, danos, duraEspera, duraAtaque, tamXX, tamYY, xx, yy), pontuacao(0)
        {

        }
        Jogador::~Jogador()
        {
            pontuacao = -1;
        }

        const int Jogador:: getPontuacao() const
        {
            return pontuacao;
        }

        void Jogador:: operator++()
        {
            pontuacao++;
        }
        void Jogador::executar()
        {
            mover();
        }
        void Jogador::salvar()
        {

        }

        void Jogador::colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao)
        {
            if(entAlternativa)
            {
                //if( entAlternativa->getId() == 1    /*"Inimigo"*/ )
                //{
                //    Personagem* paux = static_cast<Personagem*>(entAlternativa);
                //    if(paux && emAtaque())
                //    {
                //        paux->sofrerDano(dano);
                //    }
                //}
                //else if(entAlternativa->getId() == 2  /*"Obstaculo"*/)
                //{
                    regularColisao(entAlternativa, distancia_colisao);
                    puloDisponivel = true;
                //}
            }
        }

        void Jogador::pular()
        {
            if(puloDisponivel)
            {
                //implementar a ação da gravidade com velocidade.y = - raiz de mgh(porém é preciso alterar o atributo de velocidade)
                puloDisponivel = false;
            }
        }
    }
}