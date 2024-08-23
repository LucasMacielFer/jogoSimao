#include "../../../include/entidades/obstaculos/Obstaculo.h"

namespace Entidades
{
    namespace Obstaculos
    {
        const unsigned int Obstaculo::idClasse(3);

        Obstaculo::Obstaculo(sf::Color c, const float tamXX, const float tamYY, const float xx, const float yy, const bool dano):
        Entidade(idClasse, c, tamXX, tamYY, xx, yy),
        danoso(dano)
        {
        }

        Obstaculo::Obstaculo():
        Entidade(),
        danoso(false)
        {
        }

        Obstaculo::~Obstaculo()
        {
            danoso = false;
        }

        void Obstaculo::obstacular(Personagens::Jogador* p)
        {
        }

        void Obstaculo::regularColisao(Entidade* entAlternativa, sf::Vector2f distancia_colisao)
        {            
            if(distancia_colisao.x > distancia_colisao.y)
            {
                if(x < entAlternativa->getPosicao().x)
                {
                    if(velocidadeX > 0) {velocidadeX = 0;}
                }
                else
                {
                    if(velocidadeX < 0) {velocidadeX = 0;}
                }
            }
            else 
            {
                if(y < entAlternativa->getPosicao().y)
                {
                    if(velocidadeY > 0) {velocidadeY = 0;}
                }
                else 
                {
                    if(velocidadeY < 0) {velocidadeY = 0;}
                }
            }
        }

        void Obstaculo::colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao)
        {
            regularColisao(entAlternativa, distancia_colisao);
            if(entAlternativa->getId()==1)
            {
                obstacular(dynamic_cast<Personagens::Jogador*>(entAlternativa));
            }
        }
    }
} 