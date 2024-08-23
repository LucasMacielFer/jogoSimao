#include "../../include/entidades/Entidade.h"

namespace Entidades
{
    Entidade::Entidade(const int i, sf::Color c, const float tamXX, const float tamYY, const float xx, const float yy, const float vel):
    Ente(i),
    tamX(tamXX),
    tamY(tamYY),
    x(xx),
    y(yy),
    maxVelocidade(vel),
    velocidade(vel),
    velocidadeX(0.0f),
    velocidadeY(0.0f),
    sentidoMovX(1),
    retangulo(sf::Vector2f(tamXX, tamYY))
    {
        retangulo.setOrigin(tamX / 2.0f, tamY / 2.0f);
        retangulo.setPosition(x, y);
        retangulo.setFillColor(c);
    } 

    Entidade::Entidade(const int i, sf::Color c, const float tamXX, const float tamYY, const float xx, const float yy):
    Ente(i),
    tamX(tamXX),
    tamY(tamYY),
    x(xx),
    y(yy),
    maxVelocidade(0.0f),
    velocidade(0.0f),
    velocidadeX(0.0f),
    velocidadeY(0.0f),
    sentidoMovX(0),
    retangulo(sf::Vector2f(tamXX, tamYY))
    {
        retangulo.setOrigin(tamX / 2.0f, tamY / 2.0f);
        retangulo.setPosition(x, y);
        retangulo.setFillColor(c);
    } 

    // Sobrecarga para o projetil
    Entidade::Entidade(const int i, sf::Color c, const float tamXX, const float tamYY, const float xx, const float yy, const int sentMovX, const float vel):
    Ente(i),
    tamX(tamXX),
    tamY(tamYY),
    x(xx),
    y(yy),
    maxVelocidade(vel),
    velocidade(vel),
    velocidadeX(vel),
    velocidadeY(0.0f),
    sentidoMovX(sentMovX),
    retangulo(sf::Vector2f(tamXX, tamYY))
    {
        retangulo.setOrigin(tamX / 2.0f, tamY / 2.0f);
        retangulo.setPosition(x, y);
        retangulo.setFillColor(c);
    }

    Entidade::Entidade():
    Ente(-1),
    tamX(0),
    tamY(0),
    x(0),
    y(0),
    maxVelocidade(0.0f),
    velocidade(0.0f),
    velocidadeX(0.0f),
    velocidadeY(0.0f),
    sentidoMovX(0),
    retangulo()
    {
    }

    Entidade::~Entidade()
    {
        x = -1;
        y = -1;
    }

    void Entidade::setTamanho(const float xx, const float yy)
    {
        tamX = xx;
        tamY = yy;
    }

    //Mudar para sf::Vector2f v = {tamX, tamY};
    const sf::Vector2f Entidade::getTamanho() const
    {
        sf::Vector2f v = {tamX, tamY};
        return v;
    }

    void Entidade::setPosicao(const float xx, const float yy)
    {
        x = xx;
        y = yy;
    }

    const sf::Vector2f Entidade::getPosicao() const 
    {
        sf::Vector2f v = {x, y};
        return v;
    }

    void Entidade::setVelocidade(const float vel)
    {
        if(vel > 0)
            velocidade = vel;
        else
            velocidade = 0;
    }

    const float Entidade::getVelMax() const
    {
        return maxVelocidade;
    }

    void Entidade::movimentaX(const float s)
    {
        sentidoMovX = s;
        if(s <= 1 && s >= -1) {velocidadeX = s*velocidade;}
    }

    // Implementação da gravidade baseada no jogo Desert++, do monitor Matheus Burda
    // Disponível em: https://github.com/MatheusBurda/Desert/tree/4d1ec28610a4675cfa3defc2a1aac12f28ffad2b
    void Entidade::aplicaGravidade(float dt)
    {
        velocidadeY += GRAVIDADE*dt;
    }

    void Entidade::desenhar(sf::RenderWindow& janela)
    {
        janela.draw(retangulo);
    }

    void Entidade::mover()
    {
        x += velocidadeX;
        y += velocidadeY;
        atualizaEntidade();
    }

    void Entidade::atualizaEntidade()
    {
        retangulo.setPosition(x, y);
    }
}