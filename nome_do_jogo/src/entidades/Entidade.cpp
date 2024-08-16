#include "../../include/entidades/Entidade.h"

namespace Entidades
{
    Entidade::Entidade(const float tamXX, const float tamYY, const float xx, const float yy):
    Ente(),
    tamX(tamXX),
    tamY(tamYY),
    x(xx),
    y(yy),
    retangulo(sf::Vector2f(100.0f, 100.0f))
    {
        retangulo.setOrigin(tamX / 2.0f, tamY / 2.0f);
        retangulo.setPosition(x, y);
        retangulo.setFillColor(sf::Color::White);
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

    void Entidade::desenhar(sf::RenderWindow& janela)
    {
        janela.draw(retangulo);
    }

    void Entidade::atualizaEntidade()
    {
        retangulo.setPosition(x, y);
    }
}