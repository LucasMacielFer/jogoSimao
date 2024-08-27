#include "../../include/entidades/Projetil.h"
#include "../../include/entidades/personagens/Personagem.h"

namespace Entidades
{
    const int Projetil::idClasse(4);

    Projetil::Projetil(Personagens::Inimigo* at, const char* txt, const float tamXX, const float tamYY, const float xx, const float yy, const int sentMovX, const float vel):
    Entidade(idClasse, txt, tamXX, tamYY, xx, yy, sentMovX, vel),
    dano(1),
    ativo(true),
    atirador(at)
    {
    }

    Projetil::Projetil():
    Entidade(),
    dano(0),
    ativo(false)
    {
    }
    
    Projetil::~Projetil()
    {
        atirador = NULL;
        dano = 0;
    }

    const bool Projetil:: getAtivo() const
    {
        return ativo;
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
        if(entAlternativa->getId()==1)
        {
            dynamic_cast<Personagens::Personagem*>(entAlternativa)->sofrerDano(dano);
        }
        else if(entAlternativa->getId()==2)
        {
            dynamic_cast<Personagens::Personagem*>(entAlternativa)->sofrerDano(dano/2);
        }
        else if(entAlternativa->getId()==3)
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

    void Projetil::salvar()
    {
    }

    void Projetil::sumir()
    {
        ativo = false;
    }
}