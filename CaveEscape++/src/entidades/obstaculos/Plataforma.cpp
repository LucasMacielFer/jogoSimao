#include "../../../include/entidades/obstaculos/Plataforma.h"

namespace Entidades
{
    namespace Obstaculos
    {
        Plataforma::Plataforma(const char* txt, const float xx, const float yy, const bool ehChao):
        Obstaculo(txt, TAM_PLAT_X, TAM_PLAT_Y, xx, yy, idObstaculos::plat, false),
        chao(ehChao)
        {
            if(!chao) {sustentacao = SUSTENTACAO;}
            else      {sustentacao = SUSTMAX;}
        }

        Plataforma::Plataforma():
        Obstaculo(),
        chao(false)
        {
        }

        Plataforma::~Plataforma()
        {
        }

        void Plataforma::salvar(const char* caminhoSalvamento)
        {
            Obstaculo::salvar(caminhoSalvamento);
            salvamento += " ";
            salvamento += std::to_string(chao);
            salvamento += " ";
            salvamento += std::to_string(sustentacao);

            std::ofstream gravador(caminhoSalvamento, std::ios::app);
            if(!gravador)
            {
                std::cout<<"Erro ao salvar plataforma"<<std::endl;
            }
            else
            {
                gravador << salvamento << std::endl;
            }
            gravador.close();
        }

        void Plataforma::executar(float dt)
        {
            if(!chao)
            {
                aplicaGravidade(dt);
            }
        }

        void Plataforma::regularColisao(Entidade* entAlternativa, sf::Vector2f distancia_colisao)
        {
            if(entAlternativa->getId() == idEntes::Jogador || entAlternativa->getId() == idEntes::Inimigo)
            {
                if(distancia_colisao.x > distancia_colisao.y)
                {
                    if(x < entAlternativa->getPosicao().x)
                    {
                        if(velocidadeX > 0) {velocidadeX = 0;}
                            dynamic_cast<Personagens::Personagem*>(entAlternativa)->setPulo(false);
                    }
                    else
                    {
                        if(velocidadeX < 0) {velocidadeX = 0;}
                            dynamic_cast<Personagens::Personagem*>(entAlternativa)->setPulo(false);
                    }
                }
                else 
                {
                    if(y < entAlternativa->getPosicao().y)
                    {
                        if(velocidadeY > 0) {velocidadeY = 0;}
                            dynamic_cast<Personagens::Personagem*>(entAlternativa)->setPulo(false);
                    }
                    else 
                    {
                        if(velocidadeY > 0) {velocidadeY = 0;}
                            dynamic_cast<Personagens::Personagem*>(entAlternativa)->setPulo(true);
                    }
                }
            }
        }

        void Plataforma::obstacular(Personagens::Personagem* p)
        {
            p->setVelocidade(p->getVelMax());
        }
    }
}