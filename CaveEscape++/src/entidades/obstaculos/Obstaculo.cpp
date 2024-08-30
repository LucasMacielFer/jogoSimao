#include "../../../include/entidades/obstaculos/Obstaculo.h"

namespace Entidades
{
    namespace Obstaculos
    {
        Obstaculo::Obstaculo(const char* txt, const float tamXX, const float tamYY, const float xx, const float yy, idObstaculos id, const bool dano):
        Entidade(idEntes::Obstaculo, txt, tamXX, tamYY, xx, yy),
        identificador(id),
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
            if(entAlternativa->getId() == idEntes::Jogador || entAlternativa->getId() == idEntes::Inimigo)
            {
                obstacular(dynamic_cast<Personagens::Personagem*>(entAlternativa));
            }
        }

        void Obstaculo::salvar(const char* caminhoSalvamento)
        {
            Entidade::salvar(caminhoSalvamento);
            salvamento += " ";
            salvamento += std::to_string(identificador);
            salvamento += " ";
            salvamento += std::to_string(danoso);
        }
    }
} 