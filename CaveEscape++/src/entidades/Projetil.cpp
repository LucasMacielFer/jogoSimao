#include "../../include/entidades/Projetil.h"
#include "../../include/entidades/personagens/Personagem.h"

namespace Entidades
{
    Projetil::Projetil(Personagens::Inimigo* at, const char* txt, const float tamXX, const float tamYY, const float xx, const float yy, const int sentMovX, const float vel):
    Entidade(idEntes::Projetil, txt, tamXX, tamYY, xx, yy, sentMovX, vel),
    dano(1),
    ativo(true),
    atirador(at)
    {
    }

    Projetil::Projetil():
    Entidade(),
    dano(0),
    ativo(false),
    atirador(NULL)
    {
    }
    
    Projetil::~Projetil()
    {
        ativo = false;
        atirador = NULL;
        dano = 0;
    }

    const bool Projetil:: getAtivo() const
    {
        return ativo;
    }
    
    Personagens::Inimigo* Projetil::getAtirador() const
    {
        return atirador;
    }


    void Projetil::regularColisao(Entidade* entAlternativa, sf::Vector2f distancia_colisao)
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

    void Projetil::colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao)
    {
        if(entAlternativa->getId() == idEntes::Jogador)
        {
            dynamic_cast<Personagens::Personagem*>(entAlternativa)->sofrerDano(dano);
        }
        else if(entAlternativa->getId() == idEntes::Inimigo)
        {
            return;
        }
        else if(entAlternativa->getId() == idEntes::Obstaculo)
        {
            regularColisao(entAlternativa, distancia_colisao);
        }
        sumir();
    }

    void Projetil::executar(float dt)
    {
        if(ativo)
        {
            aplicaGravidade(dt);
            mover();
        }
    }

    void Projetil::salvar(const char* caminhoSalvamento)
    {
        Entidade::salvar(caminhoSalvamento);
        salvamento += " ";
        salvamento += std::to_string(ativo);
        salvamento += " ";
        salvamento += std::to_string(dano);

        std::ofstream gravador(caminhoSalvamento, std::ios::app);
        if(!gravador)
        {
            std::cout<<"Erro ao salvar projetil"<<std::endl;
        }
        else
        {
            gravador << salvamento << std::endl;
        }
        gravador.close();
    }

    void Projetil::sumir()
    {
        ativo = false;
    }
}